#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int fato(int n){
    int fatorial=1;
    for (int i = n; i > 0; i--)
    {
        fatorial = fatorial * i;
    }
    return fatorial;
}

float cao(int n){
    float s=0;

    s= (1+1/fato(1))+(fato(1)/fato(2))+(1/fato(3))+(1/fato(n));
    printf("%f",s);
    return s;
}

main()
{
int n;
float resultado;
printf("digite n: \n");
scanf("%i",&n);

resultado=cao(n);

printf("%f",resultado);
}
