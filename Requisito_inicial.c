#include <stdio.h>
#include <stdlib.h>

typedef struct Disciplina Disciplina;
struct Disciplina {
    int cod;
    char *nome;
    int creditos;
    Disciplina *requisito;
};

Disciplina *requisito_inicial(Disciplina *disciplina, int *qtd) 
{
    if(disciplina->requisito != NULL)
    {
        return requisito_inicial(disciplina->requisito, *qtd + 1);
    }
    else
        return disciplina;
}