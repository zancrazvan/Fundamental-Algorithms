#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define nrVarfuri 10000

/*
Padure de multimi disjuncte -> fiecare membru indica doar spre parintele lui. Radacina fiecarui arbore contine reprezentantul multimii care este	
propriul sau parinte.


*/
typedef struct Nod{
	int key;
	int rang;             // Rangul nodului -> nr de muchii al celui mai lung drum de la nodul x la o frunza 
	struct Nod *parinte; 

}Nod;

Nod *graf[nrVarfuri+1];
int total = 0;


// Creeaza un nod, al carei cheie este un numar care reprezinta identificatorul nodului ( al catelea nod este).
void formeazaMultimea(int v)
{  
	Nod *x;

	x = (Nod*)malloc(sizeof(Nod));

	x->key = v;
	x->parinte = x;

	x->rang = 0;
	graf[v] = x;


	total++;
}

// Cauta in graf nodul cu identificatorul x -> daca exista, returneaza cheia acestuia 
int gasesteMultimea(int x)
{
	total++;

	if (graf[x]!=NULL)
		return graf[x] -> key;

}


// Reuniunea dupa rang -> radacina arborelui cu mai putine noduri trebuie sa indice spre radacina arborelui cu mai multe noduri
void uneste(int x, int y)
{
	total++;

	if(graf[x]->rang > graf[y]->rang){

			graf[y]->parinte=graf[x];		
	}

	else{
			graf[x]->parinte=graf[y];
			
			if(graf[x]->rang == graf[y]->rang){

				graf[y]->rang = graf[y]->rang+1;
			}

	
   }

}

// Determina daca graf[x] si graf[y] sunt in acceasi componenta conexa
bool aceeasiComponenta(int x, int y)
{

	if (gasesteMultimea(x) && gasesteMultimea(y))

		if (gasesteMultimea(x) == gasesteMultimea(y))
			return true;
		else 
			return false;
}


// Aici este implementata metoda Componente Conexe
// Plaseaza initial viecare varf intr-o multime proprie. Apoi pt fiecare muchie se reunesc multimile ce contin capetele muchiilor.
// 2 varfuri sunt in aceeasi componenta conexa daca nodurile corespunzatoare sunt in aceeasi multime.
void main()
{
	int i,j,k;
	FILE *f;
	f=fopen("Multimi disjuncte.csv","w");
	fprintf(f,"Numar muchii, Total Operatii \n");
	
	for(i=1;i<=nrVarfuri;i++){

        formeazaMultimea(i);
	}

for(int nrMuchii=10000;nrMuchii<=10300;nrMuchii+=100){
	for(k=1;k<=nrMuchii;k++)
	{ 
		i=rand()%(nrVarfuri-1);
		j=rand()%(nrVarfuri-1);

		if (graf[i]!=NULL && graf[j]!=NULL){

		    if (aceeasiComponenta(i,j)==false){

			   uneste(i,j);
		    }
		
	    }
    }

	printf("%d\n",nrMuchii);
	fprintf(f,"%d, %d\n",nrMuchii,total);
}

getch();
}

 




