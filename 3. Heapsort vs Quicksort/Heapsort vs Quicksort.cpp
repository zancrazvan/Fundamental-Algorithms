#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Profiler.h"

long heap=0;   // CONTOR PT HEAPSORT
long quick=0; //  CONTOR PT QUICKSORT

/*
   QUICKSORT

   Se bazeaza pe paradigma "divide si stapaneste"
   
   BEST CASE    -> O(nlogn)
   AVERAGE CASE -> O(nlogn)
   WORST CASE   -> O(n^2)


   HEAPSORT
   
   Combina algoritmul de inserare si cel de interclasare

   AVERAGE CASE -> O(nlogn)

*/
void maxHeapify(int *a, int i, int size)  // APLICA PROPRIETAREA HEAP'ULUI
{
    int stg,dr,max;
    int aux;

    stg=2*i;
    dr=2*i+1;

    heap=heap+2;
    if (stg<=size && a[stg]>a[i])
        {
			max=stg;
			heap++;
	    }
    else
	    {
          max=i;
		  heap++;
	    }

    heap=heap+2;
    if (dr<=size && a[dr]>a[max])
	   {
          max=dr;
		  heap++;
	   }

	heap++;
    if (max!=i)
        {
            aux=a[i];
            a[i]=a[max];
            a[max]=aux;
			heap = heap+3;
            maxHeapify(a,max,size);
        }
}

void bottomUp(int *a,int size)  // CONSTRUIESTE HEAP'UL PRIN METODA BOTTOM UP
{
    int i;
    for (i=size/2;i>=1;i--)
        maxHeapify(a,i,size);
}

void heapSort(int *a,int *dim, int size)  // ALGORITMUL PT HEAPSORT
{
    int i;
    long aux;
    bottomUp(a,(*dim));

    for (i=size;i>=2;i--)
    {
        heap=heap+3;

        aux=a[1];
        a[1]=a[i];
        a[i]=aux;
        (*dim)--;

        maxHeapify(a,1,(*dim));
    }
}

	
int partition(int *arr, int p, int r)
{
    long x,aux;
    int i,j;

    x=arr[p];

    i=p-1;
    j=r+1;

    while (1)
    {
        do
        {
            j--;
            quick=quick+2;
        }while(arr[j]>x);

        do
        {
            i++;

            quick=quick+2;
        }while(arr[i]<x);

        if (i<j)
        {
            quick=quick+4;

            aux=arr[i];
            arr[i]=arr[j];
            arr[j]=aux;
        }
        else return j;

        }

}

void quickSort(int *arr,int p, int r)
{
    int q;

	quick++;
    if (p<r)
    {
        q=partition(arr,p,r);
        quickSort(arr,p,q);
        quickSort(arr,q+1,r);
    }
	
}



int main()
{
   int a[10000];
   int b[10000];
   int size=10;
   

   FILE *f,*g;                                       

    FillRandomArray(a,10,10,200,false,0);  // TESTARE ALGORITMI   
    quickSort(a,0,size);                   
    for(int i = 1; i < 10; ++i)           
	   {                                 
		  printf(" %d ", a[i]);
	   }

   printf("\n");

   FillRandomArray(a,10,10,200,false,0);
   heapSort(a,&size,size);
   for(int i = 1; i < 10; ++i)
      {
		 printf(" %d ", a[i]);
      }

   getch();
                                          // END TESTARE ALGORITMI



	f=fopen("Tema3Average.csv","w");
	fprintf(f,"size, %s, %s","HeapSort","QuickSort");

		for(size=100;size<10000;size+=100)
	       { quick=0;
			 heap=0;
	         FillRandomArray(b,size,10,200,false,0);
	         quickSort(b,0,size);

		     int dim = size;
		     FillRandomArray(a,size,10,200,false,0);
	         heapSort(a,&dim,size);

	         fprintf(f,"\n%d,%d,%d",size ,heap,quick);
			 quick=0;
			 heap=0;
	        }

	    heap=0;
	    quick=0;
		
	

	fclose(f);


	// QUICKSORT COMPARATION
	g=fopen("QuickSortCompare.csv","w");
	fprintf(g,"size, %s, %s, %s","Best","Average","Worst");

	     
		for(size=100;size<10000;size+=100)
	       { quick=0; 
			    
			 FillRandomArray(b,size,10,200,false,0);       // BEST CASE
	         quickSort(b,size/2,size);                    //  O(nlogn)
			 
             fprintf(g,"\n%d,%d",size,quick);        
			 quick=0;


			 FillRandomArray(b,size,10,200,false,0);    // AVERAGE CASE
	         quickSort(b,0,size);                      //  O(nlogn)

             fprintf(g,",%d",quick);
			 quick=0;


			 FillRandomArray(b,size,10,200,false,2);  // WORST CASE
	         quickSort(b,0,size);                    //  O(n^2)
			 

             fprintf(g,",%d",quick);
			 quick=0;

	        }



    fclose(g); 

}
