#include <stdio.h>
#include <math.h>
#include <stdlib.h>

main()
{
int f=0,i=50,n=150;
float c;
for (i = 50; i <= 150; i++)
{
c=(i-32)*5/9;
printf("\n\ncelsius: %0.02f  |  fahrenheit %d",c,i);    
}
}    