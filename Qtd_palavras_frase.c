#include <stdio.h>

void imprimir_qtd_palavras(char texto[]) 
{
    int n =0;
    int i=0;
    int j;

    while(texto[i]!='\0')
    {
        n=0;
        while(texto[i]!='.')
        {
            if(texto[i]==' ')
            {
                if(texto[i-1]!=' ')
                {
                    n = n + 1 ;
                }
            }
            i++;
        }
        if(texto[i]=='.')
        {
            if(texto[i-1]!=' ')
            {
                n++;
               
            } 
            i=i+2;
        }
       > printf("%d\n", n);
        
    }
    
}

int main ()
{
  char texto[50];

  fgets(texto,50,stdin);
  
  imprimir_qtd_palavras(texto); 
}