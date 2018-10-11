#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "ventas.h"
#include "utn.h"

int inf_cantidadDeVentasDeClientes(Venta* pVentas,int limite,int id)
{
    int retorno = 0;
    int i;
    for(i = 0; i < limite; i++)
    {
        if(pVentas[i].isEmpty == 0 && pVentas[i].idCliente == id && pVentas[i].estado == 1)
        {
            retorno++;
        }
    }
    return retorno;
}

int inf_cantidadDeVentasCobradasDeClientes(Venta* pVentas,int limite,int id)
{
    int retorno = 0;
    int i;
    for(i = 0; i < limite; i++)
    {
        if(pVentas[i].isEmpty == 0 && pVentas[i].idCliente == id && pVentas[i].estado == 0)
        {
            retorno++;
        }
    }
    return retorno;
}

int inf_cantidadDeAfichesACobrar(Venta* pVentas,int limite,int id)
{
    int retorno = 0;
    int i;
    for(i = 0; i < limite; i++)
    {
        if(pVentas[i].isEmpty == 0 && pVentas[i].idCliente == id && pVentas[i].estado == 1)
        {
            retorno += pVentas[i].cantAfiches;
        }
    }
    return retorno;
}

int inf_cantidadDeAfichesCobrados(Venta* pVentas,int limite,int id)
{
    int retorno = 0;
    int i;
    for(i = 0; i < limite; i++)
    {
        if(pVentas[i].isEmpty == 0 && pVentas[i].idCliente == id && pVentas[i].estado == 0)
        {
            retorno += pVentas[i].cantAfiches;
        }
    }
    return retorno;
}

int inf_ClienteConMasVentas(Cliente* pClientes, Venta* pVentas, int limite, int limite2)
{
    int retorno = -1;
    int i;
    int cantVentas;
    int cantVentasMayor;
    int auxIdCliente;
    if(pClientes != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pClientes[i].isEmpty==0)
            {
                cantVentas = inf_cantidadDeVentasDeClientes(pVentas, limite2, pClientes[i].ID);
                if(i == 0)
                {
                    cantVentasMayor = cantVentas;
                }
                if(cantVentas > cantVentasMayor || cantVentas == cantVentasMayor)
                {
                    cantVentasMayor = cantVentas;
                    auxIdCliente = pClientes[i].ID;
                    retorno = 0;
                }
            }
        }
        printf("\nID del cliente es: %d", pClientes[auxIdCliente].ID);
        printf("\nNombre del cliente es: %s", pClientes[auxIdCliente].nombre);
        printf("\nApellido del cliente es: %s", pClientes[auxIdCliente].apellido);
        printf("\nCUIT del cliente es: %s", pClientes[auxIdCliente].cuitCliente);
        printf("\nLa cantidad de ventas a cobrar que posee es: %d\n", cantVentasMayor);
    }
    return retorno;
}

int inf_ClienteConMasVentasCobradas(Cliente* pClientes, Venta* pVentas, int limite, int limite2)
{
    int retorno = -1;
    int i;
    int cantVentas;
    int cantVentasMayor;
    int auxIdCliente;
    if(pClientes != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pClientes[i].isEmpty==0)
            {
                cantVentas = inf_cantidadDeVentasCobradasDeClientes(pVentas, limite2, pClientes[i].ID);
                if(i == 0)
                {
                    cantVentasMayor = cantVentas;
                }
                if(cantVentas > cantVentasMayor || cantVentas == cantVentasMayor)
                {
                    cantVentasMayor = cantVentas;
                    auxIdCliente = pClientes[i].ID;
                    retorno = 0;
                }
            }
        }
        printf("\nID del cliente es: %d", pClientes[auxIdCliente].ID);
        printf("\nNombre del cliente es: %s", pClientes[auxIdCliente].nombre);
        printf("\nApellido del cliente es: %s", pClientes[auxIdCliente].apellido);
        printf("\nCUIT del cliente es: %s", pClientes[auxIdCliente].cuitCliente);
        printf("\nLa cantidad de ventas a cobrar que posee es: %d\n", cantVentasMayor);
    }
    return retorno;
}

int inf_ClienteConMasVentasTotales(Cliente* pClientes, Venta* pVentas, int limite, int limite2)
{
    int retorno = -1;
    int i;
    int cantVentasACobrar;
    int cantVentasCobradas;
    int cantVentasTotales;
    int cantVentasMayor;
    int auxIdCliente;
    if(pClientes != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pClientes[i].isEmpty==0)
            {
                cantVentasACobrar = inf_cantidadDeVentasDeClientes(pVentas, limite2, pClientes[i].ID);
                cantVentasCobradas = inf_cantidadDeVentasCobradasDeClientes(pVentas, limite2, pClientes[i].ID);
                if(i == 0)
                {
                    cantVentasTotales = cantVentasACobrar + cantVentasCobradas;
                    cantVentasMayor = cantVentasTotales;
                }
                if(cantVentasTotales > cantVentasMayor || cantVentasTotales == cantVentasMayor)
                {
                    cantVentasTotales = cantVentasCobradas + cantVentasACobrar;
                    cantVentasMayor = cantVentasTotales;
                    auxIdCliente = pClientes[i].ID;
                    retorno = 0;
                }
            }
        }
        printf("\nID del cliente es: %d", pClientes[auxIdCliente].ID);
        printf("\nNombre del cliente es: %s", pClientes[auxIdCliente].nombre);
        printf("\nApellido del cliente es: %s", pClientes[auxIdCliente].apellido);
        printf("\nCUIT del cliente es: %s", pClientes[auxIdCliente].cuitCliente);
        printf("\nLa cantidad de ventas a cobrar que posee es: %d\n", cantVentasMayor);
    }
    return retorno;
}

int inf_ClienteConMasAfiches(Cliente* pClientes, Venta* pVentas, int limite, int limite2)
{
    int retorno = -1;
    int i;
    int cantAfiches;
    int cantAfichesMayor;
    int auxIdCliente;
    if(pClientes != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pClientes[i].isEmpty==0)
            {
                cantAfiches = inf_cantidadDeAfichesACobrar(pVentas, limite2, pClientes[i].ID);
                if(i == 0)
                {
                    cantAfichesMayor = cantAfiches;
                }
                if(cantAfiches > cantAfichesMayor || cantAfiches == cantAfichesMayor)
                {
                    cantAfichesMayor = cantAfiches;
                    auxIdCliente = pClientes[i].ID;
                    retorno = 0;
                }
            }
        }
        printf("\nID del cliente es: %d", pClientes[auxIdCliente].ID);
        printf("\nNombre del cliente es: %s", pClientes[auxIdCliente].nombre);
        printf("\nApellido del cliente es: %s", pClientes[auxIdCliente].apellido);
        printf("\nCUIT del cliente es: %s", pClientes[auxIdCliente].cuitCliente);
        printf("\nLa cantidad de afiches a cobrar que posee es: %d\n", cantAfichesMayor);
    }
    return retorno;
}

int inf_ClienteConMasAfichesCobrados(Cliente* pClientes, Venta* pVentas, int limite, int limite2)
{
    int retorno = -1;
    int i;
    int cantAfiches;
    int cantAfichesMayor;
    int auxIdCliente;
    if(pClientes != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pClientes[i].isEmpty==0)
            {
                cantAfiches = inf_cantidadDeAfichesCobrados(pVentas, limite2, pClientes[i].ID);
                if(i == 0)
                {
                    cantAfichesMayor = cantAfiches;
                }
                if(cantAfiches > cantAfichesMayor || cantAfiches == cantAfichesMayor)
                {
                    cantAfichesMayor = cantAfiches;
                    auxIdCliente = pClientes[i].ID;
                    retorno = 0;
                }
            }
        }
        printf("\nID del cliente es: %d", pClientes[auxIdCliente].ID);
        printf("\nNombre del cliente es: %s", pClientes[auxIdCliente].nombre);
        printf("\nApellido del cliente es: %s", pClientes[auxIdCliente].apellido);
        printf("\nCUIT del cliente es: %s", pClientes[auxIdCliente].cuitCliente);
        printf("\nLa cantidad de afiches a cobrar que posee es: %d\n", cantAfichesMayor);
    }
    return retorno;
}
