#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int info;
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

No* ins_fim(No* fim, int v){
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

void insere(Fila* f,int v){

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

int retira (Fila* f){
    int v;
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
        printf("%d ",q->info);
        if (q->prox!=NULL)
        printf("* ");
    }
}

Fila* ordena(Fila* f);

Fila* fatorprimo(int x){
    
    Fila* f2 = cria();
    Fila* aux= cria();
    while (x!=1)
    {
        for (int i = 2; i <= x;)
        {
            if (x % i == 0)
            {
                x = x/i;
                insere(f2,i);
                
            }else{
                i++;
            }
        }
    }
    aux = ordena(f2);
    return aux;
}

Fila* ordena(Fila* f){
    No* q=f->ini;
    Fila* f2=cria();
    int i=0,n=0,aux=0;
    for (q = f->ini; q!=NULL; q = q->prox)
    {
        n++;
    }
    int x[n];
    
    i=0;
    for (q = f->ini; q!=NULL; q = q->prox)
    {
        x[i]=q->info;
        i++;
    }
    for (i = 0; i <n; i++)
    {
        for (int j=i+1; j < n; j++)
    {
        

        if (x[j]>x[i])
        {
            aux = x[i];
            x[i] = x[j];
            x[j] = aux;
        }
    }
    }
    for (i = 0; i < n; i++)
    {
        insere(f2,x[i]);
    }
    return f2;

}

int main (void)
{
	Fila* f = cria();
	f = fatorprimo(3960);
    imprime(f);
}