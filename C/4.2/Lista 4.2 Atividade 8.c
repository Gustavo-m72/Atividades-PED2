#include <stdio.h>
#include <math.h>
#include  <stdlib.h>

//FILA ENCADEADA
struct noenc
{
    float info;
    struct noenc* ant;
    struct noenc* prox;
};

typedef struct noenc NoEnc;

struct filaenc
{
    NoEnc* ini;
    NoEnc* fim; 
};

typedef struct filaenc FilaEnc;

NoEnc* ins_iniEnc (NoEnc* ini, float v){
    NoEnc* p = (NoEnc*) malloc(sizeof(NoEnc));
    p->info= v;
    p->prox = ini;
    p->ant = NULL;
    if (ini!= NULL)
    {
        ini->ant = p;
    }
    return p;
}

NoEnc* ins_fimEnc (NoEnc* fim, float v){
    NoEnc* p = (NoEnc*) malloc(sizeof(NoEnc));
    p->info = v;
    p->prox = NULL;
    p->ant = fim;
    if (fim != NULL)
    {
        fim->prox = p;
    }
    return p;
}

NoEnc* ret_iniEnc (NoEnc* ini){

    NoEnc* p = ini->prox;
    if (p != NULL)
    {
        p->ant=NULL;
    }
    free(ini);
    return p;
}

NoEnc* ret_fimEnc (NoEnc* fim){
    NoEnc* p = fim->ant;
    if (p != NULL)
    {
        p->prox = NULL;
    }
    free(fim);
    return p;
}

FilaEnc* cria (void){
    FilaEnc* f = (FilaEnc*) malloc(sizeof(FilaEnc));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

void InsEsq(FilaEnc* f, float v){
    f->ini = ins_iniEnc(f->ini,v);
    if (f->fim == NULL)
    {
        f->fim = f->ini;
    }
}

void InsDir (FilaEnc* f,float v){
    f->fim = ins_fimEnc(f->fim,v);
    if (f->ini == NULL)
    {
        f->ini = f->fim;
    }
}

int vazia (FilaEnc* f){
    return (f->ini == NULL);
}

float RetEsq(FilaEnc* f){
    float v;
    if (vazia(f))
    {
        printf("UNDERFLOW. \n\n");
        exit(1);
    }
    v=f->ini->info;
    f->ini = ret_iniEnc(f->ini);
    if (f->ini == NULL)
    {
        f->fim = NULL;
    }
    return v;
}

float RetDir(FilaEnc* f){
    float v;
    if (vazia(f))
    {
        printf("UNDERFLOW.");
        exit(1);
    }
    v = f->fim->info;
    f->fim = ret_fimEnc(f->fim);
    if (f->fim == NULL)
    {
        f->fim = NULL;
    }
    return v;
}

void imprime (FilaEnc* f){
    NoEnc* q=f->ini;
    for (q = f->ini; q!=NULL; q = q->prox)
    {
        printf("%f ",q->info);
    }
}


//FILA SIMPLES

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

Fila* criaS(void){

    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    
    return f;
}

No* ins_fimS(Fila* f, float v){
    No* p = (No*) malloc(sizeof(No));
    No* fim = f->fim;
    p->info = v;
    p->prox = NULL;
    if (fim != NULL)
    {
        fim->prox = p;
    }
    return p;
}

No* inse_iniS(Fila* f, float v){
    No* p = (No*) malloc(sizeof(No));
    
    
    p->info = v;
    p->prox = f->ini; 
    f->ini = p;
    
    
    return p;
}

void InsEsqS(Fila* f,float v){
    
    f->ini = inse_iniS(f,v);
    
}

No* ret_iniS(No* ini){
    No* p=ini->prox;
    free(ini);
    return p;
}

int vaziaS (Fila* f);

void RetDirS(Fila* f){
    
    if (vaziaS(f))
    {
        printf("OVERFLOW.\n");
        exit(1);
    }
    
    No* q=f->ini;
    
    No* ant = q;
   do
    {
        
        ant = q;
        q=q->prox;
        
        
        
    } while (q!=f->fim);
    
    free(f->fim);
    f->fim = ant;
    f->fim->prox=NULL;

    
}
int vaziaS (Fila* f);
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

void insDirS(Fila* f,float v){

    f->fim = ins_fimS(f,v);
    if (f->ini == NULL)
    {
        f->ini = f->fim;
    }
}

int vaziaS (Fila* f)
{
	return (f->ini==NULL);
}

float RetEsqS (Fila* f){
    float v;
    if (vaziaS(f))
    {
        printf("fila vazia\n");
        exit(1);
    }
    v=f->ini->info;
    f->ini = ret_iniS(f->ini);
    if (f->ini == NULL)
    {
        f->fim = NULL;
    }
    return v;
}

void imprimeS (Fila* f){
    No* q=f->ini;
    for (q = f->ini; q!=NULL; q = q->prox)
    {
        printf("%f ",q->info);
    }
    
}

int main (void)
{
    printf("SIMPLES: \n");
    
    Fila* f;
	f = criaS();
	insDirS(f,1);
    insDirS(f,2);
    insDirS(f,3);
    InsEsqS(f,4);
    imprimeS(f);
    printf("\n\n");
    RetEsqS(f);
    RetDirS(f);
    imprimeS(f);
    
    printf("\n\n");

    printf("ENCADEADA: \n");
    FilaEnc* fi = cria();
    InsDir (fi,1);
    InsDir (fi, 2);
    InsDir (fi, 3);
    InsDir (fi, 4);
    InsDir (fi, 5);
    InsEsq(fi,6);
    InsEsq(fi,7);
    InsEsq(fi,8);
    imprime(fi);
	
    RetEsq(fi);
    printf("\n\n");
    imprime(fi);
    RetDir(fi);
    printf("\n\n");
    imprime(fi);
    return 0;
}