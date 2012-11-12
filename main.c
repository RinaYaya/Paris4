#include "PileB.h"
#include "P4.h"
#include "PileDyn.h"

int main()
{
P4 p;
Pile d=Nouv();
p=NouveauP();
d=Empiler(d,1);
d=Empiler(d,1);
d=Empiler(d,0);
d=Empiler(d,1);
d=Empiler(d,1);
printf("\n ieme %d \n",ieme(d,3));
p=AjouterPion(p,1,1);
p=AjouterPion(p,2,1);
p=AjouterPion(p,3,1);
p=AjouterPion(p,5,1);
p=AjouterPion(p,6,1);
p=AjouterPion(p,6,1);
p=AjouterPion(p,7,1);
printf("\n Align Vert %d \n",AlignVert(p,4));
printf("\n Align Vert %d \n",AlignVert(p,5));
printf("\n Align Vert %d \n",AlignVert(p,6));
	return 0;
}
