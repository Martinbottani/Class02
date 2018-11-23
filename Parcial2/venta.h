#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

struct S_Venta
{
  int id;
  char fechaVenta[128];
  char codigoProducto[128];
  int cantidad;
  float precioUnitario;
  char cuitCliente[128];
};
typedef struct S_Venta Venta;

Venta* new_venta(void);
Venta* new_ventaParametros(char* idStr,char* fechaStr,char* codigoStr,char* cantidadStr,char* cuitStr, char* precioStr);
int vent_delete(Venta* this);

int vent_setFecha(Venta* this, char* fecha);
int vent_getFecha(Venta* this, char* fecha);

int vent_setCodigo(Venta* this, char* codigo);
int vent_getCodigo(Venta* this, char* codigo);

int vent_setCantidad(Venta* this, char* cantidad);
int vent_getCantidad(Venta* this, int* cantidad);

int vent_setCuit(Venta* this, char* cuit);
int vent_getCuit(Venta* this, char* cuit);

int vent_setPrecio(Venta* this, char* precio);
int vent_getPrecio(Venta* this, float* precio);

int vent_setId(Venta* this, char* id);
int vent_getId(Venta* this, int* id);

#endif // VENTA_H_INCLUDED
