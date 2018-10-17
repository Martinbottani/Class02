#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

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

    for(i = 0; i < qtyEmpleados; i++)
    {
        emp_print(listaEmpleados[i]);
    }

    return 0;
}
