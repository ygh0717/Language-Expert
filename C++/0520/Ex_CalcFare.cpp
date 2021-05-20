#pragma once

#include <iostream>

//#define ON_MAIN
#ifdef ON_MAIN

using namespace std;

#define DEFAULT_FARE 45000

class CPerson
{
public:
    virtual void CalcFare() { m_nFare = DEFAULT_FARE; };
    unsigned int GetFare() { return m_nFare; }
protected:
    unsigned int m_nFare = 0;
};

// 영유아(0~7세) 요금 계산 --> // 0%
class CBaby : public CPerson 
{
    void CalcFare()
    {
        m_nFare = 0;
    }
};
// 어린이(8~13세) 요금 계산 --> // 50%
class CChild : public CPerson 
{
    void CalcFare()
    {
        m_nFare = DEFAULT_FARE *0.5;
    }
};
// 청소년(14~19세) 요금 계산--> // 75%
class CTeen : public CPerson 
{
    void CalcFare()
    {
        m_nFare = DEFAULT_FARE * 0.75;
    }
};
// 성인(20세 이상) 요금 계산--> // 100%
class CAdult : public CPerson
{
    void CalcFare()
    {
        m_nFare = DEFAULT_FARE;
    }
};


int main()
{
    for (;;)
    {
        cout << "=======================================" << endl;
        cout << "\t 에버랜드 요금 계산기" << endl;
        cout << "=======================================" << endl;

        int nCount = 0;
        cout << "\t총 몇 분이 입장하시나요? ";
        cin >> nCount;
        cout << "---------------------------------------" << endl;

        CPerson** arList = new CPerson * [nCount];

        // 1. 자료 입력: 사용자 입력에 따라서 생성할 객체 선택
        int nAge = 0;
        for (int i = 0; i < nCount; i++)
        {
            cout << i + 1 << "번의 나이를 입력하세요: ";
            cin >> nAge;

            // 사용자가 입력한 나이에 따라 객체를 동적 생성한다.
            if (0 <= nAge && nAge <= 7)        arList[i] = new CBaby;
            else if (8 <= nAge && nAge <= 13)  arList[i] = new CChild;
            else if (14 <= nAge && nAge <= 19) arList[i] = new CTeen;
            else                               arList[i] = new CAdult;
            
            // 생성한 객체에 맞는 요금이 자동으로 계산된다.
            arList[i]->CalcFare();
        }
        // 2. 자료 출력: 계산한 요금을 활용하는 부분
        int nFare = 0;
        int nTotal = 0;
        cout << "---------------------------------------" << endl;
        for (int i = 0; i < nCount; i++)
        {
            nFare = arList[i]->GetFare();
            nTotal = nTotal + nFare;

            cout << "\t" << i + 1 << "번분의 요금은 " << nFare << "원" << endl;
        }
        cout << "---------------------------------------" << endl;
        cout << "\t" << "총 요금 : " << nTotal << "원 입니다." << endl;
        cout << "---------------------------------------" << endl;

        // 3. 자료 삭제 및 종료
        for (int i = 0; i < nCount; i++)
        {
            delete arList[i];
        }
        //Person의 포인터 삭제
        delete[] arList;
    }
    return 0;
}
#endif
