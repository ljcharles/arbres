/** Ce programme effectue la saisie d'un arbre quelconque dans 2 tableaux PS et LS.
	PS indique le rang où commence les fils d'un sommet dans LS et LS contient les fils des sommets.
	Lors de la saisie de l'arbre, l'utilisateur entre la racine et
	c'est le programme qui indiquera les sommets dont il faut saisir les fils 
	Le programme cherche un sommet à partir d'un valeur donnée**/

/** On dispose d'un arbre binaire représenté par un tableau unidimensionnel, tel que le fils gauche d'un sommet se trouvant à l'indice i est en 2i
    et son fils droit en 2i+1**/

//JEAN-CHARLES Loïc
//12/10/2016
//le programme compile et fonctionne
//19/10/2016
//la méthode supprimer compile mais ne fonctionne pas
//la méthode ajouter compile mais ne fonctionne pas
//la méthode rechercher compile et fonctionne
//09/11/2016
//Le programme compile mais je dois redéfinir la pib avec un tableau

// On inclut cette bibliothèque pour gérer la partie sortie et entrée du langage c
#include <stdio.h>
#include <stdlib.h>
#include "JEAN-CHARLES_pile.h"

//n représente le nombre de sommets que pourrait contenir l'arbre
const int n=100;
//On définit un tableau qui contiendra jusqu'à 15 éléments
typedef int tab[n];


void implementerArbre(tab PS, tab LS, int *nb_som){

	// déclaration des variables
	int nom_sommet,nom_fils,indice_courant_ls,indice_fils_ls,nb_sommet_fils,nb_sommet_traites;

	// initialisation des variables
	indice_courant_ls = 1;
	indice_fils_ls = 1;
	nb_sommet_fils = 0;
	nb_sommet_traites = 0;

	printf("Entrer le nom de la racine ou 0:"); //printf affiche la phrase à l'écran
	scanf("%d",&nom_sommet); // récupérer l'entré de l'utilisateur sur le clavier

	// Tant que l'utilisateur n'entre pas 0
	while (nom_sommet != 0){
		//On incrémente le nbre de sommets traités
        nb_sommet_traites++;
		//indice courant ls prends la valeur du rang ou commance les fils de nom_sommet
		PS[nom_sommet] = indice_courant_ls;

		//faire
		do
        {
			printf("Entrer un fils du sommet %d ou 0: ",nom_sommet);
			scanf("%d",&nom_fils); // récupérer l'entré de l'utilisateur sur le clavier

			if(nom_fils != 0)
            {
                nb_sommet_fils++;
            }

			LS[indice_courant_ls]=nom_fils;
            indice_courant_ls++;
		}while(nom_fils != 0);

		if(nb_sommet_traites <= nb_sommet_fils)
        {
            while (LS[indice_fils_ls] == 0){
                indice_fils_ls++;
            }
			nom_sommet=LS[indice_fils_ls];
            indice_fils_ls++;
        }
        else
        {
            nom_sommet = 0;
        }
    }

     *nb_som = nb_sommet_fils;
}/*implementerArbre*/

void afficheArbre(tab PS, tab LS, int nb_som)
{
    int i, nb;

    nb = nb_som;
    i = 0;
    while(nb >= 0)
    {
        i++;
        if(LS[i]==0)
        {
            nb--;
        }
    }

    nb = i;

    printf("\n\nIndice : ");
    for(i = 1; i <= nb; i++)
    {
        printf("  %02d ", i);
    }

    printf("\n\nPS     : ");
    for(i = 1; i <= nb; i++)
    {
        if(i <= nb_som)
        {
            printf(" [%02d]", PS[i]);
        }
        else
        {
            printf(" [00]", PS[i]);
        }
    }

    printf("\n\nLS     : ");
    for(i = 1; i <= nb; i++)
    {
        printf(" [%02d]", LS[i]);
    }
}

void affichage_fils_frere(tab PS, tab LS, int nb_som)
{
    int i, nb_case, som, indice_actuel,indice_fils_actuel, indice_fils, som_frere;
 
    nb_case = nb_som;
    i = 0;
 
    while(nb_case > 0)
    {
        i++;
        if(LS[i] == 0)
        {
            nb_case--;
        }
    }
 
    nb_case = i;
 
    do
    {
        printf("\n\n\nEntrez un sommet pour afficher les fils du frere ou entrez 0 : ");
        scanf("%d",&som);
 
        if(nb_som < som)
        {
            printf("\n\nAucun sommet ne porte ce nom");
        }
        else if(som != 0)
        {
            indice_actuel = 1;
            i = 1;
 
            while(LS[indice_actuel] != som && nb_case >= indice_actuel)
            {
                indice_actuel++;
            }
 
            if(nb_case < indice_actuel)
            {
                printf("\n\nLa racine n'a pas de frere");
            }
            else
            {
                som_frere = LS[indice_actuel + 1];
 
                printf("\n\n Frere du sommet %02d : %02d", som, som_frere);
 
                if(som_frere != 0)
                {
                    printf("\n Fils du sommet %02d :", som_frere);
 
                    indice_fils = PS[som_frere];
                    indice_fils_actuel = indice_fils;
 
                    printf("\n\nIndice : ");
 
                    while(LS[indice_fils_actuel] != 0)
                    {
                        printf("  %02d ", i);
                        i++;
                        indice_fils_actuel++;
                    }
 
                    indice_fils_actuel = indice_fils;
 
                    printf("\n\nLS :     ");
                    while(LS[indice_fils_actuel] != 0)
                    {
                        printf(" [%02d]", LS[indice_fils_actuel]);
                        indice_fils_actuel++;
                    }
                }
                else
                {
                    printf("\nCe Sommet n'a pas de frere");
                }
            }
        }
    }while(som != 0);
}// affichage des fils d'un frere d'un sommet

void chercherSommet(int x, int r, tab Info){
	//int nb_sommet = sizeof(FG) + sizeof(FD) + 1;

	printf("\nEntrez la valeur du sommet que vous rechercher : ");
    scanf("%d",&x);
		
	if( x == r) printf("Le sommet a ete trouve et est : %d ", r);

	for(int i=0; i < sizeof(Info); i++){
		if( x == Info[i] ) printf("Le sommet a ete trouve et est : %d ", i+1);
		else printf("\nAucun sommet trouve pour cette valeur");
	}
}//chercher un sommet dans un arbre (la valeur est donnée)

void ajouterSommet(int x, int r,tab FG, tab FD, tab Info){
	//bool trouve = (bool)chercherSommet(x,r,Info);
	bool trouve = true;
	if(!trouve){
		for(int i=0; i < sizeof(FG); i++){
			if( x == Info[i] && (FG[i] == 0 || FD[i] == 0)) {
				Info[sizeof(FG)+1] = x;
			}
		}
	}
}//ajoute un sommet dans un arbre (la valeur est donnée)

void supprimerSommet(int x,int r,tab FG, tab FD, tab Info){
	bool trouve = true;
	if(!trouve){
		for(int i=0; i < sizeof(FG); i++){
			if( x == Info[i]) {
				Info[sizeof(FG)+1] = 0;
			}
		}

		for(int i=0; i < sizeof(FD); i++){
			if( x == Info[i]) {
				Info[sizeof(FD)+1] = 0;
			}
		}
	}

}//supprime un sommet dans un arbre (la valeur est donnée)

void parcoursPreordre(int racine,tab FG, tab FD, tab arbreBin){
	PILE p;
	int som = 1;
	int x;

	arbreBin[som] = racine;

	for(; som < sizeof(FG); som++) arbreBin[2 * som] = FG[som];
		
	for(; som < sizeof(FD); som++) arbreBin[2 * som + 1] = FD[som];

	creer(p);
	ajouter(p,1);

	printf("\nVALEUR :  ");

	while(!vide(p))
	{
		x = val(p);
		supprimer(p);
        
		printf(" [ %d ] ", arbreBin[x]);
		ajouter(p, 2 * x + 1);
		ajouter(p, 2 * x);

	}

}//Affiche les sommets de l'arbre binaire en effectuant un parcours en préordre

int main(){
	//tab PS, LS;
	//int nb_sommet,sommet;
	//implementerArbre(PS,LS,&nb_sommet);
	//afficheArbre(PS,LS,nb_sommet);
	//affichage_fils_frere(PS, LS, nb_sommet);

	tab FG = { 0,2,0,3,5,0,0,0};
	tab FD = { 0,1,0,6,7,0,0,0};
	tab arbreBin;
	//tab Info = {1,2,3,4,5,6}; 
	//int x=0;
	int r=4;//la racine

	//chercherSommet(x,r,Info);

	//ajouterSommet(x,r,FG,FD,Info);

	//supprimerSommet(x,r,FG,FD,Info);

	parcoursPreordre(r,FG,FD,arbreBin);

	getchar();
    flushall(); 
	getchar();

}