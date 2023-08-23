#include <stdio.h>
#include <math.h>
#include <stdlib.h>


main()
{
float med=0.0;
int idade,op=0,i=1;
printf("\n digite a idade  ");
scanf("%d",&idade);
op=op+idade;
while (idade!=0)
{
    printf("\n digite a idade  ");
    scanf("%d",&idade);
    op=op+idade;
    i++;
    if (idade==0)i--;
      
}
printf("\n%d  %d",i,op);
med = op/i;
printf("\nmedia = %0.02f",med);
}
