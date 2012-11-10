#ifndef PILEDYN_H_INCLUDED
#define PILEDYN_H_INCLUDED
#include "base.h"
//-----------------------------Structure--------------------------------
typedef struct { int *v; int h; int Taille;} StrPileD,*PileD;
//-----------------------------Prototype--------------------------------

//Creation d'une nouvelle pile
PileD Nouv2(int a);

//ajouter un entier à la pile
PileD Empiler2(PileD p, int b);

//enlever l'element en tete
PileD Depiler2(PileD p);

//remplace la tete
PileD Remplacer2(PileD p, int b);

//renvoie le sommet
int Sommet2(PileD p);

//nombre d'element dans la pile
Nat Hauteur2 (PileD p);

//test de vacuité
Bool vide2(PileD p);

#endif // PILEDYN_H_INCLUDED
