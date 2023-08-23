#include <stdlib.h>
#include <stdio.h>

typedef struct lista
{
    int info;
    struct lista* prox;
}Lista;

Lista* inicializa (void){
    return NULL;
}

Lista* insere(Lista* l,int i){
    Lista* novo=(Lista*)malloc(sizeof(Lista));
    novo->info=i;
    novo->prox=l;
    return novo;
}

void imprime(Lista* l){
    Lista* p;
    int i;
    for (p = l;p != NULL; p = p->prox)
    {
        printf("\n%d",p->info);
    }
}

Lista* busca(Lista* l, int v){
    Lista* p;
    for (p = l;p != NULL; p = p->prox)
    {
        if (p->info==v)
        {
            return p;
        }
    }
    return NULL;
}

Lista* retira(Lista* l, int v){
    Lista* ant = NULL;
    Lista* p = l;
    while (p!= NULL && p->info !=v)
    {
        ant = p;
        p=p->prox;
    }

    if (p==NULL)
    {
        return l;
    }

    if (ant==NULL)
    {
        l= p->prox;
    }else
    {
        ant->prox=p->prox;
    }
    free(p);
    return l;
}

void libera(Lista* l){
    Lista* p=l;
    while (p!=NULL)
    {
        Lista* t=p->prox;
        free(p);
        p=t;
    }
}

Lista* problemaa(Lista* l){
	Lista *p1 = l;  
    Lista *p2=inicializa();
	Lista *aux=inicializa();
    Lista *a=inicializa();
	for (p1 = l; p1 != NULL; p1 = p1->prox){
		aux=(insere(aux,p1->info)); //recebe invertida
    }
	Lista *primo = aux;
    for (p2 = aux; p2 != NULL; p2 = p2->prox){
        if (p2!=primo)
        {
            a=insere(a,p2->info);
        }
        
    }
    a=insere(a,primo->info);
	return a;
}



int main()
{
    Lista* l,*a;
    l=inicializa();
    l=insere(l,1);
    l=insere(l,2);
    l=insere(l,3);
    l=insere(l,4);
    l=insere(l,5);
    imprime(l);
    printf("\n\n");
    a=inicializa();
    a=problemaa(l);
    imprime(a);
    return 0;
}

