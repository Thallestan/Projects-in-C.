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

LinkedNode* lista_insere(LinkedNode *inicio, int i) 
{
    LinkedNode *novo = malloc(sizeof(LinkedNode));

    novo->data = i;
    novo->next = inicio;
    return novo;
}
LinkedNode* inverter_lista(LinkedNode *inicio) 
{
    if(inicio == NULL) return inicio;
    LinkedNode *atual = inicio;
    LinkedNode *inicio_novo = NULL;
    LinkedNode *anterior = NULL;
    int n=0;

    while(atual != NULL) //conta elementos da lista
    {
        n++;
        atual = atual->next;
    } 
    atual = inicio;
    
    if(n==1)
        return inicio;
        
    for(int i=0; i < n; i++)
    {
        while(atual->next != NULL)
        {
            anterior = atual;
            atual = atual->next;
        }
        if(atual->next == NULL)
        {
            atual->next = anterior;
            if(i==0)
                inicio_novo = atual;
            anterior->next = NULL;
        }
    }

    return inicio_novo;
    
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
    inicio = inverter_lista(inicio);
    imprimir1(inicio);

    liberar_lista(inicio);
}