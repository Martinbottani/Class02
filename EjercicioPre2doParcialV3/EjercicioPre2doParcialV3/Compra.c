#include "Compra.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
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

Compra* employee_new(void)
{
    return (Compra*) malloc(sizeof(Compra));
}

/**
    employee_newParametros: Crea un nuevo espacio en memoria y setea datos en una variable tipo Compra.
    @param idStr: Es la cadena de caracteres con el id a guardar.
    @param nombreStr: Es la cadena de caracteres con el nombre a guardar.
    @param horasTrabajadasStr: Es la cadena de caracteres con las horas trabajadas a guardar.
    @param sueldoStr: Es la cadena de caracteres con el sueldo a guardar.
    @return Direccion de memoria creada.
*/

Compra* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr, char* ivaStr)
{
    Compra* this = NULL;
    this = employee_new();
    if(this == NULL ||
        employee_setId(this, idStr) ||
        employee_setNombre(this, nombreStr) ||
        employee_setHorasTrabajadas(this, horasTrabajadasStr) ||
        employee_setSueldo(this, sueldoStr) ||
        employee_setIva(this, ivaStr))
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

int employee_delete(Compra* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}


int employee_setNombre(Compra* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && isValidNombre(nombre) == 0)
    {
        strcpy(this->nombreCliente,nombre);
        retorno = 0;
    }
    return retorno;
}

/**
    employee_getNombre: Recibe una variable tipo Compra donde se buscara un nombre y se devolvera ese nombre.
    @param this: Es el espacio en memoria de una variable tipo Compra donde se buscara.
    @param nombre: Es una cadena de caracteres donde se guardara el nombre a buscar.
    @return 0 OK, -1 Error.
*/

int employee_getNombre(Compra* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombreCliente);
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
    @param this: Es el espacio en memoria de una variable tipo Compra donde se buscara.
    @param horasTrabajadas: Es la cadena de caracteres con las horas trabajadas.
    @return 0 OK, -1 Error.
*/

int employee_setHorasTrabajadas(Compra* this, char* unidades)
{
    int retorno = -1;
    if(this != NULL && isValidHorasTrabajadas(unidades) == 0)
    {
        this->unidades = atoi(unidades);
        retorno = 0;
    }
    return retorno;
}

/**
    employee_getHorasTrabajadas: Recibe un dato tipo Compra donde se buscara la cantidad de horas trabajadas y se devolvera esa cantidad.
    @param this: Es el espacio en memoria de una variable tipo Compra donde se buscara.
    @param horasTrabajadas: Es el puntero a un int donde se guardara las horas a buscar.
    @return 0 OK, -1 Error.
*/

int employee_getHorasTrabajadas(Compra* this, int* unidades)
{
    int retorno = -1;
    if(this != NULL && unidades != NULL)
    {
        *unidades = this->unidades;
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
    @param this: Es el espacio en memoria de una variable tipo Compra donde se buscara.
    @param sueldo: Es la cadena de caracteres con el sueldo.
    @return 0 OK, -1 Error.
*/

int employee_setSueldo(Compra* this, char* precioUnitario)
{
    int retorno = -1;
    if(this != NULL && isValidSueldo(precioUnitario) == 0)
    {
        this->precioUnitario = atof(precioUnitario);
        retorno = 0;
    }
    return retorno;
}

/**
    employee_getSueldo: Recibe un dato tipo Compra donde se buscara un sueldo y se devolvera ese sueldo.
    @param this: Es el espacio en memoria de una variable tipo Compra donde se buscara.
    @param sueldo: Es el puntero a un int donde se guardara el sueldo a buscar.
    @return 0 OK, -1 Error.
*/

int employee_getSueldo(Compra* this, float* precioUnitario)
{
    int retorno = -1;
    if(this != NULL && precioUnitario != NULL)
    {
        *precioUnitario = this->precioUnitario;
        retorno = 0;
    }
    return retorno;
}

/**
    employee_isValidSueldo: Recibe una cadena de caracteres de sueldo para validar que solo sean numeros.
    @param sueldo: Es la cadena de caracteres a validar.
    @return 0 OK, -1 Error.
*/

int employee_setIva(Compra* this, char* iva)
{
    int retorno = -1;
    if(this != NULL && isValidSueldo(iva) == 0)
    {
        this->iva = atof(iva);
        retorno = 0;
    }
    return retorno;
}

/**
    employee_getSueldo: Recibe un dato tipo Compra donde se buscara un sueldo y se devolvera ese sueldo.
    @param this: Es el espacio en memoria de una variable tipo Compra donde se buscara.
    @param sueldo: Es el puntero a un int donde se guardara el sueldo a buscar.
    @return 0 OK, -1 Error.
*/

int employee_getIva(Compra* this, float* iva)
{
    int retorno = -1;
    if(this != NULL && iva != NULL)
    {
        *iva = this->iva;
        retorno = 0;
    }
    return retorno;
}

static int isValidSueldo(char* sueldo)
{
    int retorno = -1;
    if(isFloat(sueldo) == -1)
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
    @param this: Es el espacio en memoria de una variable tipo Compra donde se buscara.
    @param id: Es la cadena de caracteres con el id del Compra.
    @return 0 OK, -1 Error.
*/

int employee_setId(Compra* this, char* id)
{
    int retorno = -1;
    if(this != NULL && isValidId(id) == 0)
    {
        this->idProducto = atoi(id);
        retorno = 0;
    }
    return retorno;
}

/**
    employee_getId: Recibe un dato tipo Compra donde se buscara un id y se devolvera ese id.
    @param this: Es el espacio en memoria de una variable tipo Compra donde se buscara.
    @param id: Es el puntero a un int donde se guardara el id buscado.
    @return 0 OK, -1 Error.
*/

int employee_getId(Compra* this, int* idProducto)
{
    int retorno = -1;
    if(this != NULL && idProducto != NULL)
    {
        *idProducto = this->idProducto;
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

void employee_mostrar(LinkedList* pArrayListCompra)
{
    int i;
    int auxId;
    char auxNombre[1024];
    int auxHorasTrabajadas;
    float auxIva;
    float auxSueldo;
    int size;
    size = ll_len(pArrayListCompra);
    Compra* auxCompra;
    if(size > 0)
    {
        for(i=0; i < size; i++)
        {
            auxCompra = ll_get(pArrayListCompra, i);
            if( employee_getId(auxCompra, &auxId) == 0 &&
                employee_getNombre(auxCompra, auxNombre) == 0 &&
                employee_getHorasTrabajadas(auxCompra, &auxHorasTrabajadas) == 0 &&
                employee_getIva(auxCompra,&auxIva) == 0 &&
                employee_getSueldo(auxCompra, &auxSueldo) == 0)
            {
                printf("Nombre: %s - ID: %d - Precio Unitario: %.2f - Unidades: %d - IVA: %.2f \n", auxNombre, auxId, auxSueldo, auxHorasTrabajadas, auxIva);
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

int emp_buscarPantallaPorID(LinkedList* list, int id)
{
    int i;
    int retorno = -1;
    int size = ll_len(list);
    Compra* pCompra;
    if(list != NULL)
    {
        for(i = 0; i < size; i++)
        {
            pCompra = ll_get(list, i);
            if(pCompra != NULL && pCompra->idProducto == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int compraIdSeleccionado(void* pCompra, int idProducto)
{

    if(((Compra*)pCompra)->idProducto == idProducto)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void com_calcularMonto(void* pCompra)
{

}
