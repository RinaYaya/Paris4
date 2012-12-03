#include "IA.h"
//----------------------------------------------------------------------
int score(P4 p)
{
	int iCpt1=0, iCpt2=0;
	
	int s1=0,s2=0,s3=1,s4=0;
	
	for(iCpt1=1;iCpt1<=7;iCpt1++)
	{
		p=AjouterPion(p,iCpt1,Aquiletour(p));
		
		for(iCpt2=1; iCpt2<=7;iCpt2++)
		{
			p=AjouterPion(p,iCpt2,Aquiletour(p));
			p->Tour->h++;
			s4=AlignDiagDroite(p,iCpt2)+AlignDiagGauche(p,iCpt2)+AlignVert(p,iCpt2)+AlignHoriz(p,iCpt2)-3;
			p->Tour->h--;
			s4=s4-(AlignDiagDroite(p,iCpt2)+AlignDiagGauche(p,iCpt2)+AlignVert(p,iCpt2)+AlignHoriz(p,iCpt2)-3);
			s2=s2+s4;
			p=RetirerPion(p);
		}
		
		if(s1<s2)
		{
			s1=s2;
			s3=iCpt1;
		}
		p=RetirerPion(p);
		
	
	}
		
		return s3;
}
//----------------------------------------------------------------------
int Max1(int* p)
{
	int iCpt=0,i=0;
	
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
			i= (AlignDiagDroite(p,iCpt+1)+AlignDiagGauche(p,iCpt+1)+AlignHoriz(p,iCpt+1)+AlignVert(p,iCpt+1))-3;
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
		d[iCpt]= (AlignDiagDroite(p,iCpt+1)+AlignDiagGauche(p,iCpt+1)+AlignHoriz(p,iCpt+1)+AlignVert(p,iCpt+1))-3;
	}

		iReturn = Max1(d);
	return iReturn;
}

//----------------------------------------------------------------------
