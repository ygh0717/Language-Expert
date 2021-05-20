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

		// 복사 생성
		CMyString strNewData(strData);
		cout << strNewData.GetString() << endl;

		// 단순 대입 연산자 호출
		strNewData = strTest;
		cout << strNewData.GetString() << endl;

		////////////////////////////////
		CMyString strName;
		//strName = "김연아";//Error
		strName = CMyString("김연아");
		//cout << "이름을 입력하세요 : ";
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
		strNewData = strTest;//단순 대입연산자//주소만 복사함
		cout << strNewData.GetString() << endl;
		//////////////////////////////////////////
		//strData = CMyString("김연아");//Error:
		strData.SetString("김연아");
		cout << strData.GetString() << endl;

		//////////////////////////////////////////
		//char temp[20];
		//cout << "이름을 입력하세요 : ";
		//cin >> temp;
		//cin >> strData;//Error:

		//strData.SetString(temp);
		//cout << strData.GetString() << endl;
	}
	return 0;
}

#endif