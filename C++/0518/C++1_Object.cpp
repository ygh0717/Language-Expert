#include <iostream>

#define ON_MAIN
#ifdef ON_MAIN

using namespace std;

class USERDATA2
{
public :		//�⺻���� private
	int nAge;
	char szName[32];

	void PrintData();
};

void USERDATA2 :: PrintData()
{
	printf("Ŭ���� : %d, %s\n", nAge, szName);
}

typedef struct USERDATA
{
	int nAge;
	char szName[32];
	//�Լ������� �߰�
	void (*Print)(USERDATA*);
}USERDATA;

void PrintData(USERDATA* pUser)
{
	printf("%d, %s\n", pUser->nAge, pUser->szName);
}

int main()
{
	//����ü
	{
		//������� �ڵ�
		USERDATA user = { 20, "ö��" };

		//printf("%d, %s\n", user.nAge, user.szName);	//1�ܰ�
		//PrintData(&user);							//2�ܰ�
		user.nAge = 30;
		user.Print = PrintData;
		user.Print(&user);							//3�ܰ�
	}

	//��ü
	{
		//����� �ڵ�
		USERDATA2 his = { 33, "ȫ�浿" };
		his.PrintData();
	}

	//Getter/Setter �Լ�
	{
		class CMyData
		{
		public :
			int m_nID;
			void PrintMoney()
			{
				cout << "�� ���� " << m_nMoney << "��� ������" << endl;
			}
		private :
			int m_nMoney;
		public :
			int GetMoney(void) const //����� �޼���
			{
				//m_nMoney++; //Err : readonly
				return m_nMoney; 
			};
			void SetMoney(int nParam) 
			{
				if(m_nMoney > 0) //check
					m_nMoney = nParam;
			}
		};

		CMyData a;
		a.SetMoney(100);
		a.PrintMoney();
		cout << a.GetMoney() << "��� �Դϴ�." << endl;
		
	}

	return 0;
}

#endif