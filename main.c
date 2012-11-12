#include "PileB.h"
#include "P4.h"
#include "PileDyn.h"

int main()
{
P4 p=NouveauP();

p=AjouterPion(p,1,1);
p=AjouterPion(p,2,1);
p=AjouterPion(p,3,1);
p=AjouterPion(p,3,1);
p=AjouterPion(p,3,1);
p=AjouterPion(p,3,1);
p=AjouterPion(p,3,1);
p=AjouterPion(p,3,1);
p=AjouterPion(p,5,1);
p=AjouterPion(p,5,1);
p=AjouterPion(p,4,1);
p=AjouterPion(p,4,1);
p=AjouterPion(p,4,1);
p=AjouterPion(p,4,1);
p=AjouterPion(p,6,1);
p=AjouterPion(p,6,1);
p=AjouterPion(p,6,1);
p=AjouterPion(p,6,1);
p=AjouterPion(p,7,1);
printf("\n Align droit %d \n",AlignDiagGauche(p,5));


	return 0;
}
