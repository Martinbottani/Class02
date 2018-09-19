#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
//typedef int Persona;
/*
struct S_Persona
{
    char nombre[70];
    int edad;
    char dni[20];
    float altura;
};
*/

typedef struct
{
    char nombre[70];    //Campos
    int edad;
    char dni[20];
    float altura;
}Persona;
//typedef struct S_Persona Persona;
void altaPersona(Persona* per);
void printPersona(Persona p);
int main()
{
    Persona p;
    altaPersona(&p);
    printPersona(p);
    return 0;
}
void printPersona(Persona per)
{
    //Si es un puntero en vez de "." va "->" = per->nombre
    //Si es una variable va "." = per.nombre
    printf("Los datos de la persona son:\n");
    printf(" Nombre: %s\n", per.nombre);
    printf(" Su edad es: %d\n", per.edad);
    printf(" Su dni es: %s\n", per.dni);
    printf(" Su altura es: %.2f", per.altura);
}
void altaPersona(Persona* pPer)
{
    /*
    printf("Dame tu nombre: \n");
    fgets(pPer->nombre,70,stdin);
    printf("Dame tu edad: \n");
    scanf("%d", &pPer->edad);
    printf("Dame tu dni: \n");
    __fpurge(stdin);
    fgets(pPer->dni,20,stdin);
    printf("Dame tu altura: \n");
    scanf("%f", &pPer->altura);
    */
    char nombreAux[70];
    int edadAux;
    float alturaAux;
    if(utn_getNombre(nombreAux,3,"Ingrese su nombre","Error no es un nombre valido") == 0)
    {
        if(utn_getEntero(edadAux,3,"Ingrese su edad","Error no es una edad valida", 200, 0) == 0)
        {
            if(utn_getNumeroDecimal(alturaAux,3,"Ingrese su altura","Error no es una altura valida", 10, 5))
            {
                pPer->altura = alturaAux;
                pPer->edad = edadAux;
                strncpy(pPer->nombre, nombreAux, 70);
            }
        }
    }
}
