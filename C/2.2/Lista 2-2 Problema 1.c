#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main()
{
    int v=0,i;
    char palavra[10],inverso[10];

    scanf("%s",palavra);
    printf("\n%s",palavra);
    
    for (i = 0;palavra[i]; i++)
    {
        palavra[i]=tolower(palavra[i]); //tolower deixa a palavra toda minuscula
    }
    printf("\n%s",palavra);
    strcpy(inverso,palavra); //copia palavra para inverso

    strrev(inverso); //inverte
    printf("\n%s",inverso);

    v = strcmp(palavra,inverso);// compara 2 string e verifica se são iguais, se iguais retorna zero
    if (v==0)
    {
        printf ("\npalavra %s eh igual seu inverso %s",palavra,inverso);
    }
    else
    {
        printf("\npalavra %s nao eh igual seu inverso %s",palavra,inverso);
    }
    

}


