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

int buscaNo(NoArvore *raiz, int chave_busca)
{
    if(raiz == NULL) return 0;

    if (chave_busca == raiz->chave)
    {
        printf("Chave = %d\n",raiz->chave);
        return 1;
    }
    else
    {
        buscaNo(raiz->esq,chave_busca);
        buscaNo(raiz->dir,chave_busca);
        return 0;
    }
}
int qtd_chaves_comuns(NoArvore *raiz1, NoArvore *raiz2) 
{
    if(raiz2 == NULL) 
        return 0;
    else
        return buscaNo(raiz1,raiz2->chave) + qtd_chaves_comuns(raiz1,raiz2->esq) + qtd_chaves_comuns(raiz1,raiz2->dir);
}

int main()
{
    int qtd=0;

    NoArvore *tree1 = NULL;
    NoArvore *tree2 = NULL;

    
    tree1 = inserir(tree1,50);
    tree1 = inserir(tree1,25);
    tree1 = inserir(tree1,75);
    tree1 = inserir(tree1,1000);
    tree1 = inserir(tree1,900);
    tree1 = inserir(tree1,10);
    tree1 = inserir(tree1,15);

    tree2 = inserir(tree2,50);
    tree2 = inserir(tree2,26);
    tree2 = inserir(tree2,75);
    tree2 = inserir(tree2,1001);
    tree2 = inserir(tree2,950);
    tree2 = inserir(tree2,10);
    tree2 = inserir(tree2,15);

    qtd = qtd_chaves_comuns(tree1,tree2);

    printf("Chaves em comum = %d",qtd);

}