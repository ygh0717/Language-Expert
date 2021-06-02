
// MFCApplicationView.cpp: CMFCApplicationView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCApplication.h"
#endif

#include "MFCApplicationDoc.h"
#include "MFCApplicationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplicationView

IMPLEMENT_DYNCREATE(CMFCApplicationView, CView)

BEGIN_MESSAGE_MAP(CMFCApplicationView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplicationView 생성/소멸

CMFCApplicationView::CMFCApplicationView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_nX = 100;
	m_nY = 100;

	m_bDrag = FALSE;


}

CMFCApplicationView::~CMFCApplicationView()
{
}

BOOL CMFCApplicationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCApplicationView 그리기

void CMFCApplicationView::OnDraw(CDC* /*pDC*/)
{
	CMFCApplicationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMFCApplicationView 인쇄

BOOL CMFCApplicationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCApplicationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCApplicationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCApplicationView 진단

#ifdef _DEBUG
void CMFCApplicationView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplicationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplicationDoc* CMFCApplicationView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplicationDoc)));
	return (CMFCApplicationDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplicationView 메시지 처리기

void CMFCApplicationView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	//dc.TextOut(10, 10, _T("안녕하세요. 반가워요"));
	//CString strTemp;
	//strTemp.Format(_T("안녕하세요. %d, %d 입니다."), m_nX, m_nY);
	//dc.TextOut(10, 10, strTemp);

	dc.TextOut(m_nX, m_nY, _T("내 PC"));
}


void CMFCApplicationView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if ((m_nX-30 < point.x) && (point.x < m_nX+30)
	 && (m_nY - 30 < point.y) && (point.y < m_nY + 30))
	{
		m_bDrag = TRUE;		//Drag 시작
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplicationView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//m_nX = point.x;
	//m_nY = point.y;
	//RedrawWindow();		//WM_PAINT발생시킴 --> OnPaint();

	if (m_bDrag == TRUE)
	{
		//m_bDrag = FALSE;		//Drag 종료

		m_nX = point.x;
		m_nY = point.y;
		RedrawWindow();	//InvalidateRect()보다 고급진
	}

	CView::OnMouseMove(nFlags, point);
}

void CMFCApplicationView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrag == TRUE)
	{
		m_bDrag = FALSE;		//Drag 종료

		m_nX = point.x;
		m_nY = point.y;
		RedrawWindow();	//InvalidateRect()보다 고급진
	}

	CView::OnLButtonUp(nFlags, point);
}