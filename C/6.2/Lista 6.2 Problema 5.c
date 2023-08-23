#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include <string.h>
struct lista {
		char cod[40];
		struct lista* prox;
	};

typedef struct lista Lista;

/* fun��o de inicializa��o: retorna uma lista vazia */
Lista* inicializa (void)
{
	return NULL;
}

Lista* insere (Lista* l, char i[])
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	strcpy(novo->cod,i);
	novo->prox = l;
	return novo;
}

void imprime (Lista* l)
{
	Lista* p;
	for (p = l; p != NULL; p = p->prox)  
		printf("info = %s\n", p->cod);  
}	
Lista* verifica(Lista* lista, char cod[]);

int EhDigito(char cod){
    int k=0;    
    if (cod>= '0' && cod <= '9')
        {
            return 1;
        }else{
            return 0;
        }
    return 0;
}

int Letra(char cod){
    
    if ((cod>= 'a' && cod <= 'z')||(cod>= 'A' && cod <= 'Z'))
        {
            return 1;
        }else{
            return 0;
        }
}

int main (void) {
	Lista* l,*l2,*l3; /* declara uma lista n�o iniciada */
	l = inicializa(); /* inicia lista vazia */
	l = insere(l,"1a2b3c4d5e6f7g8h9i0j");
    l=verifica(l,l->cod);
    //printf("%d",EhDigito('4'));
    l = insere(l,"123a");
    l=verifica(l,l->cod);
    //imprime(l);
    l = insere(l,"M4R4C0G41");
    l=verifica(l,l->cod);
    imprime(l);
	return 0;
}





Lista* verifica(Lista* lista, char cod[]){
    int i=0,k=0,n=0,l=0;    
    char num[20],letras[20],junto[40];
    printf("%s\n",cod);
    for ( i = 0;cod[i] != '\0'; i++)
        if (EhDigito(cod[i])==1){
            num[n]=cod[i];
        n++;
        }
    num[n]='\0';

    printf("%s\n",num);
        
    for ( i = 0;cod[i] != '\0'; i++)
        if (Letra(cod[i])==1){
            letras[l]=cod[i];
        l++;
        }

    letras[l]='\0';
    printf("%s\n",letras);
    
    for ( i = 0;letras[i] != '\0'; i++)
            junto[i]=letras[i];
        for ( n = 0;num[n]!= '\0'; n++){
            junto[i]=num[n];
            i++;
        }    

    junto[i]='\n';
    for ( i = 0;junto[i]!='\n'; i++)
    {
        lista->cod[i]=junto[i];
    }
    return lista;
}