#ifndef P4_H_INCLUDED
#define P4_H_INCLUDED
#include "base.h"
#include "PileB.h"
#include "PileDyn.h"
//-----------------------------Structure--------------------------------
typedef struct {Pile p1; Pile p2; Pile p3; Pile p4; Pile p5; Pile p6; Pile p7; PileD Tour;}StrP4, *P4;
//-----------------------------Prototype--------------------------------

P4 NouveauP();
P4 AjouterPion (P4 p, int iCol,Bool b);
P4 RetirerPion (P4 p);
Bool Aquiletour(P4 p);
int Colonne(P4 p);
int NbEtape (P4 p);
int AlignHoriz(P4 p, int iCol);
int AlignVert(P4 p, int iCol);
int AlignDiagGauche(P4 p, int iCol);
int AlignDiagDroite(P4 p, int iCol);
Pile ChoixPile(P4 p, int iNum);
void AffichageGrille(P4 p);
P4 vider_grille(P4 p);

#endif // P4_H_INCLUDED
