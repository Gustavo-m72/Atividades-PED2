#include <stdio.h>
#include <stdlib.h>


struct arv {
	int info;
	struct arv* esq;
	struct arv* dir;
};
typedef struct arv Arv;

int raiz; 

Arv* init (void)
{
	return NULL;
}

void imprime (Arv* a)
{
	if (a != NULL) {
		imprime(a->esq);
		printf("%d\n",a->info);
		imprime(a->dir);
	}
}

Arv* busca (Arv* r, int v)
{
	if (r == NULL) return NULL;
	else if (r->info > v) return busca (r->esq, v);
	else if (r->info < v) return busca (r->dir, v);
	else return r;
}

Arv* insere (Arv* a, int v)
{
	if (a==NULL) {
		a = (Arv*)malloc(sizeof(Arv));
		a->info = v;
		a->esq = a->dir = NULL;
	}
	else if (v < a->info)
		a->esq = insere(a->esq,v);
	else /* v < a->info */
		a->dir = insere(a->dir,v);
	return a;
}


Arv* retira (Arv* r, int v)
{
	if (r == NULL)
		return NULL;
	else if (r->info > v)
		r->esq = retira(r->esq, v);
	else if (r->info < v)
		r->dir = retira(r->dir, v);
	else { /* achou o elemento */
		if (r->esq == NULL && r->dir == NULL) { /* elemento sem filhos */
			free (r);
			r = NULL;
		}		
		else if (r->esq == NULL) { /* só tem filho à direita */
			Arv* t = r;
			r = r->dir;
			free (t);
		}
		else if (r->dir == NULL) { /* só tem filho à esquerda */
			Arv* t = r;
			r = r->esq;
			free (t);
		}
		else { /* tem os dois filhos */
			Arv* pai = r;
			Arv* f = r->esq;
			while (f->dir != NULL) {
				pai = f;
				f = f->dir;
			}
			r->info = f->info; /* troca as informações */
			f->info = v;
			r->esq = retira(r->esq,v);
		}	
	}
	return r;
}

int vazia(Arv* a)
{
	return a==NULL;
}

void imprime_alt (Arv* a)
{
	if (!vazia(a)){
		if (a->info == raiz)
			printf("<");
		printf("%d", a->info); /* mostra raiz */
		printf("<");
		imprime_alt(a->esq); /* mostra sae */
		printf(">");
		printf("<");
		imprime_alt(a->dir); /* mostra sad */
		printf(">");
		if (a->info == 6)
			printf(">");
	}
}	


struct arvgen {
	int info;
	struct arvgen *prim;
	struct arvgen *prox;
};

typedef struct arvgen ArvGen;

ArvGen* criaG (int c)
{
	ArvGen *a =(ArvGen *) malloc(sizeof(ArvGen));
	a->info = c;
	a->prim = NULL;
	a->prox = NULL;
	return a;
}


void insereG (ArvGen* a, ArvGen* sa)
{
	sa->prox = a->prim;
	a->prim = sa;
}

void imprimeG (ArvGen* a)
{
	ArvGen* p;
	printf("%d\n",a->info);
	for (p=a->prim; p!=NULL; p=p->prox)
		imprimeG(p);
}

void imprime_altG (ArvGen* a)
{
	ArvGen* p;
	printf("<%d",a->info);
	for (p=a->prim; p!=NULL; p=p->prox)
		imprime_altG(p);
	printf(">");	
}


int buscaG (ArvGen* a, int c)
{
	ArvGen* p;
	if (a->info==c)
		return 1;
	else {
		for (p=a->prim; p!=NULL; p=p->prox) {
			if (buscaG(p,c))
			return 1;
		}
	}
	return 0;
}


void liberaG (ArvGen* a)
{
	ArvGen* p = a->prim;
	while (p!=NULL) {
		ArvGen* t = p->prox;
		liberaG(p);
		p = t;
	}
	free(a);
}

Arv* aux(ArvGen* gen,Arv* bin){
    if (bin==NULL) {
		bin = (Arv*)malloc(sizeof(Arv));
		bin->info = gen->info; 
        bin->esq = bin->dir = NULL;
	}
    return bin;
}

Arv* insidirismo(ArvGen* gen,Arv* bin){
    /*if (gen!=NULL)
    {
    bin=aux(gen,bin);
    //printf("\nbin %d\n",bin->info);
    //printf("\ngen %d\n",gen->info);
    bin->dir = insidirismo(gen->prox,bin->dir); 
    bin->esq = insidirismo(gen->prim,bin->esq);
    }*/
    ArvGen* p;
	if (bin->info==c)
		return 1;
	else {
		for (p=a->prim; p!=NULL; p=p->prox) {
			if (buscaG(p,c))
			return 1;
		}
	}

}

main() {
	
	ArvGen* a = criaG(1);
	ArvGen* b = criaG(3);
	ArvGen* c = criaG(4);
	ArvGen* d = criaG(7);
	ArvGen* e = criaG(9);
	ArvGen* f = criaG(10);
	ArvGen* g = criaG(12);
	ArvGen* h = criaG(25);
	ArvGen* i = criaG(5);
	ArvGen* j = criaG(6);
	/* monta a hierarquia */
	insereG(c,d);
	insereG(b,e);
	insereG(b,c);
	insereG(i,j);
	insereG(g,i);
	insereG(g,h);
	insereG(a,g);
	insereG(a,f);
	insereG(a,b);
	imprimeG(a);
	imprime_altG(a);
    Arv* arvor = init();
    insidirismo(a,arvor);
    imprime(arvor);
}