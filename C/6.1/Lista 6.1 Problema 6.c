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

int** matrizmaior(int** matriz,int** matriz2, int linha, int coluna){
    
    int **point = malloc(linha*sizeof(int*));
    int tam=linha*coluna,x=0;
    int maior[tam];
    cria(point,linha,coluna);
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (matriz[i][j]<matriz2[i][j])
            {
                //maior[x]=matriz2[i][j];
                //x++;
                point[i][j]=matriz2[i][j];
            }else{
               // maior[x]=matriz[i][j];
                //x++;
                point[i][j]=matriz[i][j];
            }
        }
    }
    /*for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (matriz[i][j]==x)
            {
                point[i][j]=
            }
        }
    }*/
    return point;
}

main()
{
    int linha = 2, coluna = 2;
    int **point = malloc(linha*sizeof(int*));
    int **matriz2 = malloc(linha*sizeof(int*));
    int **matrizm = malloc(linha*sizeof(int*));
    cria(point,linha,coluna);
    cria(matriz2,linha,coluna);
    leitura(point,linha,coluna);
    leitura(matriz2,linha,coluna);
    matrizm=matrizmaior(point,matriz2,linha,coluna);
    mostrar(point,linha,coluna);
    mostrar(matriz2,linha,coluna);
    mostrar(matrizm,linha,coluna);

}