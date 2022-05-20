#include <stdio.h>

int potencia(int *v, int n, int cont)
{
    int vetor[100];
    vetor[0] = 1;
    for (int i = 1; i < 100; i++)
    {
        vetor[i] = 1;
        for(int j = 1 ; j <= i ; j++)
        {
            vetor[i] = vetor[i] * 2;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (v[i] == vetor[j])
            {
                cont++;
            }
        }
    }
    return cont;
}

int main()
{
    int n=0;

    int cont = 0;

    scanf("%d", &n);

    int v[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    cont = potencia(v,n,cont);

    printf("%d valores sao potencia de 2\n", cont);
    
}