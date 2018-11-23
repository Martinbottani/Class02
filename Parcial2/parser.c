#include "venta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
int parser_parseVenta(FILE* pFile, LinkedList* listaVenta)
{
    int retorno = -1;
    Venta* pAux;
    char str[1024];
    char delim[2] = ",";
    char delim2[2] = "/n";
    char* tokenId;
    char* tokenFecha;
    char* tokenCantidad;
    char* tokenUnitario;
    char* tokenCodigo;
    char* tokenCuit;
    int valueF;
    if(pFile != NULL)
    {
        fscanf(pFile, "%[^\n]\n", str);
        while(!feof(pFile))
        {
            valueF = fscanf(pFile,"%[^\n]\n", str);
            if(valueF != 1)
            {
                break;
            }
            tokenId = strtok(str, delim);
            tokenFecha = strtok(NULL,delim);
            tokenCodigo = strtok(NULL, delim);
            tokenCantidad = strtok(NULL, delim);
            tokenUnitario = strtok(NULL, delim);
            tokenCuit = strtok(NULL, delim2);
            pAux = new_ventaParametros(tokenId, tokenFecha, tokenCodigo, tokenCantidad, tokenCuit, tokenUnitario);
            if(pAux != NULL)
            {
                ll_add(listaVenta, pAux);
                retorno = 0;
            }
        }
    }
    return retorno;
}
