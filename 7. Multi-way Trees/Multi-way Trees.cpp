# include <stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Nod{
	int cheie;
	struct Nod *stg,*dr;

}Nod;

typedef struct NodMulti{
	int cheie;
	int nrFii;
	struct NodMulti *adresaFii[100];

}NodMulti;

int vector[9]={2,7,5,2,7,7,-1,5,2};

NodMulti *radacina;
NodMulti *dispersie;
NodMulti *temp;
Nod *radacinaB;


void fromParentToMultiWay(int dimensiune){


	NodMulti *dispersie = (NodMulti*)malloc(sizeof(NodMulti)*dimensiune);

	 for(int i=0;i<dimensiune;i++){

		 (dispersie+i)->cheie=i+1;
		  (dispersie+i)->nrFii=0;

		  if(vector[i] == -1){
			  radacina=dispersie+i;
		  }
	 }

	
	temp=radacina;
	printf(" Temp cheie este %d\n",temp->cheie);
	int cont=0;
	int cont2=0;
	int cont3=0;
	int ok=1;
	int ok2=1;
	 for( int i=0;i<dimensiune;i++){

		
		 if(vector[i]==temp->cheie)
		  {

		    temp->nrFii++;
			temp->adresaFii[cont++]=(dispersie+i);
			
			printf(" Primul nivel de fii %d\n",(temp->adresaFii[cont-1])->cheie);
			
		 }
	
		 

    }
	 int aux=temp->nrFii;
	 for( int i=0;i<dimensiune;i++){

		 if(vector[i]==(temp->adresaFii[temp->nrFii-aux])->cheie)
		  { 
		
			temp->adresaFii[temp->nrFii-aux]->nrFii++;
			temp->adresaFii[temp->nrFii-aux]->adresaFii[cont2++]=(dispersie+i);
		
			printf("fiu %d\n",(temp->adresaFii[temp->nrFii-aux]->adresaFii[cont2-1])->cheie);
		
		 }
		// else printf(" NU gasit\n ");
		 
		 if(i==dimensiune-1 && ok==1){
			 temp->nrFii=temp->nrFii+1;

			 i=0;
			 ok=0;
		 }

		 
    }


}

 Nod* Insert(int X,Nod* T){

       if(T==NULL){
          T = (Nod*)malloc(sizeof(Nod));
          T->cheie = X;
          T->stg = NULL;
          T->dr = NULL;
        }
       else 
		   if(X<T->cheie)  T->stg = Insert(X,T->stg);
       else 
		   if(X>T->cheie) T->dr = Insert(X,T->dr);

return T;
}

void afisare(Nod* root)
{
	int i ;
    if (root != NULL){    
		afisare(root->stg);
		printf("%d\n",root->cheie);
		afisare(root->dr);
	}
}


void main(){


	fromParentToMultiWay(9);


Nod* n;

n=Insert (radacina->cheie , radacinaB ) ;
afisare(n);

 n=Insert( radacina->adresaFii[0]->cheie,radacinaB);
afisare(n);

 n=Insert( radacina->adresaFii[1]->cheie,radacinaB);
afisare(n);

n=Insert( radacina->adresaFii[2]->cheie,radacinaB);
afisare(n);

n= Insert( radacina->adresaFii[0]->adresaFii[0]->cheie,radacinaB);
afisare(n);

n=Insert( radacina->adresaFii[0]->adresaFii[1]->cheie,radacinaB);
afisare(n);

n=Insert( radacina->adresaFii[0]->adresaFii[2]->cheie,radacinaB);
afisare(n);

n=Insert( (radacina->adresaFii[1]->adresaFii[3])->cheie,radacinaB);
afisare(n);

n=Insert( (radacina->adresaFii[1]->adresaFii[4])->cheie,radacinaB);
afisare(n);


getch();
//	return 0;
}