#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"

static int isValidNombre(char* nom);
static int isValidApellido(char* apell);

Cliente* client_new(void)
{
    return (Cliente*) malloc(sizeof(Cliente));
}

int client_setNombre(Cliente* this, char* nom)
{
    int retorno = -1;
    if(this != NULL && isValidNombre(nom))
    {
        strncpy(this->nombre, nom, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int client_setApellido(Cliente* this, char* apell)
{
    int retorno = -1;
    if(this != NULL && isValidApellido(apell))
    {
        strncpy(this->apellido, apell, sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

static int isValidNombre(char* nom)
{
    return 1;
}

static int isValidApellido(char* apell)
{
    return 1;
}

int client_getNombre(Cliente* this, char* nom)
{
    int retorno = -1;
    if(this != NULL && nom != NULL)
    {
        strncpy(nom, this->nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int client_getApellido(Cliente* this, char* apell)
{
    int retorno = -1;
    if(this != NULL && apell != NULL)
    {
        strncpy(apell, this->apellido, sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int client_buscarLugarVacio(Cliente* array[], int limite)
{
    int retorno = -1;
    int i;
    if(array != NULL)
    {
        for(i = 0; i < limite; i++)
        {
            if(array[i] == NULL)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int client_inicializarArray(Cliente* array[], int limite)
{
    int retorno = -1;
    int i;
    if(array != NULL)
    {
        retorno = 0;
        for(i = 0; i < limite; i++)
            array[i] = NULL;
    }
    return retorno;
}

int client_buscarPorID(Cliente* array[], int limite, int id)
{
    int retorno = -1;
    int i;
    Cliente* aux;
    for(i = 0; i < limite; i++)
    {
        aux = array[i];
        if(aux != NULL && aux->idCliente == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int client_delet(Cliente* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

Cliente* client_newClienteParametros(char* nombre, char* apellido)
{
    Cliente* p;
    p = client_new();
    if(p != NULL)
    {
        if(client_setNombre(p, nombre) == -1 ||
            client_setApellido(p, apellido) == -1)
        {
            client_delet(p);
            p = NULL;
        }
    }
    return p;
}
