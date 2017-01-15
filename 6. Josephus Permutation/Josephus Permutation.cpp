#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



/*
Un arbore binar echilibrat este acel arbore, care pentru fiecare nod, numarul nodurilor din subarborele stanga, difera cu cel mult 1 de numarul
nodurilor din subarborele drept (sau invers).

Permutarea Josephus gaseste al m-lea element din n elemente, si il elimina.

*/
typedef struct Nod
{
    int key;
    int dimensiune;
    struct Nod *stanga;
    struct Nod *dreapta;
    struct Nod *parinte;
}Nod;

Nod *radacina;
int suma = 0;

// CONSTRUIREA UNUI ARBORE DE CAUTARE ECHILIBRAT
Nod* construireArbore (int stanga, int dreapta, Nod *parinte)
{
	if (stanga <= dreapta)
	   {  
		   Nod *p = (Nod*)malloc(sizeof(Nod));
		
		   suma++;
		
		   p->key = (stanga + dreapta) / 2;
	       p->dimensiune = dreapta - stanga + 1;
		   p->stanga = construireArbore(stanga, (stanga + dreapta)/ 2 - 1, p);  
		   p->dreapta = construireArbore((stanga + dreapta)/2 + 1, dreapta, p);

		   p->parinte = p;
		   return p;
	   }
	else return NULL;
}

// GASESTE AL K-LEA CEL MAI MIC NOD DIN SUBARBORELE CU RADACINA IN P
Nod* osSelect (Nod *p, int k)
{
	int r; // numarul de noduri ce au fost deja verificate

	suma++;
	if (p->stanga != NULL)
	   {
		  r = p->stanga->dimensiune + 1; // rangul lui p
		  suma++;
	   }

	else
	   {
		  r = 1;
		  suma++;
	   }

	suma++;
	if(k==r) {
		       return p;
	         }
	else { 
		   suma++;
	       p->dimensiune = p->dimensiune-1;

		   suma++;
	       if(k<r){ 
			        return osSelect(p->stanga,k);
		          }

		   suma++;
	       if(k>r){
			       return osSelect(p->dreapta,k-r);
		          }
		  }
		   
}

  Nod* getSuccessor(Nod *node)
   {
     while(node->dreapta != NULL)
       node = node->dreapta;
     return node;
   }

  int deleteNode(  Nod **rootNode, int nodeValue )
{
    struct Nod* currentNode = *rootNode;
    struct Nod* trailNode = NULL; 
    int found = 0;
 
    while(!found && currentNode != NULL)
    {
        if( currentNode->key == nodeValue )
            found = 1;
        else
        {
            trailNode = currentNode;
            if( currentNode->key > nodeValue )
                currentNode = currentNode->stanga;
            else
                currentNode = currentNode->dreapta;
        }
    }
 
    if(found == 1)
    {
        if( trailNode == NULL )
            deleteFromTree( &currentNode );
        else if( trailNode->data > nodeValue )
            deleteFromTree( &trailNode->leftChild );
        else
            deleteFromTree( &trailNode->rightChild );
    }
 
    return found;
}
Nod* remove(Nod *node, Nod* data)
   {
     if(node == NULL)
     {
       //std::cerr << "ERROR: Node does not exists\n";
       return node;
     }

	 if(data->key == node->key)
     {
     Nod *retval = NULL;
    
       if(node->stanga == NULL)
       {
         retval = node->dreapta;
         delete node;
         return retval;
       }
       else if(node->dreapta == NULL)
       {
         retval = node->stanga;
         delete node;
         return retval;
       }
       else
       {
          Nod *successor = getSuccessor(node->stanga);
          node = successor;
          node->stanga = remove(node, successor);
       }
     }
     else if(data < node)
     {
       node->stanga = remove(node, data);
     }
     else
     {
       node->dreapta = remove(node->dreapta, data);
     }

     return node;
   }

 
// GASESTE NODUL MINIM DIN SUBARBORELE CU RADACINA IN P
Nod* gasireMin(Nod* p)
{
	while (p->stanga != NULL)
	{
		suma=suma+3;
		p->dimensiune = p->dimensiune - 1;
		p = p->stanga;
	}
	return p;
}

// GASESTE SUCCESORUL NODULUI P
Nod* gasireSuccesor(Nod* p)
{
	suma++;
	if (p->dreapta != NULL)
	   {
		 return gasireMin(p);
	   }

	suma++;
	Nod *q = p->parinte;
	while (q != NULL && p == q->dreapta)
	{
		suma=suma+3;
		p = q;
		q = p->parinte;
	}
	return p;
}

// STERGEREA NODULUI s DIN SUBARBORELE CU RADACINA IN p
Nod* osDelete (Nod *p, Nod *s)
{
	Nod *y,*x;

	suma++;
	if (s->stanga == NULL || s->dreapta == NULL)
	  {
        suma++;
		y = s;
	  }
	else{ 
		  suma++;
		  
		  y = gasireSuccesor(s);
	//	  if(s==radacina) radacina=y;
	    }
	
	suma++;
	if (y->stanga != NULL)
	{
		suma++;
		x = y->stanga;
	}
	else
	{   
		suma++;
		x = y->dreapta;
	}

	suma++;
	if (x != NULL){
		suma++;
		x->parinte = y->parinte;
	}


	suma++;
	if (y->parinte == NULL)
	{
		suma++;
		radacina = x;
	}
	else
	{
		suma++;
		if (y == y->parinte->stanga){

			suma++;
			y->parinte->stanga = x;
		}
		else{
			suma++;
			y->parinte->dreapta = x;
		}
	}

	suma++;
	if (y != s)
	{  
		suma++;
 		s->key = y->key;
	}

	return y;
}

// AFISEAZA IN INORDINE SUBARBORELE CU RADACINA IN p
void print (Nod* p)
{
	if (p != NULL)
	{
		print(p->stanga);
		printf("%d %d\n", p->key, p->dimensiune);
		print(p->dreapta);
	}
}

//ALGORITMUL PENTRU AFLAREA PERMUTARILOR JOSEPHUS
void josephus (int n, int m)
{
	int c = 1;
	int s = n;
	int i;
	Nod *nod;
	for(i = 1; i <= n; i++)
	{
		c = c + m-1;
		if (c > s)
			c = (c - 1) % s + 1;
		nod = osSelect(radacina, c);
		printf("scoate: %d \n",nod->key);
		deleteNod(radacina, nod->key);
		s = s - 1;
	}
}

int main()
{
	FILE *f;
	f=fopen("Josephus.csv","w");
	fprintf(f,"Dimensiunea Arborelui, Suma \n");

//	for (int i=100;i<=10000;i=i+100)
//	{    
		suma=0;
		radacina=construireArbore(1,11,NULL);
	//	printf("\n Inainte Josephus \n");
		print(radacina);
		josephus(11,3);
	printf("\n Dupa Josephus \n");
		print(radacina);
	//	fprintf(f,"%d, %d\n",i,suma);
//}
	
	getch();
	fclose(f);
	return 0;
}
