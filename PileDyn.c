#include "base.h"
#include "PileDyn.h"
//----------------------------Nouv2-------------------------------------
PileD Nouv2(int a)
{
	PileD P=MALLOC(StrPileD);
	P->v=MALLOCN(a,int);
	P->Taille=a;
	P->h=0;
	return P;
}
//----------------------------Empiler2----------------------------------
PileD Empiler2(PileD p, int b)
{
	if((p->h+1) <= (p->Taille))
	{
		p->v[p->h]=b;
		p->h++;
	}
	else 
	{
		printf("pile pleine \n");
	}
	return p;
}
//----------------------------Depiler2----------------------------------
PileD Depiler2(PileD p)
{
	p->h--;
	return p;
}
//----------------------------Remplacer2--------------------------------
PileD Remplacer2( PileD p, int b)
{
	p->v[p->h-1]=b;
	return p;
}
//----------------------------Sommet2-----------------------------------
int Sommet2(PileD p)
{
	int itmp=-1;
	if(p->h ==0 )
	{
		printf(" Archtung: Pile vide !!!\n");
	}
	else
	{
		itmp=p->v[p->h-1];
	}
	return itmp;;
}
//----------------------------Hauteur2----------------------------------
Nat Hauteur2(PileD p)
{
	return p->h;
}
//----------------------------vide2-------------------------------------
Bool vide2 (PileD p)
{
	return p->h==0;
}
//----------------------------------------------------------------------
