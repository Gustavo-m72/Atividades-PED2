#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int potencia(int base,int y){
    if (y==0) return 1;
    if (y==1) 
        return base;
    return base * potencia(base,y-1);   
}

main()
{
    int base,y,resultado;
    scanf("%d",&base);
    scanf("%d",&y);
    resultado = potencia(base,y);
    printf("\n%i",resultado);

}

