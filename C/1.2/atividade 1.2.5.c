#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
int fatorial(int x);
int comb(int linha, int coluna);
main()
{
    int linha,coluna,nl,num;
    printf("\n numero de linhas:");
    scanf("%d",&nl);

    for (linha = 0; linha <= nl; linha++)
    {
        for ( coluna = nl-linha; coluna != 0; coluna--)
        {
            printf("   ");
        }
        for (coluna = 0; coluna <= linha; coluna++)
        {
            num=comb(linha,coluna);
            printf(" %4d ",num);        
        }
        printf("\n");        
    }
    
}

int fatorial(int x)
{
    int i, fatorial=1;
    for ( i = x; i > 0; i--)
    {
        fatorial=fatorial*i;
    }
    return fatorial;
}

int comb(int linha, int coluna)
{
    return fatorial(linha) / (fatorial(coluna) * fatorial(linha-coluna));

}
