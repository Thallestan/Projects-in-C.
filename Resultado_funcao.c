#include <stdio.h>

void funcao(int a, int b, int *resultado) 
{
    int x=0;
    int y=0;
    for (int i = 1; i <= a; i++)
    {
        x=0;
        for (int j = 1; j <= b; j++)
        {
            x = x + (i*j+10);
        }
        y=(5*i*x);
        *resultado=*resultado+y;     
    }
    
}

int main ()
{
  int a=0;
  int b=0;
  int resultado=0;

  scanf("%d",&a);
  scanf("%d",&b);

  funcao(a,b,&resultado);

  printf("Resultado = %d\n", resultado);
}