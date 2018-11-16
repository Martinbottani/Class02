#ifndef COMPRA_H_INCLUDED
#define COMPRA_H_INCLUDED

struct S_Compra
{
  char nombreCliente[128];
  int idProducto;
  float precioUnitario;
  int unidades;
  float iva;
  float montoTotal;
};
typedef struct S_Compra Compra;

void com_calcularMonto(void* p);

Compra* employee_new();
Compra* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr, char* ivaStr);
int employee_delete();

int employee_setId(Compra* this,char* id);
int employee_getId(Compra* this,int* id);

int employee_setNombre(Compra* this,char* nombre);
int employee_getNombre(Compra* this,char* nombre);

int employee_setHorasTrabajadas(Compra* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Compra* this,int* horasTrabajadas);

int employee_setSueldo(Compra* this,char* sueldo);
int employee_getSueldo(Compra* this,float* sueldo);

int employee_setIva(Compra* this, char* iva);
int employee_getIva(Compra* this, float* iva);

//void employee_mostrar(LinkedList* pArrayListCompra);

#endif // COMPRA_H_INCLUDED
