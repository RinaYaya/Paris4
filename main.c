#include "PileB.h"
#include "P4.h"
#include "PileDyn.h"

int main()
{
int i;
P4 p;
p=NouveauP();

AffichageGrille(p);
printf(" \n pion gros un pion dans la col \n");
scanf("%d",&i);
printf(" \n choix  %d \n",i);
p=AjouterPion(p,i,1);
p=AjouterPion(p,i,0);
AffichageGrille(p);
	return 0;
}
