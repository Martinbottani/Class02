#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
struct S_asociado{
int ID;
char nombre[32];
int edad;
char apellido[32];
char DNI[32];
char motivo[32];
char estado[32];
int isEmpty;
}typedef Asociado;

int altaForzada(Asociado* asociados, int limite,char* nombre,int tipo, char* direccion, float precio);
int cargarDatosVacio(Asociado* asociados,int limite);
int cargarIndice(Asociado* asociados,int indice,int limite);
int indicesVacios(Asociado* asociados,int limite,int* indiceVacio);
int buscarPantallaPorID(Asociado* asociados, int limite, int id);
int modificarID(Asociado* asociados, int indice, int limite);
int borrarPantallaPorID(Asociado* asociados, int id, int limite);
#endif // LIB_H_INCLUDED
