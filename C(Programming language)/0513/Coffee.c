//음료 자판기
#include<stdio.h>
#include<windows.h>

#define MAX 7

int cal(int Money, int choice, int price[]);
void Print(int Money, int choice, int price[], char* name[]);

typedef struct Product {
    const char* strLabel;
    const int nPrice;
}DRINK;
struct Product2 {
    const char strLabel[12];    //정해버리면 관리하기 힘들어짐
    const int nPrice;
};

int main(void)
{
    DRINK MyMenu[MAX] =
    {
        {"아메리카노", 2000},
        {"아이스카페라떼", 2500},
        {"카라멜마끼야또", 3000},
        {"생수", 500},
        {"환타", 1000},
        {"오렌지주스", 1500},
        {"딸기스무디", 4000},
    };


    int nMenu = -1;                                                                 //초기값
    //char szLabel[][12] = {"콜라", "오렌지쥬스", "생수", "사이다", "커피"};
    //const char* szLabel[] = { "콜라", "오렌지쥬스", "생수", "사이다", "커피" };   //const 쓰면 잘쓰는거ㅎㅎ
    //const int nPrice[] = { 1000,1500,700, 1000, 2500 }; //가격표
    int nMoney;                                                                     //입금된 금액
    int nChange;                                                                    // 거스름돈
    
    //printf("szLable의 사이즈 : %d\n\n", sizeof(szLabel));

    //while (1)
    //while (nMenu!=0)
    for (;;) //실전에서는 이거로 무한루프를 많이쓴다는데?
    {
        if (nMenu == 0)
        {
            printf("끝 \n\n");

            break;
        }

        printf("===음료수 자판기=== \n");
        //printf("1. 콜라 \n");
        //printf("2. 오렌지쥬스 \n");
        //printf("3. 생수 \n");
        for (int i = 0; i < MAX; i++)
        {
            printf("%d. %s\t\t%d원\n", i+1, MyMenu[i].strLabel, MyMenu[i].nPrice);
        }

        printf("0. 종료 \n");

        printf("=================== \n");
        printf("원하는 음료버튼을 선택하세요 : ");
        scanf_s("%d", &nMenu);

        printf("입력할 금액을 입력하세요 : ");
        scanf_s("%d", &nMoney);



        Print(nMoney, nMenu, MyMenu->nPrice);

        Sleep(2000);
        system("cls");

        //스위치는 정수만 비교가능하기때문에 이프문을 사용한다.
        /*
        switch (nMenu)
        {

        case 1:
           printf("콜라 받으세요 \n");
           break;
        case 2:
           printf("오렌지쥬스 받으세요 \n");
           break;
        case 3:
           printf("생수 받으세요 \n");
           break;
        case 0:
           printf("종료 \n");
           power = 0;
           break;

        default:
           printf("다시입력 \n");


        }
        */

    }

    return 0;
}

void Print(int Money, int nMenu, DRINK a[MAX])
{
    int change;
    change = cal(Money, nMenu, a->(int)nPrice);

    if (change != 0)
    {
        printf("잔돈 %d 원을 받으세요 \n", change);
        printf("%s 받으세요 \n", nMenu);
    }
    else if (change == 0)
    {
        printf("%s 받으세요 \n", szLabel[nMenu - 1]);
    }
}

int cal(int Money, int choice, int price[])
{
    int Change = 0;

    Change = Money - price[choice - 1];

    if (Change < 0)
    {
        int need = 0;
        need = price[choice - 1] - Money;
        printf("돈이 %d원 모자랍니다.", need);
        return 0;
    }

    return Change;

}
