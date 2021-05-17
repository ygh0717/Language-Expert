#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//#define ADDRBOOK_ARRAY
#ifndef ADDRBOOK_ARRAY

/////////////////////////////////////////////////////////////////////////
// �ּҷ��� ����� ������ ����
#define DATA_FILE_NAME "c:\\temp\\AddrBook_List.dat"

/////////////////////////////////////////////////////////////////////////
void ReleaseList();

/////////////////////////////////////////////////////////////////////////
typedef struct _USERDATA
{
	char strName[32];	  // �̸�
	int nAge;			  // ����
	int nGender;		  // ����

	struct _USERDATA* pNext;
} USERDATA;

// ���� ��� ��� ���� �� ����
USERDATA g_Head = { 0 };

/////////////////////////////////////////////////////////////////////////
// ����Ʈ���� �̸����� Ư�� ��带 �˻��ϴ� �Լ�
USERDATA* FindNode(char* pszName)
{
	USERDATA* pTmp = g_Head.pNext;
	while (pTmp != NULL) {
		if (strcmp(pTmp->strName, pszName) == 0)
			return pTmp;

		// ���� ���� �̵�
		pTmp = pTmp->pNext;
	}

	// ��ġ�ϴ� �����͸� ã�� ���� ���
	return NULL;
}

/////////////////////////////////////////////////////////////////////////
int AddNewNode(char* pszName, int nAge, int nGender)
{
	// ���� �̸��� �̹� �����ϴ��� Ȯ���Ѵ�.
	if (FindNode(pszName) != NULL)
	{
		printf("���� �̸��� �̹� �����Ͽ� �߰����� ���մϴ�\n");
		_getch();
		return 0;
	}

	// �޸𸮸� Ȯ���Ѵ�.
	USERDATA* pNewUser = NULL;
	pNewUser = (USERDATA*)malloc(sizeof(USERDATA));
	memset(pNewUser, 0, sizeof(USERDATA));

	// �޸𸮿� ���� �����Ѵ�.
	sprintf_s(pNewUser->strName, sizeof(pNewUser->strName), "%s", pszName);
	pNewUser->nAge = nAge;
	pNewUser->nGender = nGender; 
	pNewUser->pNext = NULL;

	// ���� ��� �ٷ� �ڿ� ���δ�. ���� ���� �ֱٿ�
	// �߰��� �����Ͱ� ���� ���ʿ� �´�. 
	pNewUser->pNext = g_Head.pNext;
	g_Head.pNext = pNewUser;

	return 1;
}

/////////////////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� ����Ʈ�� �߰��ϴ� �Լ�
void Add()
{
	char szName[32] = { 0 };
	int nAge = 0;
	int nGender = 0;

	printf("�̸��� �Է��ϼ��� : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	printf("���̸� �Է��ϼ��� : ");
	fflush(stdin);
	scanf_s("%d", &nAge);

	printf("������ �Է��ϼ���(����:0, ����:1) : ");
	fflush(stdin);
	scanf_s("%d", &nGender);

	// ������ ����Ʈ�� �߰��Ѵ�.
	AddNewNode(szName, nAge, nGender);
}

/////////////////////////////////////////////////////////////////////////
// Ư�� ��带 �˻��ϴ� �Լ�
void Search()
{
	char szName[32] = { 0 };
	USERDATA* pNode = NULL;

	printf("�˻��� �̸��� �Է��ϼ��� : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	pNode = FindNode(szName);
	if (pNode != NULL) {
		printf("[%p] %s\t%d��\t%s\n",
			pNode,
			pNode->strName,
			pNode->nAge,
			pNode->nGender ? "����" : "����");
	}
	else {
		puts("ERROR: �����͸� ã�� �� �����ϴ�.");
	}

	_getch();
}

/////////////////////////////////////////////////////////////////////////
// ����Ʈ�� ����ִ� ��� �����͸� ȭ�鿡 ����ϴ� �Լ�
void PrintAll()
{
	int nCount = 0;
	USERDATA* pTmp = g_Head.pNext;
	while (pTmp != NULL) {
		printf("[%p] %s\t%d��\t%s\n",
			pTmp,
			pTmp->strName,
			pTmp->nAge,
			pTmp->nGender ? "����" : "����");

		pTmp = pTmp->pNext;
		nCount++;
	}
	if (nCount == 0)
		printf("�����Ͱ� �������� �ʽ��ϴ�.\n");
	_getch();
}

/////////////////////////////////////////////////////////////////////////
// Ư�� ��带 �˻��ϰ� �����ϴ� �Լ�
int RemoveNode(char* pszName)
{
	USERDATA* pPrevNode = &g_Head;
	USERDATA* pDelete = NULL;

	while (pPrevNode->pNext != NULL) {
		pDelete = pPrevNode->pNext;

		if (strcmp(pDelete->strName, pszName) == 0) {
			pPrevNode->pNext = pDelete->pNext;
			free(pDelete);

			printf("%s ������ �����մϴ�.\n", pszName);
			_getch();

			return 1;
		}

		pPrevNode = pPrevNode->pNext;
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� �ڷḦ �˻��ϰ� �����ϴ� �Լ�
void Remove()
{
	char szName[32] = { 0 };

	printf("������ �̸��� �Է��ϼ��� : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	RemoveNode(szName);
}

/////////////////////////////////////////////////////////////////////////
// �޴��� ����ϴ� UI �Լ�
int PrintUI()
{
	int nInput = 0;

	system("cls");
	printf("===================================================\n");
	printf("��ȭ��ȣ��(Linked List)\n");
	printf("---------------------------------------------------\n");
	printf("[1] �߰�\t [2] �˻�\t [3] ��ü����\t [4] ����\t [0] ����\n");
	printf("===================================================\n");

	// ����ڰ� ������ �޴��� ���� ��ȯ�Ѵ�.
	scanf_s("%d", &nInput);
	getchar();//���ۿ� ���� ���� ���ſ�
	return nInput;
}

/////////////////////////////////////////////////////////////////////////
// ������ ���Ͽ��� ������ �о�� ����Ʈ�� �ϼ��ϴ� �Լ�
int LoadList(char* pszFileName)
{
	FILE* fp = NULL;
	USERDATA user = { 0 };

	fopen_s(&fp, pszFileName, "rb");

	if (fp == NULL)
		return 0;

	ReleaseList();

	while (fread(&user, sizeof(USERDATA), 1, fp))
		AddNewNode(user.strName, user.nAge, user.nGender);

	fclose(fp);

	return 0;
}

/////////////////////////////////////////////////////////////////////////
// ����Ʈ ���·� �����ϴ� ������ ���Ͽ� �����ϴ� �Լ�
int SaveList(char* pszFileName)
{
	FILE* fp = NULL;
	USERDATA* pTmp = g_Head.pNext;

	fopen_s(&fp, pszFileName, "wb");

	if (fp == NULL) {
		puts("ERROR: ����Ʈ ������ ���� ���� ���� ���߽��ϴ�.");
		_getch();

		return 0;
	}

	while (pTmp != NULL) {
		if (fwrite(pTmp, sizeof(USERDATA), 1, fp) != 1)
			printf("ERROR: %s�� ���� ������ �����ϴµ� �����߽��ϴ�.\n", pTmp->strName);

		pTmp = pTmp->pNext;
	}

	fclose(fp);

	return 1;
}

/////////////////////////////////////////////////////////////////////////
// ����Ʈ�� ��� �����͸� �����ϴ� �Լ�
void ReleaseList()
{
	USERDATA* pTmp = g_Head.pNext;
	USERDATA* pDelete = NULL;

	while (pTmp != NULL) {
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		free(pDelete);
	}

	memset(&g_Head, 0, sizeof(USERDATA));
}

/////////////////////////////////////////////////////////////////////////
void main()
{
	int nMenu = 0;
	//LoadList(DATA_FILE_NAME);

	// ���� �̺�Ʈ �ݺ���
	while ((nMenu = PrintUI()) != 0) {
		switch (nMenu) {
		case 1:		  // Add
			Add();
			break;

		case 2:		  // Search
			Search();
			break;

		case 3:		 // Print all
			PrintAll();
			break;

		case 4:		  // Remove
			Remove();
			break;
		}
	}

	// ���� ���� ���Ϸ� �����ϰ� �޸𸮸� �����Ѵ�.
	//SaveList(DATA_FILE_NAME);
	ReleaseList();
}

#endif