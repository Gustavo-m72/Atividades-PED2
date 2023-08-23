#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 

main()
{    
int nsim=0,nnao=0,n=2,i,f=0,m=0;
char escolha,sexo;
int pfs=0,pmn=0;
float mf=0,mm=0;

for (i = 0; i < n; i++)
{
printf("\ndigite o sexo: ");
fflush(stdin);
scanf("%s",&sexo);
fflush(stdin);
printf("\ndigite esocolha: (sim | nao)");
scanf("%c",&escolha);
if (sexo == 'f')f++;
if (sexo == 'm')m++;
if (sexo == 'f' && escolha == "sim")pfs++;
if (sexo == 'm' && escolha == "nao")pmn++;
if ( escolha == "nao")nnao++;
if ( escolha == "sim")nsim++;
}
mm=(pmn*100)/m;
mf=(pfs*100)/f;
printf("\nsim: %d",nsim);
printf("\nnao: %d",nnao);
printf("\na porcentagem de pessoas do sexo feminino que responderam sim %f",mf);
printf("\na porcentagem de pessoas do sexo masculino que responderam não %f",mm);

}