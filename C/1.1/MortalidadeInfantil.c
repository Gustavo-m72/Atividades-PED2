#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main(){
    char sexo; 
    int op , nasc,meses, morte,m=0,f=0,twentyfive=0;
    float total, pm,p25;
    printf("\ndigite o numero de crincas nascidas no periodo    ");
    scanf("%d",&nasc);
op=1;
   while (op!=0)
    { 
        printf("\ndigite o sexo da crianca (f - feminino | m - masculino):     ");
        scanf("%s",&sexo);
        if (sexo == 'm') m++;
        if (sexo == 'f') f++;
        if (sexo != 'm' && sexo !='f') break;
        printf("\n digite os meses de vida da crianca   ");
        scanf("%d",&meses);
        if (meses <= 25) twentyfive++;
    }
    morte = m+f;
    total = (morte*100)/nasc; 
    pm = (m*100)/morte;
    p25 = (twentyfive*100)/morte; 
    printf("\na porcentagem total é %f\n",total); 
    printf("\na porcentagem de mortes com menos de 25 meses é %f\n",p25);
    printf("\na porcentagem de meninos mortos é %f\n",pm);



} 