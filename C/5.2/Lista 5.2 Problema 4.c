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

ListaDupla* InsereInicio(ListaDupla* lista, int valor){
    ListaDupla* novo = (ListaDupla*) malloc(sizeof(ListaDupla));
    ListaDupla* prim=lista;
    
    novo->valor = valor;
    
    //lista->ant=novo;
    
    if (lista==NULL)
    {
        novo->ant=novo;
        novo->prox=novo;
        return novo;
    } 
   
    novo->prox = lista;
    novo->ant=lista->ant;
    lista->ant->prox=novo;
    lista->ant=novo;
    lista=novo;
    
    return novo;
}

/*
ListaDupla* InsereDupla(ListaDupla* lista, int valor){
    ListaDupla* novo = (ListaDupla*) malloc(sizeof(ListaDupla));
    ListaDupla* prim=lista;
    
    novo->valor = valor;
    novo->prox = lista;
    //lista->ant=novo;
    while (1)
    {
       if (prim->prox!=lista)
       {
           prim=prim->prox;
       }else{
            prim->prox=novo;
            break;
        }
    }
    
    if (lista==prim)
    {
        lista->ant==novo;
        printf("funcionou\n\n");
    } 
    novo->ant=prim;
    //lista->ant=novo;
    if (lista!=prim)
    {
        lista->ant=novo;
    }
    
    return novo;
}*/

ListaDupla* inserefim(ListaDupla* lista, int valor){
    ListaDupla* novo=(ListaDupla*)malloc(sizeof(ListaDupla));
    novo->valor=valor;

    if (lista==NULL)
    {
        novo->ant=novo;
        novo->prox=novo;
        return novo;
    }
    
    novo->prox=lista;
    lista->ant->prox=novo;
    novo->ant=lista->ant;
    lista->ant=novo;
    return lista;

}

ListaDupla* ImprimeDupla(ListaDupla* lista){
    ListaDupla* p=lista;
    
        do
		{
			printf("%d, ",p->valor);
			p = p->prox;
		} while (p!=lista);
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
    ListaDupla* prim=lista;
    
    /*
    while (1)
    {
       if (p->valor==valor)
       {
           break;
       }else{
            p=p->prox;
        }
    }*/
    
    while (1)
    {
       if (prim->prox!=lista)
       {
           prim=prim->prox;
       }else{
            break;
        }
    }
    //printf("%d\n\n",prim->valor);

    if (p == NULL)
    {
        return lista;
    }
    
    if (prim == p)
    {
        prim->ant->prox=lista;
        //printf("%d",prim->ant->valor);
        prim = prim->ant;
        //printf("\n\n%d",prim->valor);
        lista->ant=prim;
    }
    //printf("%d\n\n",prim->valor);
    if (lista == p)
    {
        p->ant=prim;
        lista = p->prox;
        //printf("%d\n\n",prim->valor);
    }
    if(p!=lista&&p!=prim)
    {
        p->ant->prox = p->prox;
        //printf("%d\n\n",prim->valor);
    }
    if (p!=lista&&p!=prim)
    {
        p->prox->ant = p->ant;
        //printf("%d\n\n",prim->valor);
    }
    free(p);
    //printf("%d\n\n",prim->valor);
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
}
*/

ListaDupla* copiar(ListaDupla* lista){
    ListaDupla* p=lista;
    ListaDupla* p1=inicializa();
        do
		{
			p1=inserefim(p1,p->valor);
			p = p->prox;
		} while (p!=lista);
    return p1;
}

ListaDupla* intercala(ListaDupla* l1, ListaDupla* l2){
    ListaDupla* l3=inicializa(),*q1=l1,*q2=l2;
    //q1=inverte(q1);
    //q2=inverte(q2);
   l3=inserefim(l3,q1->valor);
   l3=inserefim(l3,q2->valor);
   q1 = q1->prox;
   q2 = q2->prox;
    while (1)
    {
        if (q1!=l1)
        {
        l3=inserefim(l3,q1->valor);
        q1 = q1->prox;
        }

        if (q2!=l2)
        {
        l3=inserefim(l3,q2->valor);
        q2 = q2->prox;
        }

        if (q1==l1&&q2==l2)
        {
            break;
        }
    }
    return l3;
}

ListaDupla* concatenar(ListaDupla* l1){
    ListaDupla* l3=inicializa(),*q1=l1;
    //q1=inverte(q1);
    //q2=inverte(q2);
   l3=inserefim(l3,q1->valor);
   q1 = q1->prox;
  
    while (1)
    {
        if (q1!=l1)
        {
        l3=inserefim(l3,q1->valor);
        q1 = q1->prox;
        }

        if (q1==l1)
        {
            break;
        }
    }
    return l3;
}




main()
{
    ListaDupla* l1=inicializa();
    ListaDupla* l2=inicializa();
    ListaDupla* l3=inicializa();
    l1=inserefim(l1,1);
    
    l1=inserefim(l1,2);
    //printf("\n\n%d",l1->prox->ant->valor);
    l1=inserefim(l1,4);
    l1=inserefim(l1,6);
    ImprimeDupla(l1);
    l2=copiar(l1);
    l1=RetiraDupla(l1,6);
    printf("\n\n");
    ImprimeDupla(l2);
    printf("\n\n");
    //l3=intercala(l1,l2);
    //ImprimeDupla(l3);
    //l1=RetiraDupla(l1,6);
   
    l3=concatenar(l1);
    printf("\n\n");
    ImprimeDupla(l3);
    //ImprimeDupla(l1);
    
}