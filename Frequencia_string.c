#include <stdio.h>
#include <stdlib.h>

void frequencia_string(const char *str, const char *texto, int *qtd) 
{
    int i=0;
    int j=0;
    int n=0;
    *qtd = 0;

    for(i=0;str[i]!='\0';i++)
    {
        n++;
    } 

    for(i=0;texto[i]!='\0';i++)
    {
        if (str[0]==texto[i] || str[0]==(texto[i]+32) || (str[0]+32)==(texto[i]))
        {
            j=0;
            while((str[j]==texto[i] || str[j]==(texto[i]+32) || (str[j]+32)==(texto[i])) && (j!=n))
            {
                if(str[j]!='\0')
                {
                    j++;
                    i++;
                }
                if(j==(n-1))
                {
                    *qtd=*qtd+1;
                    j++;
                }
               
            }
            
        }
    }

}

int main ()
{
    char texto[100];
    char str[100];
    int qtd=0;

    fgets(texto,100,stdin);
    fgets(str,100,stdin);

    frequencia_string(str,texto,&qtd);

    printf("A palavra aparece %d vezes\n",qtd);
}

