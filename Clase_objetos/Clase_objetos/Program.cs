using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase_objetos
{
    class Program
    {
        static void Main(string[] args)
        {
            Persona persona1 = new Persona();
            Persona persona2 = new Persona("pepe", 20);

            Persona.Correr(persona2);
            persona1.SetNombre("Laura");
            Persona.Correr(persona1);
        }
    }
}
