#include <stdio.h>
#include <math.h>
#include <stdlib.h>

main()
{
int h=0,m=0,s=0;
float massai;

printf ("\ndigite a massa do material em gramas:  ");
scanf("%f",&massai);

while (massai>0.5)
{
massai=massai/2;
s=s+50; 

}
h=s/3600;
s=s-h*3600;
m=s/60;
s=s-m*60;
s=s;


printf("\nhoras: %d",h);
printf("\nminutos: %d",m);
printf("\nsegundos: %d",s);
}