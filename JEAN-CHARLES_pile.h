/** Donne les primitives de la pile**/

//JEAN-CHARLES Loïc
//09/11/2016
//Le programme compile 

#define MAX 100 /*hauteur de pile*/

typedef struct {
	int tab [MAX];
	int ind;
} PILE;

PILE creer(PILE p){
/*creation d’une pile vide*/
	p.ind = 0;
	p.tab[0] = 0;
	return p;
}

bool vide(PILE p){
/* renvoie vrai si la pile est vide*/
	return (p.ind == -1);
}

void ajouter(int e, PILE p){ /*empile e sur la pile */
if(p.ind < MAX-1){
	int i=p.ind++;
	p.tab[i]=e;
	p.ind=i;
 }
}

void supprimer(PILE p){ /*depile le sommet de la pile */
	if(!vide(p)) p.ind = p.ind-1;
}

int som(PILE p){ /*retourne le sommet de p*/
    if(!vide(p)) return p.tab[p.ind];
}