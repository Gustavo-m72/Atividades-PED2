#include <stdio.h>
#include <string.h>



struct arv {
	char op;
    float valor;
	struct arv* esq;
	struct arv* dir;
};



typedef struct arv Arv;


Arv* inicializa(void)
{
	return NULL;
}



Arv* cria(char c,float x, Arv* sae, Arv* sad){
	Arv* p=(Arv*)malloc(sizeof(Arv));
	p->op = c;
    p->valor = x;
	p->esq = sae;
	p->dir = sad;
	return p;
}


	
int vazia(Arv* a)
{
	return a==NULL;
}


/*
void imprime (Arv* a)
{
	if (!vazia(a)){
		//printf("%c ", a->info); 
		imprime(a->esq); 
		//printf("%c ", a->info); simetrica
        imprime(a->dir); 
        printf("%c ", a->info);//pós
	}
}*/

void imprime(Arv* a){
    if (!vazia(a))
    {
        /*if (a->esq->esq==NULL && a->esq->dir==NULL && a->dir->esq==NULL && a->dir->esq==NULL)
        {
            printf(" %d %d %c ",a->esq,a->dir,a->op);
        }*/
        if (a->esq==NULL && a->dir==NULL){
            printf(" %f ",a->valor);
        }else{
            if (a->esq!=NULL||a->dir!=NULL)
            {
                printf(" %c ",a->op);
            }
            if (a->esq!=NULL) imprime(a->esq); 
            if(a->dir!=NULL)imprime(a->dir);
        }
    }
}

/*
void imprime_alt (Arv* a)
{
	if (!vazia(a)){
		if (a->info == 'a')
			printf("<");
		printf("%c", a->info); 
		printf("<");
		imprime_alt(a->esq); 
		printf(">");
		printf("<");
		imprime_alt(a->dir); 
		printf(">");
		if (a->info == 'a')
			printf(">");
	}
}*/	


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
      return -1; // altura da árvore vazia
   else {
      int he = altura (a->esq);
      int hd = altura (a->dir);
      if (he < hd) return hd + 1;
      else return he + 1;
   }
}

float avalia(Arv* a){
    float x=0,y=0;
    if (!vazia(a))
    {
        if (a->esq->esq==NULL && a->esq->dir==NULL)
        {
            x=a->esq->valor;
            free(a->esq);
        }
        if (a->dir->esq==NULL && a->dir->esq==NULL)
        {
            y=a->dir->valor;
            free(a->dir);
        }
        if (a->esq!=NULL||a->dir!=NULL)
            {
                switch (a->op)
                {
                case '-':
                    a->valor=x-y;
                    break;

                case '+':
                    a->valor=x+y;
                    break;

                case '*':
                a->valor=x*y;
                break;
                
                
            }
            //if(a->esq!=NULL) avalia(a->esq); 
            //if(a->dir!=NULL) avalia(a->dir);
            }
    }
}

/*
int busca (Arv* a, char c){
	if (vazia(a))
		return 0; 
	else
		return a->info==c || busca(a->esq,c) || busca(a->dir,c);
}*/

main() {
	Arv* a1= cria('d',7,inicializa(),inicializa()); /* sub-árvore com 'd'*/
	Arv* a2= cria('b',5,inicializa(),inicializa()); /* sub-árvore com 'b'*/
	Arv* a3= cria('-',0,a1,a2); /* sub-árvore com 'e'*/
	Arv* a4= cria('+',0,a2,a3);
	imprime(a3);
	puts("");
	//imprime_alt(a);
    avalia(a3);
    printf("\n%f",a4->valor);
	printf("\nint altura(Arv* a) %d", altura(a3));

	//printf("\nint busca (Arv* a, char c) %d", busca (a, 'a'));
	//printf("\nint busca (Arv* a, char c) %d", busca (a, 'x'));
	//libera(a);
}

