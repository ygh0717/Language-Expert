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

// WndProc
LRESULT CALLBACK    ChildLeftProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    ChildTopProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    ChildBottomProc(HWND, UINT, WPARAM, LPARAM);

// HWND
HWND hC1, hC2, hC3;

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

//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//  포수 이름 등록
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

    /////////////////////////////////////////////////////////////////
    // ChildWindow Regist
    // 1. LeftChild Class
    static HBRUSH hRed = CreateSolidBrush(RGB(255, 0, 0));
    
    wcex.hbrBackground = hRed;
    wcex.lpfnWndProc = ChildLeftProc;
    wcex.lpszClassName = _T("ChildLeft");
    RegisterClassExW(&wcex);

    // 2. TopChild Class
    static HBRUSH hGreen = CreateSolidBrush(RGB(0, 255, 0));

    wcex.hbrBackground = hGreen;
    wcex.lpfnWndProc = ChildTopProc;
    wcex.lpszClassName = _T("ChildTop");
    RegisterClassExW(&wcex);
    
    // 3. BottomChild Class
    static HBRUSH hBlue = CreateSolidBrush(RGB(0, 0, 255));

    wcex.hbrBackground = hBlue;
    wcex.lpfnWndProc = ChildBottomProc;
    wcex.lpszClassName = _T("ChildBottom");
    RegisterClassExW(&wcex);

    return 0;
}

//   함수: InitInstance(HINSTANCE, int)

HWND g_hMainWnd;

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    g_hMainWnd = hWnd;

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.

// 포수
// 만들고 싶으면 case 추가해서 사용 -> 마우스 또로롱
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        hC1 = CreateWindow(_T("ChildLeft"), NULL,
            WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN,
            0, 0, 0, 0, hWnd, (HMENU)0, hInst, NULL);

        hC2 = CreateWindow(_T("ChildTop"), NULL,
                WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN,
                0, 0, 0, 0, hWnd, (HMENU)0, hInst, NULL);

        hC3 = CreateWindow(_T("ChildBottom"), NULL,
            WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN,
            0, 0, 0, 0, hWnd, (HMENU)0, hInst, NULL);
    }
    break;

    case WM_SIZE:
    {
        if (wParam != SIZE_MINIMIZED)
        {
            RECT crt;
            GetClientRect(hWnd, &crt);
            MoveWindow(hC1, 0, 0, 300, crt.bottom, TRUE);
            MoveWindow(hC2, 300, 0, crt.right-300, 150, TRUE);
            MoveWindow(hC3, 300, 150, crt.right-300, crt.bottom, TRUE);
        }
        return 0;
    }
    break;

    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
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

LRESULT CALLBACK ChildLeftProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND hEdit, hBtn;

    switch (message)
    {
    case WM_CREATE:
    {
        hEdit = CreateWindow(TEXT("EDIT"), NULL,
            WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
            10, 10, 100, 25,
            hWnd, (HMENU)1, hInst, NULL);

        hBtn = CreateWindow(TEXT("BUTTON"), TEXT("Add"),
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            10, 50, 100, 25,
            hWnd, (HMENU)2, hInst, NULL);
        break;
    }
    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
            case 2:
            {
                TCHAR str[256];
                // 1. EDIT 창의 글자읽기
                GetWindowText(hEdit, str, 256);
                // 2. 글자를 MAIN 창에 쓰기
                SetWindowText(hBtn, str);
                SetWindowText(g_hMainWnd, str);
                // 3. EDIT 창을 초기화하기
                SetWindowText(hEdit, _T(""));
            }
            break;
        }
    break;
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);    //Windows라면 당연히 되는 부분 굳이 짤 필요가 없음(move, 최대화, 최소화)
    }
    return 0;
}

LRESULT CALLBACK ChildTopProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        
        SetBkMode(hdc, TRANSPARENT);

        TextOut(hdc, 10, 10, _T("안녕하세요. 반가워요."), 12);

        EndPaint(hWnd, &ps);
    }
    break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);    //Windows라면 당연히 되는 부분 굳이 짤 필요가 없음(move, 최대화, 최소화)
    }
    return 0;
}

LRESULT CALLBACK ChildBottomProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND hEdit;

    switch (message)
    {
    case WM_CREATE:
    {
        hEdit = CreateWindow(TEXT("EDIT"), NULL,
            WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_MULTILINE,
            10, 10, 500, 500,
            hWnd, (HMENU)1, hInst, NULL);

        SetWindowText(hEdit, _T("여러분의 이야기를 써주세요."));

        break;
    }

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);    //Windows라면 당연히 되는 부분 굳이 짤 필요가 없음(move, 최대화, 최소화)
    }
    return 0;
}
#endif