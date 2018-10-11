#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "ventas.h"
#include "utn.h"

static int generarID(void);

int client_altaForzada(Cliente* pClientes, int limite,char* nombre, char* apellido, char* cuit)
{
    int retorno = -1;
    int indiceVacio;
    client_indicesVacios(pClientes, limite, &indiceVacio);
    if(pClientes != NULL && limite > 0)
    {
          if(indiceVacio >= 0)
          {
            strncpy(pClientes[indiceVacio].nombre,nombre,51);
            strncpy(pClientes[indiceVacio].cuitCliente,cuit,128);
            strncpy(pClientes[indiceVacio].apellido,apellido,51);
            pClientes[indiceVacio].ID=generarID();
            pClientes[indiceVacio].isEmpty=0;
            retorno =0;
          }
    }
    return retorno;
}

int client_cargarDatosVacio(Cliente* pClientes, int limite)
{
    int retorno = -1;
    int i;
    if(pClientes != NULL && limite > 0)
    {
        for(i = 0; i < limite; i++)
        {
            pClientes[i].isEmpty = -1;
        }
        retorno=0;
    }
    return retorno;
}

int client_cargarIndice(Cliente* pClientes,int indice,int limite)
{
    int retorno = -1;
    char auxNombre[51];
    char auxApellido[51];
    char auxCUIT[128];
    printf("Nombre:\n");
    if(utn_getString(auxNombre,51)==0)
    {
        printf("Apellido: \n");
        if(utn_getString(auxApellido,51)==0)
        {
            printf("Cuit: \n");
            if(utn_getString(auxCUIT,128)==0)
            {
                strncpy(pClientes[indice].nombre,auxNombre,51);
                strncpy(pClientes[indice].apellido,auxApellido,51);
                strncpy(pClientes[indice].cuitCliente,auxCUIT,128);
                pClientes[indice].isEmpty = 0;
                pClientes[indice].ID = generarID();
                retorno = 0;
            }
        }

    }
    return retorno;
}

int client_indicesVacios(Cliente* pClientes,int limite,int* indiceVacio)
{
    int i=0;
    int retorno = -1;
    if(pClientes != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(pClientes[i].isEmpty == -1)
            {
                *indiceVacio = i;
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

int client_chequearIndice(Cliente* pClientes,int limite)
{
    int i=0;
    int retorno = 0;
    if(pClientes != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(pClientes[i].isEmpty==0)
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }

    return retorno;
}

static int generarID(void)
{
    static int cont = -1;
    return ++cont;
}

int client_mostrarIndice(Cliente* pClientes,int limite)
{
    int retorno = -1;
    int i;
    if(pClientes != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pClientes[i].isEmpty==0)
            {
                printf("nombre: %s",pClientes[i].nombre);
                printf("\napellido: %s",pClientes[i].apellido);
                printf("\ncuit: %s",pClientes[i].cuitCliente);
                printf("\nID: %d\n",pClientes[i].ID);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int client_mostrarUnIndice(Cliente* pClientes,int limite,int indice)
{
    int retorno=-1;
    if(pClientes != NULL && limite > 0 && indice >= 0)
    {
        if(pClientes[indice].isEmpty == 0)
        {
            printf("Nombre de Cliente: %s",pClientes[indice].nombre);
            printf("\nApellido de Cliente: %s",pClientes[indice].apellido);
            printf("\nCuit de Cliente: %s",pClientes[indice].cuitCliente);
            printf("\nID de Cliente: %d\n",pClientes[indice].ID);
            retorno = 0;
        }

    }

    return retorno;
}

int client_buscarClientePorID(Cliente* pClientes, int limite, int id)
{
    int i;
    int retorno = -1;
    for(i = 0; i < limite; i++)
    {
        if(pClientes[i].isEmpty == 0 && pClientes[i].ID == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


int client_mostrarIndiceConVentas(Cliente* pClientes, int limite, Venta* pVentas, int limite2)
{
    int retorno = -1;
    int i;
    int cantVentas;
    if(pClientes != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pClientes[i].isEmpty==0)
            {
                cantVentas = inf_cantidadDeVentasDeClientes(pVentas, limite2, pClientes[i].ID);
                printf("\nID del cliente es: %d", pClientes[i].ID);
                printf("\nNombre del cliente es: %s", pClientes[i].nombre);
                printf("\nApellido del cliente es: %s", pClientes[i].apellido);
                printf("\nCUIT del cliente es: %s", pClientes[i].cuitCliente);
                printf("\nCantidad de ventas a cobrar que posee es: %d\n",cantVentas);
                retorno = 0;
            }
        }
    }
    return retorno;
}

int client_modificarID(Cliente* pCliente, int indice, int limite)
{
    int retorno = -1;
    char auxNombre[51];
    char auxApellido[51];
    char auxCUIT[128];
    int id;
    id = client_buscarClientePorID(pCliente,limite,indice);
    printf("Nuevo nombre:\n");
    if(utn_getString(auxNombre,51)==0)
    {
        printf("Nuevo apellido: \n");
        if(utn_getString(auxApellido,51)==0)
        {
            printf("Nuevo cuit: \n");
            if(utn_getString(auxCUIT,128)==0)
            {
                strncpy(pCliente[id].nombre,auxNombre,51);
                strncpy(pCliente[id].apellido,auxApellido,51);
                strncpy(pCliente[id].cuitCliente,auxCUIT,128);
                retorno = 0;
            }
        }
    }
    return retorno;
}

int client_borrarClientePorID(Cliente* pClientes, int id, int limite)
{
    int retorno = -1;
    int i;
    for(i = 0; i < limite; i++)
    {
        if(pClientes[i].isEmpty == 0 && pClientes[i].ID == id)
        {
            pClientes[i].isEmpty = -1;
            retorno = 0;
            break;
        }
    }
    return retorno;
}
