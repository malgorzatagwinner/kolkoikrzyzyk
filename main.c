#include <stdio.h>

/*tworzenie tabelki*/

char board[3][3]= {
	' ',' ',' ',
	' ',' ',' ',
	' ',' ',' ',
    };
void printboard() {
    printf("  | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
    printf("-----------------\n");
    printf("  | %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
    printf("-----------------\n");
    printf("  | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
}

int czywygralem (char znak) {
	int i=0; /*zmienna poruszajaca sie po wierszach*/
	int k=0; /*zmienna poruszajaca sie po kolumnach*/
	int p=0; /*zmienna zapisujaca czy sa juz 3 znaki*/
    for (i=0; i<3;i++){
	for (k=0; k<3; k++){
	    if(board[i][k]!=znak)
		p=0;
	    else
		p++;
	}
        if (p==3){
	    printf("Brawo, wygrales!");
	    return 1;
	}
    }
    for (k=0; k<3; k++){
	for (i=0; i<3; i++){
	    if(board[i][k]!=znak)
		p=0;
	    else
		p++;
    }
	if (p==3)
	    return 1;
/*sprawdzanie mozliwosci wygranej po przekatnej*/
    if((board[0][0]==znak && board[1][1]==znak && board[2][2]==znak) || (board[0][2]==znak && board[1][1]==znak && board[2][0]==znak)){
	printf("Brawo, wygrales!");
	return 1;
	}
    }
return 0;
}

/*sprawdzanie co jest na danym polu*/
int koleczkokrzyzykczynic( char znak) {
	    if(znak == 'O'){
	        return 1;
	    }
	    if(znak == 'X'){
	        return 1;
	    }
	    if(znak == ' '){
	        return 0;
	    }
	    else
		return 0;
}

/*sprawdzanie czy mozna wsadzic znak na pole*/
int czymogewsadzicznaknapole( int a, int b) {
    int m=0;
    m = koleczkokrzyzykczynic(board[a][b]);
	if(m==1){
	    printf("Zle pole, sprobuj jeszcze raz\n");
	    return 0;
	}
	else
	    return 1;

}

int komputergra(char znak);

/*jesli mozna wsadzic znak na pole, to tam go wstawiamy*/
int gra( char znak) {
    if(znak == 'X'){
	    komputergra(znak);
		return 1;
    }
    int a;
    int b;
    printf("\n Podaj wspolrzedne wybranego pola w ktorym chcesz miec znak\n");
    scanf("%d %d", &a,& b);
    if (czymogewsadzicznaknapole(a,b)) {
	board[a][b] = znak;
        
        return  1;
    }
    else {
	return 0;
    }
}

/*kiedy wszystkie pola sa zajete, wtedy jest remis*/
int remis(){
    int p=0;
    int i=0;
    int k=0;
    for(i=0;i<3;i++){
	for(k=0; k<3; k++){
	    if(koleczkokrzyzykczynic(board[i][k])){
		p++;
	    }
	    else{
		p=0;
	    }
	}
    }
    char znak;
    if(p==9 && czywygralem(znak)==0){
	printf("Remis, koniec gry\n");
	return 1;
    }
return 0;
}

/*zmiana z jednego gracza na drugiego*/
void kolejnygracz(char* gracz){
	if(*gracz == 'X'){
	    *gracz = 'O';
	}
	else{
	    *gracz = 'X';
	}
}

/*sprawdzanie czy komputer moze zrobic ruch w danym polu*/
int ruchkomputera(int *a, int *b){
	for(*a=0; *a<3; *a=*a+1){
	    for(*b=0; *b<3; *b=*b+1){
		fprintf(stderr, "a = %d, b= %d\n", *a, *b);
fflush(stderr);
		if(czymogewsadzicznaknapole(*a,*b)){
		    return 1;
	        }
	    }
	}
}

int komputergra(char znak){
    int a;
    int b;
    if(ruchkomputera(&a, &b)){
	    board[a][b] = znak;
	    return 1;
    }
    else{
	return 0;
    }
}



int main(){
    
    char gracz= 'O';

    while(remis()==0 && czywygralem('X')==0 && czywygralem('O')==0){
        printboard();
	while(gra(gracz)==0){}
        kolejnygracz(&gracz);
    }
}