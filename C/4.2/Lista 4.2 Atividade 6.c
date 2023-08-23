#include <stdlib.h>
#include <stdio.h>


typedef struct nop
{
    float info;
    struct nop* prox;
}Nop;

typedef struct pilha
{
    Nop* prim;
}Pilha;
//FILA de pilha
typedef struct no
{
    Pilha* info;
    struct no* prox;
}No;

typedef struct fila
{
    No* ini;
    No* fim;
}Fila;

/*
// PILHA DE FILAS
typedef struct nosmoscada
{
    float info;
    struct no* prox;
}Nos;

typedef struct fila
{
    Nos* ini;
    Nos* fim;
}FilasP;

typedef struct nopF
{
    FilasP* info;
    struct nopF* prox;
}NoPF;

typedef struct pilhaPF
{
    NoPF* prim;
}PilhaPF;
*/

/*No* ins_fim(No* fim, float v){
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
}*/

//PILHA



Pilha* criaP (void)
{
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

Nop* ins_iniP (No* l, float v)
{
	Nop* p = (Nop*) malloc(sizeof(No));
	p->info = v;
	p->prox = l;
	return p;
}

Nop* ret_iniP (Nop* l)
{
	Nop* p = l->prox;
	free(l);
	return p;
}

void push (Pilha* p, float v)
{
	p->prim = ins_iniP(p->prim,v);
}

int vaziaP (Pilha* p);

float pop (Pilha* p)
{
	float v;
	if (vaziaP(p)) {
		printf("Pilha vazia.\n");
		exit(1); 
	}
	v = p->prim->info;
	p->prim = ret_iniP(p->prim);
	return v;
}

int vaziaP (Pilha* p)
{
	return (p->prim==NULL);
}

void liberaP (Pilha* p)
{
	Nop* q = p->prim;
	while (q!=NULL) {
		Nop* t = q->prox;
		free(q);
		q = t;
	}
	free(p);
}

void imprimeP (Pilha* p)
{
	Nop* q;
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

/*Fila* inversa(Fila* f){
    Pilha* p=criaP();
    Nop* q = p->prim;
    No* x=f->ini;
    for (x = f->ini; x!=NULL; x = x->prox)
    {
        push(p,x->info);
    }
    printf("\nInversa:");
    imprimeP(p);
}*/
// fila de pilhas
Fila* cria(void){

    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

No* ins_fim(No* fim, float v){
    No* p = (No*) malloc(sizeof(No));
    p->info = criaP();
    int x;
    while (1){
    printf("\n op!=1: ");
    scanf("%d",&x);
        if (x!=1){
            printf("\n scan: ");
            scanf("%f",&v);
            push(p->info,v);
        }else break;
    }
    p->prox = NULL;
    if (fim != NULL)
    {
        fim->prox = p;
    }
    return p;
}

void insere(Fila* f){
    float v;
    f->fim = ins_fim(f->fim,v);
    if (f->ini == NULL)
    {
        f->ini = f->fim;
    }
}

void imprime (Fila* f){
    No* q=f->ini;
    for (q = f->ini; q!=NULL; q = q->prox)
    {
        imprimeP(q->info);
    }
}

//PILHA DE FILAS
/*PilhaPF* criaPdeF (void)
{
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

FilasP* criaPF(void){

    FilasP* f = (Fila*)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

Nos* ins_fimPF(No* fim, float v){
    Nos* p = (Nos*) malloc(sizeof(Nos));
    p->info = v;
    p->prox = NULL;
    if (fim != NULL)
    {
        fim->prox = p;
    }
    return p;
}*/
/*
void inserePF(FilasP* f,float v){

    Nos* p = (No*) malloc(sizeof(No));
    p->info = v;
    p->prox = NULL;
    if (fim != NULL)
    {
        fim->prox = p;
    }
    return p;
}

NoPF* ins_iniPFP (NoPF* fp, float v)
{
	
    NoPF* p =(NoPF*) malloc(sizeof(NoPF));
    p->info = criaPF();
    p->info = ins_fimPF(p->info, v);
    p->prox = fp;
    
    return p;
}

void pushPF (PilhaPF* p, float v)
{
	p->prim = ins_iniPFP(p->prim,v);
}*/

int main (void)
{
	Fila* f = cria();
	insere(f);
    insere(f);
    //PilhaPF* p= criaPdeF();
    
    printf("\n\n\n");
    imprime(f);
    

    
    
    
	return 0;
}