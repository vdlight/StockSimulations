using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace GUI
{
    public partial class Form1 : Form
    {
        [DllImport("DynamicLinkLibrary.dll")]
        public static extern int HelloWorld();



        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
            //debug..bin .. Gui..StockSimulations
            if(File.Exists("..\\..\\..\\DynamicLinkLibrary\\x64\\Debug\\DynamicLinkLibrary.dll"))
            {
                textBox1.Text =     Convert.ToString(HelloWorld()); 
     
            }
            else
            {
                textBox1.Text = "No";
            }
        }
    }
}
