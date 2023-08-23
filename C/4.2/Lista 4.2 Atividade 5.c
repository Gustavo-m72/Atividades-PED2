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
    f->fim = f->ini;
    return f;
}

No* ins_fim(Fila* f, float v){
    No* p = (No*) malloc(sizeof(No));
    No* fim = f->fim;
    p->info = v;
    p->prox = f->ini;
    if (fim != NULL)
    {
        fim->prox = p;
    }
    return p;
}

No* inse_ini(Fila* f, float v){
    No* p = (No*) malloc(sizeof(No));
    No* aux = f->fim;
    
    p->info = v;
    p->prox = f->ini; 
    f->ini = p;
    aux->prox = f->ini;
    
    return p;
}

void FuraFila(Fila* f,float v){
    
    f->ini = inse_ini(f,v);
    
}

No* ret_ini(No* ini){
    No* p=ini->prox;
    free(ini);
    return p;
}

void ret_fim(Fila* f){
    No* q=f->ini;
    
    No* aux = q;
   do
    {
        
        aux = q;
        q=q->prox;
        
        
        
    } while (q!=f->fim);
    free(f->fim);
    aux->prox = f->ini;
    f->fim = aux;

}
int vazia (Fila* f);
/*float RetiraFim (Fila* f){
    float v;
    if (vazia(f))
    {
        printf("fila vazia\n");
        exit(1);
    }
    v=f->fim->info;
    f->fim = ret_fim(f->fim);
    
    return v;
}*/

void insere(Fila* f,float v){

    f->fim = ins_fim(f,v);
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
    No* q=f->ini;
    do
    {
        printf("%f\n", q->info);
        q=q->prox;
    } while (q!=f->ini);
    
}

int main (void)
{
    Fila* f;
	f = cria();
	insere(f,1);
    insere(f,2);
    insere(f,3);
    FuraFila(f,4);
    imprime(f);
    FuraFila(f,5);
    FuraFila(f,6);
    FuraFila(f,7);
    printf("\n\n");
    imprime(f);
    ret_fim(f);
    printf("\n\n");
    imprime(f);
    FuraFila(f,8);
    FuraFila(f,9);
    FuraFila(f,10);
    printf("\n\n");
    ret_fim(f);
    imprime(f);
	
    
    return 0;
}