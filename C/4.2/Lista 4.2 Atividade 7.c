#include <stdlib.h>
#include <stdio.h>


typedef struct lista{
    int info;
    struct lista* prox;
}Lista;

typedef struct no
{
    Lista* pont;
    struct no* prox;
}No;

typedef struct fila
{
    No* ini;
    No* fim;
}Fila;

Lista* inicializa(void){
    return NULL;
}

Lista* insereL (Lista* l, int valor){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox=l;
    return novo;
}

void mostra (Lista* lista){
    Lista *p;
    for (p = lista; p!=NULL; p = p->prox)
    {
        printf("%d\n",p->info);
    }
}

int vaziaL (Lista* lista){
    if (lista == NULL)
        return 1;
    else
        return 0;
}

Lista* retiraL(Lista* l, int v){
    Lista* ant = NULL;
    Lista* p = l;

    while (p != NULL && p->info != v)
    {
        ant = p;
        p = p->prox;
    }
    
    if (p == NULL)
    {
        return l;
    }
    
    if (ant == NULL)
    {
        l=p->prox;
    }
    else
    {
        ant->prox = p->prox;
    }
    free(p);
    return l;
}

void liberaL(Lista* l){
    Lista* p = l;
    while (p != NULL)
    {
        Lista* t = p->prox;
        free(p);
        p=t;
    }
}


Fila* cria(void){

    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

No* ins_fim(No* fim, Lista* lista){
    No* p = (No*) malloc(sizeof(No));
    p->pont = lista;
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

void insere(Fila* f,Lista* lista){

    f->fim = ins_fim(f->fim,lista);
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
    
    f->ini = ret_ini(f->ini);
    if (f->ini == NULL)
    {
        f->fim = NULL;
    }
    
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
        mostra(q->pont);
    }
}



int main (void)
{
	Fila* f = cria();
	Lista* l1 = inicializa();
    l1 = insereL(l1,10);
    l1 = insereL(l1,11);
    l1 = insereL(l1,12);
    insere(f,l1);
    l1 = insereL(l1,13);

    imprime(f);
}