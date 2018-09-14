#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "array.h"
#define CANTIDAD_EDADES 1
int main()
{
    int i;
    float edades[CANTIDAD_EDADES];
    char nombres[15][50];
    for(i = 0; i < CANTIDAD_EDADES; i++)
    {
        utn_getNombre(&nombres[i][j], 3, "Ingresa tu nombre: \n", "Error \n");
        if(utn_getNumeroDecimal(&edades[i], 3, "Ingrese la edad: \n", "Error \n", 200, 0) == -1)
        {
            edades[i] = -1;
        }
    }
    return 0;
}
