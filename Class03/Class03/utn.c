#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

static int getInt(int* pResult);
static int getFloat(float* pResult);

int utn_getNumero(int* pRes, int reint, char* msg,char* msgError,char* msgError2, int max, int min)
{
    int retorno = -1;
    int auxiliarNum;
    for(; reint > 0; reint--)
    {
        printf(msg);
        if(getInt(&auxiliarNum) == 0)
        {
            if(auxiliarNum >= min && auxiliarNum <= max)
            {
                *pRes = auxiliarNum;
                retorno = 0;
                break;
            }else
            {
                printf(msgError);
            }
        }else
        {
            printf(msgError2);
            __fpurge(stdin);
        }
    }

    return retorno;
}

int utn_getDecimal(float* pRes, int reint, char* msg,char* msgError,char* msgError2, float max, float min)
{
    int retorno = -1;
    float auxiliarNum;
    for(; reint > 0; reint--)
    {
        printf(msg);
        if(getFloat(&auxiliarNum) == 0)
        {
            if(auxiliarNum >= min && auxiliarNum <= max)
            {
                *pRes = auxiliarNum;
                retorno = 0;
                break;
            }else
            {
                printf(msgError);
            }
        }else
        {
            printf(msgError2);
            __fpurge(stdin);
        }
    }

    return retorno;
}

static int getInt(int* pResult)
{
    int retorno = -1;
    int num;
    if(scanf("%d", &num) == 1)
    {
        *pResult = num;
        retorno = 0;
    }
    return retorno;
}

static int getFloat(float* pResult)
{
    int retorno = -1;
    float num;
    if(scanf("%f", &num) == 1)
    {
        *pResult = num;
        retorno = 0;
    }
    return retorno;
}
