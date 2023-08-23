#include <stdio.h>
#include <stdlib.h>

typedef struct listad
{
    int valor;
    struct listad* ant;
    struct listad* prox; 
}ListaDupla;

typedef struct listac
{
    int valor;
    struct listac* prox; 
}ListaCircular;

ListaDupla* inicializa(){

    return NULL;
}

ListaDupla* InsereDupla(ListaDupla* lista, int valor){
    ListaDupla* novo = (ListaDupla*) malloc(sizeof(ListaDupla));
    novo->valor = valor;
    novo->prox = lista;
    novo->ant = NULL;
    if (lista != NULL)
    {
        lista->ant=novo;
    }
    return novo;
}

ListaDupla* ImprimeDupla(ListaDupla* lista){
    ListaDupla* p=lista;
    
    for (p = lista; p != NULL; p=p->prox)
    {
        printf("%d  ",p->valor);
    }
}

int DuplaVazia (ListaDupla* lista){
    if (lista == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

ListaDupla* BuscaDupla(ListaDupla* lista, int valor){
    ListaDupla* p = lista;

    for (p = lista; p != NULL; p=p->prox)
    {
        if (p->valor==valor)
            return  p;
    }
    return NULL;
}

ListaDupla* RetiraDupla(ListaDupla* lista, int valor){
    ListaDupla* p = BuscaDupla(lista,valor);

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
}

void LiberaDupla(ListaDupla* lista){
    ListaDupla* p = lista;
    
    while (p!=NULL)
    {
        ListaDupla* t = p->prox;
        free(p);
        p=t;
    }
}

ListaDupla* InsereDuplaOrdenada(ListaDupla* lista, int valor){
    
    ListaDupla* novo = inicializa(); 
    novo = InsereDupla(novo,valor);
    ListaDupla* p = lista;
    ListaDupla* ant = NULL;

    while (p!= NULL && p->valor<                                                                                                                                                                                                                                                                            valor)
    {
        ant = p;
        p = p->prox;
    }
    
    if (ant == NULL)
    {
        novo->prox = lista;
        novo->ant = NULL;
        lista = novo;
    }
    else
    {
        novo->prox = ant->prox;
        ant->prox=novo;
        ant->prox->ant = novo;
        
    }
    return lista;
}

main()
{
    ListaDupla* l1=inicializa();
    l1=InsereDupla(l1,1);
    l1=InsereDupla(l1,2);
    l1=InsereDupla(l1,4);
    ImprimeDupla(l1);
    l1 = RetiraDupla(l1,2); 
    ImprimeDupla(l1);
    printf("\n\n");
    l1 = InsereDuplaOrdenada(l1,2);//porque vem antes de 4 e não de 1???
    l1 = InsereDuplaOrdenada(l1,1);
    l1 = InsereDuplaOrdenada(l1,3);
    l1 = InsereDuplaOrdenada(l1,5);
    l1 = InsereDuplaOrdenada(l1,4);
    l1 = InsereDuplaOrdenada(l1,6);
    l1 = InsereDuplaOrdenada(l1,7);
    l1 = InsereDuplaOrdenada(l1,8);
    l1 = InsereDuplaOrdenada(l1,9);
    l1 = InsereDuplaOrdenada(l1,10);
    
    ImprimeDupla(l1);
}
