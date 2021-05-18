#include <iostream>
using namespace std;

#define ON_MAIN
#ifdef ON_MAIN

//using namespace TEST;
/*
int g_nData = 1000;

void Gugudan()
{
	cout << "Global::Gugudan()" << endl;
}

namespace TEST
{
	int g_nData = 100;

	void Gugudan(void)
	{
		cout << "TEST::Gugudan()" << endl;
	}
}

void TestFuncRef1(int rParam)
{
	rParam = 100;
}
void TestFuncRef2(int& rParam)
{
	rParam = 100;
}
void TestFuncRef3(int* rParam)
{
	*rParam = 100;
}

int Sum(int a, int b)
{
	return a + b;
}
int Sum(int a, int b, int c)
{
	return a + b + c;
}
double Sum(double a, double b)
{
	return a + b;
}

int TestFunc2(int nParam = 99)	//Default값 (기본값)
{
	return nParam * 2;
}

int TestFunc3(int a, int b, int c=8)	//Default값 (기본값) 뒤에서 부터...
{
	return c * 2;
}*/

inline int add(int a, int b) //인라인 함수
{
	return a + b;
}
#define ADD(a,b)((a)+(b)) //매크로 함수

int main()
{
	//인라인 함수 (vs 매크로 함수)
	{
		cout << add(10, 20) << endl;
		cout << ADD(30, 40) << endl;
	}

	//범위 기반 for문
	/*{
		int aList[5] = { 10,20,30,40,50 };
		int sum = 0;
		for (int i = 0; i< 5; i++)
		{
			sum = sum + aList[i];
		}
		cout << "결과 1 : " << sum << endl;
		
		sum = 0;
		for (auto n : aList)
		{		
			sum = sum + n;
		}
		cout <<"결과 2 : "<< sum << endl;
	}*/


	//문자열
	/*{
		//char name[20] = "강호동";	//"C"
		string name = "홍길동";

		cout << name << endl;
		cout << name.size() << endl;

		name = "박태환";	//"C"-> strcpy()	대입연산자가 오버로딩된거
		if (name == "박태환")	//"C"-> strcmp
			cout << "이름일치!" << endl;
		else
			cout << "이름불일치!" << endl;

		name = name + "만세";	//"C"->strcat()
		cout << name << endl;
	}*/


	//동적 메모리 연산자
	/*{
		//1.=========================
		int* p1 = new int;
		*p1 = 10;
		cout << *p1 << endl;
		delete p1;
		//2.=========================
		int* p2 = new int(100);
		cout << *p2 << endl;
		delete p2;
		//3.=========================
		int* arr = new int[5];
		for (int i = 0; i < 5; i++)
		{
			arr[i] = i * 10;
			cout << arr[i] << endl;
		}
		delete[] arr;
	}*/

	//Default 매개변수
	/*{
		int a = TestFunc2(10);
		cout << a << endl;

		int b = TestFunc2();
		cout << b << endl;

		int c = TestFunc3(2, 3);
		cout << c << endl;
	}*/

	//함수 오버로딩(=다중정의)  --> by 네임맹글링(난도질)
	/*{
		cout << Sum(3, 4) << endl;
		cout << Sum(3, 4, 5) << endl;
		cout << Sum(3.3, 4.4) << endl;
	}*/

	//Call by Reference
	/*{
		int nData = 0;

		TestFuncRef1(nData);
		cout << "1."<< nData << endl;

		nData = 0;
		TestFuncRef2(nData);
		cout << "2." << nData << endl;

		nData = 0;
		TestFuncRef3(&nData);
		cout << "2." << nData << endl;
	}*/

	//포인터 vs 래퍼런스(별명)
	/*int nData = 10;
	int* pt = &nData;	//포인터의 선언과 초기화
	int& ref = nData;	//레퍼런스의 선언과 초기화

	cout << nData << endl;
	ref = 20;
	cout << nData << endl;
	nData = 30;
	cout << "여기" << ref << endl;

	int nAnother = 1000;
	ref = nAnother;
	ref++;
	cout << ref << endl;
	
	//namespace 사용*/
	/*Gugudan();
	TEST::Gugudan();

	cout << TEST::g_nData << endl;
	cout << ::g_nData << endl;
	cout << g_nData << endl;*/

	//auto 사용
	/*int a = 10;
	int b(a);	//b = a;
	auto c(b);

	cout << a + b + c << endl;*/

	return 0;

	//cin & cout 사용
	/*int age;
	cout << "나이를 입력 : " << endl;
	cin >> age;


	char job[32];
	cout << "직업을 입력 : " << endl;
	cin >> job;

	string name;
	cout << "이름을 입력 : " << endl;
	cin >> name;

	string nickname = "천재";
	name = name + nickname;

	cout << "당신의 이름은 " << name << "이고, "
		<< "나이는 " << age << "살이며, "
		<< "직업은 " << job << "입니다." << endl;*/
}
#endif