#include <stdio.h>

int contador(int *v, int n, int inicio, int *fim)
{
    int cont = 0;
    int maior = 0;

    for(int i = 0; i < n; i++)
    {
        if( i != (n-1) && v[i] < v[i+1])
        {
            if (i == 0)
            {
                inicio = i;
            }
            cont++;     
        }
        else
        {
            if((i != 0) && (v[i-1] < v[i]))
            {
                if(cont > maior)
                { 
                    maior = cont;
                    *fim = i;
                    inicio = *fim - cont;
                    
                }
                cont = 0;
            }
        }
        printf("inicio = %d\n", inicio);
        printf("fim = %d\n", *fim); 
        printf("MAIOR = %d\n", maior);
        printf("CONT = %d\n", cont);
        printf("\n");
    }
    return inicio;
}

int main()
{

    int n = 0;
    int inicio = 0;
    int fim = 0;

    scanf ("%d", &n);

    int v[n];

    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &v[i]);
    }

    inicio = contador(v,n,inicio,&fim);

    for (int i = inicio; i <= fim; i++)
    {
        printf("%d ",v[i]);
    }
}