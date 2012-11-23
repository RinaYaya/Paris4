#include "IA.h"
//----------------------------------------------------------------------
int Max1(int* p)
{
	int iCpt=0,i=0,v=1;
	
	for(iCpt=0;iCpt<7;iCpt++)
	{
		if(p[iCpt]>i)
		{
			i=p[iCpt];
		}
	}
	return i;
}
//----------------------------------------------------------------------

int Max2(int* p)
{
	int iCpt=0,i=0,v=1;
	
	for(iCpt=0;iCpt<7;iCpt++)
	{
		if(p[iCpt]>i)
		{
			i=p[iCpt];
			v=iCpt+1;
		}
	}
	return v;
}
//----------------------------------------------------------------------

int Contrer(P4 p)
{
	int iReturn=0,iCpt=0;
	int d[7];
	p->Tour->h++;

		for(iCpt=0; iCpt<7;iCpt++)
		{
			d[iCpt]= AlignDiagDroite(p,iCpt+1)+AlignDiagGauche(p,iCpt+1)+AlignHoriz(p,iCpt+1)+AlignVert(p,iCpt+1);
		}
		

	
	iReturn= Max2(d);
	
	p->Tour->h--;
	printf("\n retC %d \n",iReturn);
	return iReturn;
}
//----------------------------------------------------------------------
int Jouer(P4 p)
{
	int d[7];
	int iCpt=0, iReturn=0;
	
	for(iCpt=0; iCpt<7; iCpt++)
	{
		d[iCpt]= AlignDiagDroite(p,iCpt+1)+AlignDiagGauche(p,iCpt+1)+AlignHoriz(p,iCpt+1)+AlignVert(p,iCpt+1);
	}
	

		iReturn = Max2(d);

	printf("\n retJ %d \n",iReturn);
	return iReturn;
}
//----------------------------------------------------------------------
int MaxContrer(P4 p)
{
	int iReturn=0,iCpt=0,i;
	int d[6];
	p->Tour->h++;

		for(iCpt=0;iCpt<7;iCpt++)
		{
			i= (AlignDiagDroite(p,iCpt+1)+AlignDiagGauche(p,iCpt+1)+AlignHoriz(p,iCpt+1)+AlignVert(p,iCpt+1))-4;
		}
		
			iReturn = Max1(d);

	p->Tour->h--;
	return iReturn;
}
//----------------------------------------------------------------------
int MaxJouer(P4 p)
{
	int d[7];
	int iCpt=0, iReturn=0;
	
	for(iCpt=0; iCpt<7; iCpt++)
	{
		d[iCpt]= (AlignDiagDroite(p,iCpt+1)+AlignDiagGauche(p,iCpt+1)+AlignHoriz(p,iCpt+1)+AlignVert(p,iCpt+1))-4;
	}

		iReturn = Max1(d);
	return iReturn;
}

//----------------------------------------------------------------------
