#include <stdlib.h> 
#include <stdio.h> 

struct lista {
	int info;
	struct lista* prox;
};

typedef struct lista Lista;

Lista* inicializa (Lista* l, int i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	novo->info = i;
	novo->prox = novo;
	return novo;
}

void imprime (Lista* l)
{
	Lista* p=l; 
	/*for (p = l; p != l; p = p->prox)  
		printf("info = %d\n", p->info);*/
		
		do
		{
			printf("%d, ",p->info);
			p = p->prox;
		} while (p!=l);
		  
}		
	
Lista* insere(Lista* l, int i){
	
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	/*novo->info = i;
	if (l == NULL)
	{
		l = novo;
		novo->prox = novo;
	}else{
		Lista* aux = l;
		while (aux->prox != l)
			aux=aux->prox;
		aux->prox=novo;
		novo->prox=l;
		l=novo;
	}*/

	novo->info=i;
	novo->prox=l;

	Lista* aux=l;
	while (1)
	{
		if (aux->prox!=l)
		{
			aux=aux->prox;
		}
		else
		{
			aux->prox=novo;
			break;
		}
	}
	return novo;
} 

Lista* remover(Lista* l, int i){
	Lista* aux = l; 
	if (l->info == i)
	{
		while (1)
		{
			if (aux->prox == l)
			{
				aux->prox=l->prox;
				free(l);
				return aux->prox;
			}
			else
			{
				aux = aux->prox;
			}
		}	
	}
	do
	{
		if (aux->prox->info == i)
		{
			Lista* novopos=aux->prox->prox;
			free(aux->prox);
			aux->prox=novopos;
		}
		aux = aux->prox;
	} while (aux->prox!=l);
	return l;
}

int main () {
	
    Lista* l1;
	l1= inicializa(l1,4); 
    l1= insere(l1,5);
    l1= insere(l1,6);
    l1= insere(l1,7);
	imprime(l1);
	l1=remover(l1,5);
	l1=remover(l1,4);
	l1=remover(l1,7);
	printf("\n\nremovido");
	imprime(l1);
	return 0;
}