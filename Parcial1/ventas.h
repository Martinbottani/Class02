#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
struct S_ventas{
int idVenta;
int cantAfiches;
char nombreArchivo[128];
char zona[128];
int idCliente;
int isEmpty;
int estado;
}typedef Venta;

int vent_cargarDatosVacio(Venta* pVentas, int limite);
int vent_cargarIndice(Venta* pVentas,int indice,int limite, int idCliente);
int vent_indicesVacios(Venta* pVentas,int limite,int* indiceVacio);
int vent_mostrarIndice(Venta* pVentas,int limite);
int vent_mostrarVentas(Venta* pVentas,int limite);
int vent_modificarVenta(Venta* pVentas, int indice, int limite);
int vent_buscarVentaPorID(Venta* pVentas, int limite, int id);
int mostrarClientesVentas(Venta* pVenta,int limite, Cliente* pCliente);
int vent_modificarEstado(Venta* pVentas, int indice, int limite);
#endif // VENTAS_H_INCLUDED
