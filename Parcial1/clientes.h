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
/**
    client_mostrarIndice: Muestra los indices del array recibido.
    @param pClientes: Guarda el array recibido.
    @param limite: Guarda el int del limite del array.
    @return return 0 OK, -1 Error.
*/
int client_mostrarIndice(Cliente* pClientes,int limite);
/**
    client_mostrarUnIndice: Muestra un indice del array recibido.
    @param pClientes: Guarda el array recibido.
    @param indice: Guarda el indice recibido.
    @param limite: Guarda el int del limite del array.
    @return return 0 OK, -1 Error.
*/
int client_mostrarUnIndice(Cliente* pClientes,int limite,int indice);
/**
    client_altaForzada: Carga un valor en el mismo campo de todas las posiciones del array recibido.
    @param pClientes: Guarda el array recibido.
    @param limite: Guarda el int del limite del array.
    @param nombre: Guarda un nombre en el campo de la estructura.
    @param apellido: Guarda un apellido en el campo de la estructura.
    @param cuit: Guarda un cuit en el campo de la estructura.
    @return return 0 OK, -1 Error.
*/
int client_altaForzada(Cliente* pClientes, int limite,char* nombre, char* apellido, char* cuit);
/**
    client_cargarDatosVacio: Carga un valor en el mismo campo de todas las posiciones del array recibido.
    @param pClientes: Guarda el array recibido.
    @param limite: Guarda el int del limite del array.
    @return return 0 OK, -1 Error.
*/
int client_cargarDatosVacio(Cliente* pClientes, int limite);
/**
    client_cargarIndice: carga valores en la posicion del array recibido.
    @param pClientes: Guarda el array recibido.
    @param indice: Guarda el int de la posicion del array.
    @param limite: Guarda el int del limite del array.
    @return return 0 OK, -1 Error.
*/
int client_cargarIndice(Cliente* pClientes,int indice,int limite);
/**
    client_indicesVacios: Busca dentro del array hasta encontrar un indice vacio donde cargar un dato.
    @param pClientes: Guarda el array recibido.
    @param limite: Guarda el int del limite del array.
    @param indiceVacio: Guarda el indice de la posicion vacia del array.
    @return return 0 OK, -1 Error.
*/
int client_indicesVacios(Cliente* pClientes,int limite,int* indiceVacio);
/**
    client_chequearIndice: Recibe el array para chequear si esta cargado o no.
    @param pClientes: Guarda el array recibido.
    @param limite: Guarda el int del limite del array.
    @param indiceVacio: Recibe el puntero del indice vacio para chequearlo.
    @return return 0 OK, -1 Error.
*/
int client_chequearIndice(Cliente* pClientes,int limite);
/**
    client_buscarClientePorID: Recibe un ID para buscar un empleado.
    @param pClientes: Guarda el array recibido.
    @param limite: Guarda el int del limite del array.
    @param id: Guarda el int del empleado a buscar.
    @return return el indice del array donde esta el empleado.
*/
int client_buscarClientePorID(Cliente* pClientes, int limite, int id);
/**
    client_modificarID: Recibe un ID para modificar una posicion del array.
    @param pClientes: Guarda el array recibido.
    @param indice: Guarda el int recibido del ID a modificar.
    @param limite: Guarda el int del limite del array.
    @return return 0 OK, -1 Error.
*/
int client_modificarID(Cliente* pCliente, int indice, int limite);
/**
    client_borrarClientePorID: Recibe un ID para borrar un empleado.
    @param pCliente: Guarda el array recibido.
    @param limite: Guarda el int del limite del array.
    @param id: Guarda el int del empleado a borrar.
    @return return 0 OK, -1 Error.
*/
int client_borrarClientePorID(Cliente* pClientes, int id, int limite);
/**
    client_mostrarIndiceConVentas: Muestra los indices con venta de un array.
    @param pCliente: Guarda el array recibido.
    @param limite: Guarda el int del limite del array.
    @param pVentas: Guarda el array de ventas recibido.
    @param limite2: Guarda el int del limite del array de ventas.
    @return return 0 OK, -1 Error.
*/
int client_mostrarIndiceConVentas(Cliente* pClientes, int limites, Venta* pVentas, int limite2);



#endif // CLIENTES_H_INCLUDED
