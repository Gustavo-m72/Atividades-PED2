#include <stdio.h>
#include <math.h>
#include <stdlib.h>

main()
{
int nmalunos[4],mat=0,ptotal=0,i,x,pt[4]={0,0,0,0};
float pturma[4];
char turma[1][4],pres;
for ( i = 0; i < 4; i++)
{
    printf("\nidentificacao da turma: ");
    scanf("%s",&turma[i]);
    printf("numero de alunos matriculados: ");
    scanf("%d",&nmalunos[i]);
    for ( x = 0; x < nmalunos[i]; x++)
    {
        printf("\nnumero da matricula: ");
        scanf("%d",&mat);
        printf("\np - presente | a - ausente  ");
        scanf("%s",&pres);
        if (pres=='a')
        {
            pt[i]=pt[i]+1;
        }
    }
    pturma[i]=(pt[i]*100)/nmalunos[i];
    if (pturma[i]>5)ptotal++;
    
}
for ( i = 0; i < 4; i++)
{
    printf("\nturma: %s portcentagem de ausencia: %f",turma[i],pturma[i]);
}
printf("\nturmas com porcentagem maior que 5  %d",ptotal);

}