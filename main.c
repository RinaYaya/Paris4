#include "PileB.h"
#include "P4.h"
#include "PileDyn.h"

int main()
{
int i;
P4 p;
p=NouveauP();
printf("\n %d \n",p->p1.tete);
p=AjouterPion(p,1,1);
printf("\n %d \n",p->p1.tete);

	return 0;
}
