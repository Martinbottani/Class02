#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "venta.h"
#include "utn.h"
#include <string.h>

int inf_calcularUnidades(void* pVenta)
{
    return ((Venta*)pVenta)->cantidad;
}

int inf_calcularMontoMayor(void* pElement, int max)
{
    int retorno = 0;
    float total;
    if(pElement != NULL)
    {
        total = ((Venta*)pElement)->cantidad * ((Venta*)pElement)->precioUnitario;
        if(total > max)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int inf_calcularMontoMayor2(void* pElement)
{
    int retorno = 0;
    float total;
    int cantidad;
    float precioUnitario;
    if(pElement != NULL)
    {
        cantidad = ((Venta*)pElement)->cantidad;
        precioUnitario = ((Venta*)pElement)->precioUnitario;
        total = cantidad * precioUnitario;
        if(total > 20000)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int inf_calcularLCD(void* pElement)
{
    int retorno = 0;
    if(strcmp(((Venta*)pElement)->codigoProducto,"LCD_TV") == 0)
    {
        retorno = 1;
    }
    return retorno;
}

