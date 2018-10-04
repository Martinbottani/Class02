int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit);
int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);

int informar_orderArrayByDescription(Pantalla* pantallaArray[],int limite);
int informar_pantallasValorMenor(Pantalla* pantallaArray, int limite);
int pantalla_mostrar2(Pantalla* pantallaArray,int limite);
int pantalla_mostrarValordePantallaMenor(Pantalla* pantallaArray,int limite, int indice);
