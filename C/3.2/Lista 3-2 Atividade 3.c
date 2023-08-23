#include <stdio.h>
#include <stdlib.h>

int potenciarecursiva(int x){
    int s=0,a=1;
    
    if (x==0)
    {
        return 0;
    }else
        return (potenciarecursiva(x-1)+pow(x,3));;
}

main()
{
    int x;
    scanf("%d",&x);
    x = potenciarecursiva(x);
    printf("\n%d ",x); 
}
