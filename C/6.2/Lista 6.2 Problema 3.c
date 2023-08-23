#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    float info;
    struct no* prox;
}No;

typedef struct pilha
{
    No* prim;
}Pilha;

Pilha* cria (void)
{
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

No* ins_ini (No* l, float v)
{
	No* p = (No*) malloc(sizeof(No));
	p->info = v;
	p->prox = l;
	return p;
}

No* ret_ini (No* l)
{
	No* p = l->prox;
	free(l);
	return p;
}

void push (Pilha* p, float v)
{
	p->prim = ins_ini(p->prim,v);
}

int vazia (Pilha* p);

float pop (Pilha* p)
{
	float v;
	if (vazia(p)) {
		printf("Pilha vazia.\n");
		exit(1); /* aborta programa */
	}
	v = p->prim->info;
	p->prim = ret_ini(p->prim);
	return v;
}

int vazia (Pilha* p)
{
	return (p->prim==NULL);
}

void libera (Pilha* p)
{
	No* q = p->prim;
	while (q!=NULL) {
		No* t = q->prox;
		free(q);
		q = t;
	}
	free(p);
}

void imprime (Pilha* p)
{
	No* q;
	printf("\nImprime:\n");
	for (q=p->prim; q!=NULL; q=q->prox)
		printf("%f\n",q->info);
}

Pilha* copiavetor(Pilha*p,float vet[],int tam){

    for (int i = 0; i < tam; i++)
    {
        push(p,vet[i]);
    }
}

No* Busca(Pilha* pilha,float x){
    No* q;
	//printf("\nImprime:\n");
	for (q=pilha->prim; q!=NULL; q=q->prox)
		if (q->info==x)
        {
            return q;
        }
    
    return NULL;
}

Pilha* Quest(Pilha* p,float x){
    No* q=p->prim;
    No* k=Busca(p,x);
    No* aux;
    
    if (k==NULL)
    {
        printf("N A O a c h e i\n");
        return p;
    }
    

    if (p->prim->info==x)
    {
        pop(p);
        return p;
    }
    
    for (q=p->prim; q!=k; q=q->prox)
		aux=q;
    aux->prox=k->prox;
    return p;
    
}

main () {
	Pilha *p;
	p = cria();
	

    float vet[] = {1,2,3,4,5,6,7,8};
    int tam = sizeof(vet)/sizeof(vet[0]);

    copiavetor(p,vet,tam);

    imprime(p);
    printf("\n\n");
    Quest(p,4); 
    Quest(p,2);
    Quest(p,7); 
    Quest(p,4);    
    imprime(p);   
}