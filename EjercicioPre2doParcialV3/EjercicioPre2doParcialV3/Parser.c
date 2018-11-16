#include "Compra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
int parser_parseCompras(FILE* pFile, LinkedList* listaEmpleados)
{
    int retorno = -1;
    Compra* pAux;
    char str[1024];
    char delim[2] = ",";
    char delim2[2] = "/n";
    char* tokenId;
    char* tokenNombre;
    char* tokenUnidades;
    char* tokenUnitario;
    char* tokenHoras;
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
            tokenNombre = strtok(str,delim);
            tokenId = strtok(NULL, delim);
            tokenUnitario = strtok(NULL, delim);
            tokenUnidades = strtok(NULL, delim);
            tokenHoras = strtok(NULL, delim2);
            pAux = employee_newParametros(tokenId, tokenNombre, tokenUnidades,tokenUnitario, tokenHoras);
            if(pAux != NULL)
            {
                ll_add(listaEmpleados, pAux);
                retorno = 0;
            }
        }
    }
    return retorno;
}

