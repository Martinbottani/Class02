#include <stdio.h>
#include <stdlib.h>
#include "Pantalla.h"
#include "utn.h"

#define PANTALLAS_LEN    100

int main()
{
    int opcion;
    int index;
    int id;
    Pantalla pantallas[PANTALLAS_LEN];

    pan_init(pantallas,PANTALLAS_LEN);

    do
    {
        utn_getEntero(&opcion,1,"1)alta\n2)modif\n3)listar","no!",1,99);

        switch(opcion)
        {
            case 1:  // alta
            {
                index = pan_buscarLugarLibre(pantallas,PANTALLAS_LEN);
                if(index>=0)
                {
                    if(pan_alta(pantallas,PANTALLAS_LEN,index)!=0)
                        printf("ingresaste cualquiera\n");
                    else
                        printf("Alta exitosa\n");
                }
                else
                {
                    printf("no hay ma' lugar che\n");
                }
                break;
            }
            case 2:
            {
                if(utn_getEntero(&id,1,"ingrese id:","no!",0,9999)==0)
                {
                    index = pan_buscarPantallaPorId(pantallas,PANTALLAS_LEN,id);
                    if(index>=0)
                        pan_modificar(pantallas,PANTALLAS_LEN,index);
                    else
                        printf("id no esssiste\n");
                }
                else
                    printf("eso no eh un id\n");
                break;
            }
        }
    }while(opcion!=4);

    return 0;
}
