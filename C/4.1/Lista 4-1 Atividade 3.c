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

int igual(Pilha* p1,Pilha* p2){
    No* q1;
    No* q2;
    q1=p1->prim;
    q2=p2->prim;
    

    for (q1=p1->prim; q1!=NULL; q1=q1->prox)
		if (q1->info!=q2->info)
        {
            return 0;
        }else{
            q2 = q2->prox; 
        }
       
    if (q1==q2)
    {
        return 1;
    }   
}


main () {
	Pilha *p;
	p = cria();
	push(p, 4);
	push(p, 6);
	push(p, 8);

    Pilha *p1;
	p1 = cria();
	push(p1, 4);
	push(p1, 6);
	push(p1, 8);
    push(p1, 9);

    if (igual(p,p1)==1)
    {
        printf("igual");
    }else
    {
        printf("diferente");
    }    
}