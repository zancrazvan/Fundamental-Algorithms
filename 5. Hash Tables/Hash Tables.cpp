#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define M 9973

int dispersie[M]; // tabela de dispersie
long efortG=0,efortN=0; // contor pt eforurile medii
int contor=0; // contor pt  functia de cautare

/*
   Efortul mediu si maxim de cautare a elementelor ce nu se afla in tabela de dispersie este de minim 5 ori mai mare ( pentru factorul de umplere
   de 8000, ajungand pana la de 10 ori mai mare, pentru factorul de umplere egal cu 9900 )
   decat efortul de cautare a elementelor ce sunt in tabela de dispersie.
*/

void initializareTabela(int n)     
{
	for (int i = 1; i < n; i++)
	{
		dispersie[i] = NULL;
	}
}

int hashFunct(long el, int i)      // Functia hash
{
	return (el + i + i * i) % M;
}

void inserareElement(long el)    // Functie pentru inserare unui element in tabela de dispersie
{
    int i=0,j,ok=0;
    do
    {
        j=hashFunct(el,i);      // Se genereaza pozitia unde elementul va fi inserat 
        if (dispersie[j]==NULL)
        {
			dispersie[j]=el;  // Elementul este introdus in tabela de dispersie  
            ok=1;
        }else i++;          // Daca pe pozitia generata exista deja un element, atunci se cauta alta  
    }while (i<M && ok==0);
    if (j>M) printf ("Eroare ! \n Tabela este plina");
}

void cautareElement(long el)   // Functie pentru cautarea unui element in tabela de dispersie
{
    int j;
    int i=0,ok=0;
    do
    {  
	  
		contor++;

        j=hashFunct(el,i);   // Se cauta pozitia elementului elementului cautat
        if (dispersie[j]==el)
        {
            printf("Gasit");
			return;
			ok=1;
        }
        i++;
       
    }while (dispersie[j]!=NULL && i<=M);

    if (ok==0)
	{ 
		printf("Negasit");
		return;
	} 
}

void main()
{   int factorUmplere = 8000;
    int i,max=0,timesint=0,max2=0;
	long a[M];
	long z=0,x;

    FILE *f;
	f=fopen("TabelaDispersie.csv","w");
	fprintf(f,"Factor de umplere, Efort mediu de gasire, Efort maxim de gasire, Efort mediu de negasire, Efort maxim de negasire \n");

	

	while(factorUmplere <= 9900)
	{   
	   initializareTabela(M);  

		efortG=0;
		

		max=0;
		max2=0;
		z=0;
		for(i=1;i<=factorUmplere;i++)
		{  
			x=rand()%100;
			inserareElement(x);
			
			a[z]=x;
			z++;
		}

		 contor=0;
	
		
      for(int c=0;c<5;c++)   // Cautare elemente existente
      {
		
		for(int j=1;j<=1500;j++)
		{   
			cautareElement(a[j*5+rand()%5]);
		}

		if(contor>max) max=contor;

		efortG+=contor;
		contor=0;
      }

		contor=0;
	

       for(int c=0;c<5;c++) // Cautare elemente inexistente
	   {

		for(int j=1500;j<=3000;j++)
		{   
		
			cautareElement(M+rand()%1000000);
		
		}

	    if(contor>max2) max2=contor;

	     efortN+=contor;
	     contor=0;

       }

		contor=0;
			

	    fprintf(f,"%d,%1.2f,%1.2f,%1.2f,%1.2f\n",factorUmplere,efortG/(5*1500.0),max/1500.0,efortN/(5*1500.0),max2/1500.0);

		efortG=0;
		efortN=0;


		max=0;
		max2=0;

		contor=0;
   
		factorUmplere=factorUmplere+500;
		if(factorUmplere==10000)
		  {
			  factorUmplere=9900;
		  }
		efortN=0;

	}

	getch();
}

