#include <stdlib.h>
#include <stdio.h>

int max_heapfy(int *v, int n, int i) 
{
    int esq = 2*i + 1;
    int dir = 2*i + 2;
    int maior = i;
    
    if (esq < n && v[esq] > v[maior])
        return 1;
    if (dir < n && v[dir] > v[maior])
        return 1;
    else
        return 0;
}

int build_max_heap(int *v, int n) 
{
    int a = 0;
    int i;
    for (i = n/2 - 1; i >= 0; i--)
    {
        a = max_heapfy(v, n, i);
        if (a == 1)
        {
            return a;
        }
    }
    return a;
}

int min_heapfy(int *v, int n, int i) 
{
    int esq = 2*i + 1;
    int dir = 2*i + 2;
    int menor = i;
    
    if (esq < n && v[esq] < v[menor])
        return 1;
    if (dir < n && v[dir] < v[menor])
        return 1;
    else
        return 0;
}

int build_min_heap(int *v, int n) 
{
    int a = 0;
    int i;
    for (i = n/2 - 1; i >= 0; i--)
    {
        a = min_heapfy(v, n, i);
        if (a == 1)
        {
            return a;
        }
        
    }
    return a;
}

int Heap(int *v, int n)
{
    int max=0;
    int min=0;

    max = build_max_heap(v,n);
    min = build_min_heap(v,n);

    printf("MAX = %d\n", max);
    printf("MIN = %d\n", min);

    if(max == 0)
        return 2;
    if(min == 0)
        return 1;
    if(max != 0 && min != 0)
        return 0;
    
}
 
int main ()
{
    int n=0;
    int res=0;

    scanf("%d",&n);

    int v[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }

    res = Heap(v,n);

    printf("%d\n",res);
    
}
