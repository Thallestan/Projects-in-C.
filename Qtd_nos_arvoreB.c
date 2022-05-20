#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

//Arvore Binaria
typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    NoArvore *esq, *dir;
};

NoArvore *inserir(NoArvore *raiz, int chave_nova)
{
    if(raiz == NULL)
    {
        NoArvore *novo_no = malloc(sizeof(NoArvore));
        novo_no->chave = chave_nova;
        novo_no->esq = NULL;
        novo_no->dir = NULL;
        return novo_no;
    }
    if(chave_nova < raiz->chave)
    {
        raiz->esq = inserir(raiz->esq,chave_nova);
    }
    else if(chave_nova > raiz->chave)
    {
        raiz->dir = inserir(raiz->dir,chave_nova);
    }

    return raiz;
}

void imprimir(NoArvore* raiz, int profundidade)
{
    if(raiz == NULL) 
    {
        printf("\n");
        return;
    }
    imprimir(raiz->dir, profundidade + 1);

    printf("\n");
    int i;
    for(i=0;i<profundidade;i++) printf("   ");
    
    printf("%d", raiz->chave);

    imprimir(raiz->esq, profundidade +1);
}

int numero_nos(NoArvore *raiz)
{
    if(raiz == NULL) return 0;
    else
       return 1 + numero_nos(raiz->esq) + numero_nos(raiz->dir); 
      
}

int numero_nos_folha(NoArvore *raiz)
{
    if(raiz == NULL) return 0;
    else
    {
        if(raiz->esq == NULL && raiz->dir == NULL)
        {
            return 1 + numero_nos_folha(raiz->esq) + numero_nos_folha(raiz->dir); 
        }
        else
        {
            return 0 + numero_nos_folha(raiz->esq) + numero_nos_folha(raiz->dir); 
        }
    } 
}

int numero_nos_internos(NoArvore *raiz)
{
    if(raiz == NULL) return 0;
    else
    {
        if(raiz->esq != NULL || raiz->dir != NULL)
        {
            return 1 + numero_nos_internos(raiz->esq) + numero_nos_internos(raiz->dir);
        }
        if(raiz->esq == NULL && raiz->dir == NULL)
        {
            return 0 + numero_nos_internos(raiz->esq) + numero_nos_internos(raiz->dir); 
        }
    }
    
}

int main()
{
    int n=0;
    int a=0;
    int qtd=0;
    int folha=0;
    int interno=0;

    NoArvore *tree = NULL;

    
    tree = inserir(tree,50);
    tree = inserir(tree,25);
    tree = inserir(tree,75);
    tree = inserir(tree,1000);
    tree = inserir(tree,900);
    tree = inserir(tree,10);
    tree = inserir(tree,15);



    qtd = numero_nos(tree);
    folha = numero_nos_folha(tree);
    interno = numero_nos_internos(tree);
    printf("Numero de nos = %d\n", qtd);
    printf("Numero de nos folhas = %d\n", folha);
    printf("Numero de nos internos = %d\n", interno);
    imprimir(tree,0);

    return 0;
}

int buscaNo(NoArvore *raiz, int chave_busca)
{
    if(raiz == NULL) return 0;
    if(chave_busca == raiz->chave)
    {
        if (chave_busca < raiz->chave)
            return 1 + buscaNo(raiz->esq, chave_busca);
        else
            return 1 + buscaNo(raiz->dir, chave_busca);
    }
    if (chave_busca < raiz->chave)
        return buscaNo(raiz->esq, chave_busca);
    else
        return buscaNo(raiz->dir, chave_busca);
}