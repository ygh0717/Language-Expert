#include <iostream>
using namespace std;

//#define ON_MAIN
#ifdef ON_MAIN

#include "CMyString.h"
#include "CMyStringEx.h"

void TestFunc(const CMyString& param)
{
	cout << param.GetString() << endl;
}

int main()
{
	if (1)
	{
		CMyStringEx strTest("I love you you");
		cout << strTest.GetString() << endl;

		strTest.Append(" Do you?");
		cout << strTest.GetString() << endl;

		int n;
		n = strTest.Find("love");
		cout << n << endl;
	}
	if (0)
	{
		CMyString strData, strTest;
		strData.SetString("Hello");
		strTest.SetString("World");

		// ���� ����
		CMyString strNewData(strData);
		cout << strNewData.GetString() << endl;

		// �ܼ� ���� ������ ȣ��
		strNewData = strTest;
		cout << strNewData.GetString() << endl;

		////////////////////////////////
		CMyString strName;
		//strName = "�迬��";//Error
		strName = CMyString("�迬��");
		//cout << "�̸��� �Է��ϼ��� : ";
		//cin >> (*strName);//Error:
		cout << strName.GetString() << endl;
	}
	if (0)
	{
		CYourString strData, strTest;
		strData.SetString("Hello");
		strTest.SetString("World");
		//TestFunc(strData);
		cout << strData.GetString() << endl;
		cout << strTest.GetString() << endl;

		CYourString strNewData;
		strNewData = strTest;//�ܼ� ���Կ�����//�ּҸ� ������
		cout << strNewData.GetString() << endl;
		//////////////////////////////////////////
		//strData = CMyString("�迬��");//Error:
		strData.SetString("�迬��");
		cout << strData.GetString() << endl;

		//////////////////////////////////////////
		//char temp[20];
		//cout << "�̸��� �Է��ϼ��� : ";
		//cin >> temp;
		//cin >> strData;//Error:

		//strData.SetString(temp);
		//cout << strData.GetString() << endl;
	}
	return 0;
}

#endif