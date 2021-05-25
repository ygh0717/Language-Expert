// Win32.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//#define ON_MAIN
#ifdef ON_MAIN
#include "framework.h"
#include "Win32_1.h"

#define MAX_LOADSTRING 100
// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
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

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN321, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN321));

    MSG msg;

    // 기본 메시지 루프입니다:
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

    return RegisterClassExW(&wcex);
}

//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장

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
                    _T("메모장을 먼저 실행해 주세요."),
                    _T("알림"), MB_OK);
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
#endif