#include "PileB.h"
#include "P4.h"
#include "PileDyn.h"
//----------------------------------------------------------------------
int recuperCol()
{
	int iCol=0,iOK=0;
	int c;
	
	while(iOK==0)
	{
		//~ printf("\n >>>>>>>>>>>>>>>>>>>>>>>%d \n ",iCol);
		scanf("%d",&c);
		switch(c)
		{
			case 1: 	iCol=1;
						iOK=1;
						break;
						
			case 2: 	iCol=2;
						iOK=1;
						break;
						
			case 3: 	iCol=3;
						iOK=1;
						break;
						
			case 4: 	iCol=4;
						iOK=1;
						break;
						
			case 5: 	iCol=5;
						iOK=1;
						break;
						
			case 6: 	iCol=6;
						iOK=1;
						break;
						
			case 7: 	iCol=7;
						iOK=1;
						break;
						
			default :	printf("\nVeuillez entrer un nombre entre 1 et 7\n");
		}
	}
	return iCol;
}
//----------------------------------------------------------------------
int main()
{
	P4 p=NouveauP();
	Bool iQuit=0;
	int c;
	

	//~ printf("\nPuissance 4\n");
//~ p=AjouterPion(p,1,1);
//~ p=AjouterPion(p,1,1);
//~ p=AjouterPion(p,2,1);
//~ p=AjouterPion(p,3,1);

//~ p=AjouterPion(p,5,1);
//~ p=AjouterPion(p,6,1);
//~ AffichageGrille(p);
//~ printf("\n TETE %d \n",p->p1.tete);
//~ printf("\n ALI %d \n", AlignHoriz(p,4));
	while(iQuit==0)
	{
		AffichageGrille(p);
		
		if(Aquiletour(p))
		{
			printf("\n>>>>> Joueur 1 à vous <<<<<\n Entrer un numero de colonne pour inserer votre pion \n");
			c=recuperCol();
			if((AlignHoriz(p,c)>=4)||(AlignVert(p,c)>=4)||(AlignDiagDroite(p,c)>=4)||(AlignDiagGauche(p,c)>=4))
			{
				printf("\n>>>>>$$$$$$ Jackpot Joueur 1 $$$$$$    <<<<< \n");
				iQuit=1;
			}
			else
			{
				p=AjouterPion(p,c,1);
			}
		}
		else
		{
			printf("\n>>>>> Joueur 2 à vous <<<<<\n Entrer un numero de colonne pour inserer votre pion \n");
			c=recuperCol();
			if((AlignHoriz(p,c)>=4)||(AlignVert(p,c)>3)||(AlignDiagDroite(p,c)>=4)||(AlignDiagGauche(p,c)>=4))
			{
				printf("\n>>>>> $$$$$$ Jackpot Joueur 2 $$$$$$    <<<<< \n");
				iQuit=1;
			}
			else
			{
				p=AjouterPion(p,c,0);
			}
		}
		
		switch(c)
		{
			case 'q' : iQuit=1;
						break;
		}
	}

	return 0;
}
