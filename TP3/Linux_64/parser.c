#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* pAux;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    int flagOnce = 1;
    while(!feof(pFile))
    {
        if(flagOnce)
        {
            fscanf(pFile,"%s\n", bufferId);
            flagOnce = 0;
        }
        else if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo)==4)
        {
            pAux = employee_newParametros(bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
            if(pAux != NULL)
            {
                ll_add(pArrayListEmployee, pAux);
            }
        }
        else
        {
            break;
        }
    }
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* pAux;
    int retorno = -1;
    int cant;
    do
    {
        pAux = employee_new();
        cant = fread(pAux, sizeof(Employee), 1, pFile);
        if(pAux != NULL && cant == 1)
        {
            ll_add(pArrayListEmployee, pAux);
            retorno = 0;
        }
    }while(!feof(pFile));
    return retorno;
}
