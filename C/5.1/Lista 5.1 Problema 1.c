#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int fibonacci(int x){
    
    if (x==1||x==2)
    {
        return 1;
    }else
        return (fibonacci(x-1)+fibonacci(x-2));
}


int main()
{
    int x;
    scanf("%d",&x);
    x = fibonacci(x);
    for (int i = 0; i < x; i++){
        printf(" %d ",fibonacci(i+1));
        
    } 
}