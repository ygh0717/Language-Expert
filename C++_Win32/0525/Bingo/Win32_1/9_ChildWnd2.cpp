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

LPCTSTR lpszChildClass = TEXT("ChildWnd");
LRESULT CALLBACK    ChildWndProc(HWND, UINT, WPARAM, LPARAM);
HWND hC1;

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
// 포수
// 만들고 싶으면 case 추가해서 사용 -> 마우스 또로롱
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                CreateWindow(lpszChildClass, NULL,
                    WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN,
                    x*100, y*100, 100, 100, hWnd, (HMENU)0, hInst, NULL);
            }
        }
        //ChildWnd
        //CreateWindow(_T("lpszChildClass"), NULL,
        /*CreateWindow(lpszChildClass, NULL,
            WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_BORDER,
            10, 10, 100, 100, hWnd, (HMENU)0, hInst, NULL);*/

        //팝업
        /*CreateWindow(lpszChildClass, _T("안녕! 난 팝업!"),
            WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU,
            10, 10, 500, 500, hWnd, (HMENU)0, hInst, NULL);*/
    }
    break;
    
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

BOOL bEllipse = TRUE;
LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    BOOL bProp;
    switch (message)
    {
    case WM_CREATE:
    {
        SetProp(hWnd, TEXT("bEllipse"), (HANDLE)TRUE);
        SetProp(hWnd, TEXT("Count"), (HANDLE)3);
    }
    break;
    case WM_LBUTTONDOWN:
    {
        //bEllipse = !bEllipse;
        bProp = (BOOL)GetProp(hWnd, TEXT("bEllipse"));
        SetProp(hWnd, TEXT("bEllipse"), (HANDLE)!bProp);

        InvalidateRect(hWnd, NULL, TRUE);
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        //if (bEllipse)
        bProp = (BOOL)GetProp(hWnd, TEXT("bEllipse"));
        if(bProp)
        {
            Ellipse(hdc, 10, 10, 90, 90);
        }
        else
        {
        MoveToEx(hdc, 10, 10, NULL);  LineTo(hdc, 90, 90);
        MoveToEx(hdc, 10, 90, NULL);  LineTo(hdc, 90, 10);
        }
        EndPaint(hWnd, &ps);
        return 0;
    }
    break;

    case WM_DESTROY:
    {
        RemoveProp(hWnd, TEXT("bEllipse"));
        PostQuitMessage(0);
    }
    break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);    //Windows라면 당연히 되는 부분 굳이 짤 필요가 없음(move, 최대화, 최소화)
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
#endif