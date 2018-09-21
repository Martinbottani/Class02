#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "pantallas.h"
#include "utn.h"
static int buscarPantallaPorID(Pantalla* pantalla, int limite, int id);
int cargarDatosVacio(Pantalla* pantalla, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        pantalla[i].isEmpty=-1;
    }
    return 0;
}
int cargarIndice(Pantalla* pantalla,int indice,int limite)
{
    char auxNombre[32];
    char auxDireccion[128];
    int auxTipo;
    float auxPrecio;
    printf("Nombre:\n");
    if(utn_getString(auxNombre,32)==0)
    {
        if(utn_getEntero(&auxTipo,2,"Tipo (0 = LED, 1 = LCD): \n", "\nError\n",2,-1) == 0)
        {
            if(utn_getNumeroDecimal(&auxPrecio,2,"Precio: \n","\nError\n",3000,0) == 0)
            {
                printf("Direccion: ");
                if(utn_getString(auxDireccion,128)==0)
                {
                    strncpy(pantalla[indice].nombre,auxNombre,32);
                    strncpy(pantalla[indice].direccion,auxDireccion,128);
                    pantalla[indice].tipo = auxTipo;
                    pantalla[indice].precio = auxPrecio;
                    pantalla[indice].isEmpty = 0;
                    pantalla[indice].ID = generarID();
                }
            }
        }
    }
    return 0;
}
int mostrarIndice(Pantalla* pantalla,int indice)
{
    if(pantalla != NULL && indice > -1)
    {
        if(pantalla[indice].isEmpty==0)
        {
            printf("nombre: %s",pantalla[indice].nombre);
            printf("\ndireccion: %s",pantalla[indice].direccion);
            printf("\ntipo: %d",pantalla[indice].tipo);
            printf("\nprecio: %.2f",pantalla[indice].precio);
            printf("\nID: %d\n",pantalla[indice].ID);
        }
        else
        {
            printf("Esta Vacio");
        }
    }

    return 0;
}
int prod_getEmptyIndex(Pantalla* pantalla,int limite,int* indiceVacio)
{
    int i=0;
    int retorno = -1;
    while(i<limite)
    {
        if(pantalla[i].isEmpty==-1)
        {
            *indiceVacio=i;
            retorno = 0;
            break;
        }
        i++;
    }
    return retorno;
}

int generarID(void)
{
    static int cont = -1;
    return ++cont;
}
static int buscarPantallaPorID(Pantalla* pantalla, int limite, int id)
{
    int i;
    int retorno = -1;
    for(i = 0; i < limite; i++)
    {
        if(pantalla[i].isEmpty == 0 && pantalla[i].ID == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int modificarID(Pantalla* pantalla, int indice, int limite)
{
    char auxNombre[32];
    char auxDireccion[128];
    int auxTipo;
    float auxPrecio;
    printf("Nuevo nombre:\n");
    if(utn_getString(auxNombre,32)==0)
    {
        if(utn_getEntero(&auxTipo,2,"Nuevo tipo (0 = LED, 1 = LCD): \n", "\nError\n",2,-1) == 0)
        {
            if(utn_getNumeroDecimal(&auxPrecio,2,"Nuevo precio: \n","\nError\n",3000,0) == 0)
            {
                printf("Nueva direccion: ");
                if(utn_getString(auxDireccion,128)==0)
                {
                    strncpy(pantalla[indice].nombre,auxNombre,32);
                    strncpy(pantalla[indice].direccion,auxDireccion,128);
                    pantalla[indice].tipo = auxTipo;
                    pantalla[indice].precio = auxPrecio;
                }
            }
        }
    }
    return 0;
}
