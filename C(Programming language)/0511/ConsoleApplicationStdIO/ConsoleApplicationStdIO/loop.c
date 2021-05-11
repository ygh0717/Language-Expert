#include <stdio.h>

int main()
{
	// 1. 역삼각형
	/*
	int Num;
	printf("숫자를 하나 입력하세요 : ");
	scanf_s("%d", &Num);	//입력받기

	int Result = 0;

	for (int i = 1; i <= Num; i++)	//행(Line)
	{
		for (int j = 1; i<=j; j++)	//컬럼
		{	
			printf("*");
		}
		printf("\n");
	}
	*/

	// 2. 트리
	/*
	for (int i = 0; i < Num; i++) // 행
	{
		for (int j = i; j < Num; j++) // 컬럼
		{
			printf(" ");
		}

		for (int k = 0; k <= i * 2 ; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	*/
	
	// 3. 다이아몬드

	int inputNum;
	printf("홀수 숫자 입력 : ");
	scanf_s("%d", &inputNum);
	int count = 1;
	for (int i = 0; i < 2 * inputNum - 1; i++) // 행
	{
		if (i < inputNum)
		{
			for (int j = i; j < inputNum; j++) // 컬럼
			{
				printf(" ");
			}

			for (int k = 0; k <= i * 2; k++)
			{
				printf("*");
			}
			printf("\n");
		}
		else
		{
			for (int j = 0; j <= count; j++)
			{
				printf(" ");
			}
			count++;
			for (int j = 0; j <= (inputNum * 2 - 2 - i) * 2; j++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}