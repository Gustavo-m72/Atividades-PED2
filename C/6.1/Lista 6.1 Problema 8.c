#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct op
{
    int diagp;
    int diags;
    int tsup;
    int tinf;
}Op;


void cria(int  **matriz, int linha, int coluna){
    //**matriz = malloc(linha*sizeof(int*));

    for (int i = 0; i < linha; i++)
    {
        matriz[i] = malloc(coluna*sizeof(int));
    }
}

void leitura(int **matriz, int linha, int coluna){
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("pos[%d][%d]\n",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }
}

void mostrar(int **matriz,int linha, int coluna){
    printf("\n\n");
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("%4d",matriz[i][j]);
        }
        printf("\n");
    }
}

void busca(int** matriz, int linha, int coluna,int x){
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (matriz[i][j]==x)
            {
                printf("\n\npos: [%d][%d]",i,j);
            }
        }
    }
}

Op operacao(int** matriz, int linha, int coluna){
    
    Op x;
    x.tsup=0;
    x.diagp=0;
    x.tinf=0;
    x.diags=0;
    
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (i<j)//triangular superior
            {
                
                x.tsup+=matriz[i][j];
            }
            if (i==j) //diagonal principal
            {
                x.diagp+=matriz[i][j];
            }
            if (i>j) //triangular inferior
            {
                x.tinf+=matriz[i][j];
            }
        }
    }
    for (int i = 0; i < linha; i++){
        x.diags+=matriz[i][linha-1-i];// diagonal secundaria
    }

    return x;
}

main()
{
    int linha = 2, coluna = 2;
    int **point = malloc(linha*sizeof(int*));
    
    
    cria(point,linha,coluna);
    
    leitura(point,linha,coluna);
    
    mostrar(point,linha,coluna);
    
    Op x=operacao(point,linha,coluna);
    printf("soma diagonal principal:%d\n",x.diagp);
    printf("soma diagonal secundaria:%d\n",x.diags);
    printf("soma triangular inferior:%d\n",x.tinf);
    printf("soma triangular superior:%d\n",x.tsup);
}