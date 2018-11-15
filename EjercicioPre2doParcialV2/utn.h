#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getNombre(char* pNombre, char* msg, char* msgError);
int utn_getEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo);
int utn_getEnteroSinLimites(int* pNum, int reint, char* msg, char* msgError);
int utn_getNumeroDecimal(float *pNum, int reint, char* msg, char* msgError,float maximo,float minimo);
int utn_getString(char* pBufferString,int limite);
int isInt(char* pBuffer);
int isIntConGuiones(char* pBuffer);
int isLetra(char* pBuffer);

#endif // UTN_H_INCLUDED
