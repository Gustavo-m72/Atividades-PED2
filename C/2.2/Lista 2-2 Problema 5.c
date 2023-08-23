#include <stdio.h>
#include <math.h>
#include <stdlib.h>



void leitura(int **matriz,int linha, int coluna){
    for (int i = 0; i < linha; i++)
    {
    for (int j = 0; j < coluna; j++)
        scanf("%d",&matriz[i][j]);
    }
}

void mostrar(int **matriz,int linha, int coluna){

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++){
            printf("%4d",matriz[i][j]);
        }
        printf("\n");
    }
}

void triangularinferior(int **matriz, int linha, int coluna){
    
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++){
            if (matriz[j]>matriz[i])matriz[i][j]=0;
        }
    }
}

main()
{
    int linha = 8, coluna = 8;
    int **point = malloc(linha*sizeof(int*)), maior;
    for (int i = 0; i < linha; i++)
    {
        point[i] = malloc(coluna*sizeof(int));
    }
    leitura(point,linha,coluna);
    printf("\n\n matriz normal: ");
    printf("\n");
    mostrar(point,linha,coluna);
    printf("\n");
    printf("\n\nmatriz triangular inferior: ");
    printf("\n");
    triangularinferior(point,linha,coluna);
    mostrar(point, linha, coluna);
}