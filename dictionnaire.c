

#include "dictionnaire.h"

// inserer un nouveau noeud
PTR noeud(char info, PTR fils, PTR frere) {
    PTR p = malloc(sizeof(NOEUD));
    assert(p != NULL);
    p->info = info;
    p->fils = fils;
    p->frere = frere;
    return p;
}

/**************************************/

// insertion d'un mot
int insertion(char mot[], PTR ancetre) {
    PTR pr, pc;
    int i;
    /* à chaque tour de cette boucle on recherche le caractère */
    /* mot[i] parmi les fils du nœud pointé par ancetre */
    for(i = 0; ; i++) {
        pr = NULL;
        pc = ancetre->fils;
        while (pc != NULL && pc->info < mot[i]) {
            pr = pc;
            pc = pc->frere;
        }
        if (pc != NULL && pc->info == mot[i]) {
            if (mot[i] == '\0')
                return 1; /* le mot existait */
            ancetre = pc;
        }
        else {
            pc = noeud(mot[i], NULL, pc);
            if (pr != NULL)
                pr->frere = pc;
            else
                ancetre->fils = pc;
            while (mot[i] != '\0') {
                pc->fils = noeud(mot[++i], NULL, NULL);
                pc = pc->fils;
            }
            return 0; /* le mot est nouveau */
        }
    }
}


/**************************************/


// insertion à partir d'un fichier 
void read_file(PTR ancetre) 
{
  char *ch;
  ch = (char*)malloc(sizeof(char)); 
  FILE *f;
  f=fopen("dict.txt","r+");
  rewind(f);
  int eof;

   while( (eof = fscanf(f, "%s", ch)) != EOF )
   {  
  //printf("\n %s \n",ch);

  insertion(ch, ancetre);
    }
}

/**************************************/

// parcour de l'arbre
	void parcours(PTR arbre) {
	    PTR p;
	    pile.t[pile.n++] = arbre->info;
	    if (arbre->info == '\0')
		printf("%s\n", pile.t + 1);
	    else
		for (p = arbre->fils; p != NULL; p = p->frere)
		    parcours(p);
	    pile.n--;
	}

/**************************************/

PTR verifier(PTR racine,char c){
		if (racine->info == c) // si la lettre == le caractere => on retourne la racine
				return racine;
			else{ // sinon
				if(racine->frere) // si on a un frere 
					return verifier(racine->frere,c); // recursiviter
				else
					return racine;
			}
}

/**************************************/

int chercher_mot(char mot[], PTR racine){
   if(strlen(mot)>0) // si la taille du mot est superieur à 0
   {
      PTR ancetre; 

      ancetre=verifier(racine->fils,mot[0]); // on verifie chaque lettre du mot 
      if(ancetre->info == mot[0]){ // si on arrive à trouver la lettre correspond dans l'arbre
         mot++; // on incremente le mot , pour chercher la lettre suivante du mot
         chercher_mot(mot,ancetre); // on appel cette fonction pour chercher la lettre suivante / recursiviter
      }else // atteind le dernier élement il y a rien
         return 0;

   }else{
         racine=verifier(racine->fils,'\0'); // on verifier avec la fin de chaine de caractere
         if(racine->info == '\0')// forme un mot
            return 1; // on a bien trouver le mot
         else
            return 0; // le mot n'existe pas !

   }

}


/**************************************/