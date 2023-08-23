#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    float info;
    struct no* prox;
}No;

typedef struct fila
{
    No* ini;
    No* fim;
}Fila;

Fila* cria(void){

    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

No* ins_fim(No* fim, float v){
    No* p = (No*) malloc(sizeof(No));
    p->info = v;
    p->prox = NULL;
    if (fim != NULL)
    {
        fim->prox = p;
    }
    return p;
}

No* ret_ini(No* ini){
    No* p=ini->prox;
    free(ini);
    return p;
}

void insere(Fila* f,float v){

    f->fim = ins_fim(f->fim,v);
    if (f->ini == NULL)
    {
        f->ini = f->fim;
    }
}

int vazia (Fila* f)
{
	return (f->ini==NULL);
}

float retira (Fila* f){
    float v;
    if (vazia(f))
    {
        printf("fila vazia\n");
        exit(1);
    }
    v=f->ini->info;
    f->ini = ret_ini(f->ini);
    if (f->ini == NULL)
    {
        f->fim = NULL;
    }
    return v;
}

void libera (Fila* f){
    No* q = f->ini;
    while (q!=NULL)
    {
        No* t = q->prox;
        free(q);
        q=t;
    }
    free(f);
}

void imprime (Fila* f){
    No* q;
    for (q = f->ini; q!=NULL; q = q->prox)
    {
        printf("%f\n",q->info);
    }
}

Fila* intercala(Fila* f1,Fila* f2) {
    Fila* f3 = cria();
    No* q1 = f1->ini;
    No* q2 = f2->ini;

    while (q1!= NULL && q2!= NULL)
    {
        insere(f3,q1->info);
        q1=q1->prox;
        insere(f3,q2->info);
        q2=q2->prox;   
    }
    return f3;

}

int main (void)
{
	Fila* f = cria();
	insere(f,1);
    insere(f,3);
    insere(f,5);
    Fila* f2 = cria();
    insere(f2,2);
    insere(f2,4);
    insere(f2,6);
    insere(f2,7);
    Fila* f3 = cria();
    f3 = intercala(f,f2);
    imprime(f3);
	return 0;
}