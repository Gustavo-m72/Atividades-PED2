//Crie uma função recursiva que receba um número 
//inteiro positivo N e calcule o somatório dos números de 1 a N. 
//GustavoM
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int somatorio(int x){
    if (x==0)
    {
        return 0;
    }else
        return (somatorio(x-1)+x);
}

int main()
{
    int x;
    scanf("%d",&x);
    x = somatorio(x);
    printf("\n%d ",x); 
}
