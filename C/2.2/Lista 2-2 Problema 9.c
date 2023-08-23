typedef struct Matriz
{
    int matriz1[2][2];
    int matriz2[2][2];
    int linha;
    int coluna;

}Matriz;

struct Matriz leitura(struct Matriz matrizes){
    printf("\nmatriz 1:");
    for (int i = 0; i < 2; i++)
    {
    for (int j = 0; j < 2; j++)
        scanf("%d",&matrizes.matriz1[i][j]);
    }
    printf("\nmatriz 2:");
    for (int i = 0; i < 2; i++)
    {
    for (int j = 0; j < 2; j++)
        scanf("%d",&matrizes.matriz2[i][j]);
    }
    return matrizes;
}

struct Matriz compara(struct Matriz matrizes){
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if(matrizes.matriz1[i][j] == matrizes.matriz2[i][j])
            {
                printf("\n repetido %d",matrizes.matriz1);
            }
        }
    }
}

int main()
{
    struct Matriz matrizes;
    
    matrizes = leitura(matrizes);
    
    compara(matrizes);
}
