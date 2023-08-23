#include <stdio.h>
#include <stdlib.h>

int somatorio(int x){
    int s=0,a=1;
    
    if (x==0)
    {
        return 0;
    }else
        return (somatorio(x-1)+(x+1));
}

main()
{
    int x=3;
    x = somatorio(x);
    printf("\n%d ",x); 
}
