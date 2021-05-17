#include <stdio.h>
#include <stdlib.h>

int main()
{
	//동적메모리 할당 예제
	{
		printf("===== 음료 관리 =====\n");

		int nkinds = 0;
		printf("음료의 종류는 총 몇 개인가요? ");
		scanf_s("%d%c", &nkinds);

		int mMaxLenth = 0;
		printf("음료이름의 최대 길이는 얼마인가요? ");
		scanf_s("%d%c", &mMaxLenth);

		char** pDrink = NULL;
	}
	//동적메모리
	{
		char* p1 = (char*)malloc(sizeof(char)*2);	//2Byte->힙영역에 잡힘

		p1[0] = 'a';
		p1[1] = 'b';

		printf("%c, %c \n", p1[0], p1[1]);
		printf("p1 사이즈 : %d\n", sizeof(p1));	//2? 4?	-> 포인터라서 4Byte
		printf("p1 힙사이즈 : %d\n", _msize(p1));	//2? 4?

		free(p1);

		int b = sizeof(int) * 2;
		int* p2 = (int*)malloc(b);	//8Byte -> 힙영역에 잡힘

		p2[0] = 10;
		p2[1] = 20;

		printf("%d, %d \n", p2[0], p2[1]);
		printf("p2 사이즈 : %d\n", sizeof(p2));	//2? 4?	-> 포인터라서 4Byte
		printf("p2 힙사이즈 : %d\n", _msize(p2));	//8Byte

		free(p2);
	}
	return 0;
}