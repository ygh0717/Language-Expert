#include <stdio.h>
#include <stdlib.h>

int main()
{
	typedef struct worker {
		int num;
		char name[20];

		struct worker* pLink;
	}WORKER;

	WORKER* pHeader = NULL;
	WORKER* pNewUser = NULL;

	int count = 0;	//번호
	int answer = 1;

	while (answer == 1)
	{
		//1. 새로운 사원 1명을 위한 동적메모리 할당
		pNewUser = (WORKER*)malloc(sizeof(WORKER));//동적 메모리 할당

		//2. 사원 1명 정보 입력
		printf("사원의 이름 입력 : ");
		scanf_s("%s", pNewUser->name, 20);
		pNewUser->num = count+1;
		pNewUser->pLink = NULL;

		//3. 링크 조정
		pNewUser->pLink = pHeader;
		pHeader = pNewUser;
		count++;

		printf("계속 입력(0:no/1:yes) : ");
		scanf_s("%d", &answer);
	}

	WORKER* pTmp = pHeader;

	while (pTmp != NULL)
	{
		printf("[%p] %d. %s[%p]\n", pTmp, pTmp->num, pTmp->name, pTmp->pLink);
		
		pTmp = pTmp->pLink;
	}

	printf("===== 음료 관리 =====\n");

	int nkinds = 0;

	printf("음료의 종류는 총 몇 개인가요? ");
	scanf_s("%d", &nkinds);

	int mMaxLenth = 0;

	printf("음료이름의 최대 길이는 얼마인가요? ");
	scanf_s("%d", &mMaxLenth);

	char** pDrink = NULL;
	pDrink = (char**)malloc(sizeof(char*) * nkinds);
	printf("pDrink의 사이즈 = %d, 메모리 = %d\n",
		sizeof(pDrink), _msize(pDrink));
	{
		char temp[100];
		for (int i = 0; i < nkinds; i++)
		{
			printf("\t%d번 음료 이름 : ", i + 1);
			scanf_s("%s", temp, 100);

			int len = strlen(temp);
			//pDrink[i] = (char*)malloc(sizeof(char) * (mMaxLenth + 1));
			//strcpy(*(pDrink + i), temp);	//문자열 함수
			pDrink[i] = (char*)malloc(sizeof(char) * (len+1));

			memcpy(*(pDrink + i), temp, len + 1);
		}
		printf("\n음료이름 출력\n");
		for (int i = 0; i < nkinds; i++)
		{
			printf("\t%d번 음료 %s(%d) \n", i + 1, pDrink[i], _msize(pDrink[i]));
			free(pDrink[i]);
		}
	}
	/*{	//정적메모리로 사용
		char pDrink[3][12] = { 0 };
		char temp[100];

		for (int i = 0; i < 3; i++)
		{
			printf("\t%d번 음료 이름 : ", i + 1);
			scanf_s("%s", pDrink[i], 12);
		}

		printf("\n음료이름 출력\n");
		for (int i = 0; i < 3; i++)
		{
			printf("\t%d번 음료 %s(%d) \n", i + 1, pDrink[i], _msize(pDrink[i]));
		}
	}*/
	return 0;
}