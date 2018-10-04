#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"


int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;

    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}

int informar_orderArrayByDescription(Pantalla* pantallaArray,int limite)
{
    Pantalla pantallaAux;
    int retorno =-1;
    int flagSwap;
    int i;
    //int j;
    /*
    if(pantallaArray != NULL && limite > 0)
    {
            for(i=0; i < limite - 1; i++)
            {
                if(pantallaArray[i].isEmpty != 0)
                {
                    continue;
                }
                for(j=i+1; j < limite; j++)
                {
                    if(pantallaArray[j].isEmpty != 0)
                    {
                        continue;
                    }
                    if(pantallaArray[i].precio < pantallaArray[j].precio)

                    {
                        pantallaAux = pantallaArray[j];
                        pantallaArray[j] = pantallaArray[i];
                        pantallaArray[i] = pantallaAux;
                    }
                    else if(pantallaArray[i].precio == pantallaArray[j].precio)
                    {
                        if(strcmp(pantallaArray[i].nombre,pantallaArray[j].nombre) > 0)
                        {
                            pantallaAux = pantallaArray[j];
                            pantallaArray[j] = pantallaArray[i];
                            pantallaArray[i] = pantallaAux;
                        }
                    }
                    retorno = 0;
                }
            }
    }
    */
    if(pantallaArray != NULL && limite > 0)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i < limite -1; i++)
            {
                if(pantallaArray[i].precio < pantallaArray[i+1].precio ||
                (pantallaArray[i].precio == pantallaArray[i+1].precio &&
                strcmp(pantallaArray[i].nombre,pantallaArray[i+1].nombre) < 0))
                {
                    flagSwap = 1;
                    pantallaAux = pantallaArray[i];
                    pantallaArray[i] = pantallaArray[i+1];
                    pantallaArray[i+1] = pantallaAux;
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

int pantalla_mostrar2(Pantalla* pantallaArray,int limite)
{
    int retorno = -1;
    if(limite > 0 && pantallaArray != NULL)
    {
        informar_orderArrayByDescription(pantallaArray, limite);
        pantalla_mostrarDebug(pantallaArray, limite);
    }
    return retorno;
}

int informar_pantallasValorMenor(Pantalla* pantallaArray, int limite)
{
    int retorno =-1;
    int i;
    int flag = 0;
    if(pantallaArray != NULL && limite > 0)
    {
        for(i=0; i < limite - 1; i++)
        {
            if(pantallaArray->isEmpty !=0)
            {
                continue;
            }
            if(pantallaArray[i].precio <= 10)
            {
                flag = 1;
                pantalla_mostrarValordePantallaMenor(pantallaArray, limite, i);
                retorno = 0;
            }
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay pantalla con valor menor a 10\n");
    }
    return retorno;
}
int pantalla_mostrarValordePantallaMenor(Pantalla* pantallaArray,int limite, int indice)
{
    int retorno = -1;
    if(limite > 0 && pantallaArray != NULL && indice >= 0 && indice <= limite)
    {
        retorno = 0;
            if(!pantallaArray[indice].isEmpty)
                printf("[RELEASE] - %d - %s - %d - %.2f\n",pantallaArray[indice].idPantalla, pantallaArray[indice].nombre, pantallaArray[indice].isEmpty, pantallaArray[indice].precio);
    }
    return retorno;
}
