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
    f->fim = f->ini;
    return f;
}

No* ins_fim(Fila* f, int v){
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

No* inse_ini(Fila* f, int v){
    No* p = (No*) malloc(sizeof(No));
    No* aux = f->fim;
    
    p->info = v;
    p->prox = f->ini; 
    f->ini = p;
    aux->prox = f->ini;
    
    return p;
}

void FuraFila(Fila* f,int v){
    
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

void insere(Fila* f,int v){

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
    No* q=f->ini;
    do
    {
        printf("%d\n", q->info);
        q=q->prox;
    } while (q!=f->ini);
    
}

int buscaTrue(Fila* f,int x){
    
    No* q=f->ini;
    
    do
    {
       if (q->info!=x)
       {
           q=q->prox;
       }else
       {
            return 1;
       }
    } while (q!=f->ini);
    
    return 0;
}

No* busca(Fila* f,int x){
    
    No* q=f->ini;
    
    do
    {
       if (q->info!=x)
       {
           q=q->prox;
       }else
       {
            return q;
       }
    } while (q!=f->ini);
    
    return NULL;
}

int retirageral(Fila* f, int x){

    No* q=f->ini;
    No* aux=q;
    No* p=busca(f,x);
    printf("%d\n", p->info);
    
    if (p==NULL)
    {
        return 0;
    }
    
    
    while (1)
    {
       if (q->prox->info==x)
       {
           aux=q;
           break;
       }else{
           q=q->prox;
       }
    }
    //printf("%f\n", aux->info);
    if (f->ini->info==x)
    {
        retira(f);
        return 1;
    }
    if (f->fim->info==x)
    {
        ret_fim(f);
        return 1;
    }
    
    if (f->fim->info!=x&&f->ini->info!=x)
    {
        aux->prox=q->prox->prox;
        free(p);
        return 1;
    }
    
}


void sobrevivente(Fila* fila,int n){
    int k=n,i=0, vet[n],l=0;
    float aux;
    No* q=fila->ini;
    
    for (int m = 0; m < n; m++)
    {
        
        vet[m]=m+1;
        
    }
    

    while (1)
    {
        if (vet[l]!=0)
        {
           i++;
        }

        if (k==1&&vet[l]!=0)
        {
            printf("sobrevivente %d",vet[l]);
            break;
        }
        
        if (i==3&&k!=1)
        {
            if (vet[l]!=0)
            {
                printf("morreu %d \n",vet[l]);
                i=0;
                vet[l]=0;
                k--;
            }else{
                i=0;
            }
            
        }
        
        if (l==n-1)
        {
            l=0;
        }else{
            l++;
        }
        
    }
}  


int main (void)
{
    Fila* f;
    int n=10;
	f = cria();
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
   
    /*retirageral(f,10);
    retirageral(f,9);
    retirageral(f,8);
    retirageral(f,7);
    retirageral(f,6);
    retirageral(f,4);*/
    printf("\n\n");
    //imprime(f);
    //printf("%d\n", f->fim->prox->info);
    sobrevivente(f,10);
	//printf("%d",buscaTrue(f,5));
    
    return 0;
}