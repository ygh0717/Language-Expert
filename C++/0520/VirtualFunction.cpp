//�����Լ�
#include <iostream>
//#define ON_MAIN
#ifdef ON_MAIN

using namespace std;

class C_Animal	//virtual class
{
public:

	//���������Լ�(Pure virtual) 
	//: �������̽� ������ -> �ڽĵ��� �����ؾ���
	virtual void Cry() = 0;

	//�����Լ�
	/*virtual void Cry()
	{
		cout << "����" << endl;
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
		cout << "�۸۸�" << endl;
	}
};

class C_Cat : public C_Animal
{
public:
	void Cry()
	{
		cout << "�߿˾߿�" << endl;
	}
};

int main()
{
	//virtual class(pure virtual function)
	{
		C_Animal zzz;	//virtual class�� ��ü�� ����� ����.
	}

	//Reference + virtual
	/*{
		C_Cat a;
		a.Cry();

		C_Animal& ref = a;
		ref.Cry();
	}*/

	//������ + virtual -> virtual �� ����, ����
	/*{
		C_Animal* p1 = new C_Cat;
		p1->Cry();
		delete p1;

		C_Animal* p2 = new C_Dog;
		p2->Cry();
		delete p2;
		
	}*/
	//������
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