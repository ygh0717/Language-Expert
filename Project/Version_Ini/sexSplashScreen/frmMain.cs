using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

// 192.168.1.15

namespace sexSplashScreen
{
    public partial class frmMain : MetroFramework.Forms.MetroForm
    {
        public frmMain()
        {
            /// Loading
            /// Version
            ///
            Thread t = new Thread(new ThreadStart(Loading));
            t.Start();

            InitializeComponent();

            for (int i = 0; i < 100; i++)
                Thread.Sleep(10);   // Demo
            t.Abort();  // Complete

            ///
            /// ini File
            ///
            LoadIniFIle();
            SaveIniFile();

        }

        void Loading()
        {
            frmSplashScreen frm = new frmSplashScreen();
            Application.Run(frm);
        }

        /// <summary>
        /// 
        /// [ ini File ]
        /// 
        /// </summary>
        /// <param name="sAppName"></param>
        /// <param name="sKeyName"></param>
        /// <param name="sDefault"></param>
        /// <param name="sReturnedString"></param>
        /// <param name="nSize"></param>
        /// <param name="sFileName"></param>
        /// <returns></returns>
        /// 
        [DllImport("kernel32")]

        public static extern int GetPrivateProfileString(string sAppName, string sKeyName, string sDefault, StringBuilder sReturnedString, int nSize, string sFileName);

        [DllImport("kernel32")]

        public static extern int WritePrivateProfileString(string sAppName, string sKeyName, string sValue, string sFileName);

        public static string sINIPath = Environment.CurrentDirectory + "\\Setting.ini";
        //@"C:\Datalog\Plog\Setting.ini"; // Environment.CurrentDirectory + "\\Config.ini";

        /// <summary>

        /// Module IP

        /// </summary>

        public static string sModuleIP = String.Empty;

        /// <summary>

        /// Module Port

        /// </summary>

        public static string sModulePort = String.Empty;

        /// <summary>

        /// Module Name

        /// </summary>

        public static string sModuleName = String.Empty;

        /// <summary>

        /// Module Error

        /// </summary>

        public static string sModuleErr = String.Empty;

        /// <summary>

        /// File Path

        /// </summary>

        public static string sFilePath = String.Empty;

        //false 틀리지않다 true 틀리다 

        public static bool bCheck = false;

        public static void LoadIniFIle()

        {

            StringBuilder Buf = new StringBuilder(1024);

            GetPrivateProfileString("Module", "IP", "192.168.1.15", Buf, 1024, sINIPath);

            sModuleIP = Buf.ToString();

            GetPrivateProfileString("Module", "PORT", "9000", Buf, 1024, sINIPath);

            sModulePort = Buf.ToString();

            GetPrivateProfileString("Module", "NAME", "CTC", Buf, 1024, sINIPath);

            sModuleName = Buf.ToString();

            GetPrivateProfileString("Module", "ERROR", "FAS_Error", Buf, 1024, sINIPath);

            sModuleErr = Buf.ToString();

            GetPrivateProfileString("Module", "FILEPATH", @"D:\Datalog\Plog\CTC.FAS\E30", Buf, 1024, sINIPath);

            sFilePath = Buf.ToString();

        }

        public static void SaveIniFile()

        {

            WritePrivateProfileString("Module", "IP", sModuleIP, sINIPath);

            WritePrivateProfileString("Module", "PORT", sModulePort, sINIPath);

            WritePrivateProfileString("Module", "NAME", sModuleName, sINIPath);

            WritePrivateProfileString("Module", "ERROR", sModuleErr, sINIPath);

            WritePrivateProfileString("Module", "FILEPATH", sFilePath, sINIPath);


        }

        public static void WriteUpdatingInfo(bool b)

        {

            string sVal = b == true ? "true" : "false";

            WritePrivateProfileString("UPDATE", "UPDATING", sVal, sINIPath);

        }

        public static string ReadUpdatingInfo()

        {

            StringBuilder Buf = new StringBuilder(1024);

            GetPrivateProfileString("UPDATE", "UPDATING", "", Buf, 1024, sINIPath);

            // 구현 6 : 12시
            if(DateTime.Now.Hour.ToString() == "12")
            {

            }

            return Buf.ToString();

        }

        // 로그 취합
        private void Btn_Log_Click(object sender, EventArgs e)
        {

        }

        // 이슈 리스트 -> ?
        private void Btn_Issue_Click(object sender, EventArgs e)
        {

        }

        // 파일 취합 -> 압축
        private void Btn_File_Click(object sender, EventArgs e)
        {

        }
    }
}
