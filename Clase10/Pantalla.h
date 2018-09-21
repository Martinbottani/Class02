#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

struct S_Pantalla
{
    int id;
    int tipo;
    char nombre[32];
    char direccion[128];
    int isEmpty;
    float precio;
};
typedef struct S_Pantalla Pantalla;
#define TIPO_LED    0
#define TIPO_LCD    1


int pan_init(Pantalla* pantallas, int len);
int pan_buscarLugarLibre(Pantalla* pantallas, int len);
int pan_alta(Pantalla* pantallas, int len, int index);
int pan_modificar(Pantalla* pantallas, int len,
                                 int index);
int pan_buscarPantallaPorId(Pantalla* pantallas,
                                   int len, int id);

#endif // PANTALLA_H_INCLUDED
