// Win32.cpp : 애플리케이션에 대한 진입점을 정의합니다.
#define ON_MAIN
#ifdef ON_MAIN
#include "framework.h"
#include "Win32.h"

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
    LoadStringW(hInstance, IDC_WIN32, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance); //등록

    // 애플리케이션 초기화
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32));

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
        case 1: //현재 시각을 구해서 화면에 출력
            SYSTEMTIME st;
            GetLocalTime(&st);

            wsprintf(sTime, TEXT("지금 시간은 %d시 %d분 %d초입니다"),
                st.wHour, st.wMinute, st.wSecond);

            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 2: //공지 대화상자를 출력
            MessageBox(hWnd, TEXT("지금은 쉬는시간 신이 만든 시간"),
                TEXT("중요알림"), MB_YESNO);
            MessageBeep(0);
            break;

        }
    }
    break;

    case WM_RBUTTONDOWN:
    {
        KillTimer(hWnd, 1);     //Timer 죽이는 시점
        KillTimer(hWnd, 2);     //Timer 죽이는 시점
    }
    break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

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