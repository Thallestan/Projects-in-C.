#include <stdio.h>
#include <stdlib.h>

void imprimir(char *v, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(i != (n-1))
            printf("%c",v[i]);
        if(i == (n-1))
           printf("%c\n",v[i]); 
        
    }
    
}

void imprimir_vetor(int *v, int n)
{
    int i;
    printf("[");
    for(i = 0; i < n; i++)
    {
        if(i != (n-1))
            printf("%d ",v[i]);
        if(i == (n-1))
           printf("%d]\n",v[i]); 
        
    }
}

void countingsort(char *v, int n, int k) 
{
    int c[k + 1];
    int i;
    for (i = 0; i < k + 1; i++)
        c[i] = 0;

    for (i = 0; i < n; i++)
        c[v[i] -65]++;

    imprimir_vetor(c,(k+1));

    for (i = 1; i < k + 1; i++)
        c[i] += c[i - 1];

    imprimir_vetor(c,(k+1));

    char saida[n];
    int atual;
    for (i = n - 1; i >= 0; i--) 
    {
        atual = v[i];
        saida[c[atual - 65] - 1] = atual;
        c[atual - 65]--;
    }
    for (i = 0; i < n; i++)
        v[i] = saida[i];
}

int main()
{
    int n=0;
    char v[1000];

    fgets(v,1000,stdin);

    for (int i = 0; v[i]!='\0'; i++)
    {
        n++;
    }
    n = n - 1;

    countingsort(v,n,25);

    imprimir(v,n);

}