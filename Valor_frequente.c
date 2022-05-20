#include <stdio.h>

int valor_frequente(int v[], int n) 
{
    int a=0;
    int b=0;
    int i;
    int j;
    int freq=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;i++)
        {
            if(i!=j)
            {
                if(v[i]==v[j])
                {
                    a++;
                }
            }    
        }
        if(a>b)
        {
            b=a;
            freq=v[i];
        }
    }
    return freq;
}

int main ()
{
  int a = 0;
  int b=0;

  scanf ("%d", &a);

  int v[a];

  for (int i = 0; i < a; i++)
    {
      scanf ("%d", &b);
    }


  printf("O valor frequente eh %d ",valor_frequente(v, a));
  
  
}