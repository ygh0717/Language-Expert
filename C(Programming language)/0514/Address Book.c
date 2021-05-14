#include<stdio.h>
#include<windows.h>
#include <ctype.h>

#define     MAX_BOOKCOUNT   10
#define     LABEL_MAX       4
#define     NAME_MAX        32
#define     P_NUMVER_MAX    20
#define     DATA_FILE_NAME  //"The path you want."

typedef struct _USERDATA
{
    char strName[NAME_MAX];     // 이름
    int nAge;           // 나이
    int nGender;        // 성별
    char strPhoneNumber[P_NUMVER_MAX];
    struct Info* Link;

} USERDATA;

int        g_nCount = 0;
USERDATA   g_AddrBook[MAX_BOOKCOUNT];

const enum Menu { EXIT = 0, ADD, SEARCH, DEL, LIST };
const char* szLabel[LABEL_MAX] = { "입력","검색","삭제","목록보기" };

int LoadData(char* szFileName); // [1] 성공 [0] 실패 [시작시 호출1회]
int SaveData(char* szFileName); // 종료시 호출1회


void menu(const char* szLabel[], int* nMenu);
void Add();
void Delete();
void PrintAll();
void Search();
int NameSearch(char* name);


int main(void)
{
    LoadData(DATA_FILE_NAME); // [1] 성공 [0] 실패 [시작시 호출1회]
    int nMenu = -1;

    for (;;)
    {
        menu(szLabel, &nMenu);

        if (nMenu == ADD)
            Add();
        else if (nMenu == SEARCH)
            Search();
        else if (nMenu == DEL)
            Delete();
        else if (nMenu == LIST)
            PrintAll();
        else if (nMenu == EXIT)
        {
            printf("종료합니다. \n\n");
            SaveData(DATA_FILE_NAME); // 종료시 호출1회
            return 0;
        }
        else
        {
            printf("다시 입력해주세요.");
        }
        Sleep(1000);
        system("cls");
    }

    
    return 0;
}



void menu(const char* szLabel[], int* nMenu)
{
    printf("==========================================\n");
    printf("\t전화번호부(Array)\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < LABEL_MAX; i++) {
        printf("\t%d. %s \n", i + 1, szLabel[i]);
    }

    printf("\t0. 종료 \n");
    printf("==========================================\n");

    printf("\t원하는 기능을 선택하세요 : ");
    scanf_s("\t%d", nMenu);
    getchar();
}

//추가
void Add()
{
    char strName[15] = { NULL };
    char strPhoneNum[15] = { NULL };
    int nAge = 0;
    int nGender = 0;
    int nChoice = -1;

    if (g_nCount > MAX_BOOKCOUNT)
    {
        printf("주소록 용량초과로 추가하지 못합니다.");
        return;
    }

    printf("이름을 입력하세요 : ");
    gets(strName);

    if (NameSearch(strName) == 1)
    {
        printf("중복된 이름입니다.\n");
        return;
    }

    printf("나이를 입력하세요 : ");
    scanf_s("%d", &nAge);

    printf("성별을 입력하세요(남성:0, 여성 :1) : ");
    scanf_s("%d", &nGender);

    printf("전화번호를 입력하세요(-포함) : ");
    scanf_s("%s", strPhoneNum, sizeof(strPhoneNum));

    printf("이름 : %s,성별 : %s, 나이 : %d세 전화번호 : %s  저장하시겠습니까? yes(1)/no(0) : ",
        strName,
        nGender == 0 ? "남성" : "여성",
        nAge,
        strPhoneNum);

    scanf_s("%d", &nChoice);
    if (nChoice != 0 && nChoice != 1) {
        printf("잘못입력하셨습니다. 다시 입력하세요\n ");
        return;
    }

    if (nChoice == 1) {
        strcpy_s(g_AddrBook[g_nCount].strName, sizeof(g_AddrBook[g_nCount].strName), strName);
        strcpy_s(g_AddrBook[g_nCount].strPhoneNumber, sizeof(g_AddrBook[g_nCount].strPhoneNumber), strPhoneNum);
        g_AddrBook[g_nCount].nAge = nAge;
        g_AddrBook[g_nCount].nGender = nGender;
        g_AddrBook[g_nCount].Link = g_AddrBook + (g_nCount + 1);

        g_nCount++;
    }
    else { return; }

}
//전체 출력
void PrintAll()
{
    if (g_nCount == 0) {
        printf("목록이 없습니다.\n");
        return;
    }

    printf("----%d개의 연락처----\n\n", g_nCount);
    for (int i = 0; i < g_nCount; i++) {

        printf("%d. 이름 : %s \t ,성별 : %s\t, 나이 : %d세\t,  전화번호 : %s\n",
            i + 1,
            g_AddrBook[i].strName,
            g_AddrBook[i].nGender == 0 ? "남성" : "여성",
            g_AddrBook[i].nAge,
            g_AddrBook[i].strPhoneNumber);
    }
    getch();
}
//검색
void Search()
{
    char strName[15] = { NULL };
    int cmpResult = -1;
    if (g_nCount == 0)
        printf("목록에 아무도 없습니다.");
    else
    {
        printf("검색할 분의 이름을 입력하세요 : ");
        gets(strName);

        for (int i = 0; i < g_nCount; i++)
        {
            cmpResult = strcmp(g_AddrBook[i].strName, strName);
            if (cmpResult == 0)
            {
                printf("%d번. 이름 : %s \t ,성별 : %s\t, 나이 : %d세\t,  전화번호 : %s\n",
                    i + 1,
                    g_AddrBook[i].strName,
                    g_AddrBook[i].nGender == 0 ? "남성" : "여성",
                    g_AddrBook[i].nAge,
                    g_AddrBook[i].strPhoneNumber);
                getch();

            }
        }
        if (cmpResult != 0)
            printf("검색한 사람이 없습니다.  ");

        Sleep(2000);
    }
}
//삭제
void Delete()
{
    char strName[15] = { NULL };
    int cmpResult = -1;

    if (g_nCount == 0)
        printf("목록에 아무도 없습니다.");

    else
    {
        printf("삭제할 대상의 이름을 입력하세요 : ");
        gets(strName);

        for (int i = 0; i < g_nCount; i++)
        {
            cmpResult = strcmp(g_AddrBook[i].strName, strName);
            if (cmpResult == 0)
            {
                *(g_AddrBook + i)->strName = NULL;
                *(g_AddrBook + i)->strPhoneNumber = NULL;
                g_AddrBook[i].nGender = NULL;
                g_AddrBook[i].nAge = NULL;
                g_AddrBook[i].Link = NULL;

                for (; i <= g_nCount; i++)
                    g_AddrBook[i] = g_AddrBook[i + 1];

                printf("%s 삭제완료", strName);
                Sleep(1000);
                g_nCount--;
                return;
            }
        }
        if (cmpResult == 1)
            printf("삭제할 대상이 없습니다.");
        Sleep(1000);
        getchar();
    }
}

int NameSearch(char* name)
{
    int cmpResult = -1;

    for (int i = 0; i < g_nCount; i++)
    {
        cmpResult = strcmp(g_AddrBook[i].strName, name);
        if (cmpResult == 0)
            return 1; //있다
    }
    return 0;
}

int LoadData(char* szFileName)
{
    //g_AddrBook <- szFileName
    //1. 스트림(파일) 개방 (rb모드)
    FILE* fp = NULL;
    fopen_s(&fp, szFileName, "rb");

    if (fp == NULL)
        return;

    fread(&g_nCount, sizeof(int), 1, fp);

    //2. 스트림(파일)에서 읽기
    for (int i = 0; i< g_nCount; i++)
    {
        fread(g_AddrBook + i, sizeof(USERDATA), 1, fp);
    }

    //3. 스트림(파일) 폭파
    fclose(fp);

    return 0;
}

int SaveData(char* szFileName)
{
    //g_AddrBook -> szFileName
    // ------------------------
    //1. 스트림(파일) 개방 (wb모드)
    FILE* fp = NULL;
    fopen_s(&fp, szFileName, "wb");

    fwrite(&g_nCount, sizeof(int), 1, fp);
    //2. 스트림(파일)에 저장
    for (int i = 0; i< g_nCount; i++)
    {
        fwrite(g_AddrBook+i, sizeof(USERDATA), 1, fp);
    }

    //3. 스트림(파일) 폭파
    fclose(fp);

    return 0;
}