#include <stdio.h>
#include <stdlib.h>
#include "Profiler.h"


typedef struct node
{
	int key;
	struct node *next;
}Node;

void buildLists(Node *p[], int n);
void heapifyLists(Node *p[], int i, int n);

Node *p[1000];
int sol[10100];

int contor, si, sz;

void buildLists(Node *p[], int n)
{
	for(int i = n / 2; i >= 1; i--)
		heapifyLists(p, i, n);
}

void heapifyLists(Node *p[], int i, int n)
{
	int l;
	
	if(2 * i <= n && p[2 * i] -> key < p[i] -> key)
		l = 2 * i;
	else
		l = i;
	if(2 * i + 1 <= n && p[2 * i + 1] -> key < p[l] -> key)
		l = 2 * i + 1;
	contor += 2;
	if(l != i)
	{
		contor += 3;
		p[0] = p[i];
		p[i] = p[l];
		p[l] = p[0];
		heapifyLists(p, l, n);
	}
}

void interclasare(int n, int k)
{
		contor = 0;

			for (int i = 1; i <= k; i++)
			{
				p[i] = new Node();
				p[i]->key = rand() % (k * 3);
				p[i]->next = 0;
				Node *temp = p[i];
				contor+=3;
				for (int j = 2; j <= n / k; j++)
				{
					Node *aux = new Node();
					aux->key = temp->key + rand() % (k * 3);
					aux->next = 0;
					temp->next = aux;
					temp = aux;

					contor+=4;
				}
			}
			si = 0;
			
			sz = k;
			buildLists(p, sz);
			
			while(sz != 0)
			{
				sol[++si] = p[1] -> key;
				contor++;
				p[1] = p[1] -> next;
				
				if(p[1] == 0)
				{
					p[1] = p[sz];
					sz--;
				}
				heapifyLists(p, 1, sz);
			}

}

void main()
{
	int size=100,k;

	FILE *f;
	f = fopen("test.csv", "w");

	fprintf(f,"size, %s, %s, %s","k1","k2","k3");
	while(size<10000)
	{
		contor=0;
	    interclasare(n,5);
	    fprintf(f,"\n%d,%d",n,contor);


	    contor=0;
	    interclasare(n,10);
		fprintf(f,",%d",contor);

	    contor=0;
	    interclasare(n,100);
		fprintf(f,",%d",contor);

	size+=100;
	}
}