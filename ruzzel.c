#include "ruzzel.h"


/**************************************/

// Look for points
int look_for_letter(char tableau[], char c)
{
	int i=0,l;
	l = strlen(tableau);
	while(i<l)
	{
		if (c == tableau[i])
		{
			return 1;
		}
		i++;
	}
	return 0;
}

/**************************************/

int count_points(char c)
{
						int my_points=0;
	   					if(look_for_letter(Ten_Points,c) == 1)
	   					{
	   						my_points +=10;
	   						return my_points;
	   					}
	   					else
	   					{

		   					if(look_for_letter(Eigth_Points,c) == 1)
		   					{
		   						my_points += 8;
		   						return my_points;
		   					}
		   					else
		   					{

			   					if (look_for_letter(Four_Points,c) == 1)
			   					{
			   						my_points += 4;
			   						return my_points;
			   					}
			   					else
			   					{

				   					if (look_for_letter(Tree_Points,c) == 1)
				   					{
				   						my_points += 3;
				   						return my_points;
				   					}
				   					else
				   					{

					   					if (look_for_letter(Tow_Points,c) == 1)
					   					{
					   						my_points += 2;
					   						return my_points;
					   					}
						   				else
						   					{
						   						my_points += 1;
						   						return my_points;
						   					}
				   					}
			   					}

		   					}

	   					}
}

/**************************************/

int randem(int i ,int r){
	int al;
			        do{
		        	al = rand();
		        }while((al > r+1 && al == i) || (al < 0 && al == i));
		        return al;
}

/**************************************/

void grille()
{
        int r, i, j,aleatoir,al,l;
        int my_points=0;
    	char mot[80];

		char *c;
		c=(char*)malloc(sizeof(char));

	    PTR d = noeud('!', NULL, NULL);
	    // Insertion de dictionnaire à partir d'un fichier
	    read_file(d);
	    printf("Insertion de Dictionnaire effectuée\n");


	    	// le choix de la taille de grille
	        printf("Choisissez la taille de la Grille = ");
		    scanf("%d", &r);

		    char a[r][r];
		    char tab_rand[r]; // pour stocker des lettres Bonus

		    //on initialise le tableau par '*'
		    for (i = 0; i < r;i++)
		    {
		    	tab_rand[i]='*';
		    }

		    // on affecte les lesttre à notre grille ( matrice ) aleatoirement
		    for (i = 0; i < r; i++)
		    {
		        for (j = 0; j < r; j++)
		        {
		            aleatoir = rand();
		            while(aleatoir > 27 || aleatoir < 0)
		            	{aleatoir = rand();}

			            a[i][j] = toupper(Alphabets[aleatoir]);

		            if (i==j)
		            	{
				            tab_rand[i] = a[i][j];
				        }

		        }
		    }

// affichage de la Grille
    printf("\n Grille aléatoire :\n");
    for (i = 0; i < r; i++)
    {
        printf("\n\n");
        for (j = 0; j < r; j++)
        {
        	if(i==j)
            printf(" |%c*| ", a[i][j]);
            else printf(" |%c°| ", a[i][j]);
        }
    }
    printf("\n");
	printf("\nTrouvez des mots dans la grille !\n");
	do{


	scanf("%s",mot);
	int k;
	l = strlen(mot);
	//printf("la taille de mot = %s est L = %d\n",mot,l);
	for(k = 0; k < l; k++)
		{
				mot[k] = tolower(mot[k]);// pour chercher dans le dictionnaire , puissque on a les mots en Miniscul 
		}

		// 1 er etape :
		// chercher les lesttres de mot donner par la conssole dans la grill

		int z=0,x;
		l=r*r;
		char mot_grille[l],*str,c;


			// convertir les lettres de la grille en Miniscule 
			for (i = 0; i < r; i++)
		    { 
		        for (j = 0; j<r; j++)
		        {
		           mot_grille[z] = tolower(a[i][j]);
		           z++;
		        }
		    }


		    // chercher lettre par lettre dans la grille
		    // aussi on va calculer la somme des points pour chaque lettre
		    z=0;
		    c = mot[z];
		    int p=0;
		    l = strlen(mot);
		    	while((str = strrchr(mot_grille,c) )!= NULL && z<l)
				    {
				    	z++;
						c = mot[z];
				    	str = strrchr(mot_grille,c);
				    }

				if (z<l)
				{
					printf("Veuillez chercher un autre mot dans la grille\n");
				}
				else // on va chercher le mot dans le dictionnaire
				{
					i=chercher_mot(mot,d);

					if (i == 1)
	   				{
	   					printf("Bravo :) le mot \"%s\" existe \n",mot);

				   		z=0;
					    c = mot[z];
					    int p=0;
					    l = strlen(mot);
					    x=l-4;
					    	while(z<l)
							    {
							    	z++;
									c = mot[z];
	   					my_points += count_points(c);
							    }

					    if(x>=0)
					    	{ 
					    		x*=5;
								my_points +=x;
							}
	   					printf("totale points : %d\n",my_points );

	   				}
	   				else
	   					printf("le mot %s n'existe pas \n",mot);
				}

}while(mot != '\0');

}
