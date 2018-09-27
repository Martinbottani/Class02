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
int mostrarContrataciones(Contratacion* cliente,int limite, Pantalla* pantalla)
{
    int i;
    if(cliente != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
                if(cliente[i].isEmpty==0)
                {
                    mostrarIndice(pantalla, limite);
                    //printf("\nCUIT del Cliente: %s",cliente[i].cuitCliente);
                    printf("\nDias de contratacion: %d",cliente[i].dias);
                    printf("\nID de la pantalla contratada es: %d\n",cliente[i].idPantalla);
                }
        }

    }
    return 0;
}
int buscarContratacionPorCUIT(Contratacion* cliente, int limite, char* cuitCliente)
{
    int i;
    int retorno = -1;
    for(i = 0; i < limite; i++)
    {
        if(cliente[i].isEmpty == 0 && strcmp(cliente[i].cuitCliente, cuitCliente) == 0)
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
