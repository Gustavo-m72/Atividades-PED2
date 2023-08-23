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

void maior10(int **matriz,int linha, int coluna){
    int x=0;
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (matriz[i][j]>10)
            {
                x++;
            }
        }
    }
    printf("maiores que 10: %d\n",x);
}

main()
{
    int linha = 2, coluna = 2;
    int **point = malloc(linha*sizeof(int*));
    cria(point,linha,coluna);
    /*for (int i = 0; i < linha; i++)
    {
        point[i] = malloc(coluna*sizeof(int));
    }*/
    leitura(point,linha,coluna);
    mostrar(point,linha,coluna);
    maior10(point,linha,coluna);

    
}
