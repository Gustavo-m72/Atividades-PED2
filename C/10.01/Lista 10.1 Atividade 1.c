// Algoritmo de Dijkstra
// Fonte: https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/dijkstra.html#example-A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* Vértices de grafos são representados por objetos do tipo vertex. */
#define vertex int
#define INFINITY 1000000000
typedef struct node *link;


#define FLSH gets(l)

/* definir variavies */
 

struct graph {
   int V; 
   int A; 
   link *adj; 
};

typedef struct graph *Graph;

typedef struct cidades
{
    char nome[40];
    int cod;
}Cidades;
Cidades city[15];
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
void imprimeCidades(int cod,Cidades* city){
    
    printf("%s",city[cod].nome);
} 

void GRAPHsptD0( Graph G, vertex s,Cidades* city) 
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
      printf(" Origem ");imprimeCidades(x,city);printf( " a ");imprimeCidades(y,city); printf(" dist %d\n",min);
   }
      /*for (v = 0; v < y; v++) 
        if (dist[v] > 0)
      		printf("x %d y %d dist %d\n", pa[v], v, dist[v]);*/
}

void criaCidades(Cidades* fix,char* city, int cod){
    strcpy(fix->nome,city);
    fix->cod=cod;
}

static int cnt; // aqui vai simular a pilha!!!!
int pre[1000];


void GRAPHdfs( Graph G) 
{ 
   cnt = 0;
   vertex v;
   for (v = 0; v < G->V; ++v) 
      pre[v] = -1;
   for (v = 0; v < G->V; ++v)
      if (pre[v] == -1) 
         dfsR( G, v); // começa nova etapa
}

void dfsR( Graph G, vertex v) 
{ 
   pre[v] = cnt++; // descoberto!
   printf("Descoberto ");imprimeCidades(pre[v],city);printf("\n");
   link a;
   for (a = G->adj[v]; a != NULL; a = a->next) {
      vertex w = a->w;
      if (pre[w] == -1)
         dfsR( G, w); 
   }
}

static int num[1000];

//int fila[1000], f_fila, r_fila; // REPARE NA SIMPLICIDADE DA FILA!!!!!

/* Este módulo implementa uma fila de vértices. A fila reside no segmento queue[begin..end-1] de um vetor queue[0..N-1]. 
Vamos supor que temos sempre 0 = begin = end = N. (O código abaixo é uma adaptação do programa 4.11 do volume 1 do 
livro de Sedgewick.) */
static vertex *queue; 
static int begin, end;

void QUEUEinit( int N) { 
   queue = malloc( N * sizeof (vertex));
   begin = end = 0; 
}

int QUEUEempty( void) { 
   return begin == end; 
}

void QUEUEput( vertex v) {
   queue[end++] = v;
}

vertex QUEUEget( void) { 
   return queue[begin++];
}

void QUEUEfree( void) {
   free( queue);
}

/* A função GRAPHbfs() implementa o algoritmo de busca em largura. Ela visita todos os vértices do grafo G 
que estão ao alcance do vértice s e registra num vetor num[] a ordem em que os vértices são descobertos. Esta 
versão da função supõe que o grafo G é representado por listas de adjacência.  (Código inspirado no programa 
18.9 de Sedgewick.) */
void GRAPHbfs( Graph G, vertex s) 
{ 
   int cnt = 0;
   vertex v;
   for (v = 0; v < G->V; ++v)
      num[v] = -1;
   QUEUEinit( G->V);
   num[s] = cnt++; // descoberto!
   printf("Descoberto %d\n", num[s]); 
   QUEUEput( s); 

   //while (!QUEUEempty( )) {
   while (!QUEUEempty( )) {
   	  //puts("AQUI!") ;
      vertex v = QUEUEget( ); 
      link a;
      for (a = G->adj[v]; a != NULL; a = a->next)
         if (num[a->w] == -1) {
            num[a->w] = cnt++; // descoberto!
            printf("Descoberto %d\n", num[a->w]); 
            QUEUEput( a->w); 
         }
   }
   QUEUEfree( ); 
}


//15
main() {
    //Cidades city[15];
    criaCidades(&city[0],"Frederico Westhepalen",0);
    criaCidades(&city[1],"Palmeira",1);
    criaCidades(&city[2],"Panambi",2);
    criaCidades(&city[3],"Cruz Alta",3);
    criaCidades(&city[4],"Tapera",4);
    criaCidades(&city[5],"Espumoso",5);
    criaCidades(&city[6],"Soledade",6);
    criaCidades(&city[7],"Sarandi",7);
    criaCidades(&city[8],"Carazinho",8);
    criaCidades(&city[9],"Passo Fundo",9);
    criaCidades(&city[10],"Marau",100);
    criaCidades(&city[11],"Guapore",11);
    criaCidades(&city[12],"Lajeado",12);
    criaCidades(&city[13],"Canoas",13);
    criaCidades(&city[14],"Porto Alegre",14);
    
  	Graph G = GRAPHinit(15);
	
	GRAPHinsertArc(G, 0, 1, 1);
	GRAPHinsertArc(G, 1,7,1);
   GRAPHinsertArc(G, 1,2,30);
   GRAPHinsertArc(G, 2,3,30);
   GRAPHinsertArc(G, 3,4,30);
   GRAPHinsertArc(G, 4,5,30);
   GRAPHinsertArc(G, 5,6,30);
   GRAPHinsertArc(G, 6,12,1);
   GRAPHinsertArc(G, 7,8,1);
   GRAPHinsertArc(G, 8,6,1);
   GRAPHinsertArc(G, 8,9,20);
   GRAPHinsertArc(G, 9,10,20);
   //GRAPHinsertArc(G, 6,12,1);
   GRAPHinsertArc(G, 10,11,20);
   GRAPHinsertArc(G, 11,12,20);
   GRAPHinsertArc(G, 12,13,1);
   GRAPHinsertArc(G,13,14,1);
   //
   //GRAPHinsertArc(G, 1,2,3);
   //GRAPHinsertArc(G, 2,4,3);
   //GRAPHinsertArc(G, 4,5,3);
   //GRAPHinsertArc(G, 5,6,3);
   //
   //GRAPHinsertArc(G, 8,9,2);
  // GRAPHinsertArc(G, 9,10,2);
   //GRAPHinsertArc(G, 10,11,2);
   //GRAPHinsertArc(G, 11,12,2);






   
    
   GRAPHbfs(G,0);
   printf("\n");
   GRAPHdfs(G);
   printf("\n");
	GRAPHsptD0(G, 0,&city); 
   printf("ok");
}