#include <stdio.h>
#include <stdlib.h>

struct registro
{
    int idade;
    char sexo[1];
    float salario;
    int filhos;
};
typedef struct registro Registro;

void entrada(Registro *pessoa, int TAM){
    int j;
    for (int i = 0; i < TAM; i++)
    {
        j=i;
        printf("\nDigite idade do %d habitante: ",j+1);
        scanf("%d",&pessoa[i].idade);
        printf("\nDigite sexo do %d habitante: ",j+1);
        scanf("%s",pessoa[i].sexo);
        printf("\nDigite salario do %d habitante: ",j+1);
        scanf("%f",&pessoa[i].salario);
        printf("\nDigite numero de filhos do %d habitante: ",j+1);
        scanf("%d",&pessoa[i].filhos);
    }
}

void saida(Registro *p,int TAM){
    int j;
    for (int i = 0; i < TAM; i++)
    {
        j=i;
        printf("\nidade do %d habitante : %d",j+1,p[i].idade);
        
        printf("\nDigite sexo do %d habitante: %s",j+1,p[i].sexo);
        
        printf("\nDigite salario do %d habitante: %0.02f",j+1,p[i].salario);
        
        printf("\nDigite numero de filhos do %d habitante: %d",j+1,p[i].filhos);
        printf("\n\n\n");
    }
}


main()
{
    int TAM=2;
    Registro *pessoa = (Registro*) malloc(TAM*sizeof(Registro*));
    entrada(pessoa,TAM);
    saida(pessoa,TAM);
    return 0;
}
