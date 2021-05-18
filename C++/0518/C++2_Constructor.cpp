#include<iostream>

#define ON_MAIN
using namespace std;
#ifdef ON_MAIN 

class CTest
{
private:
    int m_nData; //�ν��Ͻ��� ������������� �������. �ν��Ͻ����� == ��ü����
public:
    CTest(int data) :m_nData(data) { this->m_nCount++; }
    int GetData() 
    { 
        return this->m_nData;
    }
    void SetData(int a)
    {
        //üũ
        this->m_nData = a;
        this->ResetCount();
    }

    void ResetCount() { this->m_nCount = 0; }

    static int GetCount()
    {
        //m_nData++; // error
        return m_nCount;
    } //�����ɹ��Լ�(=Ŭ���� �ɹ��Լ�) , static �Լ��� static ������ ���ٰ���.

    //�����ɹ����� == Ŭ���� �ɹ� ����
    static int m_nCount;//����Ƚ�� ������, �������� �ν��Ͻ��� ��������ٰ� �ص� �ϳ����������.
};

int CTest::m_nCount = 0; //static������ ��ü�� �����ȵǵ�(Ŭ���� ȣ���̾��) �޸𸮿� �����ȴ� ���� ó���� ������ �ʱ�ȭ�� ���ִ� �ڵ尡 �ʿ��ϴ�.

int main(void)
{
    cout << CTest::GetCount() << endl;

    CTest a(100);
    //a.ResetCount();

    cout << a.GetData() << endl;
    cout << a.GetCount() << endl;

    CTest b(50);
    //b.ResetCount();


    cout << b.GetData() << endl;
    cout << b.GetCount() << endl;
    return 0;
}
#endif
