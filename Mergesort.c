#include <stdlib.h>
#include <stdio.h>

void intercala(int *v, int esq_inicio, int esq_fim, int dir_fim, int *comparacoes) 
{
    int dir_inicio = esq_fim + 1;
    int esq = esq_inicio, dir = dir_inicio;

    int comp = dir_fim - esq_inicio + 1;
    int *v_aux = malloc(sizeof(int) * comp);
    
    
    
    int i;
    for (i = 0; i < comp; i++) 
    {
        if (esq > esq_fim)
            v_aux[i] = v[dir++];
        else if (dir > dir_fim)
            v_aux[i] = v[esq++];
        else
        {
            *comparacoes = *comparacoes + 1;
            if (v[esq] <= v[dir])
            v_aux[i] = v[esq++];
            else
            v_aux[i] = v[dir++];
        }
    }

    for (i = 0; i < comp; i++)
    {    
        
        v[esq_inicio + i] = v_aux[i];
    }
    free(v_aux);
}

void merge_sort(int *v, int esq, int dir, int *comparacoes) 
{
    
    if (esq < dir) 
    {
        int meio = (esq + dir) / 2;
        merge_sort(v, esq, meio,comparacoes);
        merge_sort(v, meio+1, dir,comparacoes);
        intercala(v, esq, meio, dir, comparacoes);
    }
}

void mergesort(int *v, int n, int *comparacoes) 
{
    merge_sort(v, 0, n - 1,comparacoes);
}

int main ()
{
    int n=0;
    int comparacoes=0;
    


    scanf("%d",&n);

    int *v = malloc(sizeof(int)* n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }

    mergesort(v,n,&comparacoes);

    for (int i = 0; i < n; i++)
    {
        if(i!=(n-1))   
            printf("%d ",v[i]);
        else
            printf("%d\n",v[i]);
    }
    if(n==0)
    {
        printf("\n");
    }
    printf("Comparacoes: %d\n",comparacoes);
    
    free(v);
    

}
