#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "envio.h"
#include "utn.h"
#include <string.h>

static int isValidNombre(char* nombre);
static int isValidCamion(char* camion);
static int isValidZona(char* zona);
static int isValidKilometros(char* km);
static int isValidEntrega(char* entrega);
static int isValidId(char* id);

/**
    employee_new: Crea un nuevo espacio en memoria con una variable de tipo Employee.
    @return Direccion de memoria creada.
*/

Envio* new_env(void)
{
    return (Envio*) malloc(sizeof(Envio));
}

/**
    employee_newParametros: Crea un nuevo espacio en memoria y setea datos en una variable tipo Employee.
    @param idStr: Es la cadena de caracteres con el id a guardar.
    @param nombreStr: Es la cadena de caracteres con el nombre a guardar.
    @param horasTrabajadasStr: Es la cadena de caracteres con las horas trabajadas a guardar.
    @param sueldoStr: Es la cadena de caracteres con el sueldo a guardar.
    @return Direccion de memoria creada.
*/

Envio* new_envParametros(char* idStr,char* nombreStr,char* camionStr,char* zonaStr,char* kmStr, char* entregaStr)
{
    Envio* this = NULL;
    this = new_env();
    if(this == NULL ||
        env_setId(this, idStr) ||
        env_setNombre(this, nombreStr) ||
        env_setCamion(this, camionStr) ||
        env_setZona(this, zonaStr) ||
        env_setKilometros(this, kmStr) ||
        env_setEntrega(this, entregaStr))
    {
        env_delete(this);
        this = NULL;
    }
    return this;
}

/**
    employee_delete: Borra un espacio en memoria.
    @param this: Es el espacio en memoria a borrar.
    @return 0 OK, -1 Error.
*/

int env_delete(Envio* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}


int env_setNombre(Envio* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && isValidNombre(nombre) == 0)
    {
        strcpy(this->nombreEnvio,nombre);
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

int env_getNombre(Envio* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombreEnvio);
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

int env_setCamion(Envio* this, char* camion)
{
    int retorno = -1;
    if(this != NULL && isValidCamion(camion) == 0)
    {
        this->idCamion = atoi(camion);
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

int env_getCamion(Envio* this, int* camion)
{
    int retorno = -1;
    if(this != NULL && camion != NULL)
    {
        *camion = this->idCamion;
        retorno = 0;
    }
    return retorno;
}


/**
    employee_isValidHorasTrabajadas: Recibe una cadena de caracteres de horas trabajadas para validar que solo sean numeros.
    @param horasTrabajadas: Es la cadena de caracteres a validar.
    @return 0 OK, -1 Error.
*/

static int isValidCamion(char* camion)
{
    int retorno = -1;
    if(isInt(camion) == -1)
    {
        printf("\nEl id del Camion no es valido\n");
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

int env_setZona(Envio* this, char* zona)
{
    int retorno = -1;
    if(this != NULL && isValidZona(zona) == 0)
    {
        strcpy(this->zona,zona);
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

int env_getZona(Envio* this, char* zona)
{
    int retorno = -1;
    if(this != NULL && zona != NULL)
    {
        strcpy(zona,this->zona);
        retorno = 0;
    }
    return retorno;
}

/**
    employee_isValidSueldo: Recibe una cadena de caracteres de sueldo para validar que solo sean numeros.
    @param sueldo: Es la cadena de caracteres a validar.
    @return 0 OK, -1 Error.
*/

static int isValidZona(char* zona)
{
    int retorno = -1;
    if(isLetra(zona) == 0)
    {
        retorno = 0;
    }
    return retorno;
}

int env_setKilometros(Envio* this, char* km)
{
    int retorno = -1;
    if(this != NULL && isValidKilometros(km) == 0)
    {
        this->kmRecorrido = atoi(km);
        retorno = 0;
    }
    return retorno;
}

int env_getKilometros(Envio* this, int* km)
{
    int retorno = -1;
    if(this != NULL && km != NULL)
    {
        *km = this->kmRecorrido;
        retorno = 0;
    }
    return retorno;
}


static int isValidKilometros(char* km)
{
    int retorno = -1;
    if(isInt(km) == -1)
    {
        printf("\nLos kilometros, no son validos\n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}


int env_setEntrega(Envio* this, char* entrega)
{
    int retorno = -1;
    if(this != NULL && isValidEntrega(entrega) == 0)
    {
        this->entrega = atoi(entrega);
        retorno = 0;
    }
    return retorno;
}

int env_getEntrega(Envio* this, int* entrega)
{
    int retorno = -1;
    if(this != NULL && entrega != NULL)
    {
        *entrega = this->entrega;
        retorno = 0;
    }
    return retorno;
}

static int isValidEntrega(char* entrega)
{
    int retorno = -1;
    if(isInt(entrega) == -1)
    {
        printf("\nLa entrega no es valido\n");
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

int env_setId(Envio* this, char* id)
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

int env_getId(Envio* this, int* id)
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

int env_getCosto(Envio* this, int* costo)
{
    int retorno = -1;
    if(this != NULL && costo != NULL)
    {
        *costo = this->costo;
        retorno = 0;
    }
    return retorno;
}

void envio_mostrar(LinkedList* pArrayListEmployee)
{
    int i;
    int auxId;
    char auxNombre[1024];
    int auxIdCamion;
    char auxZona[1024];
    int auxKilometros;
    int auxEntrega;
    int size;
    size = ll_len(pArrayListEmployee);
    Envio* pAux;
    if(size > 0)
    {
        for(i=0; i < size; i++)
        {
            pAux = ll_get(pArrayListEmployee, i);
            if( env_getId(pAux, &auxId) == 0 &&
                env_getNombre(pAux, auxNombre) == 0 &&
                env_getCamion(pAux, &auxIdCamion) == 0 &&
                env_getZona(pAux, auxZona) == 0 &&
                env_getKilometros(pAux, &auxKilometros) == 0 &&
                env_getEntrega(pAux, &auxEntrega) == 0)
            {
                printf("ID: %d - Nombre del Producto: %s - ID Camion: %d - Zona: %s - KM Recorridos: %d - Tipo de entrega: %d \n", auxId, auxNombre, auxIdCamion, auxZona, auxKilometros, auxEntrega);
            }
            else
            {
                printf("\nError, no se pudo mostrar la lista.\n");
            }
        }
         printf("\nLa candidad de productos es: %d.", size);
         printf("\nFin de la lista.\n");
    }
    else
    {
        printf("\nError, no hay lista cargada.\n");
    }
}

int em_calcularCosto(void* pEnvio)
{
    int retorno = -1;
    if(((Envio*)pEnvio)->kmRecorrido < 50)
    {
        ((Envio*)pEnvio)->costo = 100 * ((Envio*)pEnvio)->kmRecorrido;
        retorno = 0;
    }
    if(((Envio*)pEnvio)->kmRecorrido >= 50)
    {
        ((Envio*)pEnvio)->costo = 50 * ((Envio*)pEnvio)->kmRecorrido;
        retorno = 0;
    }
    if(((Envio*)pEnvio)->entrega == 0)
    {
        ((Envio*)pEnvio)->costo += 250;
        retorno = 0;
    }
    else if(((Envio*)pEnvio)->entrega == 1)
    {
        ((Envio*)pEnvio)->costo += 420;
        retorno = 0;
    }
    else
    {
        ((Envio*)pEnvio)->costo += 75;
        retorno = 0;
    }
    return retorno;
}

void envio_mostrarCostos(LinkedList* pArrayListEmployee)
{
    int i;
    int auxCostos;
    int size;
    size = ll_len(pArrayListEmployee);
    Envio* pAux;
    if(size > 0)
    {
        for(i=0; i < size; i++)
        {
            pAux = ll_get(pArrayListEmployee, i);
            if(env_getCosto(pAux, &auxCostos) == 0)
            {
                printf("Costo: %d\n", auxCostos);
            }
            else
            {
                printf("\nError, no se pudo mostrar la lista.\n");
            }
        }
         printf("\nFin de la lista.\n");
    }
    else
    {
        printf("\nError, no hay lista cargada.\n");
    }
}
int env_generarArchivo(char* fileName, LinkedList* lista)
{
    int retorno = -1;
    LinkedList* listaFiltreada = ll_newLinkedList();
    int i;
    int auxId;
    char auxNombre[1024];
    int auxIdCamion;
    char auxZona[1024];
    int auxKilometros;
    int auxEntrega;
    int auxCosto;
    Envio* pAux;
    int size = ll_len(lista);
    FILE* pFile;
    pFile = fopen(fileName,"w");
    listaFiltreada = ll_filter(lista,zonaSeleccionada, fileName);
    if(pFile != NULL)
    {

        retorno = 0;
        for(i = 0; i < size; i++)
        {
            pAux = ll_get(lista, i);
            if(     env_getId(pAux, &auxId) &&
                    env_getNombre(pAux, auxNombre) &&
                    env_getCamion(pAux, &auxIdCamion) &&
                    env_getZona(pAux, auxZona) &&
                    env_getKilometros(pAux, &auxKilometros) &&
                    env_getEntrega(pAux, &auxEntrega) &&
                    env_getCosto(pAux, &auxCosto))
            {
                fprintf(pFile,"ID: %d\n", auxId);
                fprintf(pFile,"Nombre de producto: %s\n",auxNombre);
                fprintf(pFile,"ID Camion: %d\n",auxIdCamion);
                fprintf(pFile,"Zona: %s\n",auxZona);
                fprintf(pFile,"KM recorridos: %d\n",auxKilometros);
                fprintf(pFile,"Tipo de entrega: %d\n",auxEntrega);
                fprintf(pFile,"Costo de envio: %d\n",auxCosto);
            }
        }
    }
    fclose(pFile);
    return retorno;
}

int zonaSeleccionada(void* pEnvio, char* aux)
{

    if(strcmp(((Envio*)pEnvio)->zona, aux) == 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
