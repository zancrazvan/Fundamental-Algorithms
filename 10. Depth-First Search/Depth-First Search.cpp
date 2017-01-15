#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct Nod
{
	int listaAdiacenta[50];
	int nr;
}Nod;

Nod *graf[103];

int color[103];
int p[103];
int d[103];

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


void visit(int i){

	color[i]=1;

	for(int j=0;j< graf[i]->nr;j++){
		contor++;
		int	v = graf[i]->listaAdiacenta[j];
		if (color[v] == 0){

			p[v]=i;
			contor+=2;
			printf("%d ",v);
			visit(v);

		}


	}


}


void dfs(){

	for (int i = 0; i < 100; i++)
	{
		color[i] = 0;
		d[i] = INT_MAX;
	}

	for (int i = 0; i < 100; i++)
	{
		if(color[i]==0){
			contor++;
			visit(i);
		}

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
	f=fopen("Tema10.csv","w");
	fprintf(f,"%s,%s","Nr Muchii","Operatii");

	for(int i=1000;i<=5000;i=i+100){

		createList(i/100);
		list();
	    printf("\n");
		dfs();
		printf("\n");

		fprintf(f,"\n%d,%d",i,contor);
		contor=0;

	}
	fclose(f);

	
	
	
	getch();

}
