#include <stdio.h>
#include <stdlib.h>

int* expandir_vetor(const int *vetor, int n_compactado, int *n_expandido)
{
    int cont=0;
    int i;
    int j;
    int a;
    for (int i = 0; i < n_compactado; i++)
    {
        if((i%2)!=0)
        {
            cont = cont + vetor[i]; 
        }
    }

    int *n_vetor = malloc(sizeof(int)* cont);
    i=0;

    while(i < n_compactado)
    {
        for(j=0; j < vetor[i+1];j++)
        {
            
            n_vetor[a]=vetor[i];
            a++;
        }
        
        i=i+2;
    }

    *n_expandido=cont;

    return n_vetor;
}

int main ()
{
  int n=0;
  int b=0;
  int n_expandido=0;

  scanf("%d", &n);

  int v[n];

  for (int i = 0; i < n; i++)
  {
    scanf ("%d", &b);
    v[i] = b;
  }

  int *vetor = expandir_vetor(v,n, &n_expandido);

  printf("n_expandido = %d\n",n_expandido);

  for (int i = 0; i < n_expandido; i++)
  {
    printf("%d ",vetor[i]);
    
  }
  printf("\n");
  free(vetor);
}