#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "clientes.h"
#include "ventas.h"
#define CANT_CLIENTES 10
#define CANT_VENTAS 10
int main()
{
    Cliente cliente[CANT_CLIENTES];
    Venta ventas[CANT_VENTAS];
    int op;
    int id;
    int borrar;
    int indiceVacio;
    int bandera=0;
    int salir=0;
    client_cargarDatosVacio(cliente,CANT_CLIENTES);
    vent_cargarDatosVacio(ventas,CANT_VENTAS);
    client_altaForzada(cliente, CANT_CLIENTES, "Carlos", "Alvarez", "2040254869");
    client_altaForzada(cliente, CANT_CLIENTES, "Agustina", "Torres", "20612579469");
    client_altaForzada(cliente, CANT_CLIENTES, "Nahuel", "Nuñez", "20143265879");
    client_altaForzada(cliente, CANT_CLIENTES, "Martin", "Bottani", "20400143529");
    do
    {
        if(client_chequearIndice(cliente,CANT_CLIENTES) == -1)
        {
            bandera = 1;
        }
        else
        {
            bandera = 0;
        }
        utn_getEntero(&op,3,"\n1-Cargar un cliente\n2-Modificar datos de cliente por ID\n3-Baja de cliente por ID\n4-Vender afiches\n5-Editar venta\n6-Cobrar venta\n7Salir\n","Error\n",8,0);
        switch(op)
        {
                case 1:
                    if(client_indicesVacios(cliente,CANT_CLIENTES,&indiceVacio) == 0)
                    {
                        client_cargarIndice(cliente,indiceVacio,CANT_CLIENTES);
                        break;
                    }
                    else
                    {
                        printf("\nNo hay indice para cargar.\n");
                    }
                    break;
                case 2:
                    if(bandera == 1)
                    {
                        if(utn_getEntero(&id,2,"\nIngrese el ID a modificar: ", "Error", CANT_CLIENTES, -1) == 0)
                        {
                            if(id >= 0)
                            {
                                client_modificarID(cliente, id,CANT_CLIENTES);
                            }
                        }
                    }
                    else
                    {
                        printf("\nNo hay datos cargados\n");
                    }
                    break;
                case 3:
                    if(bandera == 1)
                    {
                        if(utn_getEntero(&id,2,"\nIngrese el ID para borrar: ", "Error", CANT_CLIENTES, -1) == 0)
                        {
                            if(id >= 0)
                            {
                                if(utn_getEntero(&borrar,2,"\nDesea borrar este cliente? Si = 1/No = 0\n", "Error", 2, -1) == 0)
                                {
                                    if(borrar == 1)
                                    {
                                        client_borrarClientePorID(cliente, id,CANT_CLIENTES);
                                        printf("\nSe borro el cliente\n");
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        printf("\nNo hay datos cargados\n");
                    }
                    break;
                case 4:
                    //client_mostrarIndice(cliente,CANT_CLIENTES);
                    if(utn_getEntero(&id,2,"\nID de Cliente: ", "Error", CANT_CLIENTES, -1) == 0)
                    {
                        if(client_buscarClientePorID(cliente,CANT_CLIENTES,id) != -1)
                        {
                            if(vent_indicesVacios(ventas,CANT_VENTAS,&indiceVacio)==0)
                            {
                                if(vent_cargarIndice(ventas, indiceVacio, CANT_VENTAS, id) ==0)
                                {
                                    vent_mostrarIndice(ventas,CANT_VENTAS);
                                }
                                break;
                            }
                            else
                            {
                                printf("\nError, id invalido.\n");
                            }
                        }
                    }
                    break;
                case 5:
                    vent_mostrarVentas(ventas,CANT_VENTAS);
                    if(utn_getEntero(&id,2,"\nElija el ID de la venta que quiere modificar: ", "Error", CANT_VENTAS, -1) == 0)
                    {
                        if(vent_buscarVentaPorID(ventas, CANT_VENTAS, id) != -1)
                        {
                            vent_modificarVenta(ventas, id,CANT_VENTAS);
                            break;
                        }
                        else
                        {
                            printf("\nError, id invalido.\n");
                        }
                    }
                case 6:
                    vent_mostrarVentas(ventas,CANT_VENTAS);
                    if(utn_getEntero(&id,2,"\nElija el ID de la venta que quiere cobrar: ", "Error", CANT_VENTAS, -1) == 0)
                    {
                        if(vent_buscarVentaPorID(ventas, CANT_VENTAS, id) != -1)
                        {
                            mostrarClientesVentas(ventas,CANT_VENTAS, cliente);
                            vent_modificarEstado(ventas, id, CANT_VENTAS);
                            break;
                        }
                        else
                        {
                            printf("\nError, id invalido.\n");
                        }
                    }
                case 7:
                salir = 1;
        }
    }while(salir==0);

    return 0;
}