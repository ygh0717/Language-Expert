#include <stdio.h>

int main()
{
	int nMenu = -1;	//초기값
	const int nPrice[] = { 1000, 1500, 700 };	//가격표
	int nMoney;	//입력된 금액
	int nChange = 0;	//거스름돈

	for(;;)
	{

		//1. 메뉴
		printf("======음료 자판기======\n");
		printf("1. 콜라\n");
		printf("2. 사이다\n");
		printf("3. 오렌지주스\n");
		printf("0. 종료\n");
		printf("=======================\n");
		printf("원하는 음료버튼을 선택하세요 : ");

		scanf_s("%d", &nMenu);
		if (nMenu == 0)
		{
			printf("Bye\n\n");
			break;
		}

		//2. 금액 처리
		printf("====================\n");
		printf("금액을 입력하세요 : ");
		scanf_s("%d", &nMoney);	//입력


		if (nMoney >= nPrice[nMenu - 1])
		{
			nChange = nMoney - nPrice[nMenu - 1];
			printf("잔액은 %d원입니다.\n", nChange);
		}

		//3. 음료수 출력
		if (nMenu == 1)
			printf("콜라 나왔습니다.\n");
		else if (nMenu == 2)
			printf("사이다 나왔습니다.\n");
		else if (nMenu == 3)
			printf("오렌지주스 나왔습니다.\n");
		else
			printf("다른 번호를 입력해주세요.\n");

		/*switch (nMenu)
		{
		case 0: printf("프로그램을 종료합니다.\n");
			break;
		case 1: printf("콜라 나왔습니다.\n");
			break;
		case 2: printf("사이다 나왔습니다.\n");
			break;
		case 3: printf("오렌지주스 나왔습니다.\n");
			break;
		}*/
	}
	return 0;
}