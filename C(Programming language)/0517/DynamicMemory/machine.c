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

	int count = 0;	//��ȣ
	int answer = 1;

	while (answer == 1)
	{
		//1. ���ο� ��� 1���� ���� �����޸� �Ҵ�
		pNewUser = (WORKER*)malloc(sizeof(WORKER));//���� �޸� �Ҵ�

		//2. ��� 1�� ���� �Է�
		printf("����� �̸� �Է� : ");
		scanf_s("%s", pNewUser->name, 20);
		pNewUser->num = count+1;
		pNewUser->pLink = NULL;

		//3. ��ũ ����
		pNewUser->pLink = pHeader;
		pHeader = pNewUser;
		count++;

		printf("��� �Է�(0:no/1:yes) : ");
		scanf_s("%d", &answer);
	}

	WORKER* pTmp = pHeader;

	while (pTmp != NULL)
	{
		printf("[%p] %d. %s[%p]\n", pTmp, pTmp->num, pTmp->name, pTmp->pLink);
		
		pTmp = pTmp->pLink;
	}

	printf("===== ���� ���� =====\n");

	int nkinds = 0;

	printf("������ ������ �� �� ���ΰ���? ");
	scanf_s("%d", &nkinds);

	int mMaxLenth = 0;

	printf("�����̸��� �ִ� ���̴� ���ΰ���? ");
	scanf_s("%d", &mMaxLenth);

	char** pDrink = NULL;
	pDrink = (char**)malloc(sizeof(char*) * nkinds);
	printf("pDrink�� ������ = %d, �޸� = %d\n",
		sizeof(pDrink), _msize(pDrink));
	{
		char temp[100];
		for (int i = 0; i < nkinds; i++)
		{
			printf("\t%d�� ���� �̸� : ", i + 1);
			scanf_s("%s", temp, 100);

			int len = strlen(temp);
			//pDrink[i] = (char*)malloc(sizeof(char) * (mMaxLenth + 1));
			//strcpy(*(pDrink + i), temp);	//���ڿ� �Լ�
			pDrink[i] = (char*)malloc(sizeof(char) * (len+1));

			memcpy(*(pDrink + i), temp, len + 1);
		}
		printf("\n�����̸� ���\n");
		for (int i = 0; i < nkinds; i++)
		{
			printf("\t%d�� ���� %s(%d) \n", i + 1, pDrink[i], _msize(pDrink[i]));
			free(pDrink[i]);
		}
	}
	/*{	//�����޸𸮷� ���
		char pDrink[3][12] = { 0 };
		char temp[100];

		for (int i = 0; i < 3; i++)
		{
			printf("\t%d�� ���� �̸� : ", i + 1);
			scanf_s("%s", pDrink[i], 12);
		}

		printf("\n�����̸� ���\n");
		for (int i = 0; i < 3; i++)
		{
			printf("\t%d�� ���� %s(%d) \n", i + 1, pDrink[i], _msize(pDrink[i]));
		}
	}*/
	return 0;
}