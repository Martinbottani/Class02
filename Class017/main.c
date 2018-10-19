#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#define CANT_CLIENTES 100
int main()
{
    Cliente* clientes[CANT_CLIENTES];
    Cliente* aux;
    int indexVacio;
    client_inicializarArray(clientes, CANT_CLIENTES);
    //ALTA
    //aux = client_new();
    aux = client_newClienteParametros("Carlitos", "Cardona");
    indexVacio = client_buscarLugarVacio(clientes, CANT_CLIENTES);
    if(aux != NULL && indexVacio >= 0)
    {
        client_setNombre(aux, "Juan");
        clientes[indexVacio] = aux;

        char nombreAux[50];
        client_getNombre(aux, nombreAux);
        printf("%s", nombreAux);
    }
    return 0;
}
