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

Fila* inverte(Fila* f) {
    No* q=f->ini;
    Fila* f2=cria();
    int i=0,n=0;
    for (q = f->ini; q!=NULL; q = q->prox)
    {
        n++;
    }
    float x[n];
    printf("%d\n",n);
    i=0;
    for (q = f->ini; q!=NULL; q = q->prox)
    {
        x[i]=q->info;
        i++;
    }
    for (i = n-1; i >=0; i--)
    {
        insere(f2,x[i]);
    }
    
    return f2;
}



int main (void)
{
	Fila* f = cria();
	insere(f,1);
    insere(f,2);
    insere(f,3);
    insere(f,4);
    insere(f,5);
    insere(f,6);
    insere(f,7);
    insere(f,8);
    insere(f,9);
    insere(f,10);
    sobrevivente(f,10);
    imprime(f);
    printf("\n\n\n");
    Fila* f2 = cria();
    f2=inverte(f);
    imprime(f2);
	return 0;
}