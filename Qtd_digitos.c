#include <stdio.h>

int quantidade_digitos(int numero) 
{
    int qtd = 0;
    while(numero!=0)
    {
        numero=numero/10;
        if(numero!=0)
        {
            qtd++;
        }
    }
    qtd++;
    return qtd;
}

int main ()
{
  int a = 0;

  scanf ("%d", &a);

  printf("Tem %d digitos",quantidade_digitos(a));
  
  
}