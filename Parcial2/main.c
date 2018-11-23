#include <stdio.h>
#include <stdlib.h>
#include "venta.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "informes.h"
#include "generar.h"

int main()
{
    LinkedList* listaVentas = ll_newLinkedList();
    FILE* pFile;
    pFile = fopen("data.csv", "r");
    if(parser_parseVenta(pFile,listaVentas)== 0)
    {

        if(generarArchivoInforme("informes.txt",listaVentas)==0)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    fclose(pFile);
    return 0;
}
