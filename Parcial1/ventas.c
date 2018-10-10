#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "ventas.h"
#include "utn.h"
#define A_COBRAR 1
#define COBRADA 0
static int generarID(void);

int venta_cargaForzadaVenta(Venta* pVentas,int limite,char* nombreArchivo, char* zona, int estado, int cantAfiches, int idCliente)
{
    int retorno=-1;
    int indice;
    vent_indicesVacios(pVentas, limite, &indice);
    if(pVentas != NULL && limite >0)
    {
          if(indice >= 0)
          {
            strncpy(pVentas[indice].nombreArchivo,nombreArchivo,128);
            strncpy(pVentas[indice].zona,zona,128);
            pVentas[indice].estado = estado;
            pVentas[indice].cantAfiches=cantAfiches;
            pVentas[indice].idCliente = idCliente;
            pVentas[indice].idVenta = generarID();
            pVentas[indice].isEmpty = 0;
            retorno =0;
          }
    }
    return retorno;
}

int vent_cargarDatosVacio(Venta* pVentas, int limite)
{
    int retorno = -1;
    int i;
    for(i=0;i<limite;i++)
    {
        pVentas[i].isEmpty=-1;
        retorno = 0;
    }
    return retorno;
}

int vent_cargarIndice(Venta* pVentas,int indice,int limite, int idCliente)
{
    int retorno = -1;
    char auxNombreArchivo[128];
    char auxZona[128];
    int auxAfiches;
    printf("Nombre del Video:\n");
    if(utn_getString(auxNombreArchivo,128)==0)
    {
        if(utn_getEntero(&auxAfiches,2,"Cuantos afiches?: \n", "\nError\n",364,0) == 0)
        {
                printf("Zona: ");
                if(utn_getString(auxZona,128)==0)
                {
                        strncpy(pVentas[indice].nombreArchivo,auxNombreArchivo,128);
                        strncpy(pVentas[indice].zona,auxZona,128);
                        pVentas[indice].cantAfiches = auxAfiches;
                        pVentas[indice].isEmpty = 0;
                        pVentas[indice].idVenta = generarID();
                        pVentas[indice].idCliente = idCliente;
                        retorno = 0;
                }
        }
    }

    return retorno;
}

int vent_indicesVacios(Venta* pVentas,int limite,int* indiceVacio)
{
    int i=0;
    int retorno = -1;
    while(i<limite)
    {
        if(pVentas[i].isEmpty==-1)
        {
            *indiceVacio=i;
            retorno = 0;
            break;
        }
        i++;
    }
    return retorno;
}

static int generarID(void)
{
    static int cont = -1;
    return ++cont;
}

int vent_mostrarIndice(Venta* pVentas,int limite)
{
    int retorno = -1;
    int i;
    if(pVentas != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pVentas[i].isEmpty==0)
            {
                printf("\nID de Venta: %d\n",pVentas[i].idVenta);
                pVentas[i].estado = A_COBRAR;
                retorno = 0;
            }
        }

    }
    return retorno;
}
int vent_mostrarVentas(Venta* pVentas,int limite)
{
    int retorno = -1;
    int i;
    if(pVentas != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pVentas[i].isEmpty==0)
            {
                printf("\nID de Venta: %d\n",pVentas[i].idVenta);
                printf("Nombre de video: %s\n",pVentas[i].nombreArchivo);
                printf("Cantidad de afiches: %d\n",pVentas[i].cantAfiches);
                printf("Zona: %s\n",pVentas[i].zona);
                printf("ID de cliente: %d\n",pVentas[i].idCliente);
                if(pVentas[i].estado == 1)
                {
                    printf("El estado de la venta es: A COBRAR\n");
                }
                else
                {
                    printf("El estado de la venta es: COBRADO\n");
                }
                retorno = 0;
            }
        }

    }
    return retorno;
}

int vent_modificarVenta(Venta* pVentas, int indice, int limite)
{
    int retorno = -1;
    int auxAfiche;
    char auxZona[128];
    if(pVentas[indice].estado == 1)
    {
        if(utn_getEntero(&auxAfiche,5,"Modificar cantidad de afiches: \n", "\nError\n",364,-1) == 0)
        {
            printf("Zona nueva: \n");
            if(utn_getString(auxZona,128) == 0)
            {
                pVentas[indice].cantAfiches = auxAfiche;
                strncpy(pVentas[indice].zona,auxZona,128);
                retorno = 0;
            }
        }
    }

    return retorno;
}

int vent_buscarVentaPorID(Venta* pVentas, int limite, int id)
{
    int i;
    int retorno = -1;
    for(i = 0; i < limite; i++)
    {
        if(pVentas[i].isEmpty == 0 && pVentas[i].idVenta == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int vent_modificarEstado(Venta* pVentas, int indice, int limite)
{
    int est;
    if(pVentas[indice].estado == A_COBRAR)
    {
        if(utn_getEntero(&est,2,"\nQuiere cambiar el estado? Si = 1/No = 0\n","\nError\n",2,-1) == 0)
        {
            if(est == 1)
            {
                pVentas[indice].estado = COBRADA;
                printf("\nEl estado de la venta fue cambiado.\n");
            }
        }
    }
    else
    {
        printf("\nSolo puede cambiar las ventas con el estado 'A COBRAR'.\n");
    }

    return 0;
}

int vent_cantidadDeVentasDeClientes(Venta* pVentas,int limite,int id)
{
    int retorno = 0;
    int i;
    for(i = 0; i < limite; i++)
    {
        if(pVentas[i].isEmpty == 0 && pVentas[i].idCliente == id && pVentas[i].estado == 1)
        {
            retorno++;
        }
    }
    return retorno;
}
