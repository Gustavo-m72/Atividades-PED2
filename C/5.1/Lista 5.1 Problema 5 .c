#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int potencia(int x,int esp){
    if (esp==1)
    {
        return x;
    }else{
        printf("%d\n", x);
        return (x*potencia(x,esp-1));
    }
}

int main()
{
    int x=2,esp=2;
    
    x = potencia(x,esp);
    printf("\n%d ",x); 
}