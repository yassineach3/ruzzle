/*
 * Dico.h
 *
 *  Created on: 17 Dec 2017
 *      Author: Yassine
 */

#ifndef DICO_H_
#define DICO_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#ifdef NDEBUG
#undef NDEBUG
#endif

	typedef struct _Dico {
    char lettre;
    struct _Dico *lettreSuivant;
    struct _Dico *elementSuivant;
	} Dico, *PTR;

	/*
	 *  pile d'affichage
	 */
	static struct {
		    char t[80];
		    int n;
		} pile;



extern PTR dico(char lettre, PTR lettreSuivant, PTR elementSuivant);
extern PTR initDictionnaire();
extern PTR dico(char lettre, PTR lettreSuivant, PTR elementSuivant);
extern int ajouterMot(char mot[], PTR d);
extern PTR verifierElement(PTR d,char c);
extern int chercher_mot(char mot[], PTR d);
extern void read_file(PTR d);
extern void afficher(PTR arbre);

#endif /* DICO_H_ */
