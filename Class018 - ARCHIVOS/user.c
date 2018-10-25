#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "utn.h"

static int isValidName(char* name);
static int isValidSurname(char* surname);
static int isValidId(char* idUser);

User* user_new(void)
{
    return (User*) malloc(sizeof(User));
}

User* user_newParametros(char* name, char* surname, char* id)
{
    User* this = NULL;
    this = user_new();
    if(this == NULL ||
        user_setName(this, name) ||
        user_setSurname(this, surname) ||
        user_setId(this, id))
    {
        user_delete(this);
        this = NULL;
    }
    return this;
}

void user_delete(User* this)
{
    free(this);
}

int user_setName(User* this, char* name)
{
    int retorno = -1;
    if(this != NULL && isValidName(name))
    {
        strcpy(this->name,name);
        retorno = 0;
    }
    return retorno;
}

int user_getName(User* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL)
    {
        strcpy(name,this->name);
        retorno = 0;
    }
    return retorno;
}

static int isValidName(char* name)
{
    return 1;
}

int user_setSurname(User* this, char* surname)
{
    int retorno = -1;
    if(this != NULL && isValidSurname(surname))
    {
        strcpy(this->surname,surname);
        retorno = 0;
    }
    return retorno;
}

int user_getSurname(User* this, char* surname)
{
    int retorno = -1;
    if(this != NULL && surname != NULL)
    {
        strcpy(surname,this->surname);
        retorno = 0;
    }
    return retorno;
}

static int isValidSurname(char* surname)
{
    return 1;
}

int user_compareName(User* thisA, User* thisB)
{
    return strcmp(thisA->name, thisB->name);
}


void user_print(User* this)
{
    if(this != NULL) printf("\n%d - %s - %s", this->id, this->name, this->surname);
}

int user_setId(User* this, char* idUser)
{
    int retorno=0;
    if(this != NULL && isValidId(idUser))
    {
        this->id = atoi(idUser);
    }
    return retorno;
}

int user_getId(User* this, char* idUser)
{
    int retorno=0;
    if(this != NULL && idUser != NULL)
    {
        *idUser = this->id;
    }
    return retorno;
}

static int isValidId(char* idUser)
{
    int retorno = 0;
    if(isInt(idUser) == -1)
    {
        printf("\nId invalido\n");
    }
    else
    {
        retorno = 1;
    }
    return retorno;
}
