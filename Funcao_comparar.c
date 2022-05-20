#include <stdlib.h>
#include <stdio.h>

typedef struct ItemVetor ItemVetor;
struct ItemVetor {
    char *modelo;
    char *planeta;
    int autonomia;
};

int comparar(ItemVetor item1, ItemVetor item2)
{
    if (item1.autonomia > item2.autonomia)
    {
        return 1;
    }
    if (item1.autonomia < item2.autonomia)
    {
        return -1;
    }

    for(int i=0;item1.planeta[i]!='\0';i++)
    {
        if (item1.planeta[i] > item2.planeta[i])
        {
            return 1;
        }
        if (item1.planeta[i] < item2.planeta[i])
        {
            return -1;
        }
    }

    for(int i=0;item1.modelo[i]!='\0';i++)
    {
        if (item1.modelo[i] > item2.modelo[i])
        {
            return 1;
        }
        if (item1.modelo[i] < item2.modelo[i])
        {
            return -1;
        }
    }

    return 0;

}

int main ()
{
    int auto1=0;
    int auto2=0;
    int res=0;
    struct ItemVetor ItemVetor1;
    struct ItemVetor ItemVetor2;

    fgets(ItemVetor1.modelo,50,stdin);
    fgets(ItemVetor1.planeta,50,stdin);
    scanf("%d", &auto1);

    fgets(ItemVetor2.modelo,50,stdin);
    fgets(ItemVetor2.planeta,50,stdin);
    scanf("%d", &auto2);

    res = comparar(ItemVetor1,ItemVetor2);

    printf("Comparaçao = %d", res);

}