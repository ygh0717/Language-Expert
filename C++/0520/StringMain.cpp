#include<iostream>
#include"CMyString.h"
#include"CMyStringEx.h"

#define ON_MAIN
using namespace std;
#ifdef ON_MAIN 

int main(void)
{
    //CMyStringEx ���
    {
        CMyStringEx strMsg("I love you"); //�����ڿ��� �ֱ�.
        cout << strMsg.GetString() << endl;

        strMsg.Append(" Do you?");
        cout << strMsg.GetString() << endl;

        int n;
        n = strMsg.Find("love");
        cout << n << endl;
    }
    return 0;

    //CMyString ���
    /*
    string name = "kkk";
    name = name + "����";
    cout << name << endl;
    */

    CMyString strData;
    strData.SetString("������");
    cout << strData.GetString() << endl;

    //1 ���ʿ��� �޸� �ذ��ʿ�.
    strData.SetString("�ٺ��ٹ�");
    cout << strData.GetString() << endl;

    //2 �������� �ذ� �ʿ� 
    CMyString strData2 = strData; //== CMyString strData2(strData);
    cout << strData2.GetString() << endl;

    //3. ���ڿ��� �־ ����� ������ ����.
    //CMyString strData33("ȣ��");
    //cout << strData33.GetString() << endl;

    //4.���Կ�����
    CMyString strData4 = strData;
    cout << strData4.GetString() << endl;

    return 0;
}
#endif