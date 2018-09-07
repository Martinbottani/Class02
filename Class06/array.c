#include <stdio_ext.h>
#include <stdlib.h>
#include "array.h"
#include <string.h>
#define CANTIDAD_EMPLEADOS 5
#define DATO_INVALIDO -1
#define true 1
#define false 0



int utn_inicializarArray(int* pArray,int valor, int limite)
{
    int retorno=-1;
    int i;
    if(pArray != NULL && limite >0)
    {
        for(i=0;i < limite;i++)
        {
            pArray[i]=valor;
        }
        retorno=0;
    }


    return retorno;
}

int utn_mostrarArray(int* pArray,int limite)
{
    int i;
    for(i=0;i < limite;i++)
    {
        printf("\nIndex:[%d] - Value:%d - Add:%p",i,pArray[i],pArray+i);
    }

    return 0;
}

int utn_calcularMaximoArray(int* pArray,int limite,int* pMaximo)
{
    int i;
    int retorno;
    int maximo;
    int flagPrimerMaximo=0;
    for(i=0;i < limite;i++)
    {
        if(pArray[i]!=DATO_INVALIDO)
        {
            if(flagPrimerMaximo == 0)
            {
                maximo = pArray[i];
                flagPrimerMaximo=1;
            }
            else if(pArray[i] > maximo)
            {
                maximo = pArray[i];
            }
        }

    }
    if(flagPrimerMaximo==0)
    {
        retorno=-2;
    }else
    {
        retorno=0;
        *pMaximo=maximo;
    }

    return retorno;
}

int utn_calcularMinimoArray(int* pArray,int limite,int* pMinimo)
{
    int i;
    int minimo = pArray[0];
    for(i=0;i < limite;i++)
    {
        if(pArray[i] < minimo)
        {
            minimo= pArray[i];
        }
    }
    *pMinimo = minimo;
    return 0;
}

int utn_calcularPromedioArray(int* pArray,int limite,float* promedio)
{
    int i;
    int retorno;
    float acumulador;
    int valida = 0;
    float promedium;
    int flagPromedio = 0;
    for(i=0;i < limite;i++)
    {
        if(pArray[i]!=DATO_INVALIDO)
        {
            acumulador += pArray[i];
            valida++;
            if(flagPromedio == 0)
            {
                flagPromedio = 1;
            }
        }

    }
    if(flagPromedio == 0)
    {
        retorno = -1;
    }else
    {
        promedium = acumulador / (float) valida;
        *promedio = promedium;
        retorno = 0;
    }

    return retorno;
}
int utn_esNumero(char* pCadena)
{
    int retorno = 0;
    char aux;
    int i= 0;
    aux = pCadena[i];
    while(aux != 0)
    {
        if(aux < 48 || aux > 57)
        {
            retorno = -1;
            break;
        }
        i++;
        aux = pCadena[i];
    }

    return retorno;
}
int utn_ordenarArray(int* pArray, int limite, char menorMayor)
{
    int retorno = -1;
    int i = 0;
    int aux = 0;
    int flagOrdenar = 1;
    if(pArray != NULL && limite >0)
    {
         while(flagOrdenar == 1)
        {
            flagOrdenar = 0;
            for(i = 0; i < limite -1; i++)
            {
                if(menorMayor == '>')
                {
                    if(pArray[i] > pArray[i+1])
                    {
                        aux = pArray[i];
                        pArray[i] = pArray[i+1];
                        pArray[i+1] = aux;
                        flagOrdenar = 1;
                    }
                }
                else if(menorMayor == '<')
                {
                    if(pArray[i] < pArray[i+1])
                    {
                        aux = pArray[i];
                        pArray[i] = pArray[i+1];
                        pArray[i+1] = aux;
                        flagOrdenar = 1;
                    }
                }
                //printf("\nIndex ordenado es:[%d] - Value:%d - Add:%p",i,pArray[i],pArray+i);
            }
            retorno = 0;
        }
    }

    return retorno;
}
