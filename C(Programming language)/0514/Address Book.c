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
    char strName[NAME_MAX];     // �̸�
    int nAge;           // ����
    int nGender;        // ����
    char strPhoneNumber[P_NUMVER_MAX];
    struct Info* Link;

} USERDATA;

int        g_nCount = 0;
USERDATA   g_AddrBook[MAX_BOOKCOUNT];

const enum Menu { EXIT = 0, ADD, SEARCH, DEL, LIST };
const char* szLabel[LABEL_MAX] = { "�Է�","�˻�","����","��Ϻ���" };

int LoadData(char* szFileName); // [1] ���� [0] ���� [���۽� ȣ��1ȸ]
int SaveData(char* szFileName); // ����� ȣ��1ȸ


void menu(const char* szLabel[], int* nMenu);
void Add();
void Delete();
void PrintAll();
void Search();
int NameSearch(char* name);


int main(void)
{
    LoadData(DATA_FILE_NAME); // [1] ���� [0] ���� [���۽� ȣ��1ȸ]
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
            printf("�����մϴ�. \n\n");
            SaveData(DATA_FILE_NAME); // ����� ȣ��1ȸ
            return 0;
        }
        else
        {
            printf("�ٽ� �Է����ּ���.");
        }
        Sleep(1000);
        system("cls");
    }

    
    return 0;
}



void menu(const char* szLabel[], int* nMenu)
{
    printf("==========================================\n");
    printf("\t��ȭ��ȣ��(Array)\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < LABEL_MAX; i++) {
        printf("\t%d. %s \n", i + 1, szLabel[i]);
    }

    printf("\t0. ���� \n");
    printf("==========================================\n");

    printf("\t���ϴ� ����� �����ϼ��� : ");
    scanf_s("\t%d", nMenu);
    getchar();
}

//�߰�
void Add()
{
    char strName[15] = { NULL };
    char strPhoneNum[15] = { NULL };
    int nAge = 0;
    int nGender = 0;
    int nChoice = -1;

    if (g_nCount > MAX_BOOKCOUNT)
    {
        printf("�ּҷ� �뷮�ʰ��� �߰����� ���մϴ�.");
        return;
    }

    printf("�̸��� �Է��ϼ��� : ");
    gets(strName);

    if (NameSearch(strName) == 1)
    {
        printf("�ߺ��� �̸��Դϴ�.\n");
        return;
    }

    printf("���̸� �Է��ϼ��� : ");
    scanf_s("%d", &nAge);

    printf("������ �Է��ϼ���(����:0, ���� :1) : ");
    scanf_s("%d", &nGender);

    printf("��ȭ��ȣ�� �Է��ϼ���(-����) : ");
    scanf_s("%s", strPhoneNum, sizeof(strPhoneNum));

    printf("�̸� : %s,���� : %s, ���� : %d�� ��ȭ��ȣ : %s  �����Ͻðڽ��ϱ�? yes(1)/no(0) : ",
        strName,
        nGender == 0 ? "����" : "����",
        nAge,
        strPhoneNum);

    scanf_s("%d", &nChoice);
    if (nChoice != 0 && nChoice != 1) {
        printf("�߸��Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���\n ");
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
//��ü ���
void PrintAll()
{
    if (g_nCount == 0) {
        printf("����� �����ϴ�.\n");
        return;
    }

    printf("----%d���� ����ó----\n\n", g_nCount);
    for (int i = 0; i < g_nCount; i++) {

        printf("%d. �̸� : %s \t ,���� : %s\t, ���� : %d��\t,  ��ȭ��ȣ : %s\n",
            i + 1,
            g_AddrBook[i].strName,
            g_AddrBook[i].nGender == 0 ? "����" : "����",
            g_AddrBook[i].nAge,
            g_AddrBook[i].strPhoneNumber);
    }
    getch();
}
//�˻�
void Search()
{
    char strName[15] = { NULL };
    int cmpResult = -1;
    if (g_nCount == 0)
        printf("��Ͽ� �ƹ��� �����ϴ�.");
    else
    {
        printf("�˻��� ���� �̸��� �Է��ϼ��� : ");
        gets(strName);

        for (int i = 0; i < g_nCount; i++)
        {
            cmpResult = strcmp(g_AddrBook[i].strName, strName);
            if (cmpResult == 0)
            {
                printf("%d��. �̸� : %s \t ,���� : %s\t, ���� : %d��\t,  ��ȭ��ȣ : %s\n",
                    i + 1,
                    g_AddrBook[i].strName,
                    g_AddrBook[i].nGender == 0 ? "����" : "����",
                    g_AddrBook[i].nAge,
                    g_AddrBook[i].strPhoneNumber);
                getch();

            }
        }
        if (cmpResult != 0)
            printf("�˻��� ����� �����ϴ�.  ");

        Sleep(2000);
    }
}
//����
void Delete()
{
    char strName[15] = { NULL };
    int cmpResult = -1;

    if (g_nCount == 0)
        printf("��Ͽ� �ƹ��� �����ϴ�.");

    else
    {
        printf("������ ����� �̸��� �Է��ϼ��� : ");
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

                printf("%s �����Ϸ�", strName);
                Sleep(1000);
                g_nCount--;
                return;
            }
        }
        if (cmpResult == 1)
            printf("������ ����� �����ϴ�.");
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
            return 1; //�ִ�
    }
    return 0;
}

int LoadData(char* szFileName)
{
    //g_AddrBook <- szFileName
    //1. ��Ʈ��(����) ���� (rb���)
    FILE* fp = NULL;
    fopen_s(&fp, szFileName, "rb");

    if (fp == NULL)
        return;

    fread(&g_nCount, sizeof(int), 1, fp);

    //2. ��Ʈ��(����)���� �б�
    for (int i = 0; i< g_nCount; i++)
    {
        fread(g_AddrBook + i, sizeof(USERDATA), 1, fp);
    }

    //3. ��Ʈ��(����) ����
    fclose(fp);

    return 0;
}

int SaveData(char* szFileName)
{
    //g_AddrBook -> szFileName
    // ------------------------
    //1. ��Ʈ��(����) ���� (wb���)
    FILE* fp = NULL;
    fopen_s(&fp, szFileName, "wb");

    fwrite(&g_nCount, sizeof(int), 1, fp);
    //2. ��Ʈ��(����)�� ����
    for (int i = 0; i< g_nCount; i++)
    {
        fwrite(g_AddrBook+i, sizeof(USERDATA), 1, fp);
    }

    //3. ��Ʈ��(����) ����
    fclose(fp);

    return 0;
}