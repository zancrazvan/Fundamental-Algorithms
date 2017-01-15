#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct Nod
{
	int listaAdiacenta[50];
	int nr;
}Nod;

Nod *graf[103];

int color[103]; // culorile
int p[103];  // predecesor
int d[103]; //  distanta de la sursa la nod

int contor=0;

void list()
{
	for (int i = 0; i <100; i++)
	{
		printf("%d -> ", i);

		for (int j = 0; j < graf[i]->nr; j++)
			printf("%d ", graf[i]->listaAdiacenta[j]);
		printf("\n");
	}
}

void bfs(int s)
{
	for (int i = 0; i < 100; i++)
	{
		color[i] = 0;
		d[i] = INT_MAX;
		p[i] = -1;

		contor+=3;
	}

	color[s] = 1;
	d[s] = 0;
	p[s] = -1;
	int queue[103];
	int notq = 0;
	queue[0] = s;
	int nr = 1;

	while (notq < 100)
	{
		int u = queue[notq];

		for (int j = 0; j < graf[u]->nr; j++)
		{    contor++;
			int	v = graf[u]->listaAdiacenta[j];

			if (color[v] == 0)
			{   
				contor++;
				color[v] = 1;
				d[v] = d[u] + 1;
				p[v] = u;

				queue[nr] = v;
				nr++;

				contor+=4;
			}
		}
		notq++;
		printf("%d ",u);
	}
}

void prettyPrint(int root, int tab)
{
	for (int i = 0; i < 103; i++)
		if (p[i] == root)
		{
			for (int j = 0; j < tab; j++)
				printf("   ");
			printf("%d\n", i);
			prettyPrint(i, tab + 1);
		}
}

void createList(int cont2)
{

	for(int i = 0; i < 103; i++){
		graf[i] = (Nod*)malloc(sizeof(Nod));

		int cont=0;
		while(cont<cont2){

			graf[i]->listaAdiacenta[cont]=(rand() % (100 - 0 + 1)) + 0;
			graf[i]->nr=cont;
			cont++;
		}
	}
	
}

int main()
{
	FILE *f;
	f=fopen("Tema9.csv","w");
	fprintf(f,"%s,%s","Nr Muchii","Operatii");

	for(int i=1000;i<=5000;i=i+100){

		createList(i/100);
		list();
	    printf("\n");
		bfs(1);
		printf("\n");

		fprintf(f,"\n%d,%d",i,contor);
		contor=0;

	}
	fclose(f);

	
	
	
	getch();
	return 0;
}
