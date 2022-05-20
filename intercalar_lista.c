#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

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

    printf("Digite o tamanho da lista: ");
    scanf("%d",&n);

    LinkedNode *inicio = NULL;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        inicio = inserir_final(inicio,a);
    }

    imprimir1(inicio);

    liberar_lista(inicio);
}