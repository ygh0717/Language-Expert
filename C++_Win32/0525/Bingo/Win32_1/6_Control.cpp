// Win32_1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
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

//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.

// 포수
// 만들고 싶으면 case 추가해서 사용 -> 마우스 또로롱

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

        hStatic = CreateWindowW(_T("STATIC"), _T("이름 : "),
            WS_CHILD | WS_VISIBLE ,
            20, 20, 100, 25,   // Size
            hWnd, (HMENU)-1, hInst, NULL);
        
        hBtnSave = CreateWindowW(_T("BUTTON"), _T("저장"),
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            300, 20, 100, 25,   // Size
            hWnd, (HMENU)ID_BTN_FUCK, hInst, NULL);

        hBtnSave = CreateWindowW(_T("BUTTON"), _T("인쇄"),
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            300, 50, 100, 25,   // Size
            hWnd, (HMENU)ID_BTN_FUCK2, hInst, NULL);
    }
    break;
    case WM_LBUTTONDOWN:
    {
        SetParent(hBtnSave, GetDesktopWindow());
        SetWindowText(hBtnSave, _T("윈도우로 도망간 버튼"));
    }
    break;
    case WM_RBUTTONDOWN:
    {
        SetParent(hBtnSave, hWnd);
        SetWindowText(hBtnSave, _T("돌아옴"));
    }
    break;
    case WM_COMMAND:    //명령 접수
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
                //SetWindowText(hEdit, str);    무한루프에 빠짐
            }
            break;
        case ID_BTN_FUCK:
            MessageBox(hWnd, TEXT("저장"), TEXT("저장"), MB_OK);
            break;
        case ID_BTN_FUCK2:
            MessageBox(hWnd, TEXT("인쇄"), TEXT("인쇄"), MB_OK);
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
                SetWindowText(hEdit, TEXT("사라짐"));
                SetWindowText(hBtnSave, TEXT("사라짐"));

            }
            else
            {
                bShow = TRUE;
                ShowWindow(hEdit, SW_SHOW);
                SetWindowText(hEdit, TEXT("나타남"));
                SetWindowText(hBtnSave, TEXT("나타남"));
            }
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