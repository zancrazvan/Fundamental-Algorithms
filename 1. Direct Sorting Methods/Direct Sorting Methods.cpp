#include "Profiler.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX_SIZE 10000

/*
   BUBBLE SORT
   - Best Case : O(n) -> se comporta liniar
   - Average Case : O(n^2) 
   - Worst Case : O(n^2)

   INSERSION SORT
   - Best Case : O(n) -> se comporta liniar
   - Average Case : O(n^2) 
   - Worst Case : O(n^2) 

   SELECTION SORT
   - Best Case : O(n^2) 
   - Average Case : O(n^2) 
   - Worst Case : O(n^2) 

   BEST CASE
   - Comparatii -> InsersionSort e cel mai eficient
   - Atribuiti  -> BubbleSort e cel mai eficient
   - Suma       -> BubbleSort e cel mai eficient


   AVERAGE CASE
   - Comparatii -> InsersionSort e cel mai eficient
   - Atribuiti  -> SelectionSort cel mai eficient
   - Suma       -> SelectionSort e cel mai eficient

   WORST CASE
   - Comparatii -> SelectionSort e cel mai eficient
   - Atribuiti  -> SelectionSort cel mai eficient
   - Suma       -> SelectionSort e cel mai eficient

 */

Profiler profiler("demo");

void bubbleSort(int *a, long size, char* suma, char* comp, char* attr) // BUBBLE SORT
{
	int stop;
	long aux,i;
	do
	{
	    stop=0;
		profiler.countOperation(suma,size);
		profiler.countOperation(attr,size);
	    for (i=0;i<size-1;i++)
	    {
			profiler.countOperation(comp,size);
			profiler.countOperation(suma,size);
	        if(a[i]>a[i+1])
	        {
	            profiler.countOperation(attr,size,4);
				profiler.countOperation(suma,size,4);
	            aux=a[i];
	            a[i]=a[i+1];
	            a[i+1]=aux;
	            stop=1;
	        }
	    }
	}while(stop==1);
}

void insersionSort(int *a,int size, char* suma, char* comp, char* attr)  // SORTAREA PRIN INSERTIE
{
  int i,j;
  int aux;
  for(j=1;j<size;j++)
     {
	     aux=a[j]; 
		 i=j-1;

		 profiler.countOperation(attr, size,2);
		 profiler.countOperation(suma, size,2);
	     while((i>=0) && (aux<a[i]))
		 {
		     a[i+1]=a[i];
		     i=i-1;
			 profiler.countOperation(attr, size,2);
			 profiler.countOperation(comp, size,2);
			 profiler.countOperation(suma, size,4);
		 }
             a[i+1]=aux;
			 profiler.countOperation(attr, size);
			 profiler.countOperation(suma, size);
	   }    
 }


void selectionSort(int *a, int size, char* suma, char* comp, char* attr)  // SORTAREA PRIN SELECTIE
{
	int i,min,j,aux,p;

	for(i=0;i<size-1;i++)
	{
		min =a[i]; 
		p=i; 
		profiler.countOperation(attr,size,2);
		profiler.countOperation(suma,size,2);
		
		for(j=i+1;j<size;j++)
		{
			profiler.countOperation(comp,size);
			profiler.countOperation(suma,size);
			if (a[j]<min)
			{
				min=a[j];
				p=j;
				profiler.countOperation(attr,size,2);
				profiler.countOperation(suma,size,2);
			}
		}
		aux=a[p];
		a[p]=a[i];
		a[i]=aux;
		profiler.countOperation(attr,size,3);
		profiler.countOperation(suma,size,3);
	}
}

int main()
{  int a[MAX_SIZE];
   int size = 10;

   // BEST CASE
    profiler.createGroup("BestCase_Comparatii", "bubbleSort_nrComparatii_b", "insersionSort_nrComparatii_b","selectionSort_nrComparatii_b");
	profiler.createGroup("BestCase_Atribuiri", "bubbleSort_nrAtribuiri_b", "insersionSort_nrAtribuiri_b","selectionSort_nrAtribuiri_b");
	profiler.createGroup("BestCase_Suma", "bubbleSort_Suma_b", "insersionSort_Suma_b","selectionSort_Suma_b");
    for(size=100;size<=500;size=size+50)
     {
	    FillRandomArray(a,size,10,200,false,1);
		bubbleSort(a,size,"bubbleSort_Suma_b","bubbleSort_nrComparatii_b", "bubbleSort_nrAtribuiri_b");

		FillRandomArray(a,size,10,200,false,1);
		insersionSort(a,size, "insersionSort_Suma_b", "insersionSort_nrComparatii_b", "insersionSort_nrAtribuiri_b");

		FillRandomArray(a,size,10,200,false,1);
	    selectionSort(a,size, "selectionSort_Suma_b", "selectionSort_nrComparatii_b", "selectionSort_nrAtribuiri_b");

     }


   // WORST CASE
   	profiler.createGroup("WorstCase_Comparatii", "bubbleSort_nrComparatii_w", "insersionSort_nrComparatii_w","selectionSort_nrComparatii_w");
	profiler.createGroup("WorstCase_Atribuiri", "bubbleSort_nrAtribuiri_w", "insersionSort_nrAtribuiri_w","selectionSort_nrAtribuiri_w");
	profiler.createGroup("WorstCase_Suma", "bubbleSort_Suma_w", "insersionSort_Suma_w","selectionSort_Suma_w");
   for(size=100;size<=500;size=size+50)
     {
	    FillRandomArray(a,size,10,200,false,2);
		bubbleSort(a,size,"bubbleSort_Suma_w","bubbleSort_nrComparatii_w", "bubbleSort_nrAtribuiri_w");

		FillRandomArray(a,size,10,200,false,2);
		insersionSort(a,size, "insersionSort_Suma_w", "insersionSort_nrComparatii_w", "insersionSort_nrAtribuiri_w");

		FillRandomArray(a,size,10,200,false,2);
	    selectionSort(a,size, "selectionSort_Suma_w", "selectionSort_nrComparatii_w", "selectionSort_nrAtribuiri_w");

     }

	// AVERAGE CASE
	profiler.createGroup("AverageCase_Comparatii", "bubbleSort_nrComparatii_a", "insersionSort_nrComparatii_a","selectionSort_nrComparatii_a");
	profiler.createGroup("AverageCase_Atribuiri", "bubbleSort_nrAtribuiri_a", "insersionSort_nrAtribuiri_a","selectionSort_nrAtribuiri_a");
	profiler.createGroup("AverageCase_Suma", "bubbleSort_Suma_a", "insersionSort_Suma_a","selectionSort_Suma_a");
    for(size=100;size<500;size=size+50)
     {
	    FillRandomArray(a,size,10,200,false,0);
		bubbleSort(a,size, "bubbleSort_Suma_a","bubbleSort_nrComparatii_a", "bubbleSort_nrAtribuiri_a");

		FillRandomArray(a,size,10,200,false,0);
		insersionSort(a,size, "insersionSort_Suma_a", "insersionSort_nrComparatii_a", "insersionSort_nrAtribuiri_a");

		FillRandomArray(a,size,10,200,false,0);
	    selectionSort(a,size, "selectionSort_Suma_a", "selectionSort_nrComparatii_a", "selectionSort_nrAtribuiri_a");

     }
    profiler.showReport();
	return 0;
	
}