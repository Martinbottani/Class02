#include "Pantalla.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utn.h"

static int generarId(void);



int pan_init(Pantalla* pantallas, int len)
{
    int ret=-1;
    int i;
    if(pantallas!=NULL && len>0)
    {
        for(i=0; i<len; i++)
            pantallas[i].isEmpty=1;
        ret = 0;
    }
    return ret;
}

int pan_buscarLugarLibre(Pantalla* pantallas,
                                     int len)
{
    int ret=-1;
    int i;
    if(pantallas!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(pantallas[i].isEmpty==1)
            {
                ret=i;
                break;
            }
        }
    }
    return ret;
}

static int generarId(void)
{
    static int id=-1;
    id++;
    return id;
}


int pan_alta(Pantalla* pantallas, int len,
                                 int index)
{

    char nombreAux[32];
    int tipoAux=TIPO_LCD;
    int ret=-1;

    if(utn_getLetras(nombreAux,32,1,"ingrese nombre:","no!")==0)
    {
        // poner lo que falta

        // copio los campos
        pantallas[index].tipo = tipoAux;
        strncpy(pantallas[index].nombre,nombreAux,32);
        pantallas[index].isEmpty=0;
        pantallas[index].id = generarId();

        ret=0;
    }
    return ret;
}



int pan_buscarPantallaPorId(Pantalla* pantallas,
                                   int len, int id)
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(pantallas[i].isEmpty==0)
        {
            // evaluo el ID
            if(pantallas[i].id==id)
            {
                // lo encontre!! ja!
                ret = i;
                break;
            }
        }
    }
    return ret;
}




int pan_modificar(Pantalla* pantallas, int len,
                                 int index)
{

    char nombreAux[32];
    int tipoAux=TIPO_LCD;
    int ret=-1;

    if(utn_getLetras(nombreAux,32,1,"ingrese nombre:","no!")==0)
    {
        // poner lo que falta

        // copio los campos
        pantallas[index].tipo = tipoAux;
        strncpy(pantallas[index].nombre,nombreAux,32);
        //pantallas[index].isEmpty=0; // NO!
        //pantallas[index].id = generarId(); // NO!!

        ret=0;
    }
    return ret;
}









