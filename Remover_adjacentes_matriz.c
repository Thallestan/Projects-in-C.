#include <stdio.h>

void remover_numeros_matriz(int l, int c, int n_linhas, int n_colunas, int m[n_linhas][n_colunas]) 
{
    int valor=0;
    valor = m[l][c];

    if(m[l][c] == valor])
    {
        m[l][c] = 0;
    }
    if(valor == m[l-1][c])
    {
        remover_numeros_matriz((l-1),c,n_linhas,n_colunas,m);
    }
    if(valor == m[l][c-1])
    {
        remover_numeros_matriz(l,(c-1),n_linhas,n_colunas,m);
    }
    if(valor == m[l+1][c])
    {
        remover_numeros_matriz((l+1),c,n_linhas,n_colunas,m);
    }
    if(valor == m[l][c+1])
    {
        remover_numeros_matriz(l,(c+1),n_linhas,n_colunas,m);
    }
}

int main()
{
    int l=0;
    int c=0;
    int n_linhas;
    int n_colunas;
    
    scanf("%d %d", &l,&c);
    scanf("%d %d", &n_linhas,&n_colunas);
    
    int matriz[n_linhas][n_colunas];

    for(int i=0;i<n_linhas;i++)
    {
        for(int j=0;j<n_colunas;j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    remover_numeros_matriz(l,c,n_linhas,n_colunas,matriz);

    for(int i=0;i<n_linhas;i++)
    {
        for(int j=0;j<n_colunas;j++)
        {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}