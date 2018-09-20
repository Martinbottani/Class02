#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#include <string.h>
#define CANT_PRODUCTOS 5
int main()
{
    int indiceVacio;
    Producto productos[CANT_PRODUCTOS];
    utn_cargarDatoVacio(productos, CANT_PRODUCTOS);
    utn_menu(productos, CANT_PRODUCTOS);
    printf("El indice que esta vacio es: %d",indiceVacio);

    return 0;
}
int utn_cargarDatoVacio(Producto* p, int limite)
{
    int retorno = -1;
    int i;
    for(i = 0; i < limite; i++)
    {
        p[i].isEmpty = -1;
        retorno = 0;
    }
    return retorno;
}
int utn_cargarDatoArray(Producto* p, int index, int limite)
{
    int retorno = -1;
    char nombreAux[32];
    char descripcionAux[128];
    float precioAux;
    printf("Ingrese el nombre: \n");
    if(getString(nombreAux,32) == 0)
    {
        printf("Ingrese la descripcion: \n");
        if(getString(descripcionAux,128) == 0)
        {
            if(utn_getNumeroDecimal(&precioAux, 2, "Dame el precio: \n", "Error \n", 500, 0) == 0)
            {
                strcpy(p[index].nombre,nombreAux);
                strcpy(p[index].descripcion,descripcionAux);
                p[index].precio = precioAux;
                p[index].isEmpty = 0;
                //p[index].ID = generarID;
                retorno = 0;
            }
        }
    }
    return retorno;
}
int utn_imprimirDatoArray(Producto* productos, int index)
{
    int retorno = -1;
    if(productos[index].isEmpty == 0)
    {
        printf("Su nombre es: %s\n",productos[index].nombre);
        printf("Su descripcion es: %s\n",productos[index].descripcion);
        printf("Su precio es: %.2f\n", productos[index].precio);
        retorno = 0;
    }
    return retorno;
}
int utn_imprimirDatoVacio(Producto* productos,int* indiceVacio, int limite)
{
    int i = 0;
    while(i < limite)
    {
        if(productos[i].isEmpty == -1)
        {
            *indiceVacio = i;
            break;
        }
        i++;
    }
    return 0;
}
int utn_menu(Producto* productos, int limite)
{
    int indiceVacio;
    int i;
    int opcion;
    do
    {
        switch(opcion)
        {
            case 1:
                    for(i = 0; i < limite; i++)
                    {
                        if(utn_imprimirDatoVacio(productos, &indiceVacio, CANT_PRODUCTOS) == 0)
                        {
                            utn_cargarDatoArray(productos, indiceVacio, CANT_PRODUCTOS);
                            i++;
                            break;
                        }
                        else
                        {
                            printf("No hay indice en el cual escribir");
                        }
                    }

                    break;
            case 2:
                    for(i = 0; i < limite; i++)
                    {

                            utn_imprimirDatoArray(productos,i);

                    }
        }
    }while

    return 0;
}
/*

    int generarID(void)
    {
        static int cont = -1; //es privada de la funcion, además no muere
        return cont++;
    }
*/
