/** Donne les primitives de la pile**/

//JEAN-CHARLES Lo�c
//09/11/2016
//Le programme compile 

//x repr�sente le nombre de sommets que pourrait contenir la pile
const int x=100;
//On d�finit un tableau qui contiendra jusqu'� 100 �l�ments
typedef int PILE[x];

void creer(PILE p){
/*creation d�une pile vide*/
	p[0] = 0;
}

bool vide(PILE p){
/* renvoie vrai si la pile est vide*/
	return (p[0] == 0);
}

void ajouter(PILE p, int e){ /*empile e sur la pile */
	p[0]++;
	p[ p[0] ] = e;
}

void supprimer(PILE p){ /*depile le sommet de la pile */
	p[0]--;
}

int valeur(PILE p){ /*retourne le sommet de p*/
    return p[p[0]];
}