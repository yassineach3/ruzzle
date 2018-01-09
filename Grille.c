/*
 * Grille.c
 *
 *  Created on: 18 Dec 2017
 *      Author: Yassine
 *
 */

/* Affiche une matrice */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Grille.h"

void affic_mat(char** mat){
	if(mat){
		int i, j;
		for(i = 0; i < 4 ; i++){
			for(j = 0; j < 4; j++)
				printf("%c ", mat[i][j]);
	  	printf("\n");
	  }
	  printf("\n");
	}else
		printf("$$$$$$$$$$$$$ problème avec la matrice\n");
}

char distLetter(){
    rand();
    int x = rand() % 15833;
    if(x < 1209) return 'a';
    if(x < 1510) return 'b';
    if(x < 2151) return 'c';
    if(x < 2699) return 'd';
    if(x < 4526) return 'e';
    if(x < 4726) return 'f';
    if(x < 5161) return 'g';
    if(x < 5528) return 'h';
    if(x < 6931) return 'i';
    if(x < 6957) return 'j';
    if(x < 7101) return 'k';
    if(x < 7947) return 'l';
    if(x < 8395) return 'm';
    if(x < 9462) return 'n';
    if(x < 10496) return 'o';
    if(x < 10962) return 'p';
    if(x < 10987) return 'q';
    if(x < 12111) return 'r';
    if(x < 13613) return 's';
    if(x < 14653) return 't';
    if(x < 15174) return 'u';
    if(x < 15328) return 'v';
    if(x < 15452) return 'w';
    if(x < 15499) return 'x';
    if(x < 15757) return 'y';
    return 'z';
}

void gener_gril(char **mat){
	int i, j;
	srand(time(NULL));
	for(i = 0; i < 4 ; i++){
		for(j = 0; j < 4; j++)
			mat[i][j] = distLetter();
	}
}

void gener_gril_test(char** mat){
	mat[0][0]='S';
	mat[0][1]='E';
	mat[0][2]='T';
	mat[0][3]='R';

	mat[1][0]='S';
	mat[1][1]='N';
	mat[1][2]='R';
	mat[1][3]='S';

	mat[2][0]='V';
	mat[2][1]='E';
	mat[2][2]='C';
	mat[2][3]='U';

	mat[3][0]='M';
	mat[3][1]='G';
	mat[3][2]='L';
	mat[3][3]='U';

}


//int verifier_mot(char** mat,char* chaine){
//	if(mat && chaine){
//		int i,j,index=1;
//		char proch,c = chaine[0];
//		for(i=0;i<4;i++){
//			for(j=0;j<4;j++){
//				if(mat[i][j] == c){
//					proch=chaine[index];
//					if(mat[i-1][j-1] && )
//				}
//			}
//		}
//
//	}
//}



