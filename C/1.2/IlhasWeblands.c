#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{
  int y=0;
  int i=0,j=0,k=0,l=0,v=0,x=0;

  //entrada
   do{
    printf("\nvalor | 0 - para sair \n");   
    scanf("%d",&v);
    if (v==0)break;
    x=v;
    y++;    
    i=v/50;
    v=v-i*50;
    j=v/10;
    v=v-j*10;
    k=v/5;
    v=v-k*5;
    l=v;
    printf("\n teste %d\n",y);
    printf("\n%d %d %d %d\n",i,j,k,l);
    printf("\n\n");
  }while (x!=0);



}

