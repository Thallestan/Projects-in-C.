#include <stdlib.h>
#include <stdio.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    int altura;
    NoArvore *esq, *dir;
};

int altura(NoArvore *raiz)
{
	if(raiz == NULL)
		return -1;
	else
	{
		int esq = altura(raiz->esq);
		int dir = altura(raiz->dir);
		if (esq > dir)
			return esq + 1;
		else
			return dir + 1;
	}
}

int calcula_fb(NoArvore *raiz)
{
	return (altura(raiz->esq) - altura(raiz->dir));
}

int maior(int v1, int v2)
{
	if(v1 > v2)
		return v1;
	else
		return v2;
}

NoArvore *verificaBalanceamento(NoArvore *raiz, int *a)
{
	int fb = calcula_fb(raiz);
	if(fb > 1)
	{
		printf("[No desbalanceado: %d]\n",raiz->chave);
		*a = 0;
	}
	else if(fb < -1)
	{
		printf("[No desbalanceado: %d]\n",raiz->chave);
		*a = 0;	
	}
	else if((fb == -1 || fb == 0 || fb == 1) && (a > 0))
	{
		*a = 0;
		printf("[Ja esta balanceada]\n");
	}
	return raiz;
}

NoArvore *inserir(NoArvore *raiz, int valor)
{
	int a = 0;
    if(raiz == NULL)
    {
        NoArvore *novo_no = malloc(sizeof(NoArvore));
        novo_no->chave = valor;
        novo_no->esq = NULL;
        novo_no->dir = NULL;
		novo_no->altura = 0;
		a++;
		return verificaBalanceamento(novo_no, &a);
		
    }
    if(valor < raiz->chave)
    {
		a++;
        raiz->esq = inserir(raiz->esq,valor);
    }
    else if(valor > raiz->chave)
    {
		a++;
        raiz->dir = inserir(raiz->dir,valor);
    }
	
	raiz->altura = (1 + maior(altura(raiz->esq),altura(raiz->dir)));
	
	if(a > 0)
    	return verificaBalanceamento(raiz, &a);
	else
		return raiz;
}

void imprimir_posordem(NoArvore *raiz)
{
	if (raiz == NULL) return;

	imprimir_posordem(raiz->esq);
	imprimir_posordem(raiz->dir);
	printf("%d ", raiz->chave);
}

void libera(NoArvore *raiz)
{
	if (raiz == NULL) return;

	imprimir_posordem(raiz->esq);
	imprimir_posordem(raiz->dir);
	free(raiz);
}

void liberar_arvore(NoArvore *raiz) 
{
    if (raiz == NULL) return;
	
	imprimir_posordem(raiz);
    libera(raiz);
}

int main() {
	NoArvore *raiz = NULL;
	char operacao;
	do {
		scanf(" %c", &operacao);
		switch (operacao) {
			case 'I' : {
				int valor;
				scanf("%d", &valor);
				raiz = inserir(raiz, valor);
				break;
			}
			case 'A' : {
				printf("A=%d\n", altura(raiz));
				break;
			}
			case 'P' : {
				printf("[");
				liberar_arvore(raiz);
				printf("]\n");
				break;
			}
		}
	} while (operacao != 'P');
    
	return 0;
}