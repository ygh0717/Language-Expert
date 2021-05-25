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
    if (!InitInstance (hInstance, nCmdShow))
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

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN321));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN321);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
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

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
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
        if (0)
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            HBRUSH Mybr = (HBRUSH)GetStockObject(BLACK_BRUSH);  //StockObject 미리정해진 브러쉬,팬, 폰트 를 저장.. 쓰는거에 따라서 형변환 해줘야한다.
            HBRUSH Oldbr = (HBRUSH)SelectObject(hdc, Mybr);     //SelectObject을 쓰면 브러쉬가Mybr 색으로 변환되는데 그러면 기본 값인 Oldbr(하얀색이)가 사라지는데 원도우에서는 
                                                                //사용이 끝나면 다시 원래 색으로 바꿔놔야하기때문에 oldr에 저장해놔서 다쓰고나서 다시 바꿔줘야한다.
            Rectangle(hdc, 0, 0, 50, 50);
            HBRUSH Mybr2 = (HBRUSH)GetStockObject(GRAY_BRUSH);  //StockObject 미리정해진 브러쉬,팬, 폰트 를 저장.. 쓰는거에 따라서 형변환 해줘야한다.
            SelectObject(hdc, Mybr2);
            Rectangle(hdc, 50, 50, 100, 100);

            SelectObject(hdc, Oldbr);                           //브러쉬를 디폴트값으로 하는 코드
            Rectangle(hdc, 400, 300, 600, 600);
            EndPaint(hWnd, &ps);
        }
        if (1)  //나만의 BRUSH 생성
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            HBRUSH MyBR = CreateSolidBrush(RGB(255, 0, 0));
            HBRUSH Oldbr = (HBRUSH)SelectObject(hdc, MyBR);     //SelectObject을 쓰면 브러쉬가Mybr 색으로 변환되는데 그러면 기본 값인 Oldbr(하얀색이)가 사라지는데 원도우에서는 
            SelectObject(hdc, Oldbr);                           //사용이 끝나면 다시 원래 색으로 바꿔놔야하기때문에 oldr에 저장해놔서 다쓰고나서 다시 바꿔줘야한다.
            Rectangle(hdc, 50, 50, 300, 300);

            EndPaint(hWnd, &ps);
        }
        if (0)  //나만의 PEN 생성
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            HPEN MyPen = CreatePen(PS_SOLID, 5, RGB(0,255,0));
            HPEN OldPen = (HPEN)SelectObject(hdc, MyPen);       //SelectObject을 쓰면 브러쉬가Mybr 색으로 변환되는데 그러면 기본 값인 Oldbr(하얀색이)가 사라지는데 원도우에서는 
            Rectangle(hdc, 50, 50, 300, 300);

            SelectObject(hdc, OldPen);
                                                                //사용이 끝나면 다시 원래 색으로 바꿔놔야하기때문에 oldr에 저장해놔서 다쓰고나서 다시 바꿔줘야한다.
            Rectangle(hdc, 50, 50, 300, 300);

            EndPaint(hWnd, &ps);
        }
    }
    break;
    case WM_MOUSEMOVE:
    {
        HDC hdc = GetDC(hWnd);  //그림 그릴거면

        //HBRUSH MyBR = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
        HBRUSH MyBR = CreateHatchBrush(HS_VERTICAL, RGB(rand() % 256, rand() % 256, rand() % 256));
        HBRUSH Oldbr = (HBRUSH)SelectObject(hdc, MyBR);
        HPEN MyPen = CreatePen(PS_SOLID, 1, RGB(rand()%256, rand() % 256, rand() % 256));
        HPEN OldPen = (HPEN)SelectObject(hdc, MyPen);       //SelectObject을 쓰면 브러쉬가Mybr 색으로 변환되는데 그러면 기본 값인 Oldbr(하얀색이)가 사라지는데 원도우에서는 

        int x, y, r;
        x = rand() % 640;
        y = rand() % 480;
        r = rand() % 10 + 10;

        Ellipse(hdc, x - r, y - r, x + r, y + r);
        SelectObject(hdc, Oldbr);
        SelectObject(hdc, OldPen);
        ReleaseDC(hWnd, hdc);
    }
    break;
    case WM_LBUTTONDOWN:
    {
        InvalidateRect(hWnd, NULL, TRUE);
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

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
#endif