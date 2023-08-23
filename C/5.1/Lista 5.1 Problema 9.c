
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int k=0;
int buscar(int x,int busca){
    int i;
    if (x==0)
    {
        //printf("ocorre: %d",k);
        return 0;
    }else{
        i=x%10;
        if (i==busca)
        {
            //k++;
            x=x/10;
        return 1+buscar(x,busca);
        }
        x=x/10;
        return buscar(x,busca);
    }
}

int main()
{
    int x=762021192,busca=0;
    
    printf("%d",buscar(x,busca));
    
     
}