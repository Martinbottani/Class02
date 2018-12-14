#ifndef ENVIO_H_INCLUDED
#define ENVIO_H_INCLUDED
#include "LinkedList.h"
struct S_Envio
{
  int id;
  char nombreEnvio[128];
  int idCamion;
  char zona[128];
  int kmRecorrido;
  int entrega;
  int costo;
};
typedef struct S_Envio Envio;

Envio* new_env(void);
Envio* new_envParametros(char* idStr,char* nombreStr,char* camionStr,char* zonaStr,char* kmStr, char* entregaStr);
int env_delete(Envio* this);

int env_setNombre(Envio* this, char* nombre);
int env_getNombre(Envio* this, char* nombre);

int env_setCamion(Envio* this, char* camion);
int env_getCamion(Envio* this, int* camion);

int env_setZona(Envio* this, char* zona);
int env_getZona(Envio* this, char* zona);

int env_setKilometros(Envio* this, char* km);
int env_getKilometros(Envio* this, int* km);

int env_setEntrega(Envio* this, char* entrega);
int env_getEntrega(Envio* this, int* entrega);

int env_setId(Envio* this, char* id);
int env_getId(Envio* this, int* id);

int env_getCosto(Envio* this, int* costo);

void envio_mostrar(LinkedList* pArrayListEmployee);
int em_calcularCosto(void* pEnvio);
void envio_mostrarCostos(LinkedList* pArrayListEmployee);
int env_generarArchivo(char* fileName, LinkedList* lista);

int zonaSeleccionada(void* pEnvio, char* aux);

#endif // ENVIO_H_INCLUDED
