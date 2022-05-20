#include <stdlib.h>
#include <stdio.h>

typedef struct ItemVetor ItemVetor;
struct ItemVetor {
    int *v;
};




int comparar(ItemVetor item1, ItemVetor item2)
{
    if (item1.v > item2.v)
    {
        return 1;
    }
    if (item1.v < item2.v)
    {
        return -1;
    }

    return 0;

}

void ordenar_vetor(ItemVetor v[], int n)
{
    for(int i = 0; i < n-1; i++)
	{
		int indice_menor = i;
		for(int k = i+1; k < n; k++)
		{
			if(comparar(v[k],v[indice_menor]) == -1)
				indice_menor = k;
		}
		if(indice_menor != i)
		{
			int tmp = v[indice_menor];
			v[indice_menor] = v[i];
			v[i] = tmp;
		}
	}
}

int main ()
{
    int n=0;


    struct ItemVetor ItemVetor;

    scanf("%d", &n);

    for(int i=0; i<n;i++)
    {
        scanf("%d",&ItemVetor.v[i]);
    }

    ordenar_vetor(ItemVetor.v, n);

}