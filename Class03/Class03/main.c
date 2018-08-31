#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    int num;
    float coma;
    if(utn_getNumero(&num, 3, "Dame tu edad:\n", "Te fuiste del rango.\n", "La edad es numerica.\n", 199, 0) == 0)
    {
        printf("La edad es: %d \n", num);
    }
    if(utn_getDecimal(&coma, 3, "Dame un numero con coma:\n", "Te fuiste del rango.\n", "Error, dame un numero.\n", 199, 0) == 0)
    {
        printf("El numero con coma es: %.2f", coma);
    }
    return 0;
}


