#include "PileB.h"
#include "P4.h"
#include "PileDyn.h"
#include "IA.h"
#include <time.h>
//----------------------------------------------------------------------
int randIA(){
    return rand()%(7-1) +1;
}
//----------------------------------------------------------------------
int recuperCol()
{
	int iCol=0,iOK=0;
	int c;
	
	while(iOK==0)
	{
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
	Bool iQuit=0,iFermer=0;
	int c;
	srand(time(NULL));
	printf("\n Bienvenue dans le puissance 4 \n");	
	while (iFermer!=1)
	{
		iQuit=0;
		printf("choisisez un mode \n 1 -> 1 Joueur \n 2 -> 2 joueurs \n 3 -> Quitter\n");
		scanf("%d",&c);
		switch(c)
		{
 
			case 2 :while(iQuit==0)
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
							if((AlignHoriz(p,c)>=4)||(AlignVert(p,c)>=4)||(AlignDiagDroite(p,c)>=4)||(AlignDiagGauche(p,c)>=4))
							{
								printf("\n>>>>> $$$$$$ Jackpot Joueur 2 $$$$$$    <<<<< \n");
								iQuit=1;
							}
							else
							{
								p=AjouterPion(p,c,0);
							}
						}
				
					}
					p=vider_grille(p);
					break;
					
			case 1: while(iQuit==0)
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
							printf(" \n L'IA va jouer patienter. \n");
							
							
							if((AlignHoriz(p,Contrer(p))>=4)||(AlignVert(p,Contrer(p))>=4)||(AlignDiagDroite(p,Contrer(p))>=4)||(AlignDiagGauche(p,Contrer(p))>=4)||(AlignHoriz(p,Jouer(p))>=4)||(AlignVert(p,Jouer(p))>=4)||(AlignDiagDroite(p,Jouer(p))>=4)||(AlignDiagGauche(p,Jouer(p))>=4))
							{
								printf("\n>>>>>  $$$$$$ Jackpot IA $$$$$$    <<<<< \n");
								iQuit=1;
							}
							else
							{
								if(MaxContrer(p)>3)
								{
									p=AjouterPion(p,Contrer(p),0);
								}
								else
								{
									if(MaxJouer(p)>3)
									{
										p=AjouterPion(p,Jouer(p),0);
									}
									else
									{
										if(MaxContrer(p)>2)
										{
											p=AjouterPion(p,Contrer(p),0);
										}
										else
										{
											if(MaxJouer(p)>2)
											{
												p=AjouterPion(p,Jouer(p),0);
											}
											else
											{
												p=AjouterPion(p,randIA(),0);
											}
										}
									}
								}
							}
						}
						
					}
					p=vider_grille(p);

					break;
					
			case 3: iFermer=1;
					break;
					
			case 4: while(iQuit!=1)
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
								printf("\n>>>>> Joueur Ordi à vous <<<<<\n Entrer un numero de colonne pour inserer votre pion \n");
								c=score(p);
								printf("\n score : %d \n",c);
								if((AlignHoriz(p,c)>=4)||(AlignVert(p,c)>=4)||(AlignDiagDroite(p,c)>=4)||(AlignDiagGauche(p,c)>=4))
								{
									printf("\n>>>>>$$$$$$ Jackpot Joueur Ordi $$$$$$    <<<<< \n");
									iQuit=1;
								}
								else
								{
									p=AjouterPion(p,c,1);
								}
						}
					}
					
					p=vider_grille(p);
					break;
					
			default : printf(" \n MAUVAIS NOMBRE\n");
					break;
	
		}
	}
	
	free(p->Tour->v);
	free(p->Tour);
	free(p);
	return 0;
}
