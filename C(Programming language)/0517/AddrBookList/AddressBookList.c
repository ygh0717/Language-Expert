#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//#define ADDRBOOK_ARRAY
#ifndef ADDRBOOK_ARRAY

/////////////////////////////////////////////////////////////////////////
// 주소록이 저장될 데이터 파일
#define DATA_FILE_NAME "c:\\temp\\AddrBook_List.dat"

/////////////////////////////////////////////////////////////////////////
void ReleaseList();

/////////////////////////////////////////////////////////////////////////
typedef struct _USERDATA
{
	char strName[32];	  // 이름
	int nAge;			  // 나이
	int nGender;		  // 성별

	struct _USERDATA* pNext;
} USERDATA;

// 더미 헤드 노드 선언 및 정의
USERDATA g_Head = { 0 };

/////////////////////////////////////////////////////////////////////////
// 리스트에서 이름으로 특정 노드를 검색하는 함수
USERDATA* FindNode(char* pszName)
{
	USERDATA* pTmp = g_Head.pNext;
	while (pTmp != NULL) {
		if (strcmp(pTmp->strName, pszName) == 0)
			return pTmp;

		// 다음 노드로 이동
		pTmp = pTmp->pNext;
	}

	// 일치하는 데이터를 찾지 못한 경우
	return NULL;
}

/////////////////////////////////////////////////////////////////////////
int AddNewNode(char* pszName, int nAge, int nGender)
{
	// 같은 이름이 이미 존재하는지 확인한다.
	if (FindNode(pszName) != NULL)
	{
		printf("같은 이름이 이미 존재하여 추가하지 못합니다\n");
		_getch();
		return 0;
	}

	// 메모리를 확보한다.
	USERDATA* pNewUser = NULL;
	pNewUser = (USERDATA*)malloc(sizeof(USERDATA));
	memset(pNewUser, 0, sizeof(USERDATA));

	// 메모리에 값을 저장한다.
	sprintf_s(pNewUser->strName, sizeof(pNewUser->strName), "%s", pszName);
	pNewUser->nAge = nAge;
	pNewUser->nGender = nGender; 
	pNewUser->pNext = NULL;

	// 더미 노드 바로 뒤에 붙인다. 따라서 가장 최근에
	// 추가한 데이터가 가장 앞쪽에 온다. 
	pNewUser->pNext = g_Head.pNext;
	g_Head.pNext = pNewUser;

	return 1;
}

/////////////////////////////////////////////////////////////////////////
// 이름을 입력받아 리스트에 추가하는 함수
void Add()
{
	char szName[32] = { 0 };
	int nAge = 0;
	int nGender = 0;

	printf("이름을 입력하세요 : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	printf("나이를 입력하세요 : ");
	fflush(stdin);
	scanf_s("%d", &nAge);

	printf("성별을 입력하세요(남성:0, 여성:1) : ");
	fflush(stdin);
	scanf_s("%d", &nGender);

	// 실제로 리스트에 추가한다.
	AddNewNode(szName, nAge, nGender);
}

/////////////////////////////////////////////////////////////////////////
// 특정 노드를 검색하는 함수
void Search()
{
	char szName[32] = { 0 };
	USERDATA* pNode = NULL;

	printf("검색할 이름을 입력하세요 : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	pNode = FindNode(szName);
	if (pNode != NULL) {
		printf("[%p] %s\t%d세\t%s\n",
			pNode,
			pNode->strName,
			pNode->nAge,
			pNode->nGender ? "여성" : "남성");
	}
	else {
		puts("ERROR: 데이터를 찾을 수 없습니다.");
	}

	_getch();
}

/////////////////////////////////////////////////////////////////////////
// 리스트에 들어있는 모든 데이터를 화면에 출력하는 함수
void PrintAll()
{
	int nCount = 0;
	USERDATA* pTmp = g_Head.pNext;
	while (pTmp != NULL) {
		printf("[%p] %s\t%d세\t%s\n",
			pTmp,
			pTmp->strName,
			pTmp->nAge,
			pTmp->nGender ? "여성" : "남성");

		pTmp = pTmp->pNext;
		nCount++;
	}
	if (nCount == 0)
		printf("데이터가 존재하지 않습니다.\n");
	_getch();
}

/////////////////////////////////////////////////////////////////////////
// 특정 노드를 검색하고 삭제하는 함수
int RemoveNode(char* pszName)
{
	USERDATA* pPrevNode = &g_Head;
	USERDATA* pDelete = NULL;

	while (pPrevNode->pNext != NULL) {
		pDelete = pPrevNode->pNext;

		if (strcmp(pDelete->strName, pszName) == 0) {
			pPrevNode->pNext = pDelete->pNext;
			free(pDelete);

			printf("%s 정보를 삭제합니다.\n", pszName);
			_getch();

			return 1;
		}

		pPrevNode = pPrevNode->pNext;
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////
// 이름을 입력받아 자료를 검색하고 삭제하는 함수
void Remove()
{
	char szName[32] = { 0 };

	printf("삭제할 이름을 입력하세요 : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	RemoveNode(szName);
}

/////////////////////////////////////////////////////////////////////////
// 메뉴를 출력하는 UI 함수
int PrintUI()
{
	int nInput = 0;

	system("cls");
	printf("===================================================\n");
	printf("전화번호부(Linked List)\n");
	printf("---------------------------------------------------\n");
	printf("[1] 추가\t [2] 검색\t [3] 전체보기\t [4] 삭제\t [0] 종료\n");
	printf("===================================================\n");

	// 사용자가 선택한 메뉴의 값을 반환한다.
	scanf_s("%d", &nInput);
	getchar();//버퍼에 남은 엔터 제거용
	return nInput;
}

/////////////////////////////////////////////////////////////////////////
// 데이터 파일에서 노드들을 읽어와 리스트를 완성하는 함수
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
// 리스트 형태로 존재하는 정보를 파일에 저장하는 함수
int SaveList(char* pszFileName)
{
	FILE* fp = NULL;
	USERDATA* pTmp = g_Head.pNext;

	fopen_s(&fp, pszFileName, "wb");

	if (fp == NULL) {
		puts("ERROR: 리스트 파일을 쓰기 모드로 열지 못했습니다.");
		_getch();

		return 0;
	}

	while (pTmp != NULL) {
		if (fwrite(pTmp, sizeof(USERDATA), 1, fp) != 1)
			printf("ERROR: %s에 대한 정보를 저장하는데 실패했습니다.\n", pTmp->strName);

		pTmp = pTmp->pNext;
	}

	fclose(fp);

	return 1;
}

/////////////////////////////////////////////////////////////////////////
// 리스트의 모든 데이터를 삭제하는 함수
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

	// 메인 이벤트 반복문
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

	// 종료 전에 파일로 저장하고 메모리를 해제한다.
	//SaveList(DATA_FILE_NAME);
	ReleaseList();
}

#endif