#include <stdio.h>
#include <stdlib.h>
#include "venta.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "informes.h"
#include "generar.h"

int generarArchivoInforme(char* fileName,LinkedList* listaVentas)
{
    int retorno = -1;
    int cantidad = 0;
    int montoMayor = 0;
    int montoMayor2 = 0;
    int cantidadLCD = 0;
    FILE* pFile = fopen(fileName,"w");
    if(pFile != NULL)
    {
        cantidad = ll_count(listaVentas,inf_calcularUnidades);
        montoMayor = ll_count(listaVentas,inf_calcularMontoMayor);
        montoMayor2 = ll_count(listaVentas,inf_calcularMontoMayor2);
        cantidadLCD = ll_count(listaVentas,inf_calcularLCD);
        retorno = 0;
        fprintf(pFile, "Cantidad de unidades vendidas totales: %d\n", cantidad);
        fprintf(pFile, "Cantidad de ventas por un monto mayor a $10000: %d\n", montoMayor);
        fprintf(pFile, "Cantidad de ventas por un monto mayor a $20000: %d\n", montoMayor2);
        fprintf(pFile, "Cantidad de TVs LCD vendidas: %d\n", cantidadLCD);
    }
    fclose(pFile);
    return retorno;
}
