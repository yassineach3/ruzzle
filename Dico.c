/*
 * Dico.c
 *
 *  Created on: 17 Dec 2017
 *      Author: Yassine
 */
#include "Dico.h"

double ordre [26] = {16.72,3.48,9.2,3.33,11.29,0.23,0.5,1,8.41,0.55,0.05,2.15,1.91,5.75,6.02,0.87,0.52,6.56,9.02,6.99,3.55,0.56,0.01,0.03,0.23,1.11};

/**
 * bref: initialisation de la racine du dictionnaire
 */
PTR initDictionnaire(){
	PTR d= malloc(sizeof(Dico));
	if(d){
		d->lettre='!';
		d->lettreSuivant=NULL;
		d->elementSuivant=NULL;
		return d;
	}
		free(d);
		d=NULL;
	return d;

}
//----------------------------------------
/**
 * bref: création d'un element de dictionnaire
 *
 */
PTR dico(char lettre, PTR lettreSuivant, PTR elementSuivant) {
		PTR p = malloc(sizeof(Dico));
		assert(p != NULL);
		p->lettre = lettre;
		p->lettreSuivant = lettreSuivant;
		p->elementSuivant = elementSuivant;
	return p;
}
//----------------------------------------
/**
 *	exemple d'insertion de "a" , "azami" , "azerty"
 *  racine ==>    '!'
 * 				  /
 * 				 'a'
 * 				/   \
 * 				'\0'   'z'
 * 					  /   \
 * 					 'a'    'e'
 * 				      \		  \
 * 				      'm'	  'r'
 * 			   	        \	    \
 * 					    'i'	     't'
 * 					    /         /
 * 					   '\0'       'y'
 * 					     		  /
 * 					     		'\0'
 */
int ajouterMot(char mot[], PTR d) {
    PTR pr, pc;
    int i;
    /* à chaque tour de cette boucle on recherche le caractère */
    /* mot[i] parmi les lettreSuivant du nœud pointé par ancetre */
    for(i = 0; ; i++) { // bouclé sur la chaine mot
        pr = NULL;
        pc = d->lettreSuivant;
        while (pc && ordre[(pc->lettre) - 97] > ordre[mot[i]-97]) {
            pr = pc;
            pc = pc->elementSuivant;
        }
        if (pc && pc->lettre == mot[i]) {
            if (mot[i] == '\0')
                return 1; /* le mot existait */
            d = pc;
        }
        else {
            pc = dico(mot[i], NULL, pc);
            if (pr != NULL)
                pr->elementSuivant = pc;
            else
                d->lettreSuivant = pc;
            while (mot[i] != '\0') {
                pc->lettreSuivant = dico(mot[++i], NULL, NULL);
                pc = pc->lettreSuivant;
            }
            return 0; /* le mot est nouveau */
        }
    }
}
//----------------------------------------
/**
 * bref: verifier que la lettre c si il existe sur des elément suivant
 *
 */
PTR verifierElement(PTR d,char c){
		if (d->lettre == c)
				return d;
			else{
				if(d->elementSuivant)
					return verifierElement(d->elementSuivant,c);
				else
					return d;
			}
}
//----------------------------------------
/*
 * 1 il a  trouvé
 * 0 sinon
 */
int chercher_mot(char mot[], PTR d){
	if(strlen(mot)>0){
		assert(mot != NULL);
		PTR dr;

		dr=verifierElement(d->lettreSuivant,mot[0]);
		if(dr->lettre == mot[0]){
			mot++;
			chercher_mot(mot,dr);
		}else // atteind le dernier élement il y rien
			return 0;

	}else{// je dois verifier que parmis les lettreSuivant de dr il a un \0
			d=verifierElement(d->lettreSuivant,'\0');//  est ce que mot en param forme vraiment un mot
			if(d->lettre == '\0')// forme un mot
				return 1;
			else
				return 0; // la chaine mot forme pas un mot

	}
}
//----------------------------------------

void read_file(PTR d)
{
	char *ch;
	ch = (char*)malloc(sizeof(char));
	FILE *f;
	f=fopen("C:\\Users\\Yassine\\eclipse-workspace\\Ruzzle1\\src\\dico.txt","rt+");
	if(f !=NULL){
		rewind(f);
		int ret;
			while( (ret = fscanf(f,"%s",ch)) != EOF && ret !=0 ){
				ajouterMot(ch, d);
			}
	}else
		printf("le fichier n'as pas s'ouvrir \n");
	fclose(f);
}
//----------------------------------------

/**
 *
 * bref: affichage du dictionnaire avec la pile
 *
 */
void afficher(PTR arbre) {
    PTR p;
    pile.t[pile.n++] = arbre->lettre;
    if (arbre->lettre == '\0')
    	printf("%s\n", pile.t + 1);
    else
    	for (p = arbre->lettreSuivant; p != NULL; p = p->elementSuivant)
    		afficher(p);
    pile.n--;
}

//
//int main(void){
//    PTR d = dico('!', NULL, NULL);
//    read_file(d);
//
////    pile.n = 0;
////    afficher(d);
//
//
//
//
//
//	printf("entrer un mot\n");
//
//	char* mot=malloc(50*sizeof(char));
//
//	scanf("%s",mot);
//
//	if(chercher_mot(mot,d)==1){
//		printf("le mot' %s 'existe\n",mot);
//	}else
//		printf("le mot' %s 'existe pas \n",mot);
//
//
//	return EXIT_SUCCESS;
//}
