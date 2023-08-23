#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 

main()
{
    int participantes,i=0,cont=0;
    do
    {
    cont++;
    printf("\ndigite o numero de participantes");
    scanf("%d",&participantes);
    if (participantes==0)break;
    int ingresso[participantes];
    printf("\ndigite o numero dos ingressos:");
    for ( i = 1; i <= participantes; i++)
    {
        scanf("%d",&ingresso[i]);
    }
    for ( i = 1; i <= participantes; i++)
    {
        if (i==ingresso[i]){
            printf("\nteste %d",cont);
            printf("\n%d",ingresso[i]);
            printf("\n");
        }
    } 
    } while (participantes!=0);
}