#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
typedef struct S_producto
{
    char nombre[32];
    char descripcion[128];
    float precio;
    int isEmpty;
}Producto;

int utn_cargarDatoVacio(Producto* p, int limite);
int utn_cargarDatoArray(Producto* p, int index, int limite);
int utn_imprimirDatoArray(Producto* p, int index);
int utn_imprimirDatoVacio(Producto* productos,int* indiceVacio, int limite);
int getString(char* pBuffer, int limite);
int utn_menu(Producto* productos, int limite);
int utn_getNumeroDecimal(float *pNum, int reint, char* msg, char* msgError,float maximo,float minimo);

#endif // PRODUCTO_H_INCLUDED
