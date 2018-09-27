#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "contratacion.h"
#include "pantallas.h"
#include "utn.h"
static int generarID(void);
int cliente_cargarDatosVacio(Contratacion* cliente, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        cliente[i].isEmpty=-1;
    }
    return 0;
}
int cliente_cargarIndice(Contratacion* cliente,int indice,int limite, int idPantalla)
{
    char auxNombre[32];
    char auxCUIT[128];
    int auxDias;
    printf("Nombre del Video:\n");
    if(utn_getString(auxNombre,32)==0)
    {
        if(utn_getEntero(&auxDias,2,"Cuantos dias de contratacion?: \n", "\nError\n",364,0) == 0)
        {
                printf("CUIT del Cliente: ");
                if(utn_getString(auxCUIT,128)==0)
                {
                    strncpy(cliente[indice].nombreVideo,auxNombre,32);
                    strncpy(cliente[indice].cuitCliente,auxCUIT,128);
                    cliente[indice].dias = auxDias;
                    cliente[indice].isEmpty = 0;
                    cliente[indice].ID = generarID();
                    cliente[indice].idPantalla = idPantalla;

                }
        }
    }

    return 0;
}
int prod_getEmptyIndexCliente(Contratacion* cliente,int limite,int* indiceVacio)
{
    int i=0;
    int retorno = -1;
    while(i<limite)
    {
        if(cliente[i].isEmpty==-1)
        {
            *indiceVacio=i;
            retorno = 0;
            break;
        }
        i++;
    }
    return retorno;
}
int mostrarContrataciones(Contratacion* cliente,int limite, Pantalla* pantalla, char* cuitCliente)
{
    int i;
    int indicePantalla;
    if(cliente != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
                if(cliente[i].isEmpty==0 && strcmp(cliente[i].cuitCliente, cuitCliente) == 0)
                {
                    indicePantalla = buscarPantallaPorID(pantalla,limite, cliente[i].idPantalla);
                    printf("nombre: %s",pantalla[indicePantalla].nombre);
                    printf("\ndireccion: %s",pantalla[indicePantalla].direccion);
                    printf("\ntipo: %d",pantalla[indicePantalla].tipo);
                    printf("\nprecio: %.2f",pantalla[indicePantalla].precio);
                    printf("\nID: %d\n",pantalla[indicePantalla].ID);
                    printf("\nDias de contratacion: %d\n",cliente[i].dias);
                    //printf("\nID de la pantalla contratada es: %d\n",cliente[i].idPantalla);
                }
        }

    }
    return 0;
}
int buscarContratacionPorCUIT(Contratacion* cliente, int limite, char* cuitCliente,int id)
{
    int i;
    int retorno = -1;
    for(i = 0; i < limite; i++)
    {
        if(cliente[i].isEmpty == 0 && strcmp(cliente[i].cuitCliente, cuitCliente) == 0
        && cliente[i].idPantalla == id)
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int modificarContratacion(Contratacion* cliente, int indice, int limite)
{
    int auxDia;
    if(utn_getEntero(&auxDia,2,"Modificar dias de contratacion: \n", "\nError\n",364,-1) == 0)
    {
        cliente[indice].dias = auxDia;
    }
    return 0;
}
static int generarID(void)
{
    static int cont = -1;
    return ++cont;
}
int borrarContratacionPorID(Contratacion* cliente, int id, int limite, char* cuitCliente)
{
    int retorno = -1;
    int i;
    for(i = 0; i < limite; i++)
    {
        if(cliente[i].isEmpty == 0 && cliente[i].idPantalla == id && strcmp(cliente[i].cuitCliente, cuitCliente) == 0)
        {
            cliente[i].isEmpty = -1;
            retorno = 0;
            printf("\nLa contratacion fue cancelada\n");
            break;
        }
    }
    return retorno;
}
int mostrarImporteDeContrataciones(Contratacion* cliente,int limite, Pantalla* pantalla, char* cuitCliente)
{
    int i;
    int indicePantalla;
    float total;
    if(cliente != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
                if(cliente[i].isEmpty==0 && strcmp(cliente[i].cuitCliente, cuitCliente) == 0)
                {
                    indicePantalla = buscarPantallaPorID(pantalla,limite, cliente[i].idPantalla);
                    total = pantalla[indicePantalla].precio * cliente[i].dias;
                    printf("\nprecio de la facturacion %d es: %.2f\n",i+1,total);
                }
        }

    }
    return 0;
}
int mostrarContratacionesTotales(Contratacion* cliente,int limite, Pantalla* pantalla)
{
    int i;
    int indicePantalla;
    if(cliente != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
                if(cliente[i].isEmpty==0)
                {
                    indicePantalla = buscarPantallaPorID(pantalla,limite, cliente[i].idPantalla);
                    printf("\nnombre de pantalla: %s\n",pantalla[indicePantalla].nombre);
                    printf("nombre del video: %s\n", cliente[i].nombreVideo);
                    printf("cantidad de dias contratados: %d\n", cliente[i].dias);
                    printf("CUIT del Cliente: %s\n", cliente[i].cuitCliente);
                    //printf("\nID de la pantalla contratada es: %d\n",cliente[i].idPantalla);

                }
        }

    }
    return 0;
}
