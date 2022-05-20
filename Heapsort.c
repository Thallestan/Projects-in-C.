#include <stdlib.h>
#include <stdio.h>

int comparar(ItemVetor item1, ItemVetor item2);

void max_heapfy(ItemVetor *v, int n, int i, int *comp) 
{
    
    int esq = 2*i + 1;
    int dir = 2*i + 2;
    int maior = i;
    *comp = *comp + 1;
    if (esq < n && (comparar(v[esq],v[maior]) > 0))  
        maior = esq;
    *comp = *comp + 1;
    if (dir < n && (comparar(v[dir],v[maior]) > 0))       
        maior = dir;
    if (maior != i) 
    {
        ItemVetor aux;
        aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;
        max_heapfy(v, n, maior, comp);
    }
}

void build_max_heap(ItemVetor *v, int n, int *comp) 
{
    int i;
    for (i = n/2 - 1; i >= 0; i--)
        max_heapfy(v, n, i, comp);
}

void heap_sort(ItemVetor *v, int n, int *comp) 
{
    build_max_heap(v, n, comp);
    int i;
    for (i = n-1; i > 0; i--) 
    {
        ItemVetor aux;
        aux = v[i];
        v[i] = v[0];
        v[0] = aux;
        max_heapfy(v, i, 0, comp);
    }
}

int heapsort(ItemVetor v[], int n) 
{
    int comp =0;
    heap_sort(v, n, &comp);
    return comp;  
}