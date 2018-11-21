#include <stdio.h>
#include <stdlib.h>
#include "Compra.h"
#include "LinkedList.h"
#include "Parser.h"
#include "utn.h"

/**
    Realizar un programa que lee de un archivo los datos de compras de productos realizadas por clientes.
    Luego se le pedira al usuario que ingrese un id de un producto y el programa deberá imprimir por pantalla:
    - 1. Lista de compras filtrada segun el producto ingresado
    - 2. Monto total de cada compra considerando el valor del iva indicado.

    - 3. Por ultimo la lista filtrada obtenida con los datos ya calculados, debera ser escrita en un archivo separado por
    comas llamado "informe.csv", con el mismo formato que el original pero con una columna mas al final, en donde se
    indicara el monto total calculado.

    Para realizar el punto 1, se debera utilizar la funcion "filter".
    Para realizar el punto 2, se debera utilizar la funcion "map".
    Para imprimir por pantalla la lista, utilizar iterator.
*/

int generarArchivoInforme(FILE* fileName,LinkedList* listaCompras);

int main()
{
    // Definir lista de compras
    LinkedList* listaCompras = ll_newLinkedList();
    LinkedList* listaFiltrada = ll_newLinkedList();
    int id;
    FILE* pFile;
    pFile = fopen("data.csv", "r");
    //FILE* pFile2;
    //pFile2 = fopen("informe.csv", "r");
    // Crear lista compras
    //...

    // Leer compras de archivo data.csv
    if(parser_parseCompras(pFile,listaCompras)== 0)
    {

        //employee_mostrar(listaCompras);
        if(utn_getEntero(&id, 3, "Ingrese el numero de id: \n","Error, id invalido \n", 100, 0) == 0
           && emp_buscarPantallaPorID(listaCompras, id) != -1)
        {
            listaFiltrada = ll_filter2(listaCompras, id, compraIdSeleccionado);
            employee_mostrar(listaFiltrada);
            /*
            if(generarArchivoInforme(pFile2,listaFiltrada)==0)
            {
                printf("Archivo generado correctamente\n");
            }
            else
                printf("Error generando archivo\n");
                */
        }
        else
        {
            printf("\nError\n");
        }
        // Generar archivo de salida
    }
    else
    {
        printf("Error leyendo compras\n");
    }
    fclose(pFile);
    //fclose(pFile2);


    return 0;
}

int generarArchivoInforme(FILE* fileName,LinkedList* listaCompras)
{

    return 1;
}
