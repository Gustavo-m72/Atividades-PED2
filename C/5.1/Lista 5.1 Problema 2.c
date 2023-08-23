#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int inverte(int x){
    if (x==0)
    {
        return x;
    }else{
        printf("%d",x%10);
        x=x/10;
        return inverte(x);
    }
}

int main()
{
    int x;
    scanf("%d",&x);
    inverte(x);
     
}