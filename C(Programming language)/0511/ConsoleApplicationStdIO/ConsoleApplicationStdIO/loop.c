#include <stdio.h>

int main()
{
	// 1. ���ﰢ��
	/*
	int Num;
	printf("���ڸ� �ϳ� �Է��ϼ��� : ");
	scanf_s("%d", &Num);	//�Է¹ޱ�

	int Result = 0;

	for (int i = 1; i <= Num; i++)	//��(Line)
	{
		for (int j = 1; i<=j; j++)	//�÷�
		{	
			printf("*");
		}
		printf("\n");
	}
	*/

	// 2. Ʈ��
	/*
	for (int i = 0; i < Num; i++) // ��
	{
		for (int j = i; j < Num; j++) // �÷�
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
	
	// 3. ���̾Ƹ��

	int inputNum;
	printf("Ȧ�� ���� �Է� : ");
	scanf_s("%d", &inputNum);
	int count = 1;
	for (int i = 0; i < 2 * inputNum - 1; i++) // ��
	{
		if (i < inputNum)
		{
			for (int j = i; j < inputNum; j++) // �÷�
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