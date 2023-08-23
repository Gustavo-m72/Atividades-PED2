#include <stdio.h>
#include <stdlib.h>

struct arvgen {
	char info;
	struct arvgen *prim;
	struct arvgen *prox;
};

typedef struct arvgen ArvGen;

//A estrutura arvgen, que representa o nó da árvore, é definida conforme mostrado
//anteriormente. A função para criar uma folha deve alocar o nó e inicializar seus campos,
//atribuindo NULL para os campos prim e prox, pois trata-se de um nó folha.
ArvGen* cria (char c)
{
	ArvGen *a =(ArvGen *) malloc(sizeof(ArvGen));
	a->info = c;
	a->prim = NULL;
	a->prox = NULL;
	return a;
}

//A função que insere uma nova sub-árvore como filha de um dado nó é muito simples.
//Como não vamos atribuir nenhum significado especial para a posição de um nó filho, a
//operação de inserção pode inserir a sub-árvore em qualquer posição. Neste caso, vamos
//optar por inserir sempre no início da lista que, como já vimos, é a maneira mais simples
//de inserir um novo elemento numa lista encadeada.
void insere (ArvGen* a, ArvGen* sa)
{
	sa->prox = a->prim;
	a->prim = sa;
}

void imprime (ArvGen* a)
{
	ArvGen* p;
	printf("%c\n",a->info);
	for (p=a->prim; p!=NULL; p=p->prox)
		imprime(p);
}

void imprime_alt (ArvGen* a)
{
	ArvGen* p;
	printf("<%c",a->info);
	for (p=a->prim; p!=NULL; p=p->prox)
		imprime_alt(p);
	printf(">");	
}

//A operação para buscar a ocorrência de uma dada informação na árvore é exemplificada
//abaixo:
int busca (ArvGen* a, char c)
{
	ArvGen* p;
	if (a->info==c)
		return 1;
	else {
		for (p=a->prim; p!=NULL; p=p->prox) {
			if (busca(p,c))
			return 1;
		}
	}
	return 0;
}

// A última operação apresentada é a que libera a memória alocada pela árvore. O único
//cuidado que precisamos tomar na programação dessa função é a de liberar as subárvores
//antes de liberar o espaço associado a um nó (isto é, usar pós-ordem).
void libera (ArvGen* a)
{
	ArvGen* p = a->prim;
	while (p!=NULL) {
		ArvGen* t = p->prox;
		libera(p);
		p = t;
	}
	free(a);
}

int igual(ArvGen* a,ArvGen* b){
    ArvGen* x = b->prim; 
    ArvGen* p = a->prim;
	if (a->info==b->info){
		for (p=a->prim; p!=NULL; p=p->prox){
			igual(p,x);
			x=x->prox;
		}	
	}else
		{
			return 0;
		}
	
	if (p==NULL&&x==NULL)
	{
		return 1;
	}
}

int folhas(ArvGen* a){
        if(a==NULL){
            return 0;
        }
        if (a->prim!=NULL)
        {
            return folhas(a->prim)+folhas(a->prox);
        }else
            return 1+folhas(a->prox);
}
 
int intermediarios(ArvGen* a){
        if(a==NULL){
            return 0;
        }
        if (a->prim!=NULL)
        {
            return 1+(intermediarios(a->prim)+intermediarios(a->prox));
        }else
            return folhas(a->prox);
}

main() {
	//Com essas duas funções, podemos construir a árvore do exemplo da Figura 13.7 com o
	//seguinte fragmento de código:
	/* cria nós como folhas */
	ArvGen* a = cria('a');
	ArvGen* b = cria('b');
	ArvGen* c = cria('c');
	ArvGen* d = cria('d');
	ArvGen* e = cria('e');
	ArvGen* f = cria('f');
	ArvGen* g = cria('g');
	ArvGen* h = cria('h');
	ArvGen* i = cria('i');
	ArvGen* j = cria('j');
    
	/* monta a hierarquia */
	insere(c,d);
	insere(b,e);
	insere(b,c);
	insere(i,j);
	insere(g,i);
	insere(g,h);
	insere(a,g);
	insere(a,f);
	insere(a,b);
    
	//imprime(a);
	//imprime_alt(a);

    //printf("%d",igual(g,g));
    //printf("%d",folhas(a));
    
    printf("%d",intermediarios(a));
}