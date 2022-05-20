#include <stdlib.h>
#include <stdio.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    NoArvore *esq, *dir;
};

int menor(NoArvore *raiz) 
{
    if(raiz == NULL) return -1;

    if (raiz->esq != NULL)
    {
        return menor(raiz->esq);
    }
    if(raiz->esq == NULL)
    {
        return raiz->chave;
    }
}

int maior(NoArvore *raiz) 
{
    if(raiz == NULL) return -1;

    if (raiz->dir != NULL)
    {
        return maior(raiz->dir);
    }
    if(raiz->dir == NULL)
    {
        return raiz->chave;
    }
    
}

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

NoArvore *buscaNo(NoArvore *raiz, int chave_busca)
{
    if(raiz == NULL) return NULL;

    if(chave_busca == raiz->chave)
        return raiz;
    else if(chave_busca < raiz->chave)
        return buscaNo(raiz->esq, chave_busca);
    else
        return buscaNo(raiz->dir,chave_busca);
}

int main()
{
    int n=0;
    int a=0;

    NoArvore *tree = NULL;

    printf("Digite o tamanho da arvore: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++) //Preencher arvore
    {
        scanf("%d",&a);
        tree = inserir(tree,a);
    }


    printf("O maior numero eh %d\n",maior(tree));
    printf("O menor numero eh %d\n",menor(tree));
    imprimir(tree,0);

    return 0;
}

void percurso_ordem(NoArvore *raiz)
{
    if(raiz == NULL) return;

    percurso_ordem(raiz->esq);
    printf("%d ",raiz->chave);
    percurso_ordem(raiz->dir);
}