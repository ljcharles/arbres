/** Donne les primitives de la pile**/

//JEAN-CHARLES Loïc
//09/11/2016
//Le programme compile 

<<<<<<< HEAD
//x représente le nombre de sommets que pourrait contenir la pile
=======
//n représente le nombre de sommets que pourrait contenir l'arbre
>>>>>>> origin/master
const int x=100;
//On définit un tableau qui contiendra jusqu'à 100 éléments
typedef int PILE[x];

void creer(PILE p){
/*creation d’une pile vide*/
	p[0] = 0;
}

bool vide(PILE p){
/* renvoie vrai si la pile est vide*/
<<<<<<< HEAD
	return (p[0] == 0);
=======
	return (p == 0);
>>>>>>> origin/master
}

void ajouter(PILE p, int e){ /*empile e sur la pile */
	p[0]++;
	p[ p[0] ] = e;
}

void supprimer(PILE p){ /*depile le sommet de la pile */
	p[0]--;
}

<<<<<<< HEAD
int valeur(PILE p){ /*retourne le sommet de p*/
=======
int val(PILE p){ /*retourne le sommet de p*/
>>>>>>> origin/master
    return p[p[0]];
}