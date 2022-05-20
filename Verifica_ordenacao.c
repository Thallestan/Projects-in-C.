#include <stdio.h>
#include <stdlib.h>

typedef struct DiscoVoador DiscoVoador;
struct DiscoVoador {
    char *modelo;
    char *planeta;
    int autonomia;
};

int verificar_ordenacao(DiscoVoador *discos, int n_discos) 
{
    int a=0;
    for(int i =0; i < (n_discos-1); i++)
    {
        if(discos[i].modelo[5] < discos[i+1].modelo[5])
        {
            a++;
        }
        if(discos[i].modelo[5] == discos[i+1].modelo[5])
        {
            if((discos[i].modelo[6] == '\0') && (discos[i+1].modelo[6] != '\0'))
            {
                a++;
            }
            else
            {
                if(discos[i].modelo[6] < discos[i+1].modelo[6])
                {
                    a++;
                }
                if(discos[i].modelo[6] == discos[i+1].modelo[6])
                {
                    if((discos[i].modelo[7] == '\0') && (discos[i+1].modelo[7] != '\0'))
                    {
                        a++;
                    }
                    else
                    {
                        if(discos[i].modelo[7] < discos[i+1].modelo[7])
                        {
                            a++;
                        }
                        if(discos[i].modelo[7] == discos[i+1].modelo[7])
                        {
                            if((discos[i].modelo[8] == '\0') && (discos[i+1].modelo[8] != '\0'))
                            {
                                a++;
                            }
                            else
                            {
                                if(discos[i].modelo[8] < discos[i+1].modelo[8])
                                {
                                    a++;
                                }
                                if(discos[i].modelo[8] == discos[i+1].modelo[8])
                                {
                                    if((discos[i].modelo[9] == '\0') && (discos[i+1].modelo[9] != '\0'))
                                    {
                                        a++;
                                    }
                                    else
                                    {
                                        if(discos[i].modelo[9] < discos[i+1].modelo[9])
                                        {
                                            a++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(a == (n_discos-1))
    {
        return 1;
    }
    //Conferir se é ordem decrescente

    a=0;
    for(int i =0; i < (n_discos-1); i++)
    {
        if(discos[i].modelo[5] > discos[i+1].modelo[5])
        {
            a++;
        }
        if(discos[i].modelo[5] == discos[i+1].modelo[5])
        {
            if((discos[i].modelo[6] != '\0') && (discos[i+1].modelo[6] == '\0'))
            {
                a++;
            }
            else
            {
                if(discos[i].modelo[6] > discos[i+1].modelo[6])
                {
                    a++;
                }
                if(discos[i].modelo[6] == discos[i+1].modelo[6])
                {
                    if((discos[i].modelo[7] != '\0') && (discos[i+1].modelo[7] == '\0'))
                    {
                        a++;
                    }
                    else
                    {
                        if(discos[i].modelo[7] > discos[i+1].modelo[7])
                        {
                            a++;
                        }
                        if(discos[i].modelo[7] == discos[i+1].modelo[7])
                        {
                            if((discos[i].modelo[8] != '\0') && (discos[i+1].modelo[8] == '\0'))
                            {
                                a++;
                            }
                            else
                            {
                                if(discos[i].modelo[8] > discos[i+1].modelo[8])
                                {
                                    a++;
                                }
                                if(discos[i].modelo[8] == discos[i+1].modelo[8])
                                {
                                    if((discos[i].modelo[9] != '\0') && (discos[i+1].modelo[9] == '\0'))
                                    {
                                        a++;
                                    }
                                    else
                                    {
                                        if(discos[i].modelo[9] > discos[i+1].modelo[9])
                                        {
                                            a++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(a == (n_discos-1))
    {
        return 2;
    }
    
    //Ordem crescente planeta

    a=0;
    for(int i =0; i < (n_discos-1); i++)
    {
        if(discos[i].planeta[0] < discos[i+1].planeta[0])
        {
            a++;
        }
        if(discos[i].planeta[0] == discos[i+1].planeta[0])
        {
            if(discos[i].planeta[1] < discos[i+1].planeta[1])
            {
                    a++;
            }
            if(discos[i].planeta[1] == discos[i+1].planeta[1])
            {
                if(discos[i].planeta[2] < discos[i+1].planeta[2])
                {
                    a++;
                }
                if(discos[i].planeta[2] == discos[i+1].planeta[2])
                {
                    if(discos[i].planeta[3] < discos[i+1].planeta[3])
                    {
                        a++;
                    }
                    if(discos[i].planeta[3] == discos[i+1].planeta[3])
                    {
                        if((discos[i].planeta[4] == '\0') && (discos[i+1].planeta[4] == '\0'))
                        {
                            a++;
                        }
                        else
                        {
                            if(discos[i].planeta[4] < discos[i+1].planeta[4])
                            {
                                a++;
                            }
                            if(discos[i].planeta[4] == discos[i+1].planeta[4])
                            {
                                if((discos[i].planeta[5] == '\0') && (discos[i+1].planeta[5] == '\0'))
                                {
                                    a++;
                                }
                                else
                                {
                                    if(discos[i].planeta[5] < discos[i+1].planeta[5])
                                    {
                                        a++;
                                    }
                                    if(discos[i].planeta[5] == discos[i+1].planeta[5])
                                    {
                                        if((discos[i].planeta[6] == '\0') && (discos[i+1].planeta[6] == '\0'))
                                        {
                                            a++;
                                        }
                                        else
                                        {
                                            if(discos[i].planeta[6] < discos[i+1].planeta[6])
                                            {
                                                a++;
                                            }
                                            if(discos[i].planeta[6] == discos[i+1].planeta[6])
                                            {
                                                if((discos[i].planeta[7] == '\0') && (discos[i+1].planeta[7] == '\0'))
                                                {
                                                    a++;
                                                }
                                            }
                                        } 
                                    }
                                } 
                            }
                        } 
                    }  
                }
            }
        }
    }
    if(a == (n_discos-1))
    {
        return 3;
    }
    
    // Crescente autonomia

    a=0;
    for(int i =0; i < (n_discos-1); i++)
    {
        if(discos[i].autonomia[0] < discos[i+1].autonomia)
        {
            a++;
        }
    }
    if(a == (n_discos-1))
    {
        return 4;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n = 4;
    int ord =0;

    struct DiscoVoador f[n];

    f[0].modelo = "MODELO_A";
    f[0].planeta = "TERRA";
    f[0].autonomia = 100;

    f[1].modelo = "MODELO_B";
    f[1].planeta = "MARTE";
    f[1].autonomia = 500;

    f[2].modelo = "MODELO_C";
    f[2].planeta = "JUPITER";
    f[2].autonomia = 300;

    f[3].modelo = "MODELO_D";
    f[3].planeta = "PLUTAO";
    f[3].autonomia = 50;


    ord = verificar_ordenacao(f, n);

    printf("Ordenacao = %d\n", ord);
}