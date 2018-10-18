#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "service.h"
#include "user.h"

void ordernar(void* lista[], int limite, int (*comparar)(void*, void*));

int main()
{

    Empleado* listaEmpleados[1000];
    int qtyEmpleados = 0;
    int i;
    char auxiliar[50];

    for(i = 0; i < 100; i++)
    {
        sprintf(auxiliar, "Juan - %d", i);
        listaEmpleados[i] = emp_newParametros(auxiliar, "Perez", 1.45);
        qtyEmpleados++;
    }
    listaEmpleados[i] = emp_newParametros("AAAA", "Perez", 1.45);
    qtyEmpleados++;
    ordernar((void*)listaEmpleados, qtyEmpleados, emp_compareNombre);
    for(i = 0; i < qtyEmpleados; i++)
    {
        emp_print(listaEmpleados[i]);
    }
    /*
    Service* listaServicios[1000];
    int qtyServicios = 0;
    int i;

    for(i = 0; i < 100; i++)
    {
        listaServicios[i] = serv_newParametros(50, "Esto es un servicio");
        qtyServicios++;
    }

    for(i = 0; i < qtyServicios; i++)
    {
        serv_print(listaServicios[i]);
    }


    User* listaUsuarios[1000];
    int qtyUsuarios = 0;
    int i;

    for(i = 0; i < 100; i++)
    {
        listaUsuarios[i] = user_newParametros("Martin", "martinbottani.13@gmail.com");
        qtyUsuarios++;
    }

    for(i = 0; i < qtyUsuarios; i++)
    {
        user_print(listaUsuarios[i]);
    }
    */
    return 0;
}
void ordernar(void* lista[], int limite, int (*comparar)(void*, void*))
{
    int flagSwap;
    int i;
    void* auxiliarPuntero;
    do
    {
        flagSwap = 0;
        for(i = 0; i < limite - 1; i++)
        {
            if(comparar(lista[i], lista[i+1]) > 0)
            {
                auxiliarPuntero = lista[i];
                lista[i] = lista[i+1];
                lista[i+1] = auxiliarPuntero;
                flagSwap = 1;
            }
        }
    }while(flagSwap);
}
