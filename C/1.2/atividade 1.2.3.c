#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 

main()
{

int n,i;

do
{
printf("\ndigite um numero inteiro e positivo:  ");
scanf("%d",&n);
for (i = 0; i <= n; i++)
{
    if (i*i==n)printf("\neh um quadrado perfeito");
}

} while (n!=0);

}