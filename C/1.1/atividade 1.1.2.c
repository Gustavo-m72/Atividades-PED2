#include <stdio.h>
#include <math.h>
#include <stdlib.h>

main()
{
int m=0,f=0,i=0;
char sexo;
float medf=0,alturaf=0,pessoas[5],maior=0,menor=0;
for (i = 0; i < 5; i++)
{
    printf ("\ndigite seu sexo\n");
    scanf ("%s",&sexo);
    fflush(stdin);
    printf("\n\ndigite sua altura  ");
    scanf("%f",&pessoas[i]);
    if (sexo == 'm') m++;
    if (sexo == 'f')
    {
      alturaf=alturaf + pessoas[i];
      f++; 
    }
   
}
maior=pessoas[0];
menor=pessoas[0];
for ( i = 0; i < 5; i++)
{
  if (pessoas[i]>maior) maior=pessoas[i];
  if (pessoas[i]<menor) menor=pessoas[i];
}


medf=alturaf/f;
printf("\nmaior altura: %f",maior);
printf("\nmenor numero: %f",menor);
printf("\nmedia feminina: %f",medf);
printf("\nnumero de homens: %d",m);
}