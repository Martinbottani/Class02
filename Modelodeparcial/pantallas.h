#ifndef PANTALLAS_H_INCLUDED
#define PANTALLAS_H_INCLUDED
#define TIPO_LED 0
#define TIPO_LCD 1
struct Spantalla{
int ID;
char nombre[32];
int tipo;
char direccion[128];
float precio;
int isEmpty;
}typedef Pantalla;

int cargarDatosVacio(Pantalla* pantalla,int limite);
int cargarIndice(Pantalla* pantalla,int indice,int limite);
int mostrarIndice(Pantalla* pantalla,int indice);
int prod_getEmptyIndex(Pantalla* pantalla,int limite,int* indiceVacio);
int buscarPantallaPorID(Pantalla* pantalla, int limite, int id);
int modificarID(Pantalla* pantalla, int indice, int limite);
int borrarPantallaPorID(Pantalla* pantalla, int id, int limite);
#endif // PANTALLAS_H_INCLUDED
