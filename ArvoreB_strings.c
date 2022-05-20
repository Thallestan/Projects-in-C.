#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct NoArvore NoArvore;
struct NoArvore {
    char *chave;
    NoArvore *esq, *dir;
};

NoArvore *inserir(NoArvore *raiz, char *chave_nova)
{
    int i=0;
    char *chave = malloc(sizeof(char)* 100);

    for(i=0; chave_nova[i] !='\0'; i++)
    {
        chave[i] = chave_nova[i];
    }
    chave[i] = '\0';    
    
    if(raiz == NULL)
    {
        NoArvore *novo_no = malloc(sizeof(NoArvore));
        novo_no->chave = chave;
        novo_no->esq = NULL;
        novo_no->dir = NULL;
        
        return novo_no;
    }
    if(chave[0] < raiz->chave[0])
    {
        raiz->esq = inserir(raiz->esq,chave);
    }
    if(chave[0]  > raiz->chave[0])
    {
        raiz->dir = inserir(raiz->dir,chave);
    }
    if(chave[0] == raiz->chave[0])
    {
        if(chave[1] < raiz->chave[1])
        {
            raiz->esq = inserir(raiz->esq,chave);
        }
        if(chave[1]  > raiz->chave[1])
        {
            raiz->dir = inserir(raiz->dir,chave);
        }
    }
    return raiz;
}

char *get_min(NoArvore *raiz)
{
    char *res;
    if(raiz->esq == NULL)
    {
        res = malloc(sizeof(char) * 100);
        for(int i=0; raiz->chave[i] != '\0'; i++)
        {
            res[i] = raiz->chave[i];
        }
        return res;
    }    
    else
        return get_min(raiz->esq);
}

NoArvore *remover(NoArvore *raiz, char *chave)
{
    char *chave_busca = malloc(100*sizeof(char));
    int i=0;
    for( i=0; chave[i] != '\0'; i++)
    {
        chave_busca[i] = chave[i];
    }
    chave_busca[i] = '\0';

    if(raiz == NULL) return NULL;

    if(chave_busca[0] < raiz->chave[0])
    {
        raiz->esq = remover(raiz->esq,chave_busca);
    }
    if(chave_busca[0] > raiz->chave[0])
    {
        raiz->dir = remover(raiz->dir, chave_busca);
    }
    if (strcmp(chave_busca,raiz->chave) == 0)
    {
        //CASO 1
        if(raiz->esq == NULL && raiz->dir == NULL)
        {
            free(raiz);
            return NULL;
        }
        //CASO 2
        if(raiz->esq == NULL)
        {
            NoArvore *arvdir = raiz->dir;
            free(raiz);
            return arvdir;
        }
        if(raiz->dir == NULL)
        {
            NoArvore *arvesq = raiz->esq;
            free(raiz);
            return arvesq;
        }
        //CASO 3
        char * sucessor = malloc(100*sizeof(char));
        sucessor = get_min(raiz->dir);
        raiz->chave = sucessor;
        raiz->dir = remover(raiz->dir,sucessor);
    }

    return raiz;
}

NoArvore *buscar(NoArvore *raiz, char *chave_busca)
{
    char *chave = malloc(100*sizeof(char));
    int i=0;
    
    for(i=0; chave_busca[i] != '\0'; i++)
    {
        chave[i] = chave_busca[i];
    }
    chave[i] = '\0'; 

    if (raiz == NULL) return NULL;
    if (chave[0] == raiz->chave[0])
    {
        if(chave[1] < raiz->chave[1])
            return buscar(raiz->esq, chave);
        if(chave[1] > raiz->chave[1])
            return buscar(raiz->dir, chave);
        if (strcmp(chave,raiz->chave) == 0)
            return raiz;
    }
    if(chave[0] < raiz->chave[0])
        return buscar(raiz->esq, chave);
    if(chave[0] > raiz->chave[0])
        return buscar(raiz->dir, chave);
    
}

void liberar_arvore(NoArvore *raiz) 
{
    if (raiz == NULL) return;
    liberar_arvore(raiz->esq);
    liberar_arvore(raiz->dir);
    free(raiz);
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
    
    for(int i=0;raiz->chave[i]!='\0';i++)
    {
        printf("%c",raiz->chave[i]);
    }
    printf("\n");

    imprimir(raiz->esq, profundidade +1);
}

int main()
{

    NoArvore *tree = NULL;
    NoArvore *tree2 = NULL;
    NoArvore *tree3 = NULL;

    char char1[100] = "dados";
    char char2[100] = "algoritmos";
    char char3[100] = "estruturas";
    char char4[100] = "professor";

    tree = inserir(tree,char1);
    tree = inserir(tree,char2);
    tree = inserir(tree,char3);
    tree = inserir(tree,char4);
    
    imprimir(tree,0);
    printf("======================\n");

    tree = remover(tree,char3);
    tree = remover(tree,char2);

    imprimir(tree,0);
    printf("======================\n");
    
    tree = buscar(tree, char4);
    
    for(int i=0;tree->chave[i]!='\0';i++)
    {
        printf("%c",tree->chave[i]);
    }
    printf("\n");

    printf("======================\n");
    
    liberar_arvore(tree);

    return 0;
}