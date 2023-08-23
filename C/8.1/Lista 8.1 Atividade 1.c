#include <stdio.h>
#include <string.h>

//Cada nó deve armazenar três informações: a informação propriamente dita, no caso um
//caractere, e dois ponteiros para as sub-árvores, à esquerda e à direita. Então a estrutura
//de C para representar o nó da árvore pode ser dada por:

struct arv {
	char info;
	struct arv* esq;
	struct arv* dir;
};

//Da mesma forma que uma lista encadeada é representada por um ponteiro para o
//primeiro nó, a estrutura da árvore como um todo é representada por um ponteiro para o
//nó raiz.
//Como acontece com qualquer TAD (tipo abstrato de dados), as operações que fazem
//sentido para uma árvore binária dependem essencialmente da forma de utilização que se
//pretende fazer da árvore. Nesta seção, em vez de discutirmos a interface do tipo abstrato
//para depois mostrarmos sua implementação, vamos optar por discutir algumas
//operações mostrando simultaneamente suas implementações. Ao final da seção
//apresentaremos um arquivo que pode representar a interface do tipo. Nas funções que se
//seguem, consideraremos que existe o tipo Arv definido por:

typedef struct arv Arv;

//Como veremos as funções que manipulam árvores são, em geral, implementadas de
//forma recursiva, usando a definição recursiva da estrutura.

//Vamos procurar identificar e descrever apenas operações cuja utilidade seja a mais geral
//possível. Uma operação que provavelmente deverá ser incluída em todos os casos é a
//inicialização de uma árvore vazia. Como uma árvore é representada pelo endereço do
//nó raiz, uma árvore vazia tem que ser representada pelo valor NULL. Assim, a função
//que inicializa uma árvore vazia pode ser simplesmente:

Arv* inicializa(void)
{
	return NULL;
}

//Para criar árvores não vazias, podemos ter uma operação que cria um nó raiz dadas a
//informação e suas duas sub-árvores, à esquerda e à direita. Essa função tem como valor
//de retorno o endereço do nó raiz criado e pode ser dada por:

Arv* cria(char c, Arv* sae, Arv* sad){
	Arv* p=(Arv*)malloc(sizeof(Arv));
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}

//As duas funções inicializa e cria representam os dois casos da definição recursiva
//de árvore binária: uma árvore binária (Arv* a;) é vazia (a = inicializa();) ou é
//composta por uma raiz e duas sub-árvores (a = cria(c,sae,sad);). Assim, com
//posse dessas duas funções, podemos criar árvores mais complexas.
//Exemplo: Usando as operações inicializa e cria, crie uma estrutura que represente
//a árvore da Figura 13.5.

//	 a
//	/ \
//	b  c
//	\  /\
//	 d e f

//Para tratar a árvore vazia de forma diferente das outras, é importante ter uma operação
//que diz se uma árvore é ou não vazia. Podemos ter:
	
int vazia(Arv* a)
{
	return a==NULL;
}

//Uma outra função muito útil consiste em exibir o conteúdo da árvore. Essa função deve
//percorrer recursivamente a árvore, visitando todos os nós e imprimindo sua informação.
//A implementação dessa função usa a definição recursiva da árvore. Vimos que uma
//árvore binária ou é vazia ou é composta pela raiz e por duas sub-árvores. Portanto, para
//imprimir a informação de todos os nós da árvore, devemos primeiro testar se a árvore é
//vazia. Se não for, imprimimos a informação associada a raiz e chamamos
//(recursivamente) a função para imprimir os nós das sub-árvores.

void imprime (Arv* a)
{
	if (!vazia(a)){
		//printf("%c ", a->info); /* mostra raiz */
		imprime(a->esq); /* mostra sae */
		//printf("%c ", a->info); simetrica
        imprime(a->dir); /* mostra sad */
        printf("%c ", a->info);//pós
	}
}	

// Exercício: Modifique a implementação de imprime, de forma que a saída impressa
//reflita, além do conteúdo de cada nó, a estrutura da árvore, usando a notação introduzida
//a n t e r i o r m e n t e . A s s i m , a s a í d a d a f u n ç ã o s e r i a :
//<a<b<><d<><>>><c<e<><>><f<><>>>>.

void imprime_alt (Arv* a)
{
	if (!vazia(a)){
		if (a->info == 'a')
			printf("<");
		printf("%c", a->info); /* mostra raiz */
		printf("<");
		imprime_alt(a->esq); /* mostra sae */
		printf(">");
		printf("<");
		imprime_alt(a->dir); /* mostra sad */
		printf(">");
		if (a->info == 'a')
			printf(">");
	}
}	

//Uma outra operação que pode ser acrescentada é a operação para liberar a memória
//alocada pela estrutura da árvore. Novamente, usaremos uma implementação recursiva.
//Um cuidado essencial a ser tomado é que as sub-árvores devem ser liberadas antes de se
//liberar o nó raiz, para que o acesso às sub-árvores não seja perdido antes de sua
//remoção. Neste caso, vamos optar por fazer com que a função tenha como valor de
//retorno a árvore atualizada, isto é, uma árvore vazia, representada por NULL.

Arv* libera (Arv* a){
	if (!vazia(a)){
		libera(a->esq); /* libera sae */
		libera(a->dir); /* libera sad */
		free(a); /* libera raiz */
	}
	return NULL;
}

// Uma propriedade fundamental de todas as árvores é que só existe um caminho da raiz
// para qualquer nó. Com isto, podemos definir a altura de uma árvore como sendo o
// comprimento do caminho mais longo da raiz até uma das folhas. Por exemplo, a altura
// da árvore da Figura 13.5 é 2, e a altura das árvores da Figura 13.6 é 1. Assim, a altura
// de uma árvore com um único nó raiz é zero e, por conseguinte, dizemos que a altura de
// uma árvore vazia é negativa e vale -1.
int altura(Arv* a) {
   if (a == NULL) 
      return -1; // altura da árvore vazia
   else {
      int he = altura (a->esq);
      int hd = altura (a->dir);
      if (he < hd) return hd + 1;
      else return he + 1;
   }
}

int busca (Arv* a, char c){
	if (vazia(a))
		return 0; /* árvore vazia: não encontrou */
	else
		return a->info==c || busca(a->esq,c) || busca(a->dir,c);
	// Note que esta forma de programar busca, em C, usando o operador lógico || (“ou”)
	// faz com que a busca seja interrompida assim que o elemento é encontrado. Isto acontece
	// porque se c==a->info for verdadeiro, as duas outras expressões não chegam a ser
	// avaliadas. Analogamente, se o caractere for encontrado na sub-árvore da esquerda, a
	// busca não prossegue na sub-árvore da direita.
	// Podemos dizer que a expressão:
	// return c==a->info || busca(a->esq,c) || busca(a->dir,c);
	// é equivalente a:
	// if (c==a->info)
	//		return 1;
	// else if (busca(a->esq,c))
	// 		return 1;
	// else
	// 		return busca(a->dir,c);	
}

main() {
	Arv* a1= cria('d',inicializa(),inicializa()); /* sub-árvore com 'd'*/
	Arv* a2= cria('b',inicializa(),a1); /* sub-árvore com 'b'*/
	Arv* a3= cria('e',inicializa(),inicializa()); /* sub-árvore com 'e'*/
	Arv* a4= cria('f',inicializa(),inicializa()); /* sub-árvore com 'f'*/
	Arv* a5= cria('c',a3,a4); /* sub-árvore com 'c'*/
	Arv* a = cria('a',a2,a5 ); /* árvore com raiz 'a'*/
	imprime(a);
	puts("");
	imprime_alt(a);
	// Exercício: Escreva uma função que percorre uma árvore binária para determinar sua
	// altura. O protótipo da função pode ser dado por:
	// int altura(Arv* a);
	printf("\nint altura(Arv* a) %d", altura(a));
	// Uma outra função que podemos considerar percorre a árvore buscando a ocorrência de
	// um determinado caractere c em um de seus nós. Essa função tem como retorno um
	// valor booleano (um ou zero) indicando a ocorrência ou não do caractere na árvore.
	// int busca (Arv* a, char c);
	printf("\nint busca (Arv* a, char c) %d", busca (a, 'a'));
	printf("\nint busca (Arv* a, char c) %d", busca (a, 'x'));
	libera(a);
}

// Finalmente, considerando que as funções discutidas e implementadas acima formam a
// interface do tipo abstrato para representar uma árvore binária, um arquivo de interface
// arvbin.h pode ser dado por:
//	typedef struct arv Arv;
//	Arv* inicializa (void);
//	Arv* cria (char c, Arv* e, Arv* d);
//	int vazia (Arv* a);
//	void imprime (Arv* a);
//	Arv* libera (Arv* a);
//	int busca (Arv* a, char c);

//Alternativamente, a árvore poderia ser criada com uma única atribuição, seguindo a sua
///estrutura, “recursivamente”:
//Arv* a = cria('a',
//cria('b',
//		inicializa(),
//		cria('d', inicializa(), inicializa())
//			),
//		cria('c',
//			cria('e', inicializa(), inicializa()),
//			cria('f', inicializa(), inicializa())
//			)	
//		);