#include "Profiler.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX_SIZE 10000
Profiler profiler("demo");
/*
  METODA BUTTOM UP

  Deoarece toate elementele subsirului A[([n/2]+1....n] sunt frunza, metoda buttomUp trebuie sa traverseze doar restul elementelor
  si sa execute metoda maxHeapify.

  COMPLEXITATE: O(n)



  METODA TOP DOWN

  La prima expandare se adauga o frunza a arborelui. La urmatorii pasi se traverseaza un drum pornind de la aceasta frunza catre radacina
  in scopul gasirii locului definitiv al nodului corent.

  COMPLEXITATE: O(log n)



*/

int op=0;   // CONTOR PT maxHeapify
int op2=0; // CONTOR PT insertInHeap


void maxHeapify(int *a, int i, int size)  // maxHeapify mentine proprietatea Heap-ului
{
    int stg,dr,max;
    long aux;

    stg=2*i;
    dr=2*i+1;

    op = op+2;
    if (stg<=size && a[stg]>a[i])
        { 
			max=stg;
			op++;
	    }
    else
        { 
			max=i;
			op++;
	    }

    op=op+2;
    if (dr<=size && a[dr]>a[max])
	{
       max=dr;
	   op++;
	}

	op++;
    if (max!=i)
        {
            op=op+3;
            aux=a[i];
            a[i]=a[max];
            a[max]=aux;
            maxHeapify(a,max,size);
        }
}

void bottomUp(int *a,int size) // HEAP CONSTRUIT PRIN METODA BOTTOM-UP
{
    int i;
    for (i=size/2;i>=0;i--)
	   {
          maxHeapify(a,i,size);
	   }
}

void insertInHeap(int *a,int key,int *dim)
{
    (*dim)=(*dim)+1;
    int i;
    i=(*dim);

	op2=op2+2;
    while (i>1 && a[i/2]<key)
    {
        op2=op2+2;
        a[i]=a[i/2];
        i=i/2;
    }
	
	op2++;
    a[i]=key;
}

void topDown(int *a,int n)
{
    int dimension=1,i;
    for (i=2;i<=n;i++)
        insertInHeap(a,a[i],&dimension);
}



int main ()
{
   int a[MAX_SIZE], b[MAX_SIZE];
   int size = 10,i;
   FILE *f,*g;

   FillRandomArray(a,10,10,200,false,0);
   bottomUp(a,size);
	for(int j=1;j<=9;j++)
		printf("%d ",a[j]);

   printf("\n");

   FillRandomArray(b,10,10,200,false,0);
   topDown(b,size);
	for(int j=1;j<=9;j++)
		printf("%d ",b[j]);


	// AVERAGE CASE
	f=fopen("Tema2Average.csv","w");
	fprintf(f,"size,%s,%s","BottomUp","TopDown");
	

	
	for(size=100;size<10000;size+=100)
	{
	
	FillRandomArray(a,size,10,200,false,0);
	bottomUp(a,size);

	FillRandomArray(b,size,10,200,false,0);
	topDown(b,size);

	fprintf(f,"\n%d,%d,%d",size,op,op2);

	op=0;
	op2=0;

	}

	fclose(f);

	// WORST
	g=fopen("Tema2Worst.csv","w");
	fprintf(g,"size,%s,%s","BottomUp","TopDown");
	

	
	for(size=5;size<10000;size=size+(size+1))
	{
	
	FillRandomArray(a,size,10,200,false,0);
	bottomUp(a,size);

	FillRandomArray(b,size,10,200,false,0);
	topDown(b,size);

	fprintf(g,"\n%d,%d,%d",size,op,op2);

	op=0;
	op2=0;

	}

	fclose(g);

	

	getch();
	return 0;


}