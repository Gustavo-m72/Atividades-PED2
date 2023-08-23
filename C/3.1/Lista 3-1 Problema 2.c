#include <stdlib.h> 
#include <stdio.h> 

struct lista {
	int info;
	struct lista* prox;
};

typedef struct lista Lista;


Lista* inicializa (void)
{
	return NULL;
}

void libera (Lista* l){
	Lista* p = l;

	while (p!=NULL)
	{
		Lista* t = p->prox;
		free(p);
		p = t;
	}
	

}

Lista* insere (Lista* l, int i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	novo->info = i;
	novo->prox = l;
	return novo;
}

void imprime (Lista* l)
{
	Lista* p;
	for (p = l; p != NULL; p = p->prox)  
		printf("info = %d\n", p->info);  
}		
	
Lista* copia (Lista* l1){
	Lista *p1 = l1;  
    Lista *p2=inicializa();
	Lista *aux=inicializa();
	for (p1 = l1; p1 != NULL; p1 = p1->prox){
		aux=(insere(aux,p1->info)); //recebe invertida
		
		/*p2 = (Lista*) malloc(sizeof(Lista)); //cria um valor a mais
		p2->info = p1->info;
			p2=p2->prox;
		if (p1->prox == NULL)
		{
			p2->prox=NULL;
		}
		if (p1==p2)
		{
			return p2;
		}*/
		
    }
	for (aux; aux != NULL; aux = aux->prox)
		p2=(insere(p2,aux->info));

	libera(aux);
	return p2;
}

int igual(Lista *l1, Lista *l2){
    Lista* p1 = l1; 
	Lista* p2 = l2;
	for (p1 = l1; p1 != NULL; p1 = p1->prox)  
		if (l1->info != l2->info)
			return 0;
		else
			p2 = p2->prox;
			
	if (p1 == p2)
		return 1;
		
	return 0;
}

int main () {
	Lista* l1; 
	l1 = inicializa();
    l1= insere(l1,5);
    l1= insere(l1,6);
    l1= insere(l1,7);
	l1= insere(l1,8);
    l1= insere(l1,9);
    l1= insere(l1,10);
	Lista* l2=inicializa(); 
	l2=copia(l1);
    
	
	if (igual(l1,l2)==1)
    {
        printf("\n listas iguais");
    }
    else 
        printf("listas diferentes");
    
	
}