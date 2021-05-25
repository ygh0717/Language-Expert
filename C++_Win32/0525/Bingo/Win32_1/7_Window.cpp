// Win32.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
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

static HBRUSH hRed, hGreen, hBlue;
static HBRUSH NowBrush;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        hRed = CreateSolidBrush(RGB(rand()%256, rand() % 256, rand() % 256));
        hGreen = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
        hBlue = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));

        NowBrush = hRed;

        /*HBRUSH Oldbr = (HBRUSH)SelectObject(hdc, hRed);
        HBRUSH Oldbr = (HBRUSH)SelectObject(hdc, hGreen);
        HBRUSH Oldbr = (HBRUSH)SelectObject(hdc, hBlue);
        SelectObject(hdc, Oldbr);
        EndPaint(hWnd, &ps);*/
    }
    break;
    case WM_KEYDOWN:
    {
        if(wParam == VK_SPACE)
        DestroyWindow(hWnd);
        else if(wParam == VK_UP)
        SetWindowPos(hWnd, NULL, 0, 0, 100, 100,
            SWP_NOMOVE | SWP_NOZORDER);
        else if (wParam == VK_DOWN)
            SetWindowPos(hWnd, NULL, 0, 0, 500, 500,
                SWP_NOMOVE | SWP_NOZORDER);
        else if (wParam == VK_LEFT)
        {
            if (NowBrush == hRed)    NowBrush = hGreen;
            else if (NowBrush == hGreen)    NowBrush = hBlue;
            else if (NowBrush == hBlue)    NowBrush = hRed;
            SetClassLongPtr(hWnd, GCLP_HBRBACKGROUND, (LONG_PTR)NowBrush);
            InvalidateRect(hWnd, NULL, TRUE);
        }
    }
    break;
    case WM_CHAR:
    {
        if ((TCHAR)wParam == 'n')
        {
            HWND hNote;
            hNote = FindWindow(_T("NotePad"), NULL);
            if (hNote)
            {
                SendMessage(hNote, WM_CLOSE, NULL, NULL);
            }
            else
            {
                MessageBox(hWnd,
                    _T("�޸����� ���� ������ �ּ���."),
                    _T("�˸�"), MB_OK);
            }
        }
    }
    break;
    case WM_LBUTTONDOWN:
    {
        SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 100, 100,
            SWP_NOMOVE | SWP_NOSIZE);
    }
    break;
    case WM_RBUTTONDOWN:
    {
        SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 100, 100,
            SWP_NOMOVE | SWP_NOSIZE);
    }
    break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // �޴� ������ ���� �м��մϴ�:
        switch (wmId)
        {
        case IDM_ABOUT:
            //DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
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