#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int info;
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

int pop (Pilha* p)
{
	int v;
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
		printf("%d\n",q->info);
}

Pilha* TPilha(Pilha*p,int vet[],int tam){

     

    for (int i = 0; i < tam; i++)
    {
        if (vet[i] % 2 == 0)
        {
            push(p,vet[i]);
        }else
        {
            pop(p);
        }
    }
}

Pilha* copiavetor(Pilha*p,int vet[],int tam){

    for (int i = 0; i < tam; i++)
    {
        push(p,vet[i]);
    }
}

main () {
	Pilha *p;
	p = cria();
	

    int vet[] = {2,4,6,8,10,12,13,14,15};
    int tam = sizeof(vet)/sizeof(vet[0]);

    TPilha(p,vet,tam);

    imprime(p);
    
}