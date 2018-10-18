#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED

typedef struct
{
    int gravedad;
    char mensaje[65];
    int serviceID;
}Service;

Service* serv_new(void);
Service* serv_newParametros(int gravedad, char* mensaje);
void serv_delete(Service* this);
int serv_setGravedad(Service* this, int gravedad);
int serv_getGravedad(Service* this, int gravedad);
int serv_setMensaje(Service* this, char* mensaje);
int serv_getMensaje(Service* this, char* mensaje);
int serv_compareMensaje(Service* thisA, Service* thisB);
void serv_print(Service* this);

#endif // SERVICE_H_INCLUDED
