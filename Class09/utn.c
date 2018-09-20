#include <stdio.h>
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


static int getString(char* pBuffer, int limite);
static int isFloat(char* pBuffer);
static int isTelefono(char* pBuffer);
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
            if(utn_getFloat(&buffer) == 0 && buffer >= min && buffer <= max)
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
int utn_getFloat(float* pResultado)
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
int utn_getTelefono(float* pResultado)
{
    int retorno = -1;
    char bufferString[4096];
    if(getString(bufferString, 15) == 0 && isTelefono(bufferString))
    {
        *pResultado = atof(bufferString);
        retorno = 0;
    }
    return retorno;
}
static int isFloat(char* pBuffer)
{
    int i = 0;
    int retorno = -1;
    int contadorPuntos = 0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] == '.' && contadorPuntos == 0)
        {
            contadorPuntos++;
            i++;
            continue;
        }
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            retorno = 0;
            break;
        }
        i++;
    }
    return retorno;
}
static int isTelefono(char* pBuffer)
{
    int i = 0;
    int retorno = -1;
    int contadorGuiones = 0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] != ' ' && pBuffer[i] != '-')
        {
            contadorGuiones++;
            i++;
            continue;
        }
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            retorno = 0;
            break;
        }
        i++;
    }
    return retorno;
}
static int getString(char* pBuffer, int limite)
{
    int retorno = -1;
    char bufferString[4096];
    if(pBuffer != NULL && limite > 0)
    {
        fflush(stdin);
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
