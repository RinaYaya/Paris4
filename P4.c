#include "P4.h"

//----------------------------------------------------------------------
Pile ChoixPile(P4 p, int iNum)
{
	Pile pTmp;
	
	switch (iNum)
	{
		case 1: pTmp=p->p1;
				break;
				
		case 2: pTmp=p->p2;
				break;
				
		case 3: pTmp=p->p3;
				break;
				
		case 4: pTmp=p->p4;
				break;
				
		case 5: pTmp=p->p5;
				break;
				
		case 6: pTmp=p->p6;
				break;
				
		case 7: pTmp=p->p7;
				break;
	
		default: printf(" \n ChoixPile >>>>> NUMERO ICOL INCORRECTE <<<<< \n");
			     break;
	}
	return pTmp;
}
//----------------------------------------------------------------------
P4 NouveauP()
{
	P4 p=MALLOC(StrP4);
	
	p->Tour=Nouv2(50);
	p->p1=Nouv();
	p->p2=Nouv();
	p->p3=Nouv();
	p->p4=Nouv();
	p->p5=Nouv();
	p->p6=Nouv();
	p->p7=Nouv();
	
	return p;
	
}
//----------------------------------------------------------------------
P4 AjouterPion (P4 p, int iCol,Bool b)
{
	
	switch (iCol)
	{
		case 1: p->p1=Empiler(p->p1,b);
				p->Tour=Empiler2(p->Tour,iCol);
				break;

		case 2: p->p2=Empiler(p->p2,b);
				p->Tour=Empiler2(p->Tour,iCol);
				break;

		case 3: p->p3=Empiler(p->p3,b);
				p->Tour=Empiler2(p->Tour,iCol);
				break;

		case 4: p->p4=Empiler(p->p4,b);
				p->Tour=Empiler2(p->Tour,iCol);
				break;

		case 5: p->p5=Empiler(p->p5,b);
				p->Tour=Empiler2(p->Tour,iCol);
				break;

		case 6: p->p6=Empiler(p->p6,b);
				p->Tour=Empiler2(p->Tour,iCol);
				break;

		case 7: p->p7=Empiler(p->p7,b);
				p->Tour=Empiler2(p->Tour,iCol);
				break;

		default: printf(" \n ChoixPile >>>>> NUMERO ICOL INCORRECTE <<<<< \n");
			     break;
	}

	return p;
}
//----------------------------------------------------------------------
P4 RetirerPion (P4 p)
{
	Pile pTmp;
	
	if(p->Tour->h!=0)
	{
		pTmp=ChoixPile(p,Sommet2(p->Tour));
		pTmp=Depiler(pTmp);
		p->Tour=Depiler2(p->Tour);
	}
	return p;
}
//----------------------------------------------------------------------
Bool Aquiletour(P4 p)
{
	return ((Hauteur2(p->Tour)%2)==0);
}
//----------------------------------------------------------------------
int Colonne(P4 p)
{
	return Sommet2(p->Tour);
}
//----------------------------------------------------------------------
int NbEtape (P4 p)
{
	return Hauteur2(p->Tour);
}
//----------------------------------------------------------------------
int AlignHoriz(P4 p, int iCol)
{
	int iCptC=iCol+1, iNbPion=1,iCptL=0;
	Bool b=1;
	Pile pTmp=ChoixPile(p,iCol);
	iCptL=(Hauteur(pTmp))+1;
	
	if(iCptC<=7)
	{
		do
		{
			pTmp=ChoixPile(p,iCptC);
			if((Hauteur(pTmp)>=iCptL)&&(pTmp.v[iCptL-1]==Aquiletour(p)))
			{
				iNbPion++;
			}
			if(/*(Hauteur(pTmp)<iCptL)||*/(pTmp.v[iCptL-1]!=Aquiletour(p)))
			{
				b=0;
			}
			iCptC++;
		}
		while((iCptC<=8)&&(b==1));
	}
	
	b=1;
	iCptC=iCol-1;
	
	if(iCptC>0)
	{
		do
		{
			
			pTmp=ChoixPile(p,iCptC);
			if((Hauteur(pTmp)>=iCptL)&&(pTmp.v[iCptL-1]==Aquiletour(p)))
			{
				iNbPion++;
			}
			if(/*(Hauteur(pTmp)<=iCptL)||*/(pTmp.v[iCptL-1]!=Aquiletour(p)))
			{
				b=0;
			}
			iCptC--;
		}
		while((iCptC>0)&&(b==1));
	}
	
	return iNbPion;
}
//----------------------------------------------------------------------
int AlignVert(P4 p, int iCol)
{
	Pile pTmp=ChoixPile(p,iCol);
	int iNbPion=1,iCpt=pTmp.tete-1;

	Bool b=1;
	
	while((iCpt>=0)&&(b==1))
	{
		
		if(pTmp.v[iCpt]==Aquiletour(p))
		{
			iNbPion++;
		}
		if(pTmp.v[iCpt]==(!Aquiletour(p)))
		{
			b=0;
		}
		
		iCpt--;
		
	}
	
	return iNbPion;
}
//----------------------------------------------------------------------
int AlignDiagGauche(P4 p, int iCol)
{
	int iLig=0, iNbPion=1,iTmp=iCol;
	Pile pTmp= ChoixPile(p,iCol);
	Bool b=1;
	iLig=Hauteur(pTmp)+2;
	iCol++;
	
	while((b==1)&&(iCol<8))
	{
		pTmp= ChoixPile(p,iCol);
		if((iLig<=Hauteur(pTmp))&&(ieme(pTmp,iLig)==Aquiletour(p)))
		{
			iNbPion++;
		}
		else
		{
			b=0;
		}
		iLig++;
		iCol++;
	}
	b=1;
	iCol=iTmp-1;
	pTmp=ChoixPile(p,iTmp);
	iLig=Hauteur(pTmp);
	

	while((b==1)&&(iCol>0))
	{
		pTmp= ChoixPile(p,iCol);
		if((iLig<=Hauteur(pTmp))&&(ieme(pTmp,iLig)==Aquiletour(p)))
		{

			iNbPion++;
		}
		else
		{
			b=0;
		}
		iLig--;
		iCol--;
	}
	return iNbPion;
}
//----------------------------------------------------------------------
int AlignDiagDroite(P4 p, int iCol)
{
	int iLig=0, iNbPion=1,iTmp=iCol;
	Pile pTmp= ChoixPile(p,iCol);
	Bool b=1;
	iLig=Hauteur(pTmp);
	iCol++;
	
	while((b==1)&&(iCol<8))
	{
		pTmp= ChoixPile(p,iCol);
		if((ieme(pTmp,iLig)==Aquiletour(p))&&(iLig<=Hauteur(pTmp)))
		{
			iNbPion++;
		}
		else
		{
			b=0;
		}
		iLig--;
		iCol++;
	}
	b=1;
	iCol=iTmp-1;
	pTmp=ChoixPile(p,iTmp);
	iLig=Hauteur(pTmp)+2;
	
	while((b==1)&&(iCol>0))
	{
		pTmp= ChoixPile(p,iCol);

		if((ieme(pTmp,iLig)==Aquiletour(p))&&(iLig<=Hauteur(pTmp)))
		{

			iNbPion++;
		}
		else
		{
			b=0;
		}
		iLig++;
		iCol--;
	}
	return iNbPion;
}
//----------------------------------------------------------------------
void AffichageGrille(P4 p)
{
	int iCpth=1,iCptv=1;
	Pile pTmp;
	for(iCpth=5;iCpth>=0;iCpth--)
	{
		printf("|");
		for(iCptv=1;iCptv<=7;iCptv++)
		{
			pTmp=ChoixPile(p,iCptv);
			
			if((iCpth<(pTmp.tete))&&(ieme(pTmp,iCpth) == 1))
			{
				
				printf("X |");

			}
			else
			{
				if((iCpth<(pTmp.tete))&&(ieme(pTmp,iCpth) == 0))
				{
					printf("0 |");
				}
				else
				{
					printf("  |");
				}
			}
		}
		printf("\n");
	}
}








