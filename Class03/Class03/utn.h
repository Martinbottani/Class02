#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
/**
    utn_getNumero : pide un entero al usuario.
    @param pEdad: puntero de edad.
    @param reint: cantidad de intentos.
    @param msg: Mensaje 1.
    @param msgError: Mensaje de Error 1.
    @param msgError2: Mensaje de Error 2.
    @return : 0 Ok, -1 Error.
*/

int utn_getNumero(int* pRes, int reint, char* msg, char* msgError, char* msgError2, int max, int min);
int utn_getDecimal(float* pRes, int reint, char* msg, char* msgError, char* msgErro2, float max, float min);

#endif // UTN_H_INCLUDED
