// Win32.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//#define ON_MAIN
#ifdef ON_MAIN
#include "framework.h"
#include "Win32_1.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름

// 이 코드 모듈에 포함된 함수의 선언을 전달
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

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN321, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance); //등록

    // 애플리케이션 초기화
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN321));

    MSG msg;

    // 기본 메시지 루프입니다: 거의 무한루프 - 핵심
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);  //투수(던져)
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
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

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
            MessageBox(hWnd, _T("상대 프로그램이 실행중이 아닙니다."),
                       _T("긴급공지"), MB_OK);
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
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);    //Windows라면 당연히 되는 부분 굳이 짤 필요가 없음(move, 최대화, 최소화)
    }
    return 0;
}
#endif