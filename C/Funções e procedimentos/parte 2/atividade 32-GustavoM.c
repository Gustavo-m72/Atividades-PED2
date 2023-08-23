#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct  Matriz
{
    int m;
    int matriz[6][6];
    int vetor[36];
}Matriz;

struct Matriz leitura(struct Matriz gato){
    printf("\n digite multiplicador: ");
    scanf("%d",&gato.m);
    printf("\n digite matriz: ");
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("\n linha %d coluna %d: ",i,j);
            scanf("%d",&gato.matriz[i][j]);
        }
    }
    return gato;
}

struct Matriz multiplacao(struct Matriz gato){
    int x=0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
        gato.vetor[x] = gato.m * gato.matriz[i][j];
        x++;
        }
    }    
    return gato;
}

main()
{
    struct Matriz gato;
    gato = leitura(gato);
    gato = multiplacao(gato);
    for (int i = 0; i < 36; i++)
    {
        printf("\n%d",gato.vetor[i]);
    }
}
