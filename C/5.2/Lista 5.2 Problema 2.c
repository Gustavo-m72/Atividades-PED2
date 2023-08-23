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

Lista* copia(Lista* l){
	Lista *p1 = l;  
    Lista *p2=inicializa();
	Lista *aux=inicializa();
    Lista *a=inicializa();
	for (p1 = l; p1 != NULL; p1 = p1->prox){
		aux=(insere(aux,p1->info)); //recebe invertida
    }
	Lista *primo = aux;
    for (aux; aux != NULL; aux = aux->prox)
    {
        p2=insere(p2,aux->info);
    }
    for (p1 = l; p1 != NULL; p1 = p1->prox){
		p1=(insere(aux,p2->info));
        p2=p2->prox;
    }
}
Lista* concaternar(Lista* l,Lista* p2){
    Lista *p1;
for (p1 = l; p1 != NULL; p1 = p1->prox){
		p1=(insere(p1,p2->info));
        p2=p2->prox;
    }
}

Lista* inverte (Lista* l1){
	Lista *p1 = l1;  
    Lista *p2=inicializa();
	Lista *aux=inicializa();
	for (p1 = l1; p1 != NULL; p1 = p1->prox){
		aux=(insere(aux,p1->info)); //recebe invertida
    }
	

	
	return aux;
}

Lista* intercala(Lista* l1, Lista* l2){
    Lista* l3=inicializa(),*q1=l1,*q2=l2;
    q1=inverte(q1);
    q2=inverte(q2);
    while (1)
    {
        if (q1!=NULL)
        {
        l3=insere(l3,q1->info);
        q1 = q1->prox;
        }

        if (q2!=NULL)
        {
        l3=insere(l3,q2->info);
        q2 = q2->prox;
        }

        if (q1==NULL&&q2==NULL)
        {
            break;
        }
    }
    return l3;
}

int main()
{
    Lista* l,*a,*l3;
    l=inicializa();
    l=insere(l,1);
    l=insere(l,3);
    l=insere(l,5);
    l=insere(l,7);
    l=insere(l,9);
    
    printf("\n\n");
    a=inicializa();
    a=insere(a,2);
    a=insere(a,4);
    a=insere(a,6);
    a=insere(a,8);
    a=insere(a,10);
    a=insere(a,11);
    
    printf("\n\n");
    l3=inicializa();
    l3=intercala(l,a);
    
    imprime(l3);
    return 0;
}