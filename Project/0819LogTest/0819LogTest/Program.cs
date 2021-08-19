using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0819LogTest
{
    class Program
    {
        static void Main(string[] args)
        {
            AddLog(IssueList.FAS_Error, LogType.CTC, "Input Info..!");
        }

        // 로그 함수
        public static void AddLog(IssueList issueList, LogType log, string message)
        {
            string logName = string.Format("{0}_{1}.txt", log, DateTime.Now.ToString("yyyyMMddHH"));
            string logDir = Path.Combine(Environment.CurrentDirectory, "Log");
            //string logFile = Path.Combine(logDir, "log.txt");
            string logFile = Path.Combine(logDir, logName);

            if (Directory.Exists(logDir) == false) Directory.CreateDirectory(logDir);
            if (File.Exists(logFile) == false) File.Create(logFile);
            //
            //
            //
            // if -> LogType, IssueList 나누기
            using (var sw = new StreamWriter(logFile, true, Encoding.Default))
            {
                sw.WriteLine(string.Format("{0} [{1}] {2}", DateTime.Now.ToString("HH:mm:ss"), issueList, message));
                sw.Close();
            }
        }

        public enum LogType
        {
            // Add
            CTC,
            TMC,
            PM2,
            PM3,
            EFEM,
        }

        public enum IssueList
        {
            FAS_Error,
            TM_Error,
            PM_Error,
        }

        
    }
}
