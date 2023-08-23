#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cidade
{
    char cidade[30];
    
    struct cidade* ant;
    struct cidade* prox; 
}Cidade;

typedef struct listad
{
    char rodovia[30];
    Cidade* cidades;
    struct listad* prox; 
}Lista;

Lista* inicializa(){

    return NULL;
}
Cidade* inicializaCidade(){

    return NULL;
}

Cidade* InsereCidade(Cidade* lista, char* valor){
    Cidade* novo = (Cidade*) malloc(sizeof(Cidade));
    strcpy(novo->cidade,valor);
    novo->prox = lista;
    novo->ant = NULL;
    if (lista != NULL)
    {
        lista->ant=novo;
    }
    return novo;
}

Lista* insere (Lista* l, char* rodovia,char* cidades)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->cidades=inicializaCidade();
	strcpy(novo->rodovia,rodovia);
	//printf("%s\n",novo->rodovia);
    novo->cidades=InsereCidade(novo->cidades,cidades);
    //printf("%s\n",novo->cidades->cidade);
    novo->prox = l;
	return novo;
}

Cidade* ImprimeCidade(Cidade* lista){
    Cidade* p=lista;
    for (p = lista; p != NULL; p=p->prox)
    { 
        printf("%s\n",p->cidade);
    }
}

Lista* Imprime(Lista* lista){
    Lista* p=lista;
    
    for (p = lista; p != NULL; p=p->prox)
    {
        printf("\n\nrodovia:%s Cidades:  \n",p->rodovia);
        ImprimeCidade(p->cidades);
    }
}

int DuplaVazia (Lista* lista){
    if (lista == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Lista* Busca(Lista* lista, char* valor){
    Lista* p = lista;

    for (p = lista; p != NULL; p=p->prox)
    {
        if (strcmp(p->rodovia,valor)==0)
            return  p;
    }
    return NULL;
}
/*
Cidade* RetiraDupla(Cidade* lista, int valor){
    Cidade* p = BuscaDupla(lista,valor);

    if (p == NULL)
    {
        return lista;
    }
    
    if (lista == p)
    {
        lista = p->prox;
    }
    else
    {
        p->ant->prox = p->prox;
    }
    if (p->prox != NULL)
    {
        p->prox->ant = p->ant;
    }
    free(p);

    return lista;
}*/

void LiberaDupla(Lista* lista){
    Lista* p = lista;
    
    while (p!=NULL)
    {
        Lista* t = p->prox;
        free(p);
        p=t;
    }
}

Lista* InsereNaRodovia(Lista* lista,char* rodovia,char* cidadenovo){
    Lista* p= (Lista*) malloc(sizeof(Lista));
    p=Busca(lista,rodovia);
    p->cidades=InsereCidade(p->cidades,cidadenovo);
    return p;
}

Cidade* BuscaCidade(Cidade* lista, char* valor){
    Cidade* p = lista;

    for (p = lista; p != NULL; p=p->prox)
    {
        if (strcmp(p->cidade,valor)==0)
            return  1;
    }
    return 0;
}

Lista* rodoviasCidade(Lista* lista, char* cidade){
    Lista* p=lista;
    for (p = lista; p != NULL; p=p->prox)
    {
        if (BuscaCidade(p->cidades,cidade)==1)
        {
            printf("\ncidade %s rodovia %s",cidade,p->rodovia);
        }
    }
}

Lista* cruzamento(Lista* lista,char* rodovia1,char* rodovia2){
    Lista* p1=Busca(lista,rodovia1);
    Lista* p2=Busca(lista,rodovia2);
    Cidade* l1=p1->cidades;
    Cidade* l2=p2->cidades;
    
    if (p1==NULL||p2==NULL)
    {
        return NULL;
    }
    printf("\n\nRodovia %s e rodovia %s se cruzam em:\n",rodovia1,rodovia2);
    
    
    for (l1 = p1->cidades; l1 != NULL; l1=l1->prox)
    {
        for(l2 = p2->cidades; l2 != NULL; l2=l2->prox)
            if (strcmp(l1->cidade,l2->cidade)==0)
            {
                printf("Cidade: %s\n",l1->cidade);
                return 1;
            }
    }
    return 0;
}

main()
{
    Lista* rodovia=inicializa();
    rodovia=insere(rodovia,"br151","jaboticaba");
    InsereNaRodovia(rodovia,"br151","boavista");
    InsereNaRodovia(rodovia,"br151","palmeira");
    InsereNaRodovia(rodovia,"br151","passofundo");
    InsereNaRodovia(rodovia,"br151","frederico");
    //Imprime(rodovia);
    rodovia=insere(rodovia,"rs123","alegrete");
    InsereNaRodovia(rodovia,"rs123","frederico");
    InsereNaRodovia(rodovia,"rs123","planalto");
    InsereNaRodovia(rodovia,"rs123","jacutinga");
    //printf("%s",rodovia->cidades->cidade);
    //printf("%s",rodovia->prox->cidades->cidade);
    Imprime(rodovia);

    //rodoviasCidade(rodovia,"frederico");
    cruzamento(rodovia,"br151","rs123");
}