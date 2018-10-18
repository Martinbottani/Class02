#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

static int isValidNombre(char* nombre);
static int isValidApellido(char* apellido);
static int isValidAltura(float altura);

Empleado* emp_new(void)
{
    return (Empleado*) malloc(sizeof(Empleado));
}

Empleado* emp_newParametros(char* nombre, char* apellido, float altura)
{
    Empleado* this = NULL;
    this = emp_new();
    if(this == NULL ||
        emp_setNombre(this, nombre) ||
        emp_setApellido(this, apellido) ||
        emp_setAltura(this, altura))
    {
        emp_delete(this);
        this = NULL;
    }
    return this;
}

void emp_delete(Empleado* this)
{
    free(this);
}
// Nombre
int emp_setNombre(Empleado* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && isValidNombre(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int emp_getNombre(Empleado* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}

static int isValidNombre(char* nombre)
{
    return 1;
}
int emp_compareNombre(void* thisA, void* thisB)
{
    Empleado* A = (Empleado*)thisA;
    Empleado* B = (Empleado*)thisB;
    return strcmp(A->nombre, B->nombre);
}
// Apellido
int emp_setApellido(Empleado* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && isValidApellido(apellido))
    {
        strcpy(this->apellido,apellido);
        retorno = 0;
    }
    return retorno;
}

int emp_getApellido(Empleado* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        strcpy(apellido,this->apellido);
        retorno = 0;
    }
    return retorno;
}

static int isValidApellido(char* apellido)
{
    return 1;
}
// Altura
int emp_setAltura(Empleado* this, float altura)
{
    int retorno = -1;
    if(this != NULL && isValidAltura(altura))
    {
        this->altura = altura;
        retorno = 0;
    }
    return retorno;
}

int emp_getAltura(Empleado* this, float* altura)
{
    int retorno = -1;
    if(this != NULL && altura != NULL)
    {
        *altura = this->altura;
        retorno = 0;
    }
    return retorno;
}

static int isValidAltura(float altura)
{
    return 1;
}

void emp_print(Empleado* this)
{
    if(this != NULL) printf("\n%s - %s - %.2f - %d", this->nombre, this->apellido, this->altura, this->idEmpleado);
}

