#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

LinkedNode *selection_sort(LinkedNode *inicio, int *trocas, int *comparacoes) 
{
    *trocas = 0;
    *comparacoes=0;
    LinkedNode *i = NULL;
    LinkedNode *k = NULL;

    for (i = inicio; i!=NULL; i=i->next) 
    {
        LinkedNode *indice_menor = i;
        for (k = i->next; k!=NULL; k=k->next)
        {
            *comparacoes= *comparacoes + 1;
            if (k->data < indice_menor->data)
                indice_menor = k;
        }
        int tmp = i->data;
        if(i->data != indice_menor->data)
            *trocas = *trocas +1;
        i->data = indice_menor->data;
        
        indice_menor->data = tmp;
    }

    return inicio;
}


void imprimir1(LinkedNode *inicio)
{
    LinkedNode *atual = inicio;
    while(atual != NULL)
    {
        if (atual->next != NULL)
            printf("%d ",atual->data);
        else
            printf("%d",atual->data);
        atual = atual->next;
    }
    printf("\n");
}

void *inserir_final(LinkedNode *inicio, int valor)
{
    LinkedNode *novo = malloc(sizeof(LinkedNode));
    if(novo == NULL) 
        return inicio;

    novo->data = valor;
    novo->next = NULL;

    if(inicio == NULL) 
        return novo;

    LinkedNode *anterior = NULL;
    LinkedNode *atual = inicio;
    while(atual != NULL)
    {
        anterior = atual;
        atual = atual->next;
    }
    anterior->next = novo;
    return inicio;
}

void liberar_lista(LinkedNode *inicio)
{
    if(inicio == NULL) return;
    liberar_lista(inicio->next);
    free(inicio);
}

int main()
{
    int n=0;
    int a=0;
    int trocas =0;
    int comparacoes=0;

    scanf("%d",&n);

    LinkedNode *inicio = NULL;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        inicio = inserir_final(inicio,a);
    }

    selection_sort(inicio,&trocas,&comparacoes);

    imprimir1(inicio);
    printf("Trocas = %d",trocas);
    printf("Comparacoes = %d",comparacoes);
    printf("\n");

    liberar_lista(inicio);
}