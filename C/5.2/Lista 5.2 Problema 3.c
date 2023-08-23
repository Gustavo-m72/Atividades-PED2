#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct lista
{
    char nome[40];
    char link[40];
    struct lista* prox;
}Lista;

Lista* inicializa (void){
    return NULL;
}

Lista* insere(Lista* l,char name[],char link[]){
    
    Lista* novo=(Lista*)malloc(sizeof(Lista));
    strcpy(novo->nome,name);
    strcpy(novo->link,link);
    novo->prox=l;
    return novo;
}
Lista* inserenofim(Lista* l,char name[],char link[]){
    Lista* novo=(Lista*)malloc(sizeof(Lista));
    strcpy(novo->nome,name);
    strcpy(novo->link,link);
    novo->prox=l;
    return novo;
}

void mostra(Lista* l){
    Lista* p=l;
        printf("\n\nencontrada:");
        printf("\nnome: %s",p->nome);
        printf("\nlink: %s",p->link);
}

void imprime(Lista* l){
    Lista* p;
    
    for (p = l;p != NULL; p = p->prox)
    {
        printf("\n\nnome: %s",p->nome);
        printf("\nlink: %s",p->link);
       
    }
}

Lista* retira(Lista* l, char name[]){
    Lista* ant = NULL;
    Lista* p = l;
    while (p!= NULL && p->nome != name)
    {
        ant = p;
        p=p->prox;
    }

    if (p==NULL)
    {
        return l;
    }

    if (ant==NULL)
    {
        l= p->prox;
    }else
    {
        ant->prox=p->prox;
    }
    free(p);
    return l;
}

void libera(Lista* l){
    Lista* p=l;
    while (p!=NULL)
    {
        Lista* t=p->prox;
        free(p);
        p=t;
    }
}

void busca(Lista* l, char name[]){
    Lista* p;
    
    
    


    for (p = l;p != NULL; p = p->prox)
    {
        if (strcmp(p->nome,name)==0)
        {
            mostra(p);
            l=retira(l,p->nome);
            p->prox=NULL;
            l->prox=p;
            break;
        }
    }
}

int main()
{
    Lista* musicas;
    musicas=inicializa();
   
    musicas=insere(musicas,"MeDeMotivo","https://youtu.be/PDQrcz4KUKs");
    musicas=insere(musicas,"AsVezesNunca","https://youtu.be/Al6UXiiCoxw");
    musicas=insere(musicas,"NaquelaMesa","https://youtu.be/8YaOWBvx_Ms");
    
   
    
    
    //busca(l,"musica1");
    busca(musicas,"MeDeMotivo");
    
    
    printf("\n\n");
    imprime(musicas);
    return 0;
}