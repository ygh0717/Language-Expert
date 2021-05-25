// Win32_1.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
//
//#define ON_MAIN
#ifdef ON_MAIN
#include "framework.h"
#include "Win32_1.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ���Ե� �Լ��� ������ �����մϴ�:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN321, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���ø����̼� �ʱ�ȭ�� �����մϴ�:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN321));

    MSG msg;

    // �⺻ �޽��� �����Դϴ�:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

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

//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  �뵵: �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���ø����̼� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.

// ����
// ����� ������ case �߰��ؼ� ��� -> ���콺 �Ƿη�

HWND hStatic;
HWND hEdit;
HWND hBtnSave;
#define ID_EDIT_NAME 100
#define ID_BTN_FUCK 101
#define ID_BTN_FUCK2 102

int nTop = 100;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        hEdit = CreateWindowW(_T("EDIT"), _T("I Love You"),
            WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
            10, 100, 200, 25,   // Size
            hWnd, (HMENU)ID_EDIT_NAME, hInst, NULL);

        hStatic = CreateWindowW(_T("STATIC"), _T("�̸� : "),
            WS_CHILD | WS_VISIBLE ,
            20, 20, 100, 25,   // Size
            hWnd, (HMENU)-1, hInst, NULL);
        
        hBtnSave = CreateWindowW(_T("BUTTON"), _T("����"),
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            300, 20, 100, 25,   // Size
            hWnd, (HMENU)ID_BTN_FUCK, hInst, NULL);

        hBtnSave = CreateWindowW(_T("BUTTON"), _T("�μ�"),
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            300, 50, 100, 25,   // Size
            hWnd, (HMENU)ID_BTN_FUCK2, hInst, NULL);
    }
    break;
    case WM_LBUTTONDOWN:
    {
        SetParent(hBtnSave, GetDesktopWindow());
        SetWindowText(hBtnSave, _T("������� ������ ��ư"));
    }
    break;
    case WM_RBUTTONDOWN:
    {
        SetParent(hBtnSave, hWnd);
        SetWindowText(hBtnSave, _T("���ƿ�"));
    }
    break;
    case WM_COMMAND:    //��� ����
    {
        switch (LOWORD(wParam)) 
        {
        case ID_EDIT_NAME:
            if (HIWORD(wParam) == EN_CHANGE)
            {
                TCHAR str[128];
                GetWindowText(hEdit, str, 128);
                SetWindowText(hWnd, str);
                SetWindowText(hStatic, str);
                //SetWindowText(hEdit, str);    ���ѷ����� ����
            }
            break;
        case ID_BTN_FUCK:
            MessageBox(hWnd, TEXT("����"), TEXT("����"), MB_OK);
            break;
        case ID_BTN_FUCK2:
            MessageBox(hWnd, TEXT("�μ�"), TEXT("�μ�"), MB_OK);
            break;
        }
        
    }
    break;
    case WM_KEYDOWN:
    {
        if (wParam == VK_UP || wParam == VK_DOWN)
        {
            if (wParam == VK_UP)      nTop -= 10;
            else                      nTop += 10;
            MoveWindow(hEdit, 10, nTop, 200, 25, TRUE);
        }
        if (wParam == VK_LEFT|| wParam == VK_RIGHT)
        {
            static BOOL bShow = TRUE;
            if (bShow)
            {
                bShow = FALSE;
                ShowWindow(hEdit, SW_HIDE);
                SetWindowText(hEdit, TEXT("�����"));
                SetWindowText(hBtnSave, TEXT("�����"));

            }
            else
            {
                bShow = TRUE;
                ShowWindow(hEdit, SW_SHOW);
                SetWindowText(hEdit, TEXT("��Ÿ��"));
                SetWindowText(hBtnSave, TEXT("��Ÿ��"));
            }
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