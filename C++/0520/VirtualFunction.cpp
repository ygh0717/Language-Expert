//가상함수
#include <iostream>
//#define ON_MAIN
#ifdef ON_MAIN

using namespace std;

class C_Animal	//virtual class
{
public:

	//순수가상함수(Pure virtual) 
	//: 인터페이스 설계함 -> 자식들이 구현해야함
	virtual void Cry() = 0;

	//가상함수
	/*virtual void Cry()
	{
		cout << "응애" << endl;
	}*/

	void TestFunc()
	{
		cout << "***TestFunc()***" << endl;
		Cry();
		cout << "****************" << endl;
	}
};

class C_Dog : public C_Animal
{
public:
	void Cry()
	{
		cout << "멍멍멍" << endl;
	}
};

class C_Cat : public C_Animal
{
public:
	void Cry()
	{
		cout << "야옹야옹" << endl;
	}
};

int main()
{
	//virtual class(pure virtual function)
	{
		C_Animal zzz;	//virtual class는 객체를 만들수 없다.
	}

	//Reference + virtual
	/*{
		C_Cat a;
		a.Cry();

		C_Animal& ref = a;
		ref.Cry();
	}*/

	//재정의 + virtual -> virtual 전 응애, 응애
	/*{
		C_Animal* p1 = new C_Cat;
		p1->Cry();
		delete p1;

		C_Animal* p2 = new C_Dog;
		p2->Cry();
		delete p2;
		
	}*/
	//재정의
	/*{
		C_Cat* a = new C_Cat;
		a->Cry();
		a->TestFunc();
		delete a;
		C_Dog* b= new C_Dog;
		b->Cry();
		b->TestFunc();
		delete b;
	}*/
	return 0;
}

#endif