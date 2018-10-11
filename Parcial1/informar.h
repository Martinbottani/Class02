#ifndef INFORMAR_H_INCLUDED
#define INFORMAR_H_INCLUDED

int inf_cantidadDeVentasDeClientes(Venta* pVentas,int limite,int id);
int inf_cantidadDeVentasCobradasDeClientes(Venta* pVentas,int limite,int id);
int inf_cantidadDeAfichesACobrar(Venta* pVentas,int limite,int id);
int inf_cantidadDeAfichesCobrados(Venta* pVentas,int limite,int id);
int inf_ClienteConMasVentas(Cliente* pClientes, Venta* pVentas, int limite, int limite2);
int inf_ClienteConMasVentasCobradas(Cliente* pClientes, Venta* pVentas, int limite, int limite2);
int inf_ClienteConMasVentasTotales(Cliente* pClientes, Venta* pVentas, int limite, int limite2);
int inf_ClienteConMasAfiches(Cliente* pClientes, Venta* pVentas, int limite, int limite2);
int inf_ClienteConMasAfichesCobrados(Cliente* pClientes, Venta* pVentas, int limite, int limite2);
#endif // INFORMAR_H_INCLUDED
