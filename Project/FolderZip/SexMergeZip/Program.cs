using System;
using System.IO;
using System.IO.Compression;

using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ICSharpCode.SharpZipLib.Zip;

namespace SexMergeZip
{
    class Program
    {
        static void Main(string[] args)
        {
            Program p = new Program();
            //            string test = "안녕하세요";
            //p.fn_LogWrite(test, DirPath, FilePath);


            //p.file_Merge();


            //string FolderPath = @"CTC.FAS\E30";
            // FolderPath -> 좀 더 간략하게 ..
            string FolderPath = @"CTC.FAS\E30";
            p.create_folder(FolderPath);
            p.E30();
            FolderPath = @"CTC.FAS\E40";
            p.create_folder(FolderPath);
            p.E40();

            p.file_Merge();


        }

        private void E30()
        {
            string DirPath = @"CTC.FAS\E30";
            string FilePath = DirPath + "\\E30_" + DateTime.Now.ToString("yyyyMMddHH") + ".log";

            fn_LogWrite(DirPath, FilePath);
        }

        private void E40()
        {
            string DirPath = @"CTC.FAS\E40"; ;
            string FilePath = DirPath + "\\E40_" + DateTime.Now.ToString("yyyyMMddHH") + ".log";

            fn_LogWrite(DirPath, FilePath);
        }

        // 압축
        private void file_Merge()
        {
            try
            {
                // 원본 폴더에서 압축할 파일들을 복사해올 폴더를 생성
                //var directoryName = @"C:\ZipTest\" + "PROG"; 
                /*var directoryName = @"SEX" + "PROG";
                Directory.CreateDirectory(directoryName);
                
                var fileList = new List<string>
                {
                    "E30",
                    "E40"
                };

                foreach (var fileName in fileList)
                {
                    // 원본 파일 위치
                    var sourceFile = Path.Combine(@"C:\Users\ygh_0\OneDrive\Desktop\SexMergeZip\SexMergeZip\bin\Debug\CTC.FAS", fileName);
                    // 파일 이동할 곳 
                    var destFile = Path.Combine(directoryName, fileName);
                    // 1. 압축할 폴더로 데이터 복사 
                    File.Copy(sourceFile, destFile, true);
                }*/

                string directoryName = "PROG";
                Directory.CreateDirectory(directoryName);

                var fileList = new List<string>
                {
                    "E30.FAS",
                    "E40.FAS"
                };

                foreach (var fileName in fileList)
                {
                    // 원본 파일 위치
                    var sourceFile = Path.Combine(@"C:\Users\ygh_0\OneDrive\바탕 화면\SexMergeZip\SexMergeZip\bin\Debug", fileName);
                    // 파일 이동할 곳 
                    var destFile = Path.Combine(directoryName, fileName);
                    // 1. 압축할 폴더로 데이터 복사 
                    File.Copy(sourceFile, destFile, true);
                }

               // .zip 파일 패스 
               var zipPath = directoryName + ".7z";
                // 특정 폴더, .zip으로 압축 
                ZipFile.CreateFromDirectory(directoryName, zipPath);

                // 압축 끝난 폴더 삭제 
                Directory.Delete(directoryName, true);
                Console.WriteLine("파일 압축이 끝났습니다.");
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message.ToString());
                Console.WriteLine(e.StackTrace.ToString());
            }

            Console.ReadLine();
        }

        // 로그 생성
        private void fn_LogWrite(string DirPath, string FilePath)
        {
            string temp;

            DirectoryInfo di = new DirectoryInfo(DirPath);
            FileInfo fi = new FileInfo(FilePath);

            try
            {
                if (!di.Exists) Directory.CreateDirectory(DirPath);
                if (!fi.Exists)
                {
                    using (StreamWriter sw = new StreamWriter(FilePath))
                    {
                        temp = string.Format("[{0}] {1}", DateTime.Now, "하앙하앙하앙");
                        sw.WriteLine(temp);
                        sw.Close();
                    }
                }
                else
                {
                    using (StreamWriter sw = File.AppendText(FilePath))
                    {
                        temp = string.Format("[{0}] {1}", DateTime.Now + "하앙하앙하앙");
                        sw.WriteLine(temp);
                        sw.Close();
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }

        // 폴더 생성
        private void create_folder(string FolderPath)
        {
            DirectoryInfo di = new DirectoryInfo(FolderPath);

            // 만약 폴더가 존재하지 않다면
            if(di.Exists == false) di.Create();
        }

    }
}
