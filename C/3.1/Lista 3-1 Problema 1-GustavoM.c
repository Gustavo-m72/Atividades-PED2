#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int x;
    struct lista * proximo; 
}Lista;

Lista* inicializa(){

    return NULL;
}

Lista* cria(Lista* l1, int i){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->x = i;
    novo->proximo = l1;
    return novo;
}

int igual(Lista *l1, Lista *l2){
    Lista* p1 = l1; 
	Lista* p2 = l2;

	for (p1 = l1; p1 != NULL; p1 = p1->proximo)  
		if (l1->x != l2->x)
			return 0;
		else
			p2 = p2->proximo;
			
	if (p1 == p2)
		return 1;
		
	return 0;
}

int main()
{
    Lista *l1; 
    Lista *l2;
    l1=inicializa();
    l2=inicializa();

    l1 = cria(l1,5);
    l2 = cria(l2,5);
    
    l1 = cria(l1,6);
    l2 = cria(l2,7);

    if (igual(l1,l2)==1)
    {
        printf("\n listas iguais");
    }
    else 
        printf("listas diferentes");
    return 0;
}
