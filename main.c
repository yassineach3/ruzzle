/*
 * Main.c
 *
 *  Created on: 18 Dec 2017
 *      Author: Yassine
 */
#include "Dico.h"
#include "Grille.h"

int main(void){

	char** grille;
	grille=malloc(4*sizeof(char*));
	int i;
	for(i=0;i<4;++i){
		grille[i]=malloc(4*sizeof(char));
	}


	gener_gril(grille);
	affic_mat(grille);



	    PTR d = dico('!', NULL, NULL);
	    read_file(d);
//
//	    pile.n = 0;
//	    afficher(d);





		printf("entrer un mot\n");

		char* mot=malloc(50*sizeof(char));

		scanf("%s",mot);

		if(chercher_mot(mot,d)==1){
			printf("le mot' %s 'existe\n",mot);
		}else
			printf("le mot' %s 'existe pas \n",mot);
		system("pause");
	//return 0;
}
