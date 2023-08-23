#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 

main()
{

int n=0,acumulador=0,i;

do
{
acumulador=0;
printf("\ndigite um numero inteiro e positivo:  ");
scanf("%d",&n);
for (i = 1; i < n; i++)
{
    if (n % i == 0){
        printf("%d",i);
        acumulador=acumulador + i;
    }
}
if(acumulador == n)printf("\nnumero perfeito: %d",n);
} while (n!=0);
}

