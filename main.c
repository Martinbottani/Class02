#include <stdio.h>
#include <stdlib.h>

int main()
{
    //printf("Hello world!\n");
    //return 0;
    /*
    int numeros[3];
    int numeroMaximo;
    int numeroMinimo;
    int i;
    for(i = 0; i < 3; i++)
    {
        printf("Numero %d:\n ",i+1);
        scanf("%d", &numeros[i]);
        if(i == 0)
        {
            numeroMaximo = numeros[i];
            numeroMinimo = numeros[i];
        }
        else if(numeros[i] > numeroMaximo)
        {
            numeroMaximo = numeros[i];
        }
        else if(numeros[i] < numeroMinimo)
        {
            numeroMinimo = numeros[i];
        }
    }
    printf("Min: %d - Max: %d\n", numeroMinimo, numeroMaximo);
    for(i = 0; i < 3; i++)
    {
        if(numeros[i] > numeroMinimo && numeros[i] < numeroMaximo)
        {
            printf("El numero %d es el del medio\n", numeros[i]);
            break;
        }
    }
    if(i == 3)
    {
        printf("No hay numero medio");
    }
    */
    /*

    int numero1;
    int numero2;
    int numero3;
    int numeroMinimo;
    int numeroMaximo;
    printf("Ingrese el numero 1:\n");
    scanf("%d",&numero1);
    printf("Ingrese el numero 2:\n");
    scanf("%d",&numero2);
    printf("Ingrese el numero 3:\n");
    scanf("%d",&numero3);
    numeroMaximo = numero1;
    numeroMinimo = numero1;
    if(numero2 > numeroMaximo)
    {
        numeroMaximo = numero2;
    }
    else if(numero2 < numeroMinimo)
    {
        numeroMinimo = numero2;
    }
    if(numero3 > numeroMaximo)
    {
        numeroMaximo = numero3;
    }
    else if(numero3 < numeroMinimo)
    {
        numeroMinimo = numero3;
    }
    if(numero1 > numeroMinimo && numero1 < numeroMaximo)
    {
        printf("El numero del medio es: %d\n", numero1);
    }
    else if(numero2 > numeroMinimo && numero2 < numeroMaximo)
    {
        printf("El numero del medio es: %d\n", numero2);
    }
    else if(numero3 > numeroMinimo && numero3 < numeroMaximo)
    {
        printf("El numero del medio es: %d\n", numero3);
    }
    else
    {
        printf("No hay numero medio\n");
    }
    printf("El numero mayor es: %d\n",numeroMaximo);
    printf("El numero menor es: %d\n",numeroMinimo);
    */

    int numero;
    int numeroMaximo;
    int numeroMinimo;
    int acumuladorNumeros = 0;
    float promedio;
    int i;
    for(i = 0; i < 10; i++)
    {
        printf("Dame un numero %d: \n",i+1);
        scanf("%d", &numero);
        if(i == 0)
        {
            numeroMaximo = numero;
            numeroMinimo = numero;
        }
        if(numero < numeroMinimo)
        {
            numeroMinimo = numero;
        }
        else if(numero > numeroMaximo)
        {
            numeroMaximo = numero;
        }
        acumuladorNumeros += numero;
    }
    promedio = (float)acumuladorNumeros / i;
    printf("El numero mayor es: %d\n", numeroMaximo);
    printf("El numero menor es: %d\n", numeroMinimo);
    printf("El promedio es: %.1f\n", promedio);
    return 0;

}
