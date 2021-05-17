#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define ADDRBOOK_ARRAY
#ifdef ADDRBOOK_ARRAY

/////////////////////////////////////////////////////////////////////////
// �ּҷ��� ����� ������ ����
#define DATA_FILE_NAME "c:\\temp\\AddrBook_Arr.dat"

/////////////////////////////////////////////////////////////////////////
void ReleaseList();

/////////////////////////////////////////////////////////////////////////
typedef struct _USERDATA
{
	char strName[32];	  // �̸�
	int nAge;			  // ����
	int nGender;		  // ����
} USERDATA;

//�迭�� ó��
#define		MAX_BOOKCOUNT	5
int			g_nCount = 0;
USERDATA	g_AddrBook[ MAX_BOOKCOUNT ];

/////////////////////////////////////////////////////////////////////////
// ����Ʈ���� �̸����� Ư�� ��带 �˻��ϴ� �Լ�
USERDATA* FindNode(char* pszName)
{
	for (int i = 0; i < g_nCount; i++)
	{
		if (strcmp(g_AddrBook[i].strName, pszName) == 0)
			return g_AddrBook + i;
	}

	// ��ġ�ϴ� �����͸� ã�� ���� ���
	return NULL;
}
/////////////////////////////////////////////////////////////////////////
int AddNewNode(char* pszName, int nAge, int nGender)
{
	USERDATA* pNewUser = NULL;
	
	pNewUser = &g_AddrBook[g_nCount];
	memset(pNewUser, 0, sizeof(USERDATA));
	
	sprintf_s(pNewUser->strName, sizeof(pNewUser->strName), "%s", pszName);
	pNewUser->nAge = nAge;
	pNewUser->nGender = nGender;

	g_nCount++;
	return 1;
}

///////////////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� ����Ʈ�� �߰��ϴ� �Լ�
void Add()
{
	char szName[32] = { 0 };
	int nAge = 0;
	int nGender = 0;

	if (g_nCount + 1 > MAX_BOOKCOUNT)
	{
		printf("�ּҷ� �뷮�ʰ��� �߰����� ���մϴ�\n");
		_getch();
		return;
	}

	printf("�̸��� �Է��ϼ��� : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));
		
	// ���� �̸��� �̹� �����ϴ��� Ȯ���Ѵ�.
	if (FindNode(szName) != NULL)
	{
		printf("���� �̸��� �̹� �����Ͽ� �߰����� ���մϴ�\n");
		_getch();
		return;
	}
		
	printf("���̸� �Է��ϼ��� : ");
	fflush(stdin);
	scanf_s("%d", &nAge);

	printf("������ �Է��ϼ���(����:0, ����:1) : ");
	fflush(stdin);
	scanf_s("%d", &nGender);


	// ������ �迭�� ������ �߰��Ѵ�.
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
	USERDATA* pTmp;
	for (int i = 0; i < g_nCount; i++)
	{
		pTmp = &g_AddrBook[i];
		printf("[%p] %s\t%d��\t%s\n",
			pTmp,
			pTmp->strName,
			pTmp->nAge,
			pTmp->nGender ? "����" : "����");
	}
	if (g_nCount == 0)
		printf("�����Ͱ� �������� �ʽ��ϴ�.\n");
	_getch();
}

/////////////////////////////////////////////////////////////////////////
// Ư�� ��带 �˻��ϰ� �����ϴ� �Լ�
int RemoveNode(char* pszName)
{
/*	USERDATA* pPrevNode = &g_Head;
	USERDATA* pDelete = NULL;

	while (pPrevNode->pNext != NULL) {
		pDelete = pPrevNode->pNext;

		if (strcmp(pDelete->strName, pszName) == 0) {
			pPrevNode->pNext = pDelete->pNext;
			free(pDelete);

			return 1;
		}

		pPrevNode = pPrevNode->pNext;
	}
*/
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
	printf("��ȭ��ȣ��(Array)\n");
	printf("---------------------------------------------------\n");
	//printf("[1] �߰�\t [2] �˻�\t [3] ��ü����\t [4] ����\t [0] ����\n");
	printf("[1] �߰�\t [2] �˻�\t [3] ��ü����\t [0] ����\n");
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
	if (fp == NULL)	return 0;

	ReleaseList();
	//������� �б�: �ּҷ� ��ü����
	fread(&g_nCount, sizeof(g_nCount), 1, fp);
	//�ٵ����� �б�: �ּҷ� ����
	for (int i = 0; i < g_nCount; i++)
	{
		fread(g_AddrBook+i, sizeof(USERDATA), 1, fp);
		//AddNewNode(user.strName, user.nAge, user.nGender);
	}
	fclose(fp);
	return 0;
}

/////////////////////////////////////////////////////////////////////////
// ����Ʈ ���·� �����ϴ� ������ ���Ͽ� �����ϴ� �Լ�
int SaveList(char* pszFileName)
{
	FILE* fp = NULL;
	USERDATA* pTmp;

	fopen_s(&fp, pszFileName, "wb");

	if (fp == NULL) {
		puts("ERROR: ����Ʈ ������ ���� ���� ���� ���߽��ϴ�.");
		_getch();
		return 0;
	}
	//������� ����: �ּҷ� ��ü����
	fwrite(&g_nCount, sizeof(g_nCount), 1, fp);
	//�ٵ����� ����: �ּҷ� ����
	for (int i = 0; i < g_nCount; i++)
	{
		pTmp = g_AddrBook + i;
		if (fwrite(pTmp, sizeof(USERDATA), 1, fp) != 1)
			printf("ERROR: %s�� ���� ������ �����ϴµ� �����߽��ϴ�.\n", pTmp->strName);
	}
	fclose(fp);
	
	return 1;
}

/////////////////////////////////////////////////////////////////////////
// ����Ʈ�� ��� �����͸� �����ϴ� �Լ�
void ReleaseList()
{
	//�迭 �ʱ�ȭ
	memset(g_AddrBook, 0, sizeof(g_AddrBook));
	g_nCount = 0;
}

void main()
{
	int nMenu = 0;
	LoadList(DATA_FILE_NAME);

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
	SaveList(DATA_FILE_NAME);
	ReleaseList();
}
#endif