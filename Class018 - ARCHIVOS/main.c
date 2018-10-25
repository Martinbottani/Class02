#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include <strings.h>
void mostrar(User* pUser[], int size)
{
    int i;
    char auxId;
    char auxNombre[50];
    char auxApellido[50];
    for(i = 0; i < size; i++)
    {
        user_getId(pUser[i], &auxId);
        user_getName(pUser[i], auxNombre);
        user_getSurname(pUser[i], auxApellido);
        printf("\nID: %d - NOMBRE: %s - APELLIDO: %s", (int)auxId, auxNombre, auxApellido);
    }
}

void guardar(User* pUser[], int size)
{
    int i;
    char auxId;
    char auxNombre[50];
    char auxApellido[50];
    FILE* pArchivoBkp = fopen("bkp.txt", "w");
    if(pArchivoBkp != NULL)
    {
        for(i = 0; i < size; i++)
        {
            user_getId(pUser[i], &auxId);
            user_getName(pUser[i], auxNombre);
            user_getSurname(pUser[i], auxApellido);
            fprintf(pArchivoBkp, "\nID: %d - NOMBRE: %s - APELLIDO: %s", (int)auxId, auxNombre, auxApellido);
        }
        fclose(pArchivoBkp);
    }

}

int main()
{
    User* pUser[1024];
    User* pAux;
    int size = 0;
    FILE* pArchivo;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];
    int flagOnce = 1;
    pArchivo = fopen("archivo.ext","r");
    while(!feof(pArchivo))
    {
        if(flagOnce)
        {
            fscanf(pArchivo,"%s\n", bufferId);
            flagOnce = 0;
        }
        fscanf(pArchivo,"%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferApellido);
        //printf("%s - %s - %s\n", bufferId, bufferNombre, bufferApellido);

        pAux = user_newParametros(bufferNombre,bufferApellido,bufferId);
        if(pAux != NULL)
        {
            pUser[size] = pAux;
            size++;
        }
    }
    fclose(pArchivo);
    mostrar(pUser, size);
    guardar(pUser, size);
    return 0;
}
