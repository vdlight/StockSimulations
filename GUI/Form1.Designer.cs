namespace GUI
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea2 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend2 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.stocks_chart = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.wallet_chart = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.update_timer = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.stocks_chart)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.wallet_chart)).BeginInit();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(962, 58);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(361, 20);
            this.textBox1.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(1070, 168);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 1;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // stocks_chart
            // 
            chartArea1.Name = "ChartArea1";
            this.stocks_chart.ChartAreas.Add(chartArea1);
            legend1.Name = "Legend1";
            this.stocks_chart.Legends.Add(legend1);
            this.stocks_chart.Location = new System.Drawing.Point(12, 58);
            this.stocks_chart.Name = "stocks_chart";
            this.stocks_chart.Size = new System.Drawing.Size(917, 305);
            this.stocks_chart.TabIndex = 2;
            this.stocks_chart.Text = "Stocks";
            // 
            // wallet_chart
            // 
            chartArea2.Name = "ChartArea1";
            this.wallet_chart.ChartAreas.Add(chartArea2);
            legend2.Name = "Legend1";
            this.wallet_chart.Legends.Add(legend2);
            this.wallet_chart.Location = new System.Drawing.Point(12, 415);
            this.wallet_chart.Name = "wallet_chart";
            this.wallet_chart.Size = new System.Drawing.Size(917, 305);
            this.wallet_chart.TabIndex = 3;
            this.wallet_chart.Text = "Value";
            // 
            // update_timer
            // 
            this.update_timer.Interval = 3000;
            this.update_timer.Tick += new System.EventHandler(this.update_timer_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1483, 823);
            this.Controls.Add(this.wallet_chart);
            this.Controls.Add(this.stocks_chart);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.stocks_chart)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.wallet_chart)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.DataVisualization.Charting.Chart stocks_chart;
        private System.Windows.Forms.DataVisualization.Charting.Chart wallet_chart;
        private System.Windows.Forms.Timer update_timer;
    }
}

