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

int maiordiagonalp(int **matriz, int linha, int coluna){
    int maior = matriz[0][0];
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++){
            if (i==j){
                if(maior<matriz[i][j])maior=matriz[i][j]; 
            }
        }
    }
    return maior;
}

int somadiagonalsec(int **matriz, int linha, int coluna){
    int soma=0;
    
    for (int i = 0; i < linha; i++)
    {

        soma+=matriz[i][coluna-1-i];  
    }
    return soma;
}

main()
{

    int linha = 2, coluna = 2,maior,soma;
    int **point = malloc(linha*sizeof(int*));
    for (int i = 0; i < linha; i++)
    {
        point[i] = malloc(coluna*sizeof(int));
    }
    leitura(point,linha,coluna);
    printf("\n\n matriz normal: ");
    printf("\n");
    mostrar(point,linha,coluna);
    printf("\n");
    printf("\n\nsoma diagonal secunadaria || maior valor diagonal principal: ");
    maior = maiordiagonalp(point,linha,coluna);
    soma = somadiagonalsec(point,linha,coluna);
    printf("\n%d \t\t\t\t %d",soma, maior);
}