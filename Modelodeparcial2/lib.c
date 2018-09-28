#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "utn.h"
static int generarID(void);

int altaForzada(Asociado* asociados, int limite,char* nombre,int edad, char* apellido, float precio)
{
    int retorno = -1;
    int indiceVacio;
    indicesVacios(asociados,limite, &indiceVacio);
    if(asociados != NULL && limite >0)
    {
          if(indiceVacio >= 0)
          {
            strncpy(asociados[indiceVacio].nombre,nombre,32);
            asociados[indiceVacio].edad=edad;
            strncpy(asociados[indiceVacio].apellido,apellido,32);
            asociados[indiceVacio].ID=generarID();
            asociados[indiceVacio].isEmpty=0;
            retorno =0;
          }
    }
    return retorno;
}
int cargarDatosVacio(Asociado* asociados, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        asociados[i].isEmpty=-1;
    }
    return 0;
}
int cargarIndice(Asociado* asociados,int indice,int limite)
{
    char auxNombre[32];
    char auxApellido[32];
    char auxDNI[32];
    int auxEdad;
    printf("Nombre:\n");
    if(utn_getString(auxNombre,32)==0)
    {

                printf("Apellido: \n");
                if(utn_getString(auxApellido,128)==0)
                {
                    if(utn_getEntero(&auxEdad,2,"Edad: \n", "\nError\n",200,0) == 0)
                    {
                        printf("DNI: \n");
                        if(utn_getString(auxDNI,128)==0)
                        {

                                strncpy(asociados[indice].nombre,auxNombre,32);
                                strncpy(asociados[indice].apellido,auxApellido,128);
                                strncpy(asociados[indice].DNI,auxDNI,128);
                                asociados[indice].edad = auxEdad;
                                asociados[indice].isEmpty = 0;
                                asociados[indice].ID = generarID();
                        }
                    }
                }

    }
    return 0;
}
int indicesVacios(Asociado* asociados,int limite,int* indiceVacio)
{
    int i=0;
    int retorno = -1;
    while(i<limite)
    {
        if(asociados[i].isEmpty==-1)
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
int buscarPantallaPorID(Asociado* asociados, int limite, int id)
{
    int i;
    int retorno = -1;
    for(i = 0; i < limite; i++)
    {
        if(asociados[i].isEmpty == 0 && asociados[i].ID == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int modificarID(Asociado* asociados, int indice, int limite)
{
    char auxNombre[32];
    char auxApellido[32];
    int id;
    id = buscarPantallaPorID(asociados,limite,indice);
    if(id >= 0)
    {
        if(asociados != NULL && limite >0)
        {
            printf("Nuevo nombre:\n");
            if(utn_getString(auxNombre,32)==0)
            {

                        printf("Nuevo apellido: \n");
                        if(utn_getString(auxApellido,128)==0)
                        {

                                        strncpy(asociados[indice].nombre,auxNombre,32);
                                        strncpy(asociados[indice].apellido,auxApellido,128);
                        }

            }
        }
    }
    return 0;
}
int borrarPantallaPorID(Asociado* asociados, int id, int limite)
{
    int retorno = -1;
    int i;
    for(i = 0; i < limite; i++)
    {
        if(asociados[i].isEmpty == 0 && asociados[i].ID == id)
        {
            asociados[i].isEmpty = -1;
            retorno = 0;
            break;
        }
    }
    return retorno;
}
