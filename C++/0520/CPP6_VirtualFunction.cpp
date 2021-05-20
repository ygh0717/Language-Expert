#include <iostream>

//#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

class CAnimal//virtual class
{
public : 
	//순수가상함수(Pure virtual function)
	//  : 인터페이스 설계를 함
	//	: ->자식들이 구현해야 함
	virtual void Cry() = 0;

/*	
	//가상함수(virtual function)
	virtual void Cry()
	{
		cout << "운다" << endl;
	}
*/
	void TestFunc()
	{
		cout << "***TestFunc()***" << endl;
		Cry();
		cout << "****************" << endl;
	}
};

class CDog : public CAnimal
{
public:
	void Cry()
	{
		cout << "멍멍멍" << endl;
	}
};

class CCat : public CAnimal
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
		//virtual class은 객체를 생성할 수 없다
		//CAnimal zzz;//Error
	}
	//Reference + virtual
	{
		CCat a;
		a.Cry();

		CAnimal& ref = a;
		ref.Cry();
	}
	//return 0;
	//재정의 + virtual
	{
		CAnimal* p1 = new CCat;
		p1->Cry();		
		delete p1;

		CAnimal* p2 = new CDog;
		p2->Cry();
		delete p2;
	}
	//return 0;
	//재정의
	{
		CCat* a = new CCat;
		a->Cry();
		a->TestFunc();
		delete a;

		CDog* b = new CDog;
		b->Cry();
		b->TestFunc();
		delete b;
	}
	return 0;
}

#endif