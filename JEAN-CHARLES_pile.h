/** Donne les primitives de la pile**/

//JEAN-CHARLES Lo�c
//09/11/2016
//Le programme compile 

//n repr�sente le nombre de sommets que pourrait contenir l'arbre
const int x=100;
//On d�finit un tableau qui contiendra jusqu'� 100 �l�ments
typedef int PILE[x];

void creer(PILE p){
/*creation d�une pile vide*/
	p[0] = 0;
}

bool vide(PILE p){
/* renvoie vrai si la pile est vide*/
	return (p == 0);
}

void ajouter(int e, PILE p){ /*empile e sur la pile */
	int suivant = 0;
	p[0]++;
	suivant = p[0];
	p[ suivant ] = e;
}

void supprimer(PILE p){ /*depile le sommet de la pile */
	if(!vide(p)) p[0]--;
}

int som(PILE p){ /*retourne le sommet de p*/
    if(!vide(p)) return p[p[0]];
}