// Win32.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
//#define ON_MAIN
#ifdef ON_MAIN
#include "framework.h"
#include "Win32_1.h"

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

//
//  �Լ�: MyRegisterClass()
//
//  �뵵: â Ŭ������ ����մϴ�.
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

    return RegisterClassExW(&wcex);
}

//   �Լ�: InitInstance(HINSTANCE, int)
//
//   �뵵: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   �ּ�:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ ����

    HWND hWnd = CreateWindowW(szWindowClass, _T("KeyDown"), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr); 

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  �뵵: �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���ø����̼� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.

// ����
// ����� ������ case �߰��ؼ� ��� -> ���콺 �Ƿη�
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static TCHAR* mem;
    static TCHAR str[256] = { 0 };
    int len;
    static int x1 = 100;
    static int y1 = 100;
    static int x2 = 200;
    static int y2 = 200;

    switch (message)
    {
    case WM_CHAR:   //Ű���忡�� ���� Ű�� ������ ��
    {
        if ((TCHAR)wParam == ' ')
        {
            str[0] = 0;
        }
        else
        {
            len = lstrlen(str);
            str[len] = (TCHAR)wParam;
            str[len + 1] = 0;
        }

        InvalidateRect(hWnd, NULL, TRUE);  //WM_PAINT �߻�

        return 0;
    }
    break;

    case WM_KEYDOWN:    //Ű���忡�� ���� Ű�� ������ ��
    {
        switch (wParam)
        {
        case VK_LEFT:
            x1 -= 8; break;
        case VK_RIGHT:
            x2 += 8; break;
        case VK_UP:
            y1 -= 8; break;
        case VK_DOWN:
            y2 += 8; break;
        }
        InvalidateRect(hWnd, NULL, FALSE);  //WM_PAINT �߻�
    }
    break;

    case WM_MOUSEMOVE:
    {
        x1 = LOWORD(lParam);
        y1 = HIWORD(lParam);
        //InvalidateRect(hWnd, NULL, FALSE);  //WM_PAINT �߻�
        InvalidateRect(hWnd, NULL, TRUE);  //WM_PAINT �߻�
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...

        TextOut(hdc, x1, y1, _T("�ȳ��ϼ���. �������Դϴ�."), 14);
        TextOut(hdc, x2, y2, _T("O"), 1);

        TextOut(hdc, 100, 100, str, lstrlen(str));

        return 0;

        EndPaint(hWnd, &ps);
    }
    break;

    case WM_CREATE: //������ ����
    {
        mem = (TCHAR*)malloc(1048576);
    }
    break;

    case WM_DESTROY: //������ �ı�
        free(mem);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);    //Windows��� �翬�� �Ǵ� �κ� ���� © �ʿ䰡 ����(move, �ִ�ȭ, �ּ�ȭ)
    }
    return 0;
}
enum modeBINGO {
    bingoNONE,
    bingoMINE,
    bingoMyBINGO,
    bingoYOURS,
    bingoYourBINGO
};

typedef struct {

    int row;
    int col;

    HWND HID;

}BINGO;
#endif