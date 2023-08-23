#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 

main()
{
    int canal=0,npessoas=0,canal4=0,canal5=0,canal7=0,canal12=0,i=0,canais=0,ac=0;
    float poc4=0,poc5=0,poc7=0,poc12=0;

    do
    {
        printf("\nnumero de pessoas na casa:  ");
        scanf("%d",&npessoas);
        printf("\ncanal assistido: (4|5|7|12)");
        scanf("%d",&canal);
        if (canal==0)npessoas=0;
        ac=ac+npessoas;
        switch (canal)
        {
            case 4 :canal4+=npessoas;break;
            case 5 :canal5+=npessoas;break;
            case 7 :canal7+=npessoas;break;
            case 12 :canal12+=npessoas;break;
        }
    } while (canal!=0);
    poc4=(canal4*100)/ac;
    poc5=(canal5*100)/ac;
    poc7=(canal7*100)/ac;
    poc12=(canal12*100)/ac;
    printf("\nporcentagem do canal 4: %f",poc4);
    printf("\nporcentagem do canal 5: %f",poc5); 
    printf("\nporcentagem do canal 7: %f",poc7); 
    printf("\nporcentagem do canal 12: %f",poc12);                 
    
}