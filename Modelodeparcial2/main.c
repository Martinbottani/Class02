#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "utn.h"
#define CANT_ASOCIADOS 5
int main()
{
    Asociado asociados[CANT_ASOCIADOS];
    int op;
    int id;
    int indiceVacio;
    int salir=0;
    cargarDatosVacio(asociados,CANT_ASOCIADOS);
    do
    {
    utn_getEntero(&op,3,"1-Cargar Asociado:\n2-Modificar datos de Asociado\n3-Baja de asociado\n","\nError\n",4,0);
        switch(op)
        {
                case 1:
                    if(indicesVacios(asociados,CANT_ASOCIADOS,&indiceVacio)==0)
                    {
                        cargarIndice(asociados,indiceVacio,CANT_ASOCIADOS);
                        break;
                    }
                    else
                    {
                        printf("\nNo hay indice.\n");
                    }
                    break;
                case 2:
                    if(utn_getEntero(&id,2,"\nIngrese el ID a modificar: ", "Error", CANT_ASOCIADOS, -1) == 0)
                    {
                        if(id >=0)
                        {
                            modificarID(asociados, id,CANT_ASOCIADOS);
                        }
                        else
                        {
                            printf("\nError, indice invalido.\n");
                        }
                    }
                    break;
                case 3:
                    if(utn_getEntero(&id,2,"\nIngrese el ID para borrar: ", "Error", CANT_ASOCIADOS, -1) == 0)
                    {
                        if(id >=0)
                        {
                            borrarPantallaPorID(asociados, id,CANT_ASOCIADOS);
                        }
                        else
                        {
                            printf("\nError, indice invalido.\n");
                        }
                    }
                    break;
                case 4:
                salir = 1;
        }
    }while(salir==0);
    return 0;
}
