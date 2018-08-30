#include <stdio_ext.h>
#include <stdlib.h>

int getEdad(int* pEdad);

int main()
{
    int edad;
    if(getEdad(&edad) == 0)
    {
        printf("La edad es: %d", edad);
    }
    return 0;
}

int getEdad(int* pEdad)
{
    int retorno = -1;
    int auxiliarEdad;
    for(int reintentos = 3; reintentos > 0; reintentos--)
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
