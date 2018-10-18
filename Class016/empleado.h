#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    float altura;
    int idEmpleado;
}Empleado;

Empleado* emp_new(void);
Empleado* emp_newParametros(char* nombre, char* apellido, float altura);
void emp_delete(Empleado* this); //This = contexto, significa que borra ese o 1 empleado.
int emp_setNombre(Empleado* this, char* nombre);
int emp_getNombre(Empleado* this, char* nombre);
int emp_setApellido(Empleado* this, char* apellido);
int emp_getApellido(Empleado* this, char* apellido);
int emp_setAltura(Empleado* this, float altura);
int emp_getAltura(Empleado* this, float* altura); //Siempre recibe un puntero para guardar lo que acabo de obtener.
int emp_compareNombre(void* thisA, void* thisB); //Es igual a strcmp.
void emp_print(Empleado* this);
#endif // EMPLEADO_H_INCLUDED
