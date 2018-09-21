#include <stdio_ext.h>
#include <stdlib.h>
#include "pantallas.h"
#include "utn.h"
#define CANT_PANTALLAS 5
int main()
{
    Pantalla pant[CANT_PANTALLAS];
    int op;
    int id;
    int i;
    int indiceVacio;
    int salir=0;
    cargarDatosVacio(pant,CANT_PANTALLAS);

    do
    {
    utn_getEntero(&op,3,"\n1-Cargar un pantalla\n2-Imprimir lista de la pantalla\n3-Modificar un ID\n4-Salir\n","Error\n",4,0);
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
                        printf("No hay indice");
                    }
                    break;
                case 2:
                    for(i=0;i<CANT_PANTALLAS;i++)
                    {
                        if(pant[i].isEmpty==0)
                        {
                            mostrarIndice(pant,i);

                        }
                    }
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
                            printf("Error, indice invalido");
                        }
                    }
                    break;
                case 4:
                salir = 1;
        }
    }while(salir==0);

    return 0;
}
