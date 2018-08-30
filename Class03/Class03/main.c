#include <stdio_ext.h>
#include <stdlib.h>

//int getEdad(int* pEdad);
int getEntero(int* pRes, int reint, char* msg, char* msgError, char* msgError2, int max, int min);

int main()
{
    int n;
    if(getEntero(&n, 3, "Dame tu edad:\n", "Te fuiste del rango.\n", "La edad es numerica.\n", 199, 0) == 0)
    {
        printf("La edad es: %d", n);
    }
    return 0;
}
/*
int getEdad(int* pEdad)
{
    int retorno = -1;
    int auxiliarEdad;
    int reintentos;
    for(reintentos = 3; reintentos > 0; reintentos--)
    {
        printf("Dame tu edad: \n");
        if(scanf("%d", &auxiliarEdad) == 1)
        {
            if(auxiliarEdad >= 0 && auxiliarEdad <= 199)
            {
                *pEdad = auxiliarEdad;
                retorno = 0;
                break;
            }else
            {
                printf("Te fuiste del rango\n");
            }
        }else
        {
            printf("La edad es numerica\n");
            __fpurge(stdin);
        }
    }

    return retorno;
}
*/
int getEntero(int* pRes, int reint, char* msg,char* msgError,char* msgError2, int max, int min)
{
    int retorno = -1;
    int auxiliarEdad;
    for(; reint > 0; reint--)
    {
        printf(msg);
        if(scanf("%d", &auxiliarEdad) == 1)
        {
            if(auxiliarEdad >= min && auxiliarEdad <= max)
            {
                *pRes = auxiliarEdad;
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
