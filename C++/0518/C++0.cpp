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

int TestFunc2(int nParam = 99)	//Default�� (�⺻��)
{
	return nParam * 2;
}

int TestFunc3(int a, int b, int c=8)	//Default�� (�⺻��) �ڿ��� ����...
{
	return c * 2;
}*/

inline int add(int a, int b) //�ζ��� �Լ�
{
	return a + b;
}
#define ADD(a,b)((a)+(b)) //��ũ�� �Լ�

int main()
{
	//�ζ��� �Լ� (vs ��ũ�� �Լ�)
	{
		cout << add(10, 20) << endl;
		cout << ADD(30, 40) << endl;
	}

	//���� ��� for��
	/*{
		int aList[5] = { 10,20,30,40,50 };
		int sum = 0;
		for (int i = 0; i< 5; i++)
		{
			sum = sum + aList[i];
		}
		cout << "��� 1 : " << sum << endl;
		
		sum = 0;
		for (auto n : aList)
		{		
			sum = sum + n;
		}
		cout <<"��� 2 : "<< sum << endl;
	}*/


	//���ڿ�
	/*{
		//char name[20] = "��ȣ��";	//"C"
		string name = "ȫ�浿";

		cout << name << endl;
		cout << name.size() << endl;

		name = "����ȯ";	//"C"-> strcpy()	���Կ����ڰ� �����ε��Ȱ�
		if (name == "����ȯ")	//"C"-> strcmp
			cout << "�̸���ġ!" << endl;
		else
			cout << "�̸�����ġ!" << endl;

		name = name + "����";	//"C"->strcat()
		cout << name << endl;
	}*/


	//���� �޸� ������
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

	//Default �Ű�����
	/*{
		int a = TestFunc2(10);
		cout << a << endl;

		int b = TestFunc2();
		cout << b << endl;

		int c = TestFunc3(2, 3);
		cout << c << endl;
	}*/

	//�Լ� �����ε�(=��������)  --> by ���Ӹͱ۸�(������)
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

	//������ vs ���۷���(����)
	/*int nData = 10;
	int* pt = &nData;	//�������� ����� �ʱ�ȭ
	int& ref = nData;	//���۷����� ����� �ʱ�ȭ

	cout << nData << endl;
	ref = 20;
	cout << nData << endl;
	nData = 30;
	cout << "����" << ref << endl;

	int nAnother = 1000;
	ref = nAnother;
	ref++;
	cout << ref << endl;
	
	//namespace ���*/
	/*Gugudan();
	TEST::Gugudan();

	cout << TEST::g_nData << endl;
	cout << ::g_nData << endl;
	cout << g_nData << endl;*/

	//auto ���
	/*int a = 10;
	int b(a);	//b = a;
	auto c(b);

	cout << a + b + c << endl;*/

	return 0;

	//cin & cout ���
	/*int age;
	cout << "���̸� �Է� : " << endl;
	cin >> age;


	char job[32];
	cout << "������ �Է� : " << endl;
	cin >> job;

	string name;
	cout << "�̸��� �Է� : " << endl;
	cin >> name;

	string nickname = "õ��";
	name = name + nickname;

	cout << "����� �̸��� " << name << "�̰�, "
		<< "���̴� " << age << "���̸�, "
		<< "������ " << job << "�Դϴ�." << endl;*/
}
#endif