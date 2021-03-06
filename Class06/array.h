#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

int utn_mostrarArray(int* pArray,int limite);
int utn_inicializarArray(int* pArray,int valor, int limite);
int utn_calcularMaximoArray(int* pArray,int limite,int* pMaximo);
int utn_calcularMinimoArray(int* pArray,int limite,int* pMinimo);
int utn_calcularPromedioArray(int* pArray,int limite,float* promedio);
int utn_esNumero(char* pArray);
int utn_ordenarArray(int* pArray, int limite, char menorMayor);
#endif // ARRAY_H_INCLUDED
