

#ifndef DICTIONNAIRE_H_
#define DICTIONNAIRE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#ifdef NDEBUG
#undef NDEBUG
#endif

/**************************************/
typedef struct noeud {
    char info;
    struct noeud *fils, *frere;
} NOEUD, *PTR;

/**************************************/

	static struct {
	    char t[80];
	    int n;
	} pile;

/**************************************/

extern PTR noeud(char info, PTR fils, PTR frere);
extern void read_file(PTR ancetre);
extern int insertion(char mot[], PTR ancetre);
extern void parcours(PTR arbre);
extern PTR verifier(PTR racine,char c);
extern int chercher_mot(char mot[], PTR racine);

#endif /* DICTIONNAIRE_H_ */