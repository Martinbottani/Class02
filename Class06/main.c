#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "array.h"
#include <string.h>
#define CANTIDAD_EMPLEADOS 5
#define DATO_INVALIDO -1

//&salario[0];Esta bien,pero es muy largo
//salario; => &salario[60] desde donde quiero la direccion de memoria
void insertion(int data[],int len);

int main()
{
    //char menorMayor;
    int edades[CANTIDAD_EMPLEADOS];
    int i;
    int maximo;
    int minimo;
    float promedio;

    while(utn_inicializarArray(edades,DATO_INVALIDO,CANTIDAD_EMPLEADOS)==-1)
    {
        printf("La direccion del array esta mal");
    }
    //printf("Como queres ordenar el Array?: > o <\n");
    //__fpurge(stdin);
    //scanf("%c", &menorMayor);
    for(i=0;i< CANTIDAD_EMPLEADOS;i++)
    {

        utn_getEntero(&edades[i],1,"Ingrese la edad: \n", "Esa no es una edad\n",200,0);
        /*if(utn_getEntero(&edades[i],1,"Ingrese la edad: \n", "Esa no es una edad\n",200,0)==-1)
        {
            edades[i]=-1;
        }*/

    }

    utn_mostrarArray(edades,CANTIDAD_EMPLEADOS);
    //utn_mostrarArray(edades+2,CANTIDAD_EMPLEADOS-2);
    /*
    if(utn_ordenarArray(edades, CANTIDAD_EMPLEADOS,menorMayor)==-1)
    {
        printf("\nEl orden no se pudo hacer porque esta mal la direccion del Array");
    }
    else
    {
        printf("\nEl array ordenado es:\n");
        utn_mostrarArray(edades,CANTIDAD_EMPLEADOS);
    }
    */
    insertion(edades,CANTIDAD_EMPLEADOS);
    printf("\n\nEl array ordenado es:\n");
    utn_mostrarArray(edades,CANTIDAD_EMPLEADOS);
    utn_calcularMaximoArray(edades,CANTIDAD_EMPLEADOS,&maximo);
    utn_calcularMinimoArray(edades,CANTIDAD_EMPLEADOS,&minimo);
    utn_calcularPromedioArray(edades,CANTIDAD_EMPLEADOS,&promedio);
    printf("\n\nEl maximo es: %d\n",maximo);
    printf("\nEl minimo es: %d\n",minimo);
    printf("\nEl promedio es: %.2f\n",promedio);
    return 0;

}
void insertion(int data[],int len)
{
     int i,j;
     int temp;
     for(i=1;i<len;i++)
     {
        temp = data[i];
        j=i-1;
        while(j>=0 && temp<data[j]) // temp<data[j] o temp>data[j]
        {
         data[j+1] = data[j];
         j--;
        }
        data[j+1]=temp; // inserción
     }
}
