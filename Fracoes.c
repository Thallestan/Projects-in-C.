#include <stdio.h>
#include <stdlib.h>

typedef struct Fracao Fracao;
struct Fracao {
    int numerador, denominador;
};

//Algoritmo de Euclides iterativo
int mdc(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
//Algoritmo do MMC
int MMC(int a, int b)
{
    
    return a * (b / mdc(a, b));
}

Fracao reducao(Fracao f1)
{
    while((((f1.numerador%2) == 0) && ((f1.denominador%2) == 0)) || (((f1.numerador%7) == 0) && ((f1.denominador%7) == 0)) || (((f1.numerador%3) == 0) && ((f1.denominador%3) == 0)) || (((f1.numerador%5) == 0) && ((f1.denominador%5) == 0)) )
    {
        if(((f1.numerador%2) == 0) && ((f1.denominador%2) == 0))
        {
            f1.numerador = f1.numerador/2;
            f1.denominador = f1.denominador/2;
        }
        if(((f1.numerador%3) == 0) && ((f1.denominador%3) == 0))
        {
            f1.numerador = f1.numerador/3;
            f1.denominador = f1.denominador/3;
        }
        if(((f1.numerador%5) == 0) && ((f1.denominador%5) == 0))
        {
            f1.numerador = f1.numerador/5;
            f1.denominador = f1.denominador/5;
        }
        if(((f1.numerador%7) == 0) && ((f1.denominador%7) == 0))
        {
            f1.numerador = f1.numerador/7;
            f1.denominador = f1.denominador/7;
        }
    }

    return f1;
    
}

Fracao somar(Fracao f1, Fracao f2) 
{
    struct Fracao soma;
    int mmc=0;
    mmc = MMC(f1.denominador,f2.denominador);

    if(f1.denominador != f2.denominador)
    {
        soma.denominador = mmc;
        soma.numerador = ((mmc/f1.denominador)*f1.numerador)+((mmc/f2.denominador)*f2.numerador);
    }
    else
    {
        if(f1.numerador == f2.numerador)
        {
            soma.numerador = (f1.numerador + f2.numerador);
            soma.denominador = (f1.denominador + f2.denominador);
        }
        else
        {
            soma.denominador = f1.denominador;
            soma.numerador = (f1.numerador + f2.numerador);
        }
    }


    return reducao(soma);
}

Fracao somar_vetor(Fracao f[], int n_fracoes) 
{
    struct Fracao soma;
    
    soma.numerador = f[0].numerador;
    soma.denominador = f[0].denominador;

    for(int i = 1;i < n_fracoes; i++)
    {
        soma = somar(soma,f[i]);
        
    }

    
    return soma;
}

Fracao multiplicar(Fracao f1, Fracao f2) 
{
    struct Fracao soma;

    soma.numerador = (f1.numerador * f2.numerador);
    soma.denominador = (f1.denominador * f2.denominador);

    return reducao(soma);
}

Fracao multiplicar_vetor(Fracao f[], int n_fracoes) 
{
    struct Fracao soma;
    
    soma.numerador = f[0].numerador;
    soma.denominador = f[0].denominador;

    for(int i = 1;i < n_fracoes; i++)
    {
        soma = multiplicar(soma,f[i]);
        printf("soma.num = %d\n", soma.numerador);
        printf("soma.den = %d\n", soma.denominador);
        
    }
    
    return soma;
}

int main()
{
    int n_fracoes = 4;

    struct Fracao f1, f2, f[n_fracoes], res;

      f1.numerador = 15;
    f1.denominador = 20;

      f2.numerador = 12;
    f2.denominador = 60;

      f[0].numerador = 3;
    f[0].denominador = 2;

      f[1].numerador = 3;
    f[1].denominador = 6;
    
      f[2].numerador = 5;
    f[2].denominador = 25;
    
      f[3].numerador = 7;
    f[3].denominador = 5;

    res = multiplicar_vetor(f, n_fracoes);

    printf("%d\n", res.numerador);
    printf("%d\n", res.denominador);


}