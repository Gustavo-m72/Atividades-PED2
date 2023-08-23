#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{ int Entry; // chave
int count; // contador 
int bal; // -1, 0, +1
struct TreeNode *LeftNode, *RightNode; //subárvores
};
typedef struct TreeNode TreePointer;



void SearchInsert(int x, TreePointer *pA, int *h)
{ TreePointer *pB, *pC;
if(pA == NULL) // inserir
{ pA = malloc(sizeof(TreePointer));
h = 1;
pA->Entry = x;
pA->count = 1;
pA->LeftNode = pA->RightNode = NULL;
pA->bal = 0;
}else
if(x < pA->Entry)
{ SearchInsert(x, pA->LeftNode, &h);
if(h) // subárvore esquerda cresceu
{ switch (pA->bal)
{ case -1: pA->bal = 0; h = 0; break;
case 0: pA->bal = +1; break;
case +1: pB = pA->LeftNode;
if(pB->bal == +1) // rotação LL
{ pA->LeftNode = pB->RightNode; pB->RightNode = pA;
pA->bal = 0; pA = pB;
}
else // rotação LR
{ pC = pB->RightNode; pB->RightNode = pC->LeftNode;
pC->LeftNode = pB; pA->LeftNode = pC->RightNode;
pC->RightNode = pA;
if(pC->bal == +1) pA->bal = -1; else pA->bal = 0;
if(pC->bal == -1) pB->bal = +1; else pB->bal = 0;
pA = pC;
}
pA->bal = 0; h = 0;
} // switch
}
}else
if(x > pA->Entry)
{ SearchInsert(x, pA->RightNode, &h);
if(h) // subárvore direita cresceu
{ switch (pA->bal)
{ case +1: pA->bal = 0; h = 0; break;
case 0: pA->bal = -1; break;
case -1: pB = pA->RightNode;
if(pB->bal == -1) // rotação RR
{ pA->RightNode = pB->LeftNode; pB->LeftNode = pA;
pA->bal = 0; pA = pB;
}
else // rotação RL
{ pC = pB->LeftNode; pB->LeftNode = pC->RightNode;
pC->RightNode = pB; pA->RightNode = pC->LeftNode;
pC->LeftNode = pA;
if(pC->bal == -1) pA->bal = +1; else pA->bal = 0;
if(pC->bal == +1) pB->bal = -1; else pB->bal = 0;
pA = pC;
}
pA->bal = 0; h = 0;
} // switch
}
}else // elemento encontrado
pA->count++;
}


void balanceL(TreePointer *pA, int *h)
{ TreePointer *pB, *pC;
int balB, balC;
// subarvore esquerda encolheu
switch(pA->bal)
{ case +1: pA->bal = 0; break;
case 0: pA->bal = -1; h = 0; break;
case -1:
pB = pA->RightNode; balB = pB->bal;
if(balB <= 0) // rotacao RR
{ pA->RightNode = pB->LeftNode;
pB->LeftNode = pA;
if(balB == 0)
{ pA->bal = -1; pB->bal = +1; h = 0; }
else
{ pA->bal = 0; pB->bal = 0; }
pA = pB;
}
else // rotacao RL
{ pC = pB->LeftNode; balC = pC->bal;
pB->LeftNode = pC->RightNode;
pC->RightNode = pB;
pA->RightNode = pC->LeftNode;
pC->LeftNode = pA;
if(balC==-1) pA->bal=+1; else pA->bal=0;
if(balC==+1) pB->bal=-1; else pB->bal=0;
pA = pC; pC->bal = 0;
}
}
}

void balanceR(TreePointer *pA, int *h)
{ TreePointer *pB, *pC;
int balB, balC;
// subarvore direita encolheu
switch(pA->bal)
{ case -1: pA->bal = 0; break;
case 0: pA->bal = +1; h = 0; break;
case +1:
pB = pA->LeftNode; balB = pB->bal;
if(balB >= 0) // rotacao LL
{ pA->LeftNode = pB->RightNode;
pB->RightNode = pA;
if(balB == 0)
{ pA->bal = +1; pB->bal = -1; h = 0; }
else
{ pA->bal = 0; pB->bal = 0; }
pA = pB;
}
else // rotacao LR
{ pC = pB->RightNode; balC = pC->bal;
pB->RightNode = pC->LeftNode;
pC->LeftNode = pB;
pA->LeftNode = pC->RightNode;
pC->RightNode = pA;
if(balC==+1) pA->bal=-1; else pA->bal=0;
if(balC==-1) pB->bal=+1; else pB->bal=0;
pA = pC; pC->bal = 0;
}
}
}

void DelMin(TreePointer *q, TreePointer *r,int *h)
{
if(r->LeftNode != NULL)
{ DelMin(q, r->LeftNode, &h);
if(h)
balanceL(r,&h);
}
else
{ q->Entry = r->Entry;
q->count = r->count;
q = r;
r = r->RightNode;
h = 1;
}
}

void Delete(int x,TreePointer *p, int *h)
{ TreePointer *q;
if(p == NULL)
{ printf("Elemento inexistente");
abort();
}
if(x < p->Entry)
{ Delete(x,p->LeftNode,&h);
if(h)
balanceL(p,&h);
}
else
if(x > p->Entry)
{ Delete(x,p->RightNode,&h);
if(h)
balanceR(p,&h);
}
else // remover p->
{ q = p;
if(q->RightNode == NULL)
{ p = q->LeftNode;
h = 1;
}
else
if(q->LeftNode == NULL)
{ p = q->RightNode;
h = 1;
}
else
{ DelMin(q,q->RightNode,&h);
if(h)
balanceR(p,&h);
}
free(q);
}
}
int main()
{
    TreePointer *a=malloc(sizeof(TreePointer));
    int h;
    SearchInsert(10,a,h);
    printf("%d",a->Entry);
    return 0;
}