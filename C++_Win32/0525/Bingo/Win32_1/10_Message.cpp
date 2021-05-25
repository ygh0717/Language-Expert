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

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

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

HWND hWndTarget;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        hWndTarget = FindWindow(NULL, _T("KeyDown"));
        if (hWndTarget == NULL)
        {
            MessageBox(hWnd, _T("��� ���α׷��� �������� �ƴմϴ�."),
                       _T("��ް���"), MB_OK);
        }
    }
    break;
    case WM_LBUTTONDOWN:
    {
        if (hWndTarget) 
        {
            SendMessage(hWndTarget, WM_KEYDOWN, VK_LEFT, 0);
        }
        if (WM_LBUTTONDBLCLK)
        {
            PostQuitMessage(0);
        }
    }
    break;
    case WM_RBUTTONDOWN:
    {
        if (hWndTarget)
        {
            SendMessage(hWndTarget, WM_KEYDOWN, VK_RIGHT, 0);
        }
    }
    break;
    /*case WM_LBUTTONDBLCLK:
    {
        PostQuitMessage(0);
    }
    break;*/
    case WM_KEYDOWN:
    {
        switch (wParam)
        {

        case VK_UP:
            SendMessage(hWndTarget, WM_KEYDOWN, VK_UP, 0);
            break;
        case VK_DOWN:
            SendMessage(hWndTarget, WM_KEYDOWN, WM_KEYDOWN, 0);
            break;
        case VK_LEFT:
            SendMessage(hWndTarget, WM_KEYDOWN, VK_LEFT, 0);
            break;
        case VK_RIGHT:
            SendMessage(hWndTarget, WM_KEYDOWN, VK_RIGHT, 0);
            break;
        default:
            break;
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);    //Windows��� �翬�� �Ǵ� �κ� ���� © �ʿ䰡 ����(move, �ִ�ȭ, �ּ�ȭ)
    }
    return 0;
}
#endif