using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase_objetos
{
    class Persona
    {
        public String nombre;
        public int edad;

        public Persona() {}

        public Persona(string nombre, int edad)
        {
            this.edad = edad;
            this.nombre = nombre;
        }

        public void SetNombre(string nombre)
        {
            this.nombre = nombre;
        }

        public static void Correr(Persona p1)
        {
            Console.Write("La persona {0} esta corriendo", p1.nombre);
            Console.ReadLine();
        }
    }
}
