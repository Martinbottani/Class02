#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "service.h"

static int isValidGravedad(int gravedad);
static int isValidMensaje(char* mensaje);
static int setID(Service* this);

Service* serv_new(void)
{
    return (Service*) malloc(sizeof(Service));
}

Service* serv_newParametros(int gravedad, char* mensaje)
{
    Service* this = NULL;
    this = serv_new();
    if(this == NULL ||
        serv_setGravedad(this, gravedad) ||
        serv_setMensaje(this, mensaje) ||
        setID(this))
    {
        serv_delete(this);
        this = NULL;
    }
    return this;
}

void serv_delete(Service* this)
{
    free(this);
}

int serv_setGravedad(Service* this, int gravedad)
{
    int retorno = -1;
    if(this != NULL && isValidGravedad(gravedad))
    {
        this->gravedad = gravedad;
        retorno = 0;
    }
    return retorno;
}

int serv_getGravedad(Service* this, int gravedad)
{
    int retorno = -1;
    if(this != NULL && gravedad > 0)
    {
        gravedad = this->gravedad;
        retorno = 0;
    }
    return retorno;
}

static int isValidGravedad(int gravedad)
{
    return 1;
}

int serv_setMensaje(Service* this, char* mensaje)
{
    int retorno = -1;
    if(this != NULL && isValidMensaje(mensaje))
    {
        strcpy(this->mensaje,mensaje);
        retorno = 0;
    }
    return retorno;
}

int serv_getMensaje(Service* this, char* mensaje)
{
    int retorno = -1;
    if(this != NULL && mensaje != NULL)
    {
        strcpy(mensaje,this->mensaje);
        retorno = 0;
    }
    return retorno;
}

static int isValidMensaje(char* mensaje)
{
    return 1;
}

int serv_compareMensaje(Service* thisA, Service* thisB)
{
    return strcmp(thisA->mensaje, thisB->mensaje);
}


void serv_print(Service* this)
{
    if(this != NULL) printf("\n%d - %s - %d", this->gravedad, this->mensaje, this->serviceID);
}

static int setID(Service* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        static int cont = -1;
        ++cont;
        this->serviceID = cont;
        retorno = 0;
    }
    return retorno;
}

