#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include <string.h>
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

int utn_mostrarArray(float* pArray,int limite)
{
    int i;
    for(i=0;i < limite;i++)
    {
        printf("\nIndex:[%d] - Value:%d",i,pArray[i]);
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
