#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"
#include "utn.h"
#include <string.h>

static int isValidNombre(char* name);
static int isValidHorasTrabajadas(char* horasTrabajadas);
static int isValidSueldo(char* sueldo);
static int isValidId(char* id);

/**
    employee_new: Crea un nuevo espacio en memoria con una variable de tipo Employee.
    @return Direccion de memoria creada.
*/

Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

/**
    employee_newParametros: Crea un nuevo espacio en memoria y setea datos en una variable tipo Employee.
    @param idStr: Es la cadena de caracteres con el id a guardar.
    @param nombreStr: Es la cadena de caracteres con el nombre a guardar.
    @param horasTrabajadasStr: Es la cadena de caracteres con las horas trabajadas a guardar.
    @param sueldoStr: Es la cadena de caracteres con el sueldo a guardar.
    @return Direccion de memoria creada.
*/

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* this = NULL;
    this = employee_new();
    if(this == NULL ||
        employee_setId(this, idStr) ||
        employee_setNombre(this, nombreStr) ||
        employee_setHorasTrabajadas(this, horasTrabajadasStr))
    {
        employee_delete(this);
        this = NULL;
    }
    return this;
}

/**
    employee_delete: Borra un espacio en memoria.
    @param this: Es el espacio en memoria a borrar.
    @return 0 OK, -1 Error.
*/

int employee_delete(Employee* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}


int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && isValidNombre(nombre) == 0)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

/**
    employee_getNombre: Recibe una variable tipo Employee donde se buscara un nombre y se devolvera ese nombre.
    @param this: Es el espacio en memoria de una variable tipo Employee donde se buscara.
    @param nombre: Es una cadena de caracteres donde se guardara el nombre a buscar.
    @return 0 OK, -1 Error.
*/

int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}

/**
    employee_isValidNombre: Recibe una cadena de caracteres de un nombre para validar que solo sean letras, espacios o guiones.
    @param nombre: Es una cadena de caracteres a validar.
    @return 0 OK, -1 Error.
*/

static int isValidNombre(char* nombre)
{
    int retorno = -1;
    if(isLetra(nombre) == 0)
    {
        retorno = 0;
    }
    return retorno;
}

/**
    employee_setHorasTrabajadas: Recibe una cantidad de horas trabajadas para guardarla.
    @param this: Es el espacio en memoria de una variable tipo Employee donde se buscara.
    @param horasTrabajadas: Es la cadena de caracteres con las horas trabajadas.
    @return 0 OK, -1 Error.
*/

int employee_setHorasTrabajadas(Employee* this, char* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && isValidHorasTrabajadas(horasTrabajadas) == 0)
    {
        this->horasTrabajadas = atoi(horasTrabajadas);
        retorno = 0;
    }
    return retorno;
}

/**
    employee_getHorasTrabajadas: Recibe un dato tipo Employee donde se buscara la cantidad de horas trabajadas y se devolvera esa cantidad.
    @param this: Es el espacio en memoria de una variable tipo Employee donde se buscara.
    @param horasTrabajadas: Es el puntero a un int donde se guardara las horas a buscar.
    @return 0 OK, -1 Error.
*/

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

/**
    employee_isValidHorasTrabajadas: Recibe una cadena de caracteres de horas trabajadas para validar que solo sean numeros.
    @param horasTrabajadas: Es la cadena de caracteres a validar.
    @return 0 OK, -1 Error.
*/

static int isValidHorasTrabajadas(char* horasTrabajadas)
{
    int retorno = -1;
    if(isInt(horasTrabajadas) == -1)
    {
        printf("\nLas horas trabajadas no son validas\n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/**
    employee_setSueldo: Recibe un sueldo para guardarlo.
    @param this: Es el espacio en memoria de una variable tipo Employee donde se buscara.
    @param sueldo: Es la cadena de caracteres con el sueldo.
    @return 0 OK, -1 Error.
*/

int employee_setSueldo(Employee* this, char* sueldo)
{
    int retorno = -1;
    if(this != NULL && isValidSueldo(sueldo) == 0)
    {
        this->sueldo = atoi(sueldo);
        retorno = 0;
    }
    return retorno;
}

/**
    employee_getSueldo: Recibe un dato tipo Employee donde se buscara un sueldo y se devolvera ese sueldo.
    @param this: Es el espacio en memoria de una variable tipo Employee donde se buscara.
    @param sueldo: Es el puntero a un int donde se guardara el sueldo a buscar.
    @return 0 OK, -1 Error.
*/

int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

/**
    employee_isValidSueldo: Recibe una cadena de caracteres de sueldo para validar que solo sean numeros.
    @param sueldo: Es la cadena de caracteres a validar.
    @return 0 OK, -1 Error.
*/

static int isValidSueldo(char* sueldo)
{
    int retorno = -1;
    if(isInt(sueldo) == -1)
    {
        printf("\nEl sueldo no es valido\n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/**
    employee_setId: Recibe un id para guardarlo.
    @param this: Es el espacio en memoria de una variable tipo Employee donde se buscara.
    @param id: Es la cadena de caracteres con el id del Employee.
    @return 0 OK, -1 Error.
*/

int employee_setId(Employee* this, char* id)
{
    int retorno = -1;
    static int proximoId = -1;
    int auxID;
    if(this != NULL && isValidId(id) == 0)
    {
        auxID = atoi(id);
        if(auxID == -1)
        {
            proximoId++;
            this->id = proximoId;
            retorno = 0;
        }else if(auxID > proximoId)
        {
            proximoId = auxID;
            this->id = proximoId;
            retorno = 0;
        }

    }
    return retorno;
}

/**
    employee_getId: Recibe un dato tipo Employee donde se buscara un id y se devolvera ese id.
    @param this: Es el espacio en memoria de una variable tipo Employee donde se buscara.
    @param id: Es el puntero a un int donde se guardara el id buscado.
    @return 0 OK, -1 Error.
*/

int employee_getId(Employee* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

/**
    employee_isValidId: Recibe una cadena de caracteres de un id para validar que solo sean numeros.
    @param id: Es la cadena de caracteres a validar.
    @return 0 OK, -1 Error.
*/

static int isValidId(char* id)
{
    int retorno = -1;
    if(isIntConGuiones(id) == -1)
    {
        printf("\nError, id invalido.\n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

void employee_mostrar(LinkedList* pArrayListEmployee)
{
    int i;
    int auxId;
    char auxNombre[1024];
    int auxHorasTrabajadas;
    int size;
    size = ll_len(pArrayListEmployee);
    Employee* auxEmployee;
    if(size > 0)
    {
        for(i=0; i < size; i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            if( employee_getId(auxEmployee, &auxId) == 0 &&
                employee_getNombre(auxEmployee, auxNombre) == 0 &&
                employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas) == 0)
            {
                printf("ID: %d - Nombre: %s - Horas Trabajadas: %d \n", auxId, auxNombre, auxHorasTrabajadas);
            }
            else
            {
                printf("\nError, no se pudo mostrar la lista.\n");
            }
        }
         printf("\nLa candidad de empleados es: %d.", size);
         printf("\nFin de la lista.\n");
    }
    else
    {
        printf("\nError, no hay lista cargada.\n");
    }
}

int em_calcularSueldo(void* pEmployee)
{
    int retorno = -1;
    if(((Employee*)pEmployee)->horasTrabajadas <= 120)
    {
        ((Employee*)pEmployee)->sueldo = 180;
        retorno = 0;
    }
    if(((Employee*)pEmployee)->horasTrabajadas > 120 && ((Employee*)pEmployee)->horasTrabajadas <= 160)
    {
        ((Employee*)pEmployee)->sueldo = 240;
        retorno = 0;
    }
    if(((Employee*)pEmployee)->horasTrabajadas > 160 && ((Employee*)pEmployee)->horasTrabajadas <= 240)
    {
        ((Employee*)pEmployee)->sueldo = 350;
        retorno = 0;
    }
    return retorno;
}
