#include <stdio.h>
#include <stdlib.h>



int leitura(int vet[],int tam){
    for (int i = 0; i < tam; i++)
    {
        scanf("%d",&vet[i]);
    }
}

int buscar(int x,int vet[],int tam){
    int pos,com;
    for (int i = 0; i < tam; i++)
    {
        if (vet[i]==x){
            pos=i;
            com=i;
            return pos;
            printf("pos: %d",pos);
        }
    }
    if (pos!=com)
    {
        printf("pos nao encontrada\n\n");
    }
    
} 

main()
{
    int tam = 5,*vetor;
    int vet[tam],x,pos;
    leitura(vet,tam); 

    for (int i = 0; i < tam; i++)
        {
            printf("%d",vet[i]);
        }

    printf("\ndigite o item a buscar: ");
    scanf("%d",&x);

    pos=buscar(x,vet,tam);

}