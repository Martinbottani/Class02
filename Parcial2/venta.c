#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "venta.h"
#include "utn.h"
#include <string.h>

static int isValidFecha(char* fecha);
static int isValidCodigo(char* codigo);
static int isValidCantidad(char* cantidad);
static int isValidCuit(char* cuit);
static int isValidPrecio(char* precio);
static int isValidId(char* id);

/**
    employee_new: Crea un nuevo espacio en memoria con una variable de tipo Employee.
    @return Direccion de memoria creada.
*/

Venta* new_venta(void)
{
    return (Venta*) malloc(sizeof(Venta));
}

/**
    employee_newParametros: Crea un nuevo espacio en memoria y setea datos en una variable tipo Employee.
    @param idStr: Es la cadena de caracteres con el id a guardar.
    @param nombreStr: Es la cadena de caracteres con el nombre a guardar.
    @param horasTrabajadasStr: Es la cadena de caracteres con las horas trabajadas a guardar.
    @param sueldoStr: Es la cadena de caracteres con el sueldo a guardar.
    @return Direccion de memoria creada.
*/

Venta* new_ventaParametros(char* idStr,char* fechaStr,char* codigoStr,char* cantidadStr,char* cuitStr, char* precioStr)
{
    Venta* this = NULL;
    this = new_venta();
    if(this == NULL ||
        vent_setId(this, idStr) ||
        vent_setFecha(this, fechaStr) ||
        vent_setCodigo(this, codigoStr) ||
        vent_setCantidad(this, cantidadStr) ||
        vent_setCuit(this, cuitStr) ||
        vent_setPrecio(this, precioStr))
    {
        vent_delete(this);
        this = NULL;
    }
    return this;
}

/**
    employee_delete: Borra un espacio en memoria.
    @param this: Es el espacio en memoria a borrar.
    @return 0 OK, -1 Error.
*/

int vent_delete(Venta* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}


int vent_setFecha(Venta* this, char* fecha)
{
    int retorno = -1;
    if(this != NULL && isValidFecha(fecha) == 0)
    {
        strcpy(this->fechaVenta,fecha);
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

int vent_getFecha(Venta* this, char* fecha)
{
    int retorno = -1;
    if(this != NULL && fecha != NULL)
    {
        strcpy(fecha,this->fechaVenta);
        retorno = 0;
    }
    return retorno;
}

/**
    employee_isValidNombre: Recibe una cadena de caracteres de un nombre para validar que solo sean letras, espacios o guiones.
    @param nombre: Es una cadena de caracteres a validar.
    @return 0 OK, -1 Error.
*/

static int isValidFecha(char* fecha)
{
    int retorno = -1;
    if(isLetra(fecha) == 0)
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

int vent_setCodigo(Venta* this, char* codigo)
{
    int retorno = -1;
    if(this != NULL && isValidCodigo(codigo) == 0)
    {
        strcpy(this->codigoProducto,codigo);
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

int vent_getCodigo(Venta* this, char* codigo)
{
    int retorno = -1;
    if(this != NULL && codigo != NULL)
    {
        strcpy(codigo,this->codigoProducto);
        retorno = 0;
    }
    return retorno;
}


/**
    employee_isValidHorasTrabajadas: Recibe una cadena de caracteres de horas trabajadas para validar que solo sean numeros.
    @param horasTrabajadas: Es la cadena de caracteres a validar.
    @return 0 OK, -1 Error.
*/

static int isValidCodigo(char* codigo)
{
    int retorno = -1;
    if(isLetra(codigo) == 0)
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

int vent_setCantidad(Venta* this, char* cantidad)
{
    int retorno = -1;
    if(this != NULL && isValidCantidad(cantidad) == 0)
    {
        this->cantidad = atoi(cantidad);
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

int vent_getCantidad(Venta* this, int* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad != NULL)
    {
        *cantidad = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

/**
    employee_isValidSueldo: Recibe una cadena de caracteres de sueldo para validar que solo sean numeros.
    @param sueldo: Es la cadena de caracteres a validar.
    @return 0 OK, -1 Error.
*/

static int isValidCantidad(char* cantidad)
{
    int retorno = -1;
    if(isInt(cantidad) == -1)
    {
        printf("\nLa cantidad no es valido\n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

int vent_setCuit(Venta* this, char* cuit)
{
    int retorno = -1;
    if(this != NULL && isValidCuit(cuit) == 0)
    {
        strcpy(this->cuitCliente,cuit);
        retorno = 0;
    }
    return retorno;
}

int vent_getCuit(Venta* this, char* cuit)
{
    int retorno = -1;
    if(this != NULL && cuit != NULL)
    {
        strcpy(cuit,this->cuitCliente);
        retorno = 0;
    }
    return retorno;
}

static int isValidCuit(char* cuit)
{
    int retorno = -1;
    if(isLetra(cuit) == 0)
    {
        retorno = 0;
    }
    return retorno;
}

int vent_setPrecio(Venta* this, char* precio)
{
    int retorno = -1;
    if(this != NULL && isValidPrecio(precio) == 0)
    {
        this->precioUnitario = atof(precio);
        retorno = 0;
    }
    return retorno;
}

int vent_getPrecio(Venta* this, float* precio)
{
    int retorno = -1;
    if(this != NULL && precio != NULL)
    {
        *precio = this->precioUnitario;
        retorno = 0;
    }
    return retorno;
}

static int isValidPrecio(char* cantidad)
{
    int retorno = -1;
    if(isFloat(cantidad) == -1)
    {
        printf("\nLa cantidad no es valido\n");
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

int vent_setId(Venta* this, char* id)
{

    int retorno = -1;
    if(this != NULL && isValidId(id) == 0)
    {
        this->id = atoi(id);
        retorno = 0;
    }
    return retorno;
}

/**
    employee_getId: Recibe un dato tipo Employee donde se buscara un id y se devolvera ese id.
    @param this: Es el espacio en memoria de una variable tipo Employee donde se buscara.
    @param id: Es el puntero a un int donde se guardara el id buscado.
    @return 0 OK, -1 Error.
*/

int vent_getId(Venta* this, int* id)
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
    if(isInt(id) == -1)
    {
        printf("\nError, id invalido.\n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}



