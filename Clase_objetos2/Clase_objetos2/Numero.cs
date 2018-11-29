using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase_objetos2
{
    class Numero
    {
        public int numero;

        public Numero() {}

        public void SetNumero(int numero)
        {
            this.numero = numero;
        }

        public static int Suma(Numero numero, Numero numero2)
        {
            int total = numero.numero + numero2.numero;
            return total;
        }

        public static int Resta(Numero numero, Numero numero2)
        {
            int total = numero.numero - numero2.numero;
            return total;
        }

        public static int Multiplicacion(Numero numero, Numero numero2)
        {
            int total = numero.numero * numero2.numero;
            return total;
        }

        public static int Division(Numero numero, Numero numero2)
        {
            int total = numero.numero / numero2.numero;
            return total;
        }
    }
}
