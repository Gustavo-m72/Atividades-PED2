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
    if (i*i==n){
        printf("\nobedece a primeira regra");
        if (n % 2 == 0 && i % 2 == 0)
        {
            printf("\nobedece a terceira regra");

        }
        if (n % 4 == 0 && i % 4 == 0)
        {
            printf("\nobedece a quarta regra");
            
        }
        if (n % 2 != 0 && i % 2 != 0)
        {
            printf("\nobedece a quinta regra");
            if (n % 8 == 1)
        {
            printf("\nobedece a sexta regra");
            
        }
        }
    }
}

} while (n!=0);

}