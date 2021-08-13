using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Console;

namespace ThreadTest
{
    public partial class Form1 : Form
    {
        Thread 호랑이 = null; // thread 이름 지정
        Thread 독수리 = null;

        
        
        private void _호랑이()
        {
            string s = "호랑이";
            int n = 0;
            for (; ; )
            {
                n++;
                
                Console.WriteLine(n + "번" + s);
                Thread.Sleep(500);
            }
        }
        private void _독수리()
        {
            string s = "독수리";
            int n = 0;
            for (; ; )
            {
                n++;
                Console.WriteLine(n + "번" + s);
                Thread.Sleep(500);

            }
        }

        public Form1()
        {
            InitializeComponent();
        }

        // 생성
        private void button1_Click(object sender, EventArgs e)
        {
            if (호랑이 == null) // TestThread에 지정이 안되어 있으면 지정함.
            {
                호랑이 = new Thread(_호랑이);
                Console.WriteLine(호랑이.ThreadState);
            }
            if (독수리 == null) // TestThread에 지정이 안되어 있으면 지정함.
            {
                독수리 = new Thread(_독수리);
                Console.WriteLine(독수리.ThreadState);

                List<string> list = new List<string>();

                list.Add((독수리.ThreadState).ToString());

            }
        }

        // 시작
        private void button2_Click(object sender, EventArgs e)
        {
            Console.WriteLine(독수리.ThreadState);
            Console.WriteLine(독수리.ThreadState);

            호랑이.Start();
            독수리.Start();
            Console.WriteLine(호랑이.ThreadState);
            Console.WriteLine(독수리.ThreadState);

        }

        // 정지
        private void button3_Click(object sender, EventArgs e)
        {
            Console.WriteLine(호랑이.ThreadState);
            Console.WriteLine(독수리.ThreadState);


            //호랑이.Suspend();
            Console.WriteLine(호랑이.ThreadState);
            //독수리.Suspend();
            Console.WriteLine(독수리.ThreadState);
        }

        // 재시작
        private void button4_Click(object sender, EventArgs e)
        {
            Console.WriteLine(호랑이.ThreadState);
            Console.WriteLine(독수리.ThreadState);

            호랑이.Resume();
            Console.WriteLine(호랑이.ThreadState);
            독수리.Resume();
            Console.WriteLine(독수리.ThreadState);
        }

        // 중단
        private void button5_Click(object sender, EventArgs e)
        {
            Console.WriteLine(호랑이.ThreadState);
            Console.WriteLine(독수리.ThreadState);

            호랑이.Abort();
            Console.WriteLine(호랑이.ThreadState);
            독수리.Abort();
            Console.WriteLine(독수리.ThreadState);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            listView1.BeginUpdate();

            listView1.View = View.Details;


        }

        private void ThreadListView(ListView lv, Thread[] thread)
        {
            lv.BeginUpdate();

            lv.View = View.Details;

            lv.GridLines = true;
            lv.FullRowSelect = true;
            lv.CheckBoxes = true;

            foreach (var th in thread)
            {
                ListViewItem lvi = new ListViewItem(th.Name);

                lv.Items.Add(lvi);
            }

            lv.Columns.Add("스레드명", 200, HorizontalAlignment.Left);
            lv.Columns.Add("상태", 200, HorizontalAlignment.Left);
            lv.Columns.Add("ON | OFF", 200, HorizontalAlignment.Left);

            lv.EndUpdate();

            this.Refresh();

        }

        private void ThreadData(ListView lv)
        {
                String[] sex = { 호랑이.Name , 독수리.Name};
                ListViewItem lvi = new ListViewItem(sex);
                lv.Items.Add(lvi);

                lvi = new ListViewItem(new String[] { 호랑이.GetHashCode().ToString() , 독수리.GetHashCode().ToString()});
                lv.Items.Add(lvi);
        }
    }
}
