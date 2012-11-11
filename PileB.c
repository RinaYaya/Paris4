#include "PileB.h"
//-----------------------------Nouv()-----------------------------------
Pile Nouv()
{
	Pile P;
	P.tete=0;
	return P;
}
//-------------------------------Empiler--------------------------------
Pile Empiler(Pile pPile, Bool b)
{
	if((pPile.tete) <N)
	{
		pPile.v[pPile.tete]=b;
		pPile.tete++;
	}
	else
	{
		printf("pile pleine \n");
	}
	return pPile;
}
//-------------------------------Depiler--------------------------------
Pile Depiler(Pile pPile)
{
	if(pPile.tete != 0)
	{
		pPile.tete--;
	}
	else
	{
		printf("Pile Vide \n");
	}
	return pPile;
}
//-------------------------------Remplacer------------------------------
Pile Remplacer(Pile pPile, Bool b)
{
	pPile.v[pPile.tete-1]=b;
	return pPile;
}
//-------------------------------Sommet---------------------------------
Bool Sommet(Pile pPile)
{
	if(pPile.tete !=0)
	{
		return pPile.v[pPile.tete-1];
	}
	else
	{
		printf("ici pd");
		return;
	}
}
//--------------------------------Hauteur-------------------------------
Nat Hauteur (Pile pPile)
{
	return pPile.tete;
}
//---------------------------------vide---------------------------------
Bool vide (Pile pPile)
{
	return pPile.tete==0;
}
//----------------------------------------------------------------------
Bool ieme(Pile p,int i)
{
	
	if((i<7)&&(i>0))
	{
		i=p.tete-i;
		while(i!=0)
		{
			p=Depiler(p);
			i--;
		}
	}
	else
	{
		printf(" \n IEME >>>>> Indice faux boulz <<<<< \n");
	}
	
	return Sommet(p);
}
