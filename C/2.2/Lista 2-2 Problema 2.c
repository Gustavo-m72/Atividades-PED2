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

int determinante(int **matriz){
    int dp1,dp2,dp3,determinante,det1,det2;
    int ds1,ds2,ds3;

    dp1=((matriz[0][0])*(matriz[1][1])*(matriz[2][2]));
    dp2=((matriz[0][1])*(matriz[1][2])*(matriz[2][0]));
    dp3=((matriz[0][2])*(matriz[1][0])*(matriz[2][1]));
    ds1=(matriz[2][0]*matriz[1][1]*matriz[0][2]);
    ds2=(matriz[2][1]*matriz[1][2]*matriz[0][0]);
    ds3=(matriz[2][2]*matriz[1][0]*matriz[0][1]);
    det1=(dp1+dp2+dp3);
    det2=(ds1+ds2+ds3);
    determinante=det1-det2;
    printf("determinante eh %d",determinante);
    return determinante;
    
   /*2
5
6
1
6
7
-1
2
3*/
}

main()
{
    int linha = 3, coluna = 3;
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
    determinante(point);   
    printf("\n");

   
}