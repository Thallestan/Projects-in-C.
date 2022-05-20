#include <stdio.h>
#include <stdlib.h>

void *quantidade_discos(char **discos, int n_discos, int **quantidade_por_fabricante)
{
    for(int i=0;i < n_discos; i++)    
    {
        if(discos[i][7] == 'A')
            (*quantidade_por_fabricante)[0] = (*quantidade_por_fabricante)[0] + 1;
        if(discos[i][7] == 'B')
            (*quantidade_por_fabricante)[1] = (*quantidade_por_fabricante)[1] + 1;
        if(discos[i][7] == 'C')
            (*quantidade_por_fabricante)[2] = (*quantidade_por_fabricante)[2] + 1;
        if(discos[i][7] == 'D')
            (*quantidade_por_fabricante)[3] = (*quantidade_por_fabricante)[3] + 1;
    }

    return *quantidade_por_fabricante;
}

int main ()
{
    int n_discos=4;
    
    int **qtd;
    qtd = malloc(sizeof(int *) * 4);

    char **discos;
    discos = malloc(sizeof(char *) * n_discos);


    for (int i = 0; i < n_discos; i++)
        discos[i] = malloc(sizeof(char) * 10);

    
    for (int i = 0; i < n_discos; i++)
        fgets(discos[i],10,stdin);    
    
    quantidade_discos(discos,n_discos,qtd);

    for (int i = 0; i < n_discos; i++)
        printf("%d ",*qtd[i]);
    printf("\n");

    for (int i = 0; i < n_discos; i++)
        free(discos[i]);
    free(discos);
    free(qtd);
}
