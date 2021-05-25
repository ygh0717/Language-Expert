// Win32.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
#define ON_MAIN
#ifdef ON_MAIN
#include "framework.h"
#include "Win32_1.h"

#define MAX_LOADSTRING 100
#define BINGO_SIZE 3

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ�
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸�

// �� �ڵ� ��⿡ ���Ե� �Լ��� ������ ����
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    ChildWndProc(HWND, UINT, WPARAM, LPARAM);

LPCTSTR lpszChildClass = TEXT("ChildWnd");

BOOL g_bMyTurn = TRUE;

enum modeBINGO {
    bingoNONE,
    bingoMINE,
    bingoMyBINGO,
    bingoYOURS,
    bingoYourBINGO
};

HWND arrBingo[BINGO_SIZE][BINGO_SIZE];

//Program Start
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN321, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance); //���

    // ���ø����̼� �ʱ�ȭ
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN321));

    MSG msg;

    // �⺻ �޽��� �����Դϴ�: ���� ���ѷ��� - �ٽ�
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);  //����(����)
        }
    }
    return (int)msg.wParam;
}
//  ���� �̸� ���
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_WIN321));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WIN321);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    RegisterClassExW(&wcex);

    // 1. LeftChild Class
    static HBRUSH hRed = CreateSolidBrush(RGB(255, 0, 0));

    wcex.hbrBackground = hRed;
    wcex.lpfnWndProc = ChildWndProc;
    wcex.lpszClassName = lpszChildClass;
    wcex.hCursor = LoadCursor(NULL, IDC_CROSS);
    wcex.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);

    RegisterClassExW(&wcex);

    return 0;
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ ����

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

// ����
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int x, y;
    HDC hdc;
    PAINTSTRUCT ps;

    switch (message)
    {
    case WM_CREATE:
    {
        for (int x = 0; x < BINGO_SIZE; x++)
        {
            for (int y = 0; y < BINGO_SIZE; y++)
            {
                arrBingo[x][y] = CreateWindow(lpszChildClass, NULL,
                    WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN,
                    x * 100, y * 100, 100, 100, hWnd, (HMENU)0, hInst, NULL);
            }
        }
    }
    break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    BOOL nProp;
    switch (message)
    {
    case WM_CREATE:
    {
        SetProp(hWnd, TEXT("������"), (HANDLE)bingoNONE);//�ʱ�ȭ
    }
    break;

    case WM_LBUTTONDOWN:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        TCHAR str[256];

        nProp = (BOOL)GetProp(hWnd, TEXT("������"));
        GetWindowText(hWnd, str, 256);

        if (nProp == bingoNONE)
        {
            if (g_bMyTurn == TRUE) // ���׶��
            {
                 SetProp(hWnd, TEXT("������"), (HANDLE)bingoMINE);
                 SetWindowText(hWnd, TEXT("���� ����"));
            }
            else if(g_bMyTurn == FALSE) // X
            {
                 SetProp(hWnd, TEXT("������"), (HANDLE)bingoYOURS);
                 SetWindowText(hWnd, TEXT("���� ����"));
            }
        }

        int x, y = 0;
        for (int i = 0; i < BINGO_SIZE; i++)
        {
            for (int j = 0; j < BINGO_SIZE; j++)
            {

            }
        }

        InvalidateRect(hWnd, NULL, TRUE);
    }
    break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        nProp = (BOOL)GetProp(hWnd, TEXT("������"));
        
        if (nProp == bingoNONE)
        {
            Rectangle(hdc, 10, 10, 90, 90);
        }
        else if(nProp == bingoMINE)
        {
            Ellipse(hdc, 10, 10, 90, 90);
            g_bMyTurn = FALSE;
        }
        else if (nProp == bingoYOURS)
        {
            MoveToEx(hdc, 10, 10, NULL);  LineTo(hdc, 90, 90);
            MoveToEx(hdc, 10, 90, NULL);  LineTo(hdc, 90, 10);
            g_bMyTurn = TRUE;
        }
        else if (nProp == bingoMyBINGO)
        {
            // TODO : Color and Text
        }
        else if (nProp == bingoYourBINGO)
        {
            // TODO : Color and Text
        }
        EndPaint(hWnd, &ps);

        return 0;
    }
    break;

    case WM_DESTROY:
    {
        RemoveProp(hWnd, TEXT("������"));

        PostQuitMessage(0);
    }
    break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);    //Windows��� �翬�� �Ǵ� �κ� ���� © �ʿ䰡 ����(move, �ִ�ȭ, �ּ�ȭ)
    }
    return 0;
}

#endif