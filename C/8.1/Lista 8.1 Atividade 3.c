#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct arv {
	char info;
	struct arv* esq;
	struct arv* dir;
};

typedef struct arv Arv;

Arv* inicializa(void)
{
	return NULL;
}

Arv* cria(char c, Arv* sae, Arv* sad){
	Arv* p=(Arv*)malloc(sizeof(Arv));
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}

int vazia(Arv* a)
{
	return a==NULL;
}

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

Arv* libera (Arv* a){
	if (!vazia(a)){
		libera(a->esq); /* libera sae */
		libera(a->dir); /* libera sad */
		free(a); /* libera raiz */
	}
	return NULL;
}

int altura(Arv* a) {
   if (a == NULL) 
      return -1; 
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
	
}

int folhas(Arv* a){
    
    if (a==NULL)
    {
        return 0;
    }else if (a->esq==NULL&&a->dir==NULL)
    {
        return 1;
    }else{
        return folhas(a->esq)+folhas(a->dir);
    }
}
/*
int igual(Arv* a, Arv* b){
    if (a==NULL&&b==NULL)
	{
		
		return 1;
	}
	if (a==NULL||b==NULL)
	{
		
		return 0;
	}
	return((a->info==b->info)&&igual(a->esq,b->esq)&&igual(a->dir,b->dir));
	
	//*if (altura(a)==altura(b)&&folhas(a)==folhas(b))
    //{
        //if (vazia(a)==vazia(b)){
		//if (strcmp(a->info,b->info)==0)
        //{
           // return igual(a->esq,b->esq);  
			//return igual(a->dir,b->dir);
        //}else return NULL;
		//}
    //}else{
        //return NULL;
    //}
	
	
}

int ingual(Arv* a,Arv* b){
	if (a!=NULL&&b!=NULL){
		if (altura(a)==altura(b)&&folhas(a)==folhas(b))
		{
			if (a->info==b->info)
			{
				return ingual(a->esq,b->esq)+ingual(a->dir,b->dir);
			}else ;
		}
	}else if (a==NULL&&b==NULL)
	{
		return 1;
	}
}*/

int igualidade (Arv* a, Arv* c){
	if (a!=NULL&&c!=NULL)
		if (a->info!=c->info)
			return 1; /* árvore vazia: não encontrou */
		else if (a->info==c->info)
		{
			return igualidade(a->esq,c->esq) + igualidade(a->dir,c->dir);
		}
}
main() {
	Arv* a1= cria('d',inicializa(),inicializa()); /* sub-árvore com 'd'*/
	Arv* a2= cria('b',inicializa(),a1); /* sub-árvore com 'b'*/
	Arv* a3= cria('e',inicializa(),inicializa()); /* sub-árvore com 'e'*/
	Arv* a4= cria('f',inicializa(),inicializa()); /* sub-árvore com 'f'*/
	Arv* a5= cria('c',a3,a4); /* sub-árvore com 'c'*/
	Arv* a6= cria('c',a3,a5); /* sub-árvore com 'c'*/
	Arv* a = cria('a',a2,a5 ); /* árvore com raiz 'a'*/
	Arv* b = cria('a',a2,a5 ); /* árvore com raiz 'a'*/
	

	printf("\nint altura(Arv* a) %d", altura(a));
	printf("\nint altura(Arv* b) %d", altura(b));
    printf("\nfolhas: %d",folhas(a));
	printf("\nfolhas: %d",folhas(b));
	
	

	printf("\n\nigualdade %d",igualidade(a2,a2));

	libera(a);
}