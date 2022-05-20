#include <stdio.h>
#include <stdlib.h>
//Lista ligada
typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};
void liberar_lista(LinkedNode *inicio)
{
    if(inicio == NULL) return;
    liberar_lista(inicio->next);
    free(inicio);
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

//Pilha Dinamica
typedef struct PilhaDinamica PilhaDinamica;
struct PilhaDinamica
{
    LinkedNode *topo;
};
PilhaDinamica *criar_pilha()
{
    PilhaDinamica *pilha = malloc(sizeof(PilhaDinamica));
    pilha->topo = NULL;
    return pilha;
}
int push(PilhaDinamica *pilha, int item)
{
    LinkedNode *novo_item = malloc(sizeof(LinkedNode));
    if(novo_item == NULL)
    {
        return 0;
    }
    novo_item->data = item;
    novo_item->next = pilha->topo;

    pilha->topo = novo_item;

    return 1;
}
int pop(PilhaDinamica *pilha, int *item)
{
    if (pilha->topo == NULL) return 0; //Pilha vazia?
    
    LinkedNode *no = pilha->topo;
    pilha->topo = pilha->topo->next;

    *item = no->data;
    free(no);

    return 1;
}
void liberar_pilha(PilhaDinamica *pilha)
{
    liberar_lista(pilha->topo);
    free(pilha);
}

// Fila Dinamica
typedef struct FilaDinamica FilaDinamica;
struct FilaDinamica
{
    LinkedNode *inicio, *fim;
};
FilaDinamica *criar_fila()
{
    FilaDinamica *fila = malloc(sizeof(FilaDinamica));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}
int enqueue(FilaDinamica *fila, int item)
{
    LinkedNode *novo_item = malloc(sizeof(LinkedNode));
    if(novo_item == NULL) return 0;

    novo_item->data = item;
    novo_item->next = NULL;
    if(fila->fim != NULL)
    {
        fila->fim->next = novo_item;
    }

    fila->fim = novo_item;

    if(fila->inicio == NULL)
    {
        fila->inicio = novo_item;
    }
    return 1;
}
int dequeue(FilaDinamica *fila, int *item)
{
    if(fila->inicio == NULL) return 0; //Fila vazia?

    LinkedNode *no = fila->inicio;
    *item = no->data;

    fila->inicio = fila->inicio->next;
    if(fila->inicio == NULL)
    {
        fila->fim = NULL;
    }
    free(no);

    return 1;
}
void liberar_fila(FilaDinamica *fila)
{
    liberar_lista(fila->inicio);
    free(fila);
}

//Funcao principal
int verificar_lista(LinkedNode *lista)
{
    int a=0;
    int n=0;
    int b=-1;
    int c=-1;
    int fila;
    int pilha;
    int resultado=0;
    LinkedNode *atual = lista;
    LinkedNode *anterior = NULL;
    PilhaDinamica *p = criar_pilha();
    FilaDinamica *f = criar_fila();

    while (atual != NULL)
    {
        push(p,atual->data);
        enqueue(f,atual->data);
        n++;
        anterior = atual;
        atual = atual->next;
        
    }
    for(int i=0;i<n;i++)
    {
        if(p->topo->data != f->inicio->data)
        {
            a++;
        }
        pop(p,&b);
        dequeue(f,&c);
    }

    liberar_pilha(p);
    liberar_fila(f);

    if(a==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }     
}

int main()
{
    LinkedNode *inicio = NULL;
    

    int n=0;
    int a=0;
    int r=0;
    int resultado=0;

    printf("Digite o tamanho da Lista: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++) //Preencher a lista
    {
        scanf("%d",&a);
        inicio = inserir_final(inicio,a);
    }
    
    resultado = verificar_lista(inicio);

    printf("Resultado = %d\n", resultado);

    liberar_lista(inicio);

    return 0;
}
