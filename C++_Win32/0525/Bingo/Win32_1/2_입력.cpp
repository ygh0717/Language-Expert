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
    static TCHAR* mem;
    static TCHAR str[256] = { 0 };
    int len;
    static int x1 = 100;
    static int y1 = 100;
    static int x2 = 200;
    static int y2 = 200;

    switch (message)
    {
    case WM_CHAR:   //키보드에서 문자 키가 눌렸을 때
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

        InvalidateRect(hWnd, NULL, TRUE);  //WM_PAINT 발생

        return 0;
    }
    break;

    case WM_KEYDOWN:    //키보드에서 문자 키가 눌렸을 때
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
        InvalidateRect(hWnd, NULL, FALSE);  //WM_PAINT 발생
    }
    break;

    case WM_MOUSEMOVE:
    {
        x1 = LOWORD(lParam);
        y1 = HIWORD(lParam);
        //InvalidateRect(hWnd, NULL, FALSE);  //WM_PAINT 발생
        InvalidateRect(hWnd, NULL, TRUE);  //WM_PAINT 발생
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

        TextOut(hdc, x1, y1, _T("안녕하세요. 윤강희입니다."), 14);
        TextOut(hdc, x2, y2, _T("O"), 1);

        TextOut(hdc, 100, 100, str, lstrlen(str));

        return 0;

        EndPaint(hWnd, &ps);
    }
    break;

    case WM_CREATE: //윈도우 생성
    {
        mem = (TCHAR*)malloc(1048576);
    }
    break;

    case WM_DESTROY: //윈도우 파괴
        free(mem);
        PostQuitMessage(0);
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

typedef struct {

    int row;
    int col;

    HWND HID;

}BINGO;
#endif