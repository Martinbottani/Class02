#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    char nombre[50];
    char apellido[50];
    int idCliente;
}Cliente;

Cliente* client_new(void);
Cliente* client_newClienteParametros(char* nombre, char* apellido);
int client_setNombre(Cliente* aux, char* nom);
int client_setApellido(Cliente* aux, char* apell);
int client_getNombre(Cliente* this, char* nom);
int client_getApellido(Cliente* this, char* apell);
int client_buscarLugarVacio(Cliente* array[], int limite);
int client_inicializarArray(Cliente* array[], int limite);
int client_buscarPorID(Cliente* array[], int limite, int id);
int client_delet(Cliente* this);
#endif // CLIENTES_H_INCLUDED
