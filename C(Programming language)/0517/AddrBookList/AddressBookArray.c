#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define ADDRBOOK_ARRAY
#ifdef ADDRBOOK_ARRAY

/////////////////////////////////////////////////////////////////////////
// 주소록이 저장될 데이터 파일
#define DATA_FILE_NAME "c:\\temp\\AddrBook_Arr.dat"

/////////////////////////////////////////////////////////////////////////
void ReleaseList();

/////////////////////////////////////////////////////////////////////////
typedef struct _USERDATA
{
	char strName[32];	  // 이름
	int nAge;			  // 나이
	int nGender;		  // 성별
} USERDATA;

//배열로 처리
#define		MAX_BOOKCOUNT	5
int			g_nCount = 0;
USERDATA	g_AddrBook[ MAX_BOOKCOUNT ];

/////////////////////////////////////////////////////////////////////////
// 리스트에서 이름으로 특정 노드를 검색하는 함수
USERDATA* FindNode(char* pszName)
{
	for (int i = 0; i < g_nCount; i++)
	{
		if (strcmp(g_AddrBook[i].strName, pszName) == 0)
			return g_AddrBook + i;
	}

	// 일치하는 데이터를 찾지 못한 경우
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
// 이름을 입력받아 리스트에 추가하는 함수
void Add()
{
	char szName[32] = { 0 };
	int nAge = 0;
	int nGender = 0;

	if (g_nCount + 1 > MAX_BOOKCOUNT)
	{
		printf("주소록 용량초과로 추가하지 못합니다\n");
		_getch();
		return;
	}

	printf("이름을 입력하세요 : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));
		
	// 같은 이름이 이미 존재하는지 확인한다.
	if (FindNode(szName) != NULL)
	{
		printf("같은 이름이 이미 존재하여 추가하지 못합니다\n");
		_getch();
		return;
	}
		
	printf("나이를 입력하세요 : ");
	fflush(stdin);
	scanf_s("%d", &nAge);

	printf("성별을 입력하세요(남성:0, 여성:1) : ");
	fflush(stdin);
	scanf_s("%d", &nGender);


	// 실제로 배열에 정보를 추가한다.
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
	USERDATA* pTmp;
	for (int i = 0; i < g_nCount; i++)
	{
		pTmp = &g_AddrBook[i];
		printf("[%p] %s\t%d세\t%s\n",
			pTmp,
			pTmp->strName,
			pTmp->nAge,
			pTmp->nGender ? "여성" : "남성");
	}
	if (g_nCount == 0)
		printf("데이터가 존재하지 않습니다.\n");
	_getch();
}

/////////////////////////////////////////////////////////////////////////
// 특정 노드를 검색하고 삭제하는 함수
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
	printf("전화번호부(Array)\n");
	printf("---------------------------------------------------\n");
	//printf("[1] 추가\t [2] 검색\t [3] 전체보기\t [4] 삭제\t [0] 종료\n");
	printf("[1] 추가\t [2] 검색\t [3] 전체보기\t [0] 종료\n");
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
	if (fp == NULL)	return 0;

	ReleaseList();
	//헤더정보 읽기: 주소록 전체갯수
	fread(&g_nCount, sizeof(g_nCount), 1, fp);
	//바디정보 읽기: 주소록 내용
	for (int i = 0; i < g_nCount; i++)
	{
		fread(g_AddrBook+i, sizeof(USERDATA), 1, fp);
		//AddNewNode(user.strName, user.nAge, user.nGender);
	}
	fclose(fp);
	return 0;
}

/////////////////////////////////////////////////////////////////////////
// 리스트 형태로 존재하는 정보를 파일에 저장하는 함수
int SaveList(char* pszFileName)
{
	FILE* fp = NULL;
	USERDATA* pTmp;

	fopen_s(&fp, pszFileName, "wb");

	if (fp == NULL) {
		puts("ERROR: 리스트 파일을 쓰기 모드로 열지 못했습니다.");
		_getch();
		return 0;
	}
	//헤더정보 저장: 주소록 전체갯수
	fwrite(&g_nCount, sizeof(g_nCount), 1, fp);
	//바디정보 저장: 주소록 내용
	for (int i = 0; i < g_nCount; i++)
	{
		pTmp = g_AddrBook + i;
		if (fwrite(pTmp, sizeof(USERDATA), 1, fp) != 1)
			printf("ERROR: %s에 대한 정보를 저장하는데 실패했습니다.\n", pTmp->strName);
	}
	fclose(fp);
	
	return 1;
}

/////////////////////////////////////////////////////////////////////////
// 리스트의 모든 데이터를 삭제하는 함수
void ReleaseList()
{
	//배열 초기화
	memset(g_AddrBook, 0, sizeof(g_AddrBook));
	g_nCount = 0;
}

void main()
{
	int nMenu = 0;
	LoadList(DATA_FILE_NAME);

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
	SaveList(DATA_FILE_NAME);
	ReleaseList();
}
#endif