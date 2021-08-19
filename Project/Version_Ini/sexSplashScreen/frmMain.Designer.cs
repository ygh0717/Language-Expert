
namespace sexSplashScreen
{
    partial class frmMain
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
            this.metroTabControl1 = new MetroFramework.Controls.MetroTabControl();
            this.metroTabPage1 = new MetroFramework.Controls.MetroTabPage();
            this.Btn_Issue = new MetroFramework.Controls.MetroButton();
            this.Btn_Log = new MetroFramework.Controls.MetroButton();
            this.metroTabPage2 = new MetroFramework.Controls.MetroTabPage();
            this.Btn_File = new MetroFramework.Controls.MetroButton();
            this.metroTabControl1.SuspendLayout();
            this.metroTabPage1.SuspendLayout();
            this.metroTabPage2.SuspendLayout();
            this.SuspendLayout();
            // 
            // metroTabControl1
            // 
            this.metroTabControl1.Controls.Add(this.metroTabPage1);
            this.metroTabControl1.Controls.Add(this.metroTabPage2);
            this.metroTabControl1.Location = new System.Drawing.Point(6, 10);
            this.metroTabControl1.Name = "metroTabControl1";
            this.metroTabControl1.SelectedIndex = 1;
            this.metroTabControl1.Size = new System.Drawing.Size(816, 499);
            this.metroTabControl1.TabIndex = 0;
            this.metroTabControl1.UseSelectable = true;
            // 
            // metroTabPage1
            // 
            this.metroTabPage1.Controls.Add(this.Btn_Issue);
            this.metroTabPage1.Controls.Add(this.Btn_Log);
            this.metroTabPage1.HorizontalScrollbarBarColor = true;
            this.metroTabPage1.HorizontalScrollbarHighlightOnWheel = false;
            this.metroTabPage1.HorizontalScrollbarSize = 10;
            this.metroTabPage1.Location = new System.Drawing.Point(4, 38);
            this.metroTabPage1.Name = "metroTabPage1";
            this.metroTabPage1.Size = new System.Drawing.Size(808, 457);
            this.metroTabPage1.TabIndex = 0;
            this.metroTabPage1.Text = "로그 취합";
            this.metroTabPage1.VerticalScrollbarBarColor = true;
            this.metroTabPage1.VerticalScrollbarHighlightOnWheel = false;
            this.metroTabPage1.VerticalScrollbarSize = 10;
            // 
            // Btn_Issue
            // 
            this.Btn_Issue.Location = new System.Drawing.Point(135, 15);
            this.Btn_Issue.Name = "Btn_Issue";
            this.Btn_Issue.Size = new System.Drawing.Size(116, 49);
            this.Btn_Issue.TabIndex = 3;
            this.Btn_Issue.Text = "Issue";
            this.Btn_Issue.UseSelectable = true;
            this.Btn_Issue.Click += new System.EventHandler(this.Btn_Issue_Click);
            // 
            // Btn_Log
            // 
            this.Btn_Log.Location = new System.Drawing.Point(13, 15);
            this.Btn_Log.Name = "Btn_Log";
            this.Btn_Log.Size = new System.Drawing.Size(116, 49);
            this.Btn_Log.TabIndex = 2;
            this.Btn_Log.Text = "로그 취합";
            this.Btn_Log.UseSelectable = true;
            this.Btn_Log.Click += new System.EventHandler(this.Btn_Log_Click);
            // 
            // metroTabPage2
            // 
            this.metroTabPage2.Controls.Add(this.Btn_File);
            this.metroTabPage2.HorizontalScrollbarBarColor = true;
            this.metroTabPage2.HorizontalScrollbarHighlightOnWheel = false;
            this.metroTabPage2.HorizontalScrollbarSize = 10;
            this.metroTabPage2.Location = new System.Drawing.Point(4, 38);
            this.metroTabPage2.Name = "metroTabPage2";
            this.metroTabPage2.Size = new System.Drawing.Size(808, 457);
            this.metroTabPage2.TabIndex = 1;
            this.metroTabPage2.Text = "파일 취합";
            this.metroTabPage2.VerticalScrollbarBarColor = true;
            this.metroTabPage2.VerticalScrollbarHighlightOnWheel = false;
            this.metroTabPage2.VerticalScrollbarSize = 10;
            // 
            // Btn_File
            // 
            this.Btn_File.Location = new System.Drawing.Point(13, 15);
            this.Btn_File.Name = "Btn_File";
            this.Btn_File.Size = new System.Drawing.Size(116, 49);
            this.Btn_File.TabIndex = 3;
            this.Btn_File.Text = "파일 취합";
            this.Btn_File.UseSelectable = true;
            this.Btn_File.Click += new System.EventHandler(this.Btn_File_Click);
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(831, 517);
            this.Controls.Add(this.metroTabControl1);
            this.Name = "frmMain";
            this.Text = "frmMain";
            this.metroTabControl1.ResumeLayout(false);
            this.metroTabPage1.ResumeLayout(false);
            this.metroTabPage2.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private MetroFramework.Controls.MetroTabControl metroTabControl1;
        private MetroFramework.Controls.MetroTabPage metroTabPage1;
        private MetroFramework.Controls.MetroButton Btn_Issue;
        private MetroFramework.Controls.MetroButton Btn_Log;
        private MetroFramework.Controls.MetroTabPage metroTabPage2;
        private MetroFramework.Controls.MetroButton Btn_File;
    }
}