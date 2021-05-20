#include <iostream>
//#define ON_MAIN
#ifdef ON_MAIN

using namespace std;

class CMyData_A
{
//private:
protected:
	char* m_pData;

public:
	CMyData_A() 
	{ 
		cout << "CMyData_A()" << endl; 
		m_pData = new char[32];
	}

	~CMyData_A()
	{ 
		cout << "~CMyData_A()" << endl;
		if(m_pData != NULL)
			delete[] m_pData;
	}
};

class CMyData_B : public CMyData_A
{
public:
	CMyData_B() { cout << "CMyData_B()" << endl; }
	~CMyData_B() { cout << "~CMyData_B()" << endl; }
};

class CMyData_C : public CMyData_B
{
public:
	CMyData_C() 
	{
		cout << "CMyData_C()" << endl;
	}

	~CMyData_C()
	{ 
		cout << "~CMyData_C()" << endl; 
		delete[] m_pData;
		m_pData = NULL;
	}
};
///////////////////////////////////////////////////////////////////////////////////
class C_Parent
{
public:
	C_Parent(){ cout << "C_Parent()" << endl; }
	C_Parent(int a) { cout << "C_Parent(int)" << endl; }
	C_Parent(double a) { cout << "C_Parent(double)" << endl; }

	int GetData() { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;

protected:
	void PrintData() { cout << "C_Parent::PrintData() : " << m_nData << endl; }
};

class C_Child : public C_Parent
{
public:
	C_Child() 
	{
		cout << "C_Child()" << endl; 
	}
	C_Child(int a) : C_Parent(a)
	{
		cout << "C_Child(int)" << endl;
	}
	C_Child(double a) : C_Parent()
	{
		cout << "C_Child(double)" << endl;
	}


	void TextFunc()
	{
		SetData(5);		//public
		PrintData();	//protected
	}
	//재정의(Overriding)
	void SetData(int nParam)
	{
		// 입력 데이터의 값을 보정하는 새로운 기능을 추가한다.
		if (nParam < 0)
			C_Parent::SetData(0);
		else if (nParam > 10)
			C_Parent::SetData(10);
		else
			C_Parent::SetData(nParam);
	}
};



int main()
{
	//생성자 선택
	{
		C_Child a;
		cout << "**********" << endl;
		C_Child b(5);
		cout << "**********" << endl;
		C_Child c(3.14);
	}

	//protected & 상속 설계...
	/*{
		//구형 클래스 - 값을 보정하는 기능이 없다.
		C_Parent a;
		a.SetData(15);
		cout << a.GetData() << endl;

		//신형 클래스(상속) - 값을 보정하는 기능이 있다.
		C_Child b;
		b.SetData(15);
		cout << b.GetData() << endl;

		C_Parent& ref = b;	//몸체가 신형이라도 ref가 부모로 시작되기때문에 구형함수실행
		ref.SetData(20);
		cout << ref.GetData() << endl;

		//a.PrintData();	//Err : protected 
		//a.TextFunc();		//protected의 접근 주의
	}*/

	//상속
	/*{
		cout << "*****Main Begin*****" << endl;
		CMyData_C xxx;
		cout << "*****Main End*****" << endl;
	}*/

	return 0;
}
#endif