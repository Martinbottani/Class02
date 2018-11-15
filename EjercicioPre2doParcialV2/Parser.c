#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Empleado.h"
int parser_parseEmpleados(FILE* pFile, LinkedList* listaEmpleados)
{
    int retorno = -1;
    Employee* pAux;
    char str[1024];
    char delim[2] = ",";
    char delim2[2] = "/n";
    char* tokenId;
    char* tokenNombre;
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
            tokenId = strtok(str,delim);
            tokenNombre = strtok(NULL, delim);
            tokenHoras = strtok(NULL, delim2);
            pAux = employee_newParametros(tokenId, tokenNombre, tokenHoras);
            if(pAux != NULL)
            {
                ll_add(listaEmpleados, pAux);
                retorno = 0;
            }
        }
    }
    return retorno;

}

