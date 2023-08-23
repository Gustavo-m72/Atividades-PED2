#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int mdc(int x,int y){
    if (x<y)
    {
        return mdc(y,x);
    }else{
        if (x % y == 0)
        {
            return y;
        }else
        {
            return mdc(y,x%y);
        }
    }
}

int main()
{
    int x=50,y=7;
    
    x = mdc(x,y);
    printf("\n%d ",x); 
}