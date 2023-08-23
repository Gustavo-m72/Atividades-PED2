#include <stdio.h>
#include <stdlib.h>

typedef struct listad
{
    int valor;
    struct listad* ant;
    struct listad* prox; 
}ListaDupla;



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
/*
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
}*/

int soma(ListaDupla* l1,ListaDupla* l2){
    int s=0,s1=0;
    ListaDupla* p=l1,*p2=l2;
    for (p = l1; p != NULL; p=p->prox)
        s+=p->valor;
    
    for (p2 = l2; p2 != NULL; p2=p2->prox)
        s1+=p2->valor;

s=s+s1;
    printf("\n\nSOMA: %d\n",s);
    return s;
}

ListaDupla* intersecao(ListaDupla* l1, ListaDupla* l2){
    ListaDupla* l3=inicializa(),*q1=l1,*q2=l2;
   
    while (1)
    {
        if (q1->valor==q2->valor)
        {
        l3=InsereDupla(l3,q1->valor);
        }
        q1 = q1->prox;
        q2 = q2->prox;

        if (q1==NULL&&q2==NULL)
        {
            break;
        }
    }
    printf("\n\nINTERSECAO:\n");
    ImprimeDupla(l3);
    return l3;
}

ListaDupla* diferenca(ListaDupla* l1,ListaDupla* l2){
    ListaDupla* q1=l1,*q2=l2,*l3=inicializa();
        
        while (1)
    {
        if (q1->valor!=q2->valor)
        {
        l3=InsereDupla(l3,q1->valor);
        }
        q1 = q1->prox;
        q2 = q2->prox;

        if (q1==NULL&&q2==NULL)
        {
            break;
        }
    }
    printf("\n\nDIFERENCA:\n");
    ImprimeDupla(l3);
    return l3;
}

ListaDupla* uniao(ListaDupla* l1, ListaDupla* l2){
    ListaDupla* l3=inicializa(),*q1=l1,*q2=l2;
   
    while (1)
    {
        if (q1!=NULL)
        {
        l3=InsereDupla(l3,q1->valor);
        q1 = q1->prox;
        }

        if (q2!=NULL)
        {
        l3=InsereDupla(l3,q2->valor);
        q2 = q2->prox;
        }

        if (q1==NULL&&q2==NULL)
        {
            break;
        }
    }
    printf("\n\nUNIAO:\n");
    ImprimeDupla(l3);
    return l3;
}
main()
{
    ListaDupla* l1=inicializa();
    l1=InsereDupla(l1,1);
    l1=InsereDupla(l1,2);
    l1=InsereDupla(l1,4);
    ImprimeDupla(l1);
    
    printf("\n\n");
    
    ListaDupla* l2=inicializa();
    l2=InsereDupla(l2,1);
    l2=InsereDupla(l2,3);
    l2=InsereDupla(l2,5);
    ImprimeDupla(l2);
    intersecao(l1,l2);
    diferenca(l1,l2);
    uniao(l1,l2);
    soma(l1,l2);
    
    printf("\n\n");

}