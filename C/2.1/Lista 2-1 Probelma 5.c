#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void transposta(int linha,int coluna){
    int matriz[linha][coluna], transp[linha][coluna];
    
    for(int i=0; i<linha;i++){
        for (int j = 0; j < coluna; j++)
        {
            scanf("%d",&matriz[i][j]);
        }
    }
    
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++){
            printf("%4d",matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; i < coluna; i++)
        {
            transp[i][j]=matriz[j][i];
        }
    }
    
    for (int i = 0; i < coluna; i++)
    {
        for (int j = 0; j < linha; j++){
            printf("%4d",transp[i][j]);
        }
        printf("\n");
    }
}

main()
{
    int linha, coluna; 
    printf("digite o tamanho da matriz linhas | colunas:");
    scanf("%d",&linha);
    scanf("%d",&coluna);
    transposta(linha,coluna);
    
    return 0;
}
