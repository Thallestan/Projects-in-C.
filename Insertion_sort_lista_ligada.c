#include <stdlib.h>
#include <stdio.h>

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode {
   int data;
   DLinkedNode *prev, *next;
};

void insertion_sort(int *v, int n) 
{
	int i, k;

	for (i = 1; i < n; i++) {
		int item_atual = v[i];

	int indice_para_inserir = i;
	for (k = i - 1; k >= 0 && item_atual < v[k]; k--) 
	{
		v[k+1] = v[k];
		indice_para_inserir--;
	}
	v[indice_para_inserir] = item_atual;
	}
}

DLinkedNode *insertion_sort(DLinkedNode *inicio, int *comparacoes) 
{
    DLinkedNode *i = inicio->next;
    *comparacoes = 0;

	while (i != NULL) 
    {
		int item_atual = i.data;
        DLinkedNode *indice_para_inserir = i;
        DLinkedNode *k = i->prev;
        while (k != NULL && item_atual < k->data) 
        {
            *comparacoes = *comparacoes + 1;
            k->next->data = k->data;
            indice_para_inserir = indice_para_inserir->prev;
            k = k->prev;
        }
        *comparacoes = *comparacoes + 1;
        indice_para_inserir->data = item_atual;
        i = i->next;
	}
}

int main()
{

}