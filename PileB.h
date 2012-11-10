#ifndef PILEB_H_INCLUDED
#define PILEB_H_INCLUDED
#include "base.h"
#define N 6
//-----------------------------Structure--------------------------------
typedef struct { Bool v[N]; int tete;} Pile;
//-----------------------------Prototype--------------------------------

//Creation d'une nouvelle pile
Pile Nouv();

//ajouter un entier à la pile
Pile Empiler(Pile pPile, Bool b);

//enlever l'element en tete
Pile Depiler(Pile pPile);

//remplace la tete
Pile Remplacer(Pile pPile, Bool b);

//renvoie le sommet
Bool Sommet(Pile pPile);

//nombre d'element dans la pile
Nat Hauteur (Pile pPile);

//test de vacuité
Bool vide (Pile pPile);

//renvoie la valeur du ieme element
Bool ieme(Pile p,int i);

#endif // PILEB_H_INCLUDED
