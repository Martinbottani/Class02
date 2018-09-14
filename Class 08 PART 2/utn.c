#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>

/**
    utn_getInt:permite ingresar un numero entero y lo validar
    @param *pResultado: guarda el numero 1 ingresado luego de validarlo
    @return : 0 OK, -1 error
*/
/**
    utn_getFloat:permite ingresar un numero con coma y lo validar
    @param *pResultado: guarda el numero 1 ingresado luego de validarlo
    @return : 0 OK, -1 error
*/

static int getFloat(float* pResultado);
static int getString(char* pBuffer, int limite);
static int getInt(int* pResultado);
int utn_getNumeroDecimal(float *pNum, int reint, char* msg, char* msgError,float max, float min)
{
    int retorno = -1;
    float buffer;
    if(pNum != NULL && msg != NULL && msgError != NULL && min <= max && reint >= 0)
    {
        do
        {
            reint--;
            printf("%s", msg);
            if(getFloat(&buffer) == 0 && buffer >= min && buffer <= max)
            {
                *pNum = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", msgError);
            }
        }while(reint >= 0);
    }

    return retorno;
}
int utn_getNombre(char* pNombre, int reint, char* msg, char* msgError)
{
    int retorno = -1;
    char buffer;
    if(pNombre != NULL && msg != NULL && msgError != NULL && reint >= 0)
    {
        do
        {
            reint--;
            printf("%s", msg);
            if(getString(&buffer, 15) == 0)
            {
                *pNombre = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", msgError);
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
            __fpurge(stdin);
        }
    }


    return retorno;
}
static int getFloat(float* pResultado)
{
    int retorno = -1;
    char bufferString[4096];
    if(getString(bufferString, 15) == 0 && isFloat(bufferString))
    {
        *pResultado = atof(bufferString);
        retorno = 0;
    }
    return retorno;
}
int isFloat(char* pBuffer)
{
    return 1;
}
static int getString(char* pBuffer, int limite)
{
    int retorno = -1;
    char bufferString[4096];
    if(pBuffer != NULL && limite > 0)
    {
        __fpurge(stdin);
        fgets(pBuffer, sizeof(pBuffer), stdin);
        if(pBuffer[strlen(pBuffer) - 1] == '\n')
        {
            pBuffer[strlen(pBuffer) - 1] = '\0';
        }
        if(strlen(bufferString) < limite)
        {
            strncpy(pBuffer, bufferString, limite);
            retorno = 0;
        }
    }

    return retorno;
}
static int getInt(int* pResultado)
{
    /*
    int ret=-1;
    int num;

    if(scanf("%d",&num)==1)
    {
        *pResultado = num;
        ret=0;
    }
    return ret;
    */
    int aux;
    char cadena[64];
    scanf("%s", cadena);
    if(utn_esNumero(cadena) == 0)
    {
        aux = atoi(cadena);
        *pResultado = aux;
        return 0;
    }
    return -1;
}
