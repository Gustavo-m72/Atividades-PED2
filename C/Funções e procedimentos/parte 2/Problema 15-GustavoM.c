#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct  Vetor
{
    int vetor1[10];
    int vetor2[10];
    int vetor3[20];
}Vetor;

struct Vetor leitura(struct Vetor vetores){
    printf("\n vetor 1:");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&vetores.vetor1[i]);
    }
    printf("\n vetor 2:");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&vetores.vetor2[i]);
    }
    return vetores;
}

struct Vetor uniao(struct Vetor vetores){
    for (int i = 0; i < 10; i++)
    {
        vetores.vetor3[i]=vetores.vetor1[i];
        vetores.vetor3[i+10]=vetores.vetor2[i];
    }
    return vetores;
};

struct Vetor ordena(struct Vetor vetores){
    int aux;
    for (int i = 0; i < 20; i++)    
    {
        for (int j = i+1; j < 20; j++)
        {
            if (vetores.vetor3[i]<vetores.vetor3[j])
            {
                aux = vetores.vetor3[i];
                vetores.vetor3[i]=vetores.vetor3[j];
                vetores.vetor3[j]=aux;
            }   
        }   
    }
return vetores;
}

main()
{
    struct Vetor vetores;
    
    vetores = leitura(vetores);
    
    vetores = uniao(vetores);
    
    vetores = ordena(vetores);
    
    printf("\n uniao dos vetores:");
    for (int i = 0; i < 20; i++)
    {
        printf("\n%d",vetores.vetor3[i]);
    } 
}
