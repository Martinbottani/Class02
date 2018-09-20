#include <stdio_ext.h>
#include <stdlib.h>
#include "producto.h"
#include <string.h>
static int getFloat(float* pResultado);
static int getInt(int* pResultado);
static int isFloat(char* pBuffer);
int utn_getNumeroDecimal(float *pNum, int reint, char* msg, char* msgError,float maximo,float minimo)
{
    float buffer;
    int retorno = -1;

    if(pNum != NULL && msg != NULL && msgError !=NULL && minimo<=maximo && reint >= 0)
    {
        do
        {
            reint--;
            printf("%s",msg);
            if(getFloat(&buffer) == 0 &&
                buffer <= maximo && buffer >= minimo )
            {
                    *pNum = buffer;
                    retorno = 0;
                    break;

            }else
            {
                printf("%s",msgError);
                __fpurge(stdin);
            }


        }while(reint >= 0);

    }

    return retorno;
}
int utn_getEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo)
{
    int auxiliarNum;
    int retorno = -1;
    for(;reint>0;reint--)
    {
        printf(msg);
        if(getInt(&auxiliarNum) == 0)
        {
            if(auxiliarNum > minimo && auxiliarNum < maximo)
            {
                *pNum = auxiliarNum;
                retorno = 0;
                break;

            }else
            {
                printf(msgError);
            }


        }else
        {
            printf(msgError);
        }
    }


    return retorno;
}
int getString(char* pBuffer, int limite)
{
    int retorno = -1;
    if(pBuffer != NULL && limite > 0)
    {
        __fpurge(stdin);
        fgets(pBuffer, limite, stdin);
        if(pBuffer[strlen(pBuffer) - 1] == '\n')
        {
            pBuffer[strlen(pBuffer) - 1] = '\0';
        }
        if(strlen(pBuffer) < limite)
        {
            retorno = 0;
        }
    }
    return retorno;
}
static int getFloat(float* pResultado)
{
    int retorno = -1;
    char bufferString[4096];
    if(getString(bufferString, 15) == 0 && isFloat(bufferString) == 0)
    {
        *pResultado = atof(bufferString);
        retorno = 0;
    }
    return retorno;
}
static int getInt(int* pResultado)
{
    int retorno=-1;
    int num;

    if(scanf("%d",&num)==1)
    {
        *pResultado = num;
        retorno=0;
    }
    return retorno;
}
static int isFloat(char* pBuffer)
{
    int i=0;
    int retorno=0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}
