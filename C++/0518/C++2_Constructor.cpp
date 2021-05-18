#include<iostream>

#define ON_MAIN
using namespace std;
#ifdef ON_MAIN 

class CTest
{
private:
    int m_nData; //인스턴스가 만들어질떄마다 만들어짐. 인스턴스변수 == 객체변수
public:
    CTest(int data) :m_nData(data) { this->m_nCount++; }
    int GetData() 
    { 
        return this->m_nData;
    }
    void SetData(int a)
    {
        //체크
        this->m_nData = a;
        this->ResetCount();
    }

    void ResetCount() { this->m_nCount = 0; }

    static int GetCount()
    {
        //m_nData++; // error
        return m_nCount;
    } //정적맴버함수(=클래스 맴버함수) , static 함수는 static 변수만 접근가능.

    //정적맴버변수 == 클래스 맴버 변수
    static int m_nCount;//누적횟수 관리용, 여러개의 인스턴스가 만들어진다고 해도 하나만만들어짐.
};

int CTest::m_nCount = 0; //static변수는 객체가 생성안되도(클래스 호출이없어도) 메모리에 생성된다 따라서 처음에 무조건 초기화를 해주는 코드가 필요하다.

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
