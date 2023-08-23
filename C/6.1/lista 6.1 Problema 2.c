#include <stdlib.h>
#include <math.h>
#include <stdio.h>

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
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("%4d",matriz[i][j]);
        }
        printf("\n");
    }
}

void diagona1(int **matriz,int linha, int coluna){
    int x=0;
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (i==j)
            {
                matriz[i][j]=1;
            }else{
                matriz[i][j]=0;    
            }
        }
    }
    printf("\n nova matriz:\n");
    mostrar(matriz,linha,coluna);
}

main()
{
    int linha = 2, coluna = 2;
    int **point = malloc(linha*sizeof(int*));
    cria(point,linha,coluna);
    leitura(point,linha,coluna);
    mostrar(point,linha,coluna);
    diagona1(point,linha,coluna);
}