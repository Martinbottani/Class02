#include <stdio.h>
#include <stdlib.h>
#include "envio.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
//#include "informes.h"
//#include "generar.h"

int main()
{
    LinkedList* lista = ll_newLinkedList();
    FILE* pFile;
    int op;
    int salir = 0;
    char auxFile[1024];
    char auxZona[1024];
    do
    {
        utn_getEntero(&op,3,"\n1-Cargar archivo\n2-Imprimir Envios\n3-Calcular costos\n4-Generar archivo de costos por zona\n6-Salir\n","Error\n",6,0);
        switch(op)
        {
                case 1:
                        if(utn_getNombre(auxFile,"Ingrese el nombre del archivo: \n", "Error\n") == 0)
                        {
                            pFile = fopen(auxFile, "r");
                            parser_parseFile(pFile,lista);
                            fclose(pFile);
                        }
                        break;
                case 2:
                        envio_mostrar(lista);
                        break;
                case 3:
                        if(ll_map(lista,em_calcularCosto)== 0)
                        {
                            envio_mostrarCostos(lista);
                        }
                        else
                        {
                            printf("Error\n");
                        }
                        break;
                case 4:
                        if(utn_getNombre(auxZona,"Ingrese el nombre de la Zona:\n","Error\n") == 0)
                        {
                            if(env_generarArchivo(auxZona, lista) ==0)
                            {
                                printf("\nArchivo generado\n");
                            }
                        }
                case 6:
                salir = 1;
        }
    }while(salir==0);
    return 0;
}
