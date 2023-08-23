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

struct media
{
   float mediasalario;
   int maioridade;
   int menoridade;
   int mulheres;
};
typedef struct media Media;

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

Media* calcular(Registro *pessoa,int TAM){
    
    Media *medias = (Media*) malloc(sizeof(Media*));
    
    medias->maioridade=pessoa[0].idade;
    medias->menoridade=pessoa[0].idade;
    medias->mediasalario=0;
    medias->mulheres=0;

    for (int i = 0; i < TAM; i++)
    {
        
        if (medias->maioridade < pessoa[i].idade)
        {
            medias->maioridade=pessoa[i].idade;
        }
        
        if (medias->menoridade > pessoa[i].idade)
        {
            medias->menoridade=pessoa[i].idade;
        }
        
        medias->mediasalario+=pessoa[i].salario;
        
        if (pessoa[i].sexo == 'f' && pessoa[i].salario <= 500 && pessoa[i].filhos == 3)
        {
            medias->mulheres++;
        }     
    }
    
    medias->mediasalario = medias->mediasalario/TAM;
    
    return medias;
}

main()
{
    int TAM=2;
    Registro *pessoa = (Registro*) malloc(TAM*sizeof(Registro*));
    Media *medias = (Media*) malloc(sizeof(Media*));
    entrada(pessoa,TAM);
    saida(pessoa,TAM);
    medias = calcular(pessoa,TAM);
    
    printf("\nmedia de salario: %0.02f", medias->mediasalario);
    printf("\nmaior idade: %d", medias->maioridade);
    printf("\nmenor idade: %d", medias->menoridade);
    printf("\nnumero de mulheres com 3 filhos que recebem ate 500 reais: %d",medias->mulheres);

    return 0;
}