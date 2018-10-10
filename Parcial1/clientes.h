#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "ventas.h"
struct S_cliente{
int ID;
char nombre[51];
char apellido[51];
char cuitCliente[128];
int isEmpty;
}typedef Cliente;

int client_mostrarIndice(Cliente* pClientes,int limite);
int client_mostrarUnIndice(Cliente* pClientes,int limite,int indice);
int client_altaForzada(Cliente* pClientes, int limite,char* nombre, char* apellido, char* cuit);
int client_cargarDatosVacio(Cliente* pClientes, int limite);
int client_cargarIndice(Cliente* pClientes,int indice,int limite);
int client_indicesVacios(Cliente* pClientes,int limite,int* indiceVacio);
int client_chequearIndice(Cliente* pClientes,int limite);
int client_buscarClientePorID(Cliente* pClientes, int limite, int id);
int client_modificarID(Cliente* pCliente, int indice, int limite);
int client_borrarClientePorID(Cliente* pClientes, int id, int limite);
int client_mostrarIndiceConVentas(Cliente* pClientes, int limites, Venta* pVentas, int limite2);



#endif // CLIENTES_H_INCLUDED
