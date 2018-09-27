#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED
#include "pantallas.h"
struct Scontratacion{
int ID;
char nombreVideo[32];
int dias;
char cuitCliente[128];
int isEmpty;
int idPantalla;
}typedef Contratacion;

int cliente_cargarDatosVacio(Contratacion* cliente, int limite);
int cliente_cargarIndice(Contratacion* cliente,int indice,int limite, int idPantalla);
int prod_getEmptyIndexCliente(Contratacion* cliente,int limite,int* indiceVacio);
int mostrarContrataciones(Contratacion* cliente,int limite, Pantalla* pantalla);
int buscarContratacionPorCUIT(Contratacion* cliente, int limite, char* cuitCliente);
int modificarContratacion(Contratacion* cliente, int indice, int limite);
#endif // CONTRATACION_H_INCLUDED
