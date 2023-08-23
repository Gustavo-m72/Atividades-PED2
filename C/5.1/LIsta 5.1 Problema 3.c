#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int somatorio(int x[],int tam){
    if (tam<0)
    {
        return 0;
    }else{
        printf("%d\n",x[tam]);
        return (somatorio(x,tam-1)+(x[tam]));
    }
}

int main()
{
    int tam=5;
    int x[5]={1,2,3,4,5};
    

    tam = somatorio(x,tam-1);
    printf("\n%d ",tam); 
}