#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void trocar(int x[],int ini,int tam){
    int aux;
    if (ini<tam)
    {
        aux=x[ini];
        x[ini]=x[tam];
        x[tam]=aux;
        return trocar(x,ini+1,tam-1);
    }
}

void imprimir(int v[],int tam){
    if (tam == 1)
    {
        printf("%d ",v[tam-1]);
    }else
    {
        imprimir(v,tam-1);
        printf("%d ",v[tam-1]);
    }
}
/*
void trocarString(char x[],int ini,int tam){
    char aux;
    if (ini<tam)
    {
        aux=x[ini];
        x[ini]=x[tam];
        x[tam]=aux;
        return trocarString(x,ini+1,tam-1);
    }else{
        x[tam+1]='\0';
    }
}*/

int main()
{
    int tam=100;
    int x[100]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
    char str[10]="marco";   
    //imprimir(x,tam);
    printf("\n\n");
    trocar(x,0,tam-1);
    printf("%s",str);
    trocarString(str,0,5);
    printf("%s",str);
    //imprimir(x,tam);
}