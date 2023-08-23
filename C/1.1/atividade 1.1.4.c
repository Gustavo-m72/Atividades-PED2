#include <stdio.h>
#include <math.h>
#include <stdlib.h>

main()
{
float compra=0,venda=0,lucro=0;
char nome[15];
int merc10=0,merc1020=0,merc20=0,op;

do
{
    printf("\nnome: ");
    scanf("%c",&nome);
    fflush(stdin);
    printf("\nvalor de compra: ");
    scanf("%f",&compra);
    printf("\nvalor de venda: ");
    scanf("%f",&venda);
    if (venda<compra*1.10)merc10++;
    if (venda>=compra*1.10&&venda<=compra*1.10)merc1020++;
    if (venda>compra*1.20)merc20++;
    
printf("\n1- continuar | 0- sair\n");
scanf("%d",&op);
}while (op!=0);

printf("\nmenor que 10%%: %d",merc10);
printf("\nentre 10%% e 20%%: %d",merc1020);
printf("\nmaior que 20%%: %d",merc20);
printf("\nlucro total: R$%0.02f",lucro=venda-compra);
}