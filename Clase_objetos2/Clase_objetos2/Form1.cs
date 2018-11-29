using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Clase_objetos2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btbsumar_Click(object sender, EventArgs e)
        {
            Numero n1 = new Numero();
            Numero n2 = new Numero();
            n1.SetNumero(2);
            n2.SetNumero(5);
            txt1.Text = Numero.Suma(n1, n2).ToString();
        }

        private void Resta_Click(object sender, EventArgs e)
        {
            Numero n1 = new Numero();
            Numero n2 = new Numero();
            n1.SetNumero(2);
            n2.SetNumero(5);
            txt1.Text = Numero.Resta(n1, n2).ToString();
        }

        private void Multiplicacion_Click(object sender, EventArgs e)
        {
            Numero n1 = new Numero();
            Numero n2 = new Numero();
            n1.SetNumero(2);
            n2.SetNumero(5);
            txt1.Text = Numero.Multiplicacion(n1, n2).ToString();
        }

        private void Dividir_Click(object sender, EventArgs e)
        {
            Numero n1 = new Numero();
            Numero n2 = new Numero();
            n1.SetNumero(2);
            n2.SetNumero(5);
            txt1.Text = Numero.Division(n1, n2).ToString();
        }

        private void Uno_Click(object sender, EventArgs e)
        {
        }
    }
}
