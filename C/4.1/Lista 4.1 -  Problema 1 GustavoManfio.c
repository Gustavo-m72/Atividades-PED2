#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no {
    float info;
    struct no* prox;
};
typedef struct no No;

typedef struct pilha {
    No* prim;
}Pilha;

Pilha* cria (void)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
 return p;
}


No* ins_ini (No* l, float v)
{
    No* p = (No*) malloc(sizeof(No));
    p->info = v;
    p->prox = l;
    return p;
}


No* ret_ini (No* l)
{
    No* p = l->prox;
    free(l);
    return p;
}

void push (Pilha* p, float v)
{
    p->prim = ins_ini(p->prim,v);
}

int vazia (Pilha* p)
{
    return (p->prim==NULL);
}

float pop (Pilha* p)
{
    float v;
    if (vazia(p)) {
        printf("Pilha vazia.\n");
        exit(1); 
    }
    v = p->prim->info;
    p->prim = ret_ini(p->prim);
    return v;
}

void libera (Pilha* p)
{
    No* q = p->prim;
    while (q!=NULL) {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

//COMECA AS FUNCOES DA ATIVIDADE 1

typedef struct calc {
    char f[21]; /* formato para impressão */
    Pilha* p; /* pilha de operandos */
}Calc;

void libera_calc (Calc* c)
{
 libera(c->p);
 free(c);
}

Calc* cria_calc (char* formato)
{
    Calc* c = (Calc*) malloc(sizeof(Calc));
    strcpy(c->f,formato);
    c->p = cria(); 
    return c;
}

void operando (Calc* c, float v)
{
    /* empilha operando */
    push(c->p,v);
    /* imprime topo da pilha */
    printf(c->f,v);
}

void operador (Calc* c, char op)
{
    float v1, v2, v;
 
    if (vazia(c->p))
        v2 = 0.0;
    else
        v2 = pop(c->p);
    if (vazia(c->p))
        v1 = 0.0;
    else
        v1 = pop(c->p);

    switch (op) {
        case '+': v = v1+v2; break;
        case '-': v = v1-v2; break;
        case '*': v = v1*v2; break;
        case '/': v = v1/v2; break;
 }
 /* empilha resultado */
    push(c->p,v);
 /* imprime topo da pilha */
    printf(c->f,v);
}

/* Programa para ler expressão e chamar funções da calculadora */

int main (void)
{
    char c;
    float v;
    Calc* calc;
/* cria calculadora com precisão de impressão de duas casas decimais
*/
    calc = cria_calc("%.2f\n");
    do {
 /* le proximo caractere nao branco */
        scanf(" %c",&c);
 /* verifica se e' operador valido */
        if (c=='+' || c=='-' || c=='*' || c=='/') {
            operador(calc,c);
        }
 /* devolve caractere lido e tenta ler número */
        else {
            ungetc(c,stdin);
            if (scanf("%f",&v) == 1)
                operando(calc,v);
        }
    } while (c!='q');
    libera_calc(calc);
 return 0;
}