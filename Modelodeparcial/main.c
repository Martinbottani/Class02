#include <stdio_ext.h>
#include <stdlib.h>
#include "pantallas.h"
#include "utn.h"
#include "contratacion.h"
#define CANT_PANTALLAS 5
#define CANT_CONTRATACIONES 5
int main()
{
    Pantalla pant[CANT_PANTALLAS];
    Contratacion cliente[CANT_CONTRATACIONES];
    int op;
    int id;
    char cuitCliente[50];
    int indiceVacio;
    int salir=0;
    cargarDatosVacio(pant,CANT_PANTALLAS);
    cliente_cargarDatosVacio(cliente, CANT_CONTRATACIONES);
    do
    {
    utn_getEntero(&op,3,"\n1-Cargar un pantalla\n2-Imprimir lista de la pantalla\n3-Modificar un ID\n4-Borrar ID\n5-Contratar una pantalla\n6-Modificar contratacion\n7-Salir\n","Error\n",8,0);
        switch(op)
        {
                case 1:
                    if(prod_getEmptyIndex(pant,CANT_PANTALLAS,&indiceVacio)==0)
                    {
                        cargarIndice(pant,indiceVacio,CANT_PANTALLAS);
                        break;
                    }
                    else
                    {
                        printf("No hay indice.");
                    }
                    break;
                case 2:
                    mostrarIndice(pant,CANT_PANTALLAS);
                    break;
                case 3:
                    if(utn_getEntero(&id,2,"\nIngrese el ID a modificar: ", "Error", CANT_PANTALLAS, -1) == 0)
                    {
                        if(id >=0)
                        {
                            modificarID(pant, id,CANT_PANTALLAS);
                        }
                        else
                        {
                            printf("Error, indice invalido.");
                        }
                    }
                    break;
                case 4:
                    if(utn_getEntero(&id,2,"\nIngrese el ID para borrar: ", "Error", CANT_PANTALLAS, -1) == 0)
                    {
                        if(id >=0)
                        {
                            borrarPantallaPorID(pant, id,CANT_PANTALLAS);
                        }
                        else
                        {
                            printf("Error, indice invalido.");
                        }
                    }
                    break;
                case 5:
                    mostrarIndice(pant,CANT_PANTALLAS);
                    if(utn_getEntero(&id,2,"\nElija el ID de la pantalla que quiere contratar: ", "Error", CANT_PANTALLAS, -1) == 0)
                    {
                        if(buscarPantallaPorID(pant, CANT_PANTALLAS, id) != -1)
                        {
                            if(prod_getEmptyIndexCliente(cliente,CANT_CONTRATACIONES,&indiceVacio)==0)
                            {
                                cliente_cargarIndice(cliente, indiceVacio, CANT_CONTRATACIONES, id);
                                break;
                            }
                            else
                            {
                                printf("Error, id invalido.");
                            }
                        }
                    }
                    break;
                case 6:
                    printf("Cuit del Cliente: ");
                    if(utn_getString(cuitCliente, 50) == 0)
                    {
                        if(buscarContratacionPorCUIT(cliente, CANT_CONTRATACIONES, cuitCliente) == 0)
                        {
                            mostrarContrataciones(cliente, CANT_CONTRATACIONES, pant);
                            if(utn_getEntero(&id,2,"\nElija el ID de la pantalla que quiere modificar: ", "Error", CANT_PANTALLAS, -1) == 0)
                            {
                                if(buscarPantallaPorID(pant, CANT_PANTALLAS, id) != -1)
                                {
                                    modificarContratacion(cliente, id, CANT_CONTRATACIONES);
                                    break;
                                }
                                else
                                {
                                    printf("Error, id invalido.");

                                }
                            }
                        }
                    }
                    break;
                case 7:
                salir = 1;
        }
    }while(salir==0);

    return 0;
}
