#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Pos 
{
    int linha;
    int coluna;
    int maior;
}Pos;


void leitura(int **matriz){
    for (int i = 0; i < 2; i++)
    {
    for (int j = 0; j < 2; j++)
        scanf("%d",&matriz[i][j]);
    }
}

struct Pos maioral(int **matriz){
     Pos posicao;
    posicao.maior=matriz[0][0];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++){
            if (posicao.maior < matriz[i][j])
            {
                posicao.maior = matriz[i][j];
                posicao.linha = i;
                posicao.coluna = j; 
            }
        }
    }
    return posicao;
}

void mostrar(int **matriz){

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++){
            printf("%4d",matriz[i][j]);
        }
        printf("\n");
    }
}

main()
{
    struct Pos posicao;
    int **point = malloc(2*sizeof(int*)), maior;
    for (int i = 0; i < 2; i++)
    {
        point[i] = malloc(2*sizeof(int));
    }
    leitura(point);
    mostrar(point);
    posicao = maioral(point);
    printf("maior: %d, pos Linha: %d | Coluna: %d\n", posicao.maior, posicao.linha,posicao.coluna);
}
