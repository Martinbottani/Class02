#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "array.h"
#define CANTIDAD_EDADES 5
void insertion(int data[],int len);
int main()
{

    int i;
    float edades[CANTIDAD_EDADES];
    for(i = 0; i < CANTIDAD_EDADES; i++)
    {
        if(utn_getNumeroDecimal(&edades[i], 3, "Ingrese la edad: \n", "Error \n", 200, 0) == -1)
        {
            edades[i] = -1;
        }
    }
    utn_mostrarArray(edades,CANTIDAD_EDADES);
    /*
    for(i = 0; i < CANTIDAD_EDADES; i++)
    {
        printf("Ingrese la edad: \n");
        scanf("%d", &edades[i]);
    }
    for(i = 0; i < CANTIDAD_EDADES; i++)
    {
        printf("%d\n", edades[i]);
    }

    insertion(edades, CANTIDAD_EDADES);
    printf("\n\nEl array ordenado es: \n");
    for(i = 0; i < CANTIDAD_EDADES; i++)
    {
        printf("%d\n", edades[i]);
    }
    */
    return 0;
}
/*
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
*/
