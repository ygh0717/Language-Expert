//���� ���Ǳ�
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
    const char strLabel[12];    //���ع����� �����ϱ� �������
    const int nPrice;
};

int main(void)
{
    DRINK MyMenu[MAX] =
    {
        {"�Ƹ޸�ī��", 2000},
        {"���̽�ī���", 2500},
        {"ī��Ḷ���߶�", 3000},
        {"����", 500},
        {"ȯŸ", 1000},
        {"�������ֽ�", 1500},
        {"���⽺����", 4000},
    };


    int nMenu = -1;                                                                 //�ʱⰪ
    //char szLabel[][12] = {"�ݶ�", "�������꽺", "����", "���̴�", "Ŀ��"};
    //const char* szLabel[] = { "�ݶ�", "�������꽺", "����", "���̴�", "Ŀ��" };   //const ���� �߾��°Ť���
    //const int nPrice[] = { 1000,1500,700, 1000, 2500 }; //����ǥ
    int nMoney;                                                                     //�Աݵ� �ݾ�
    int nChange;                                                                    // �Ž�����
    
    //printf("szLable�� ������ : %d\n\n", sizeof(szLabel));

    //while (1)
    //while (nMenu!=0)
    for (;;) //���������� �̰ŷ� ���ѷ����� ���̾��ٴµ�?
    {
        if (nMenu == 0)
        {
            printf("�� \n\n");

            break;
        }

        printf("===����� ���Ǳ�=== \n");
        //printf("1. �ݶ� \n");
        //printf("2. �������꽺 \n");
        //printf("3. ���� \n");
        for (int i = 0; i < MAX; i++)
        {
            printf("%d. %s\t\t%d��\n", i+1, MyMenu[i].strLabel, MyMenu[i].nPrice);
        }

        printf("0. ���� \n");

        printf("=================== \n");
        printf("���ϴ� �����ư�� �����ϼ��� : ");
        scanf_s("%d", &nMenu);

        printf("�Է��� �ݾ��� �Է��ϼ��� : ");
        scanf_s("%d", &nMoney);



        Print(nMoney, nMenu, MyMenu->nPrice);

        Sleep(2000);
        system("cls");

        //����ġ�� ������ �񱳰����ϱ⶧���� �������� ����Ѵ�.
        /*
        switch (nMenu)
        {

        case 1:
           printf("�ݶ� �������� \n");
           break;
        case 2:
           printf("�������꽺 �������� \n");
           break;
        case 3:
           printf("���� �������� \n");
           break;
        case 0:
           printf("���� \n");
           power = 0;
           break;

        default:
           printf("�ٽ��Է� \n");


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
        printf("�ܵ� %d ���� �������� \n", change);
        printf("%s �������� \n", nMenu);
    }
    else if (change == 0)
    {
        printf("%s �������� \n", szLabel[nMenu - 1]);
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
        printf("���� %d�� ���ڶ��ϴ�.", need);
        return 0;
    }

    return Change;

}
