// Algoritmo de Dijkstra
// Fonte: https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/dijkstra.html#example-A

#include <stdio.h>
#include <stdlib.h>

/* Vértices de grafos são representados por objetos do tipo vertex. */
#define vertex int
#define INFINITY 1000000000
typedef struct node *link;

struct graph {
   int V; 
   int A; 
   link *adj; 
};

typedef struct graph *Graph;

struct node { 
   vertex w; 
   link next; 
   int cst; // custo!
};

static link NEWnode( vertex w, link next, int cst) { 
   link a = malloc( sizeof (struct node));
   a->w = w; 
   a->next = next;     
   a->cst = cst;
   return a;                         
}

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

void GRAPHinsertArc( Graph G, vertex v, vertex w, int cst) { 
   link a;
   for (a = G->adj[v]; a != NULL; a = a->next) 
      if (a->w == w) return;
   G->adj[v] = NEWnode( w, G->adj[v], cst);
   G->A++;
}

vertex pa[1000];
int dist[1000];

/*
void GRAPHsptD0( Graph G, vertex s) 
•
Resumo do algoritmo:

1. Faça as inicializações apontadas ([ predecessor,distancia])
2. Enquanto houver vertice aberto:
3. 	Escolha u cuja estimativa seja a menor dentre os abertos
4. 	Feche u
5. Para todo nó aberto v na adjacencia de u:
6. 	Relaxe a aresta (u, v)
*/

void GRAPHsptD0( Graph G, vertex s) 
{ 
   vertex v;
   for (v = 0; v < G->V; ++v) 
      pa[v] = -1;
   pa[s] = s, dist[s] = 0; 

   vertex y;	
   while (1) {
      int min = INFINITY;
      vertex x;
      vertex v;
      for (v = 0; v < G->V; ++v) {
         if (pa[v] == -1) continue;
         link a;
         for (a = G->adj[v]; a != NULL; a = a->next) {
            if (pa[a->w] != -1) continue;
            if (dist[v] + a->cst < min) {
               min = dist[v] + a->cst;
               x = v, y = a->w;
               //printf("MINIMO entre %d e %d eh %d\n", v, a->w, min);
            }
         }
      }
      if (min == INFINITY) /*A*/ break; /*B*/
      pa[y] = x, dist[y] = min;
      printf("x %d y %d dist %d\n", x, y, min);
   }
   int distancia=0;
   printf("\n\n");
      for (v = 0; v <= 5; v++) 
        if (dist[v] > 0){
      		printf("x %d y %d dist %d\n", pa[v], v, dist[v]);
        distancia+=dist[v];
        }
    printf("\ndistancia total: %d",distancia);
}

main() {
  
// Grafo do vídeo:
/*Grafo orientado	
v0	v1(10);v2(5)
v1	v3(1)
v2	v1(3)v3(8);v4(2)
v3	v4(4);v5(4)
v4	v5(6)
v5	VAZIO

Saida:

MINIMO entre 0 e 2 eh 5
x 0 y 2 dist 5
MINIMO entre 0 e 1 eh 10
MINIMO entre 2 e 4 eh 7
x 2 y 4 dist 7
MINIMO entre 0 e 1 eh 10
MINIMO entre 2 e 1 eh 8
x 2 y 1 dist 8
MINIMO entre 1 e 3 eh 9
x 1 y 3 dist 9
MINIMO entre 3 e 5 eh 13
x 3 y 5 dist 13*/

// Grafo de ed211_Dijkstra:
/*Grafo não orientado	
Av0	v1(4);v2(2)
Bv1	v3(5)
Cv2	v1(1)v3(8);v4(10)
Dv3	v4(2);v5(6)
Ev4	v5(2)
Fv5	VAZIO

Saída:
MINIMO entre 0 e 2 eh 2
x 0 y 2 dist 2
MINIMO entre 0 e 1 eh 4
MINIMO entre 2 e 1 eh 3
x 2 y 1 dist 3
MINIMO entre 1 e 3 eh 8
x 1 y 3 dist 8
MINIMO entre 2 e 4 eh 12
MINIMO entre 3 e 4 eh 10
x 3 y 4 dist 10
MINIMO entre 3 e 5 eh 14
MINIMO entre 4 e 5 eh 12
x 4 y 5 dist 12
*/
  	Graph G = GRAPHinit(6);
	GRAPHinsertArc(G, 0, 1, 10);
	GRAPHinsertArc(G, 0, 2, 5);
	GRAPHinsertArc(G, 1, 3, 1);
	GRAPHinsertArc(G, 2, 1, 3);
	GRAPHinsertArc(G, 2, 3, 8);
	GRAPHinsertArc(G, 2, 4, 2);
	GRAPHinsertArc(G, 3, 4, 4);
	GRAPHinsertArc(G, 3, 5, 4);
	GRAPHinsertArc(G, 4, 5, 6);

	GRAPHsptD0(G, 0); 
}