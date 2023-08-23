#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int *v;
//Gustavo Manfio Stefanello
main()
{
int tam,i,j,aux;
scanf("%d",&tam);
v = (int*) malloc(tam*sizeof(int)); 
for ( i = 0; i < tam; i++)
{
    scanf("%d",&v[i]);
}
for ( i = 0; i < tam; i++)
{
    printf("%d",v[i]);
}
for (i = 0; i < tam; ++i)
{
    for (j = i; j < tam; ++j)
    {
        if (v[i] > v[j])
        {
            aux =  v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
}
printf("\n em ordem crescente: ");
for( i = 0; i < tam; i++)
{
    printf("\n%d",v[i]);
}
for (i = 0; i < tam; ++i)
{
    for (j = i; j < tam; ++j)
    {
        if (v[i] < v[j])
        {
            aux =  v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
}
printf("\n em ordem decrescente: ");
for( i = 0; i < tam; i++)
{
    printf("\n%d",v[i]);
}

}