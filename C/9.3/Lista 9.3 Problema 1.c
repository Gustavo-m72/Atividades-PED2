#include <stdio.h>
#include <stdlib.h>
// O vetor de listas de adjacência de um grafo tem uma lista encadeada (= linked list) associada com cada 
// vértice do grafo.  A lista associada com um vértice v contém todos os vizinhos de v.  Portanto, a lista 
// do vértice v representa o leque de saída de v.   Por exemplo, eis o vetor de listas de adjacência do grafo 
//cujos arcos são  0-1 0-5 1-0 1-5 2-4 3-1 5-3 :

//0: 5 1
//1: 5 0
//2: 4
//3: 1
//4:  
//5: 3

/* Vértices de grafos são representados por objetos do tipo vertex. */
#define vertex int

// Na representação por listas de adjacência, um grafo é representado por uma struct graph que contém o vetor 
// de listas de adjacência, o número de vértices, e o número de arcos do grafo:
/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A estrutura graph representa um grafo. O campo adj é um ponteiro 
para o vetor de listas de adjacência, o campo V contém o número de vértices e o campo A contém o número de 
arcos do grafo. */
typedef struct node *link;

struct graph {
   int V; 
   int A; 
   link *adj; 
};

/* Um Graph é um ponteiro para um graph. */
typedef struct graph *Graph;

/* A lista de adjacência de um vértice v é composta por nós do tipo node. Cada nó da lista corresponde a um 
arco e contém um vizinho w de v e o endereço do nó seguinte da lista. Um link é um ponteiro para um node. */
struct node { 
   vertex w; 
   link next; 
};

/* A função NEWnode() recebe um vértice w e o endereço next de um nó e devolve o endereço a de um novo nó 
tal que a->w == w e a->next == next. */
static link NEWnode( vertex w, link next) { 
   link a = malloc( sizeof (struct node));
   a->w = w; 
   a->next = next;     
   return a;                         
}

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função GRAPHinit() constrói um grafo com vértices 0 1 .. V-1 
e nenhum arco. */
Graph GRAPHinit( int V) { 
   vertex v;	
   Graph G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = malloc( V * sizeof (link));
   for (v = 0; v < V; ++v) 
      G->adj[v] = NULL;
   return G;
}
/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função GRAPHinsertArc() insere um arco v-w no grafo G. 
A função supõe que v e w são distintos, positivos e menores que G->V. Se o grafo já tem um arco v-w, 
a função não faz nada. */
void GRAPHinsertArc( Graph G, vertex v, vertex w) { 
   link a;
   for (a = G->adj[v]; a != NULL; a = a->next) 
      if (a->w == w) return;
   G->adj[v] = NEWnode( w, G->adj[v]);
   G->A++;
}

main() {
//0: 5 1
//1: 5 0
//2: 4
//3: 1
//4:  
//5: 3
	Graph G = GRAPHinit(6);
	GRAPHinsertArc(G, 0, 5);
	GRAPHinsertArc(G, 0, 1);
	GRAPHinsertArc(G, 1, 5);
	GRAPHinsertArc(G, 1, 0);
	GRAPHinsertArc(G, 2, 4);
	GRAPHinsertArc(G, 3, 1);
	GRAPHinsertArc(G, 5, 3);
	
	//void GRAPHremoveArc( Graph G, vertex v, vertex w); // implementar
	//void GRAPHshow( Graph G); // implementar
	//void GRAPHshowAll( Graph G); // implementar
}