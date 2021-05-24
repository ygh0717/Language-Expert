// Win32.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
#define ON_MAIN
#ifdef ON_MAIN
#include "framework.h"
#include "Win32.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ�
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸�

// �� �ڵ� ��⿡ ���Ե� �Լ��� ������ ����
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_WIN32, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance); //���

    // ���ø����̼� �ʱ�ȭ
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32));

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

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WIN32);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
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

void CALLBACK MyTimerProc(
    HWND unnamedParam1,
    UINT unnamedParam2,
    UINT_PTR unnamedParam3,
    DWORD unnamedParam4)
{
    HDC hdc;
    hdc = GetDC(unnamedParam1);
    for (int i = 0; i < 1000; i++)
    {
        SetPixel(hdc, rand()% 500, rand() %500,
            RGB(0, 255, 0));
    }

    ReleaseDC(unnamedParam1, hdc);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HANDLE hTimer1;
    static HANDLE hTimer2;
    static TCHAR sTime[128];

    switch (message)
    {
    case WM_CREATE:
    {
        //hTimer1 = (HANDLE)SetTimer(hWnd, 1, 1000, NULL);
        //hTimer2 = (HANDLE)SetTimer(hWnd, 2, 5000, NULL);
        SetTimer(hWnd, 2, 100, MyTimerProc);
    }
    break;

    case WM_TIMER:
    {
        switch (wParam)
        {
        case 1: //���� �ð��� ���ؼ� ȭ�鿡 ���
            SYSTEMTIME st;
            GetLocalTime(&st);

            wsprintf(sTime, TEXT("���� �ð��� %d�� %d�� %d���Դϴ�"),
                st.wHour, st.wMinute, st.wSecond);

            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 2: //���� ��ȭ���ڸ� ���
            MessageBox(hWnd, TEXT("������ ���½ð� ���� ���� �ð�"),
                TEXT("�߿�˸�"), MB_YESNO);
            MessageBeep(0);
            break;

        }
    }
    break;

    case WM_RBUTTONDOWN:
    {
        KillTimer(hWnd, 1);     //Timer ���̴� ����
        KillTimer(hWnd, 2);     //Timer ���̴� ����
    }
    break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...

        TextOut(hdc, 100, 100, sTime, lstrlen(sTime));

        EndPaint(hWnd, &ps);
    }
    break;

    case WM_DESTROY:
        PostQuitMessage(0);
        
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
#endif