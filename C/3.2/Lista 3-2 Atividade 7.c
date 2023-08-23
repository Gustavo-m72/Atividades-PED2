#include <stdio.h>
#include <stdlib.h>

int naturais(int x){
    
    
    if (x==0)
    {
        return 0;
    }else
        printf("%d, ",x);
        return (naturais(x-1));
}

main()
{
    int x=10;
    x = naturais(x);
    printf("%d ",x); 
}