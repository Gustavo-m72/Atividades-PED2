#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    int matricula;
    char nome[90];  // definir tamamnho da string nome
    float media;
};
typedef struct aluno Aluno;

struct noABB{
	Aluno info;
	struct noABB* esq;
	struct noABB* dir;
};
typedef struct noABB ABB;

int raiz; // ?



ABB* abb_cria (void)
{
	return NULL;
}


void abb_imprime (ABB* a)
{
	if (a != NULL) {
        abb_imprime(a->esq);
        printf("matricula %d\n",a->info.matricula);
        printf("nome %s\n",a->info.nome);
		printf("matricula %f\n",a->info.media);
        printf("\n");
        abb_imprime(a->dir);
	}
}

ABB* abb_insere (ABB* a,int mat,char* nome,float media) // char *nome ao inves de char nome[]
{
	if (a==NULL) {
		a = (ABB*)malloc(sizeof(ABB));
		strcpy(a->info.nome,nome);
        a->info.matricula=mat;
        a->info.media=media;
		a->esq = a->dir = NULL;
	}
	else if (media < a->info.media)
		a->esq = abb_insere(a->esq,mat,nome,media);
	else /* v < a->info */
		a->dir = abb_insere(a->dir,mat,nome,media);
	return a;
}

int vazia(ABB* a)
{
	return a==NULL;
}

void abb_alunoComMaiorMedia(ABB* a){
    if (a->dir==NULL)
    {
        printf("matricula %d\n",a->info.matricula);
        printf("nome %s\n",a->info.nome);
		printf("matricula %f\n",a->info.media);
        
    }else{
        abb_alunoComMaiorMedia(a->dir);
    }
}

int abb_contaAprovados(ABB* a){
    
     if (vazia(a))
    {
        return 0;
    }else if (a->info.media>=5)
    {
        return 1+(abb_contaAprovados(a->esq) + abb_contaAprovados(a->dir));
    }else if (a->info.media<5)
    {
        return abb_contaAprovados(a->dir);
    }
    
}

void abb_imprimeAprovados(ABB* a){
    
    if (vazia(a))
    {
        return NULL;
    }else if (a->info.media>=5)
    {
        abb_imprimeAprovados(a->dir);
        printf("matricula %d\n",a->info.matricula);
        printf("nome %s\n",a->info.nome);
		printf("matricula %f\n",a->info.media);
       printf("\n\n");
       abb_imprimeAprovados(a->esq);
       
    }
}

int abb_contaIntervalo(ABB* a,float min,float max){
    
    if (vazia(a))
    {
        return 0;
    }else if (a->info.media<=max&&a->info.media>=min)
    {
        return 1+(abb_contaIntervalo(a->esq,min,max) + abb_contaIntervalo(a->dir,min,max));
    }else if (a->info.media<min)
    {
        return abb_contaIntervalo(a->dir,min,max);
    }else if (a->info.media>max)
    {
        return abb_contaIntervalo(a->esq,min,max);
    }
}

main() {
	
	ABB *abb = abb_cria();
    //abb->info=NULL;
 abb = abb_insere(abb, 456124, "Pedro Duarte", 7.5);
 puts("a");
 abb = abb_insere(abb, 453984, "Ana Silva", 8.8);
 abb = abb_insere(abb, 365597, "Joao Filho", 2.5);
 abb = abb_insere(abb, 687451, "Maria Gomes", 10.0);

 printf("Alunos em ordem crescente de media:\n");
 abb_imprime(abb);
 printf("\nAluno com maior media:\n");
 abb_alunoComMaiorMedia(abb);
 printf("\nNumero de alunos aprovados: %d\n", abb_contaAprovados(abb));
 printf("\nAlunos aprovados em ordem decrescente: \n");
 abb_imprimeAprovados(abb);
 printf("\nNumero de alunos entre 2.5 e 8.5: %d\n",
 abb_contaIntervalo(abb, 8.8, 8.8));


 // FALTA FUNÇÃO LIBERA 
 return 0;
	

}