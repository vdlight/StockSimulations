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

        public static int y = 6;


        public Form1()
        {
            InitializeComponent();
            stocks_chart.Series.Add("SBB");
            stocks_chart.Series["SBB"].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            stocks_chart.Series["SBB"].Color = System.Drawing.Color.Green;
            stocks_chart.Series.Add("Nibe");
            stocks_chart.Series["Nibe"].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            stocks_chart.Series["Nibe"].Color = System.Drawing.Color.Red;


        }

        private void button1_Click(object sender, EventArgs e)
        {
            update_timer.Enabled = !update_timer.Enabled;
            button1.BackColor = update_timer.Enabled ? System.Drawing.Color.Green : System.Drawing.SystemColors.Control;



        }

        private void update_timer_Tick(object sender, EventArgs e)
        {
            stocks_chart.Series["SBB"].Points.AddXY("1", "1000"); 
            stocks_chart.Series["SBB"].Points.AddXY("2", "2000");
            stocks_chart.Series["SBB"].Points.AddXY("3", "3000");
            stocks_chart.Series["SBB"].Points.AddXY("4", "4000");
            stocks_chart.Series["SBB"].Points.AddXY("5", "5000");

            stocks_chart.Series["Nibe"].Points.Clear();
            stocks_chart.Series["Nibe"].Points.AddXY("1", "1000");
            stocks_chart.Series["Nibe"].Points.AddXY("2", "2000");
            stocks_chart.Series["Nibe"].Points.AddXY("3", "3000");
            stocks_chart.Series["Nibe"].Points.AddXY("4", "100");
            stocks_chart.Series["Nibe"].Points.AddXY("5", "50");

        }

        //private void button1_Click(object sender, EventArgs e)
        //{

        //    //debug..bin .. Gui..StockSimulations
        //    if(File.Exists("..\\..\\..\\DynamicLinkLibrary\\x64\\Debug\\DynamicLinkLibrary.dll"))
        //    {
        //        textBox1.Text =     Convert.ToString(HelloWorld()); 

        //    }
        //    else
        //    {
        //        textBox1.Text = "No";
        //    }
        //}
    }
}
