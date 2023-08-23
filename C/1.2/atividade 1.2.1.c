#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 

main()
{

int n=0,contador=0,i;

do
{
contador=0;
printf("\ndigite um numero inteiro e positivo:  ");
scanf("%d",&n);
for (i = 1; i <= n; i++)
{
    if (n % i == 0)contador++;
}
if (contador==2)printf("\nprimo: %d",n);
} while (n!=0);

}