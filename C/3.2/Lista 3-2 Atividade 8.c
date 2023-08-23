int naturais(int x,int i){
    
    
    if (i==x)
    {
        return x;
    }else
        printf("%d, ",i);
        return (naturais(x,i+1));
}

main()
{
    int x=10;
    x = naturais(x,0);
    printf("%d ",x); 
}