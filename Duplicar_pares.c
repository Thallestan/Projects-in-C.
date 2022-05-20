#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode {
   int data;
   DLinkedNode *next, *prev;
};

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

void *inserir_final2(DLinkedNode *inicio, int valor)
{
    DLinkedNode *novo = malloc(sizeof(DLinkedNode));
    if(novo == NULL) 
        return inicio;

    novo->data = valor;
    novo->prev = NULL;
    novo->next = NULL;

    if(inicio == NULL) 
        return novo;

    DLinkedNode *anterior = NULL;
    DLinkedNode *atual = inicio;
    while(atual != NULL)
    {
        anterior = atual;
        atual = atual->next;
    }
    novo->prev = anterior;
    anterior->next = novo;
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

void imprimir2(DLinkedNode *inicio)
{
    DLinkedNode *atual, *anterior;
    for(atual = inicio; atual != NULL ; atual = atual->next)
    {
        anterior = atual;
        if (atual->next != NULL)
            printf("%d ",atual->data);
        else
            printf("%d",atual->data);
    }
    printf("\n");
    for (atual = anterior; atual !=NULL; atual = atual->prev)
    {
        if (atual->prev != NULL)
            printf("%d ", atual->data);
        else
            printf("%d", atual->data);    
    }   
    printf("\n");
}

void liberar_lista(LinkedNode *inicio)
{
    if(inicio == NULL) return;
    liberar_lista(inicio->next);
    free(inicio);
}

void liberar_lista2(DLinkedNode *inicio)
{
    if(inicio == NULL) return;
    liberar_lista2(inicio->next);
    free(inicio);
}

void duplicar_pares2(DLinkedNode *inicio)
{
      
    DLinkedNode *anterior = NULL;
    DLinkedNode *proximo = NULL;
    DLinkedNode *atual = inicio;

    while(atual != NULL)
    {
        
        while (atual != NULL && ((atual->data%2) != 0 ) )
        {
            anterior = atual;
            atual = atual->next;
        }
        if (atual != NULL && (( atual->data%2 ) == 0 ) )
        {  
            DLinkedNode *novo = malloc(sizeof(DLinkedNode));
            if(anterior != NULL)
            {
                
                novo->data = atual->data;
                novo->prev = anterior;
                novo->next = atual;

                atual->prev = novo;

                anterior->next = novo;
                anterior = atual;

                atual = atual->next;
            }
            else
            {
                novo->data = atual->data;
                novo->prev = atual;
                novo->next = atual->next;
                
                atual->next=novo;
                atual->prev = NULL;
                inicio = atual;

                atual = atual->next;
                anterior = atual;
                atual = atual->next;
            }
        }
    }
      
}

void duplicar_pares1(LinkedNode *inicio) 
{
      
    LinkedNode *anterior = NULL;
    LinkedNode *atual = inicio;

    while(atual != NULL)
    {   
        
        while (atual != NULL && ((atual->data%2) != 0 ) )
        {
            anterior = atual;
            atual = atual->next;
        }
        if (atual != NULL && (( atual->data%2 ) == 0 ) )
        {
            LinkedNode *novo = malloc(sizeof(LinkedNode));
            if(anterior != NULL)
            {
                novo->data = atual->data;
                novo->next = atual;
                anterior->next=novo;
                anterior = atual;
                atual = atual->next;
            }
            else
            {
                novo->data = atual->data;
                novo->next = atual->next;
                atual->next = novo;
                atual = atual->next;
                atual = atual->next;
            }    
        }
    }
}

int main()
{
    int n=0;
    int a=0;
    int t=0;
    
    LinkedNode *inicio = NULL;
    DLinkedNode *inicio2 = NULL; 

    printf("Digite 1 ou 2: ");
    scanf("%d",&t);
    printf("Digite o tamanho da lista: ");
    scanf("%d",&n);
    
    if(t==1)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            inicio = inserir_final(inicio,a);
        }
        duplicar_pares1(inicio);
        imprimir1(inicio); 
    }    
    if(t==2)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            inicio2 = inserir_final2(inicio2,a);
        }
        duplicar_pares2(inicio2);
        imprimir2(inicio2);
    }
    liberar_lista(inicio);
    liberar_lista2(inicio2);
}
