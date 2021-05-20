#include <iostream>

//#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

class CMyDataA
{
//private : 
protected:
    char* m_pData;
public:
    CMyDataA() 
    { 
        cout << "CMyDataA()" << endl; 
        m_pData = new char[32];
    }
    ~CMyDataA() 
    { 
        cout << "~CMyDataA()" << endl; 
        if(m_pData != NULL)
            delete[] m_pData;
    }
};

class CMyDataB : public CMyDataA
{
public:
    CMyDataB() { cout << "CMyDataB()" << endl; }
    ~CMyDataB() { cout << "~CMyDataB()" << endl; }
};

class CMyDataC : public CMyDataB
{
public:
    CMyDataC() { cout << "CMyDataC()" << endl; }
    ~CMyDataC() 
    { 
        cout << "~CMyDataC()" << endl; 
        delete[] m_pData;
        m_pData = NULL;
    }
};
//////////////////////////////////
class CParent
{
public:		  // 누구나 접근 가능
    CParent() { cout << "CParent()" << endl; }
    CParent(int a) { cout << "CParent(int)" << endl; }
    CParent(double a) { cout << "CParent(double)" << endl; }

    int GetData() { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }

private:	  // 누구도 접근 불가능
    int m_nData = 0;

protected:	  // 파생 클래스만 접근 가능
    void PrintData() 
    { cout << "CParent::PrintData() : " << m_nData << endl; }
};

////////////////////////////////
class CChild : public CParent
{
public:		  // 누구나 접근 가능
    CChild() { cout << "CChild()" << endl; }
    CChild(int a) : CParent(a)
    { 
        cout << "CChild(int)" << endl; 
    }
    CChild(double a) : CParent()
    { 
        cout << "CChild(double)" << endl; 
    }

    void TextFunc()
    {
        SetData(5);//public
        PrintData();//protected
    }

    //재정의(오버라이딩)
    void SetData(int nParam)
    {
        // 입력 데이터의 값을 보정하는 새로운 기능을 추가한다.
        if (nParam < 0)
            CParent::SetData(0);
        else if (nParam > 10)
            CParent::SetData(10);
        else
            CParent::SetData(nParam);
    }
};


int main()
{
    //생성자를 선택함
    {
        CChild a;
        cout << "**********" << endl;
        CChild b(5);
        cout << "**********" << endl;
        CChild c(3.3);
    }
    return 0;
    {
        //구형 클래스 - 값을 보정하는 기능이 없다.
        CParent a;
        a.SetData(15);
        cout << a.GetData() << endl;

        //신형 클래스(상속) - 값을 보정하는 기능이 있다.
        CChild b;
        b.SetData(15);
        cout << b.GetData() << endl;

        CParent& ref = b;
        ref.SetData(20);
        cout << ref.GetData() << endl;
        
        //protected의 접근주의
        //a.PrintData();//protected이므로 Error발생
        //a.TextFunc();
    }
    return 0;
    //상속
    {
        cout << "*****Main Begin*****" << endl;
        CMyDataC xxx;
        cout << "******Main End******" << endl;
    }
    return 0;
}
#endif