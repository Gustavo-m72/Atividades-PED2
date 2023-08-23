#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Triangulo
{
    int x;
    int y;
    int z;
}Triangulo;

struct Triangulo leitura(struct Triangulo lado){
    printf("\n Digite lado X: ");    
    scanf("%d",&lado.x);
    
    printf("\n Digite lado Y: ");    
    scanf("%d",&lado.y);

    printf("\n Digite lado Z: ");    
    scanf("%d",&lado.z);
    printf("\n %d %d %d", lado.x,lado.y,lado.z);
    return lado;
}

struct Triangulo verifica(struct Triangulo lado)
{
    if (lado.x < lado.y + lado.z && lado.y < lado.x + lado.z && lado.z < lado.x + lado.y)
    {
        printf("\t eh um triangulo");
        printf("\nTIPO: ");
        return lado;
    }
    else
    { printf("\n invalido, digite novamente: ");
    lado=leitura(lado);
    return lado;
    }
}


struct Triangulo tipo(struct Triangulo lado){
    printf("\n %d %d %d", lado.x,lado.y,lado.z);
    while (1){
        
        if (lado.x == lado.y && lado.x == lado.z && lado.y == lado.z)
        {
            printf("\n Triangulo Equilatero");
            break;
        }

        if (lado.x == lado.z && lado.x != lado.y)
        {
            printf("\n Triangulo Isoceles");
            break;
        }
        
        if (lado.x == lado.y && lado.x != lado.z)
        {
            printf("\n Triangulo Isoceles");
            break;
        }

        if (lado.y == lado.z && lado.y != lado.x)
        {
            printf("\n Triangulo Isoceles");
            break;
        }

        if (lado.x != lado.z && lado.x != lado.y && lado.y != lado.z)
        {
            printf("\n Triangulo Escaleno");
            break;
        }
    }
}

main()
{
    
    struct Triangulo lado;

    lado=leitura(lado);
   
    lado=verifica(lado);

    tipo(lado);

}
