#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */

struct lista {
		int info;
		struct lista* prox;
	};

typedef struct lista Lista;

/* fun��o de inicializa��o: retorna uma lista vazia */
Lista* inicializa (void)
{
	return NULL;
}

/* fun��o imprime: imprime valores dos elementos */
void imprime (Lista* l)
{
	Lista* p; /* vari�vel auxiliar para percorrer a lista */
	
	for (p = l; p != NULL; p = p->prox)
		printf("info = %d\n", p->info);
	puts("");
}

/* fun��o vazia: retorna 1 se vazia ou 0 se n�o vazia */
int vazia (Lista* l)
{
	if (l == NULL)
		return 1;
	else
		return 0;
}

/* fun��o busca: busca um elemento na lista */
Lista* busca (Lista* l, int v)
{
	Lista* p;
	
	for (p=l; p!=NULL; p=p->prox)
		if (p->info == v)
			return p;
	return NULL; /* n�o achou o elemento */
}

/* fun��o retira: retira elemento da lista */
Lista* retira (Lista* l, int v) {
	Lista* ant = NULL; /* ponteiro para elemento anterior */
	Lista* p = l; /* ponteiro para percorrer a lista*/

	/* procura elemento na lista, guardando anterior */
	while (p != NULL && p->info != v) {
		ant = p;
		p = p->prox;
	}
	
	/* verifica se achou elemento */
	if (p == NULL)
		return l; /* n�o achou: retorna lista original */
	/* retira elemento */
	if (ant == NULL) {
		/* retira elemento do inicio */
		l = p->prox;
	}	
	else {
		/* retira elemento do meio da lista */
		ant->prox = p->prox;
	}
	free(p);
	return l;
}

void libera (Lista* l)
{
	Lista* p = l;

	while (p != NULL) {
		Lista* t = p->prox; /* guarda refer�ncia para o pr�ximo elemento */
	
		free(p); /* libera a mem�ria apontada por p */
		p = t; /* faz p apontar para o pr�ximo */
	}
}

/* fun��o auxiliar: cria e inicializa um n� */
Lista* cria (int v)
{
	Lista* p = (Lista*) malloc(sizeof(Lista));
	
	p->info = v;
	return p;
}

/* fun��o insere_ordenado: insere elemento em ordem */
Lista* insere_ordenado (Lista* l, int v)
{
	Lista* novo = cria(v); /* cria novo n� */
	Lista* ant = NULL; /* ponteiro para elemento anterior */
	Lista* p = l; /* ponteiro para percorrer a lista*/

	/* procura posi��o de inser��o */
	while (p != NULL && p->info < v) {
		ant = p;
		p = p->prox;
	}
	
	/* insere elemento */
	if (ant == NULL) { /* insere elemento no in�cio */
		novo->prox = l;
		l = novo;
	}
	else { /* insere elemento no meio da lista */
		novo->prox = ant->prox;
		ant->prox = novo;
	}
	return l;
}

Lista* intercala(Lista* l1, Lista* l2){
    Lista* l3=inicializa(),*q1=l1,*q2=l2;
    //q1=inverte(q1);
    //q2=inverte(q2);
    while (1)
    {
        if (q1!=NULL)
        {
        l3=insere_ordenado(l3,q1->info);
        q1 = q1->prox;
        }

        if (q2!=NULL)
        {
        l3=insere_ordenado(l3,q2->info);
        q2 = q2->prox;
        }

        if (q1==NULL&&q2==NULL)
        {
            break;
        }
    }
    return l3;
}

int main (void) {
	Lista* l,*l2,*l3; /* declara uma lista n�o iniciada */
	l = inicializa(); /* inicia lista vazia */
	l = insere_ordenado(l, 1); /* insere na lista o elemento 23 */
	l = insere_ordenado(l, 2); /* insere na lista o elemento 45 */
	l = insere_ordenado(l, 4); /* insere na lista o elemento 56 */
	l = insere_ordenado(l, 3); /* insere na lista o elemento 78 */
	l2 = inicializa(); /* inicia lista vazia */
	l2 = insere_ordenado(l2, 5); /* insere na lista o elemento 23 */
	l2 = insere_ordenado(l2, 7); /* insere na lista o elemento 45 */
	l2 = insere_ordenado(l2, 6); /* insere na lista o elemento 56 */
	l2 = insere_ordenado(l2, 8); /* insere na lista o elemento 78 */
    l3 = intercala(l,l2);
    imprime(l3);
	return 0;
}