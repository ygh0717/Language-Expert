#include <stdio.h>
#include <stdlib.h>

int main()
{
	//�����޸� �Ҵ� ����
	{
		printf("===== ���� ���� =====\n");

		int nkinds = 0;
		printf("������ ������ �� �� ���ΰ���? ");
		scanf_s("%d%c", &nkinds);

		int mMaxLenth = 0;
		printf("�����̸��� �ִ� ���̴� ���ΰ���? ");
		scanf_s("%d%c", &mMaxLenth);

		char** pDrink = NULL;
	}
	//�����޸�
	{
		char* p1 = (char*)malloc(sizeof(char)*2);	//2Byte->�������� ����

		p1[0] = 'a';
		p1[1] = 'b';

		printf("%c, %c \n", p1[0], p1[1]);
		printf("p1 ������ : %d\n", sizeof(p1));	//2? 4?	-> �����Ͷ� 4Byte
		printf("p1 �������� : %d\n", _msize(p1));	//2? 4?

		free(p1);

		int b = sizeof(int) * 2;
		int* p2 = (int*)malloc(b);	//8Byte -> �������� ����

		p2[0] = 10;
		p2[1] = 20;

		printf("%d, %d \n", p2[0], p2[1]);
		printf("p2 ������ : %d\n", sizeof(p2));	//2? 4?	-> �����Ͷ� 4Byte
		printf("p2 �������� : %d\n", _msize(p2));	//8Byte

		free(p2);
	}
	return 0;
}