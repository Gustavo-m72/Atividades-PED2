#include <stdio.h>
#include <math.h>
#include <string.h>

void compara(char palavra[],char copia[]){
    int tam = strcmp(palavra,copia);
    if (tam != 0)printf("infelizmente %s nao eh igual %s",palavra,copia);
    if (tam == 0)printf(" %s eh igual %s",palavra,copia);
}

void inverte(char palavra[],char copia[]){
    char aux;
    int tamstring=strlen(palavra);
    strcpy(copia,palavra);
    
    for(int i = 0; i < tamstring; i++)
    {
            for(int j = i+1; j < tamstring; j++){
            aux=copia[i];
            copia[i]=copia[j];
            copia[j]=aux;
        }
    }
}

main()
{
    char palavra[10];
    char copia[10];
    scanf("%s",palavra);
    inverte(palavra,copia);
    compara(palavra,copia);
}