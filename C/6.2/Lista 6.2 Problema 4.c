#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct no
{
    float info;
    char caracteristica[50];
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

No* ins_fim(No* fim, float v,char caract[]){
    No* p = (No*) malloc(sizeof(No));
    p->info = v;
    strcpy(p->caracteristica,caract);
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

void insere(Fila* f,float v,char caract[]){

    f->fim = ins_fim(f->fim,v,caract);
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
    char nome[50];
    if (vazia(f))
    {
        printf("fila vazia\n");
        exit(1);
    }
    v=f->ini->info;
    strcpy(nome,f->ini->caracteristica);
    f->ini = ret_ini(f->ini);
    if (f->ini == NULL)
    {
        f->fim = NULL;
    }
    printf("codigo da aeronave %f\n",v);
    printf("nome da aeronave %s\n",nome);
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
        printf("CODIGO %f CARACTERISTICA %s\n",q->info,q->caracteristica);
        printf("\n");
    }
}



int main (void)
{
	Fila* FilaDeDecolagem = cria();
	insere(FilaDeDecolagem,2551,"boing");
    insere(FilaDeDecolagem,2552,"Super Tucano Bandeira do Brasil");
    insere(FilaDeDecolagem,2553,"A10 ThunderBolt vermelho e preto");
    insere(FilaDeDecolagem,2554,"F5 Superhornet");
    //imprime(FilaDeDecolagem);
    retira(FilaDeDecolagem);
    Fila* FilaDeEspera = cria();
   
    
    
    
	return 0;
}