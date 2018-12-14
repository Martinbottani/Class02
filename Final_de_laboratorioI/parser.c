#include "envio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
int parser_parseFile(FILE* pFile, LinkedList* lista)
{
    int retorno = -1;
    Envio* pAux;
    char str[1024];
    char delim[2] = ",";
    char delim2[2] = "/n";
    char* tokenId;
    char* tokenNombre;
    char* tokenZona;
    char* tokenKm;
    char* tokenIdCamion;
    char* tokenEntrega;
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
            tokenNombre = strtok(NULL,delim);
            tokenIdCamion = strtok(NULL, delim);
            tokenZona = strtok(NULL, delim);
            tokenKm = strtok(NULL, delim);
            tokenEntrega = strtok(NULL, delim2);
            pAux = new_envParametros(tokenId, tokenNombre, tokenIdCamion, tokenZona, tokenKm, tokenEntrega);
            if(pAux != NULL)
            {
                ll_add(lista, pAux);
                retorno = 0;
            }
        }
    }
    return retorno;
}
