#include <stdio.h>
#include <math.h>
#include <stdlib.h>

main()
{
float paisa=90000000,paisb=200000000;
int ano=0;


while (paisb>paisa){
paisa=paisa * 1.03;
paisb=paisb * 1.015;
ano++;    
} 

printf("\n numero de anos necessarios: %d",ano);


}