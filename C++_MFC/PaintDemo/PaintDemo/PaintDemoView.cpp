
// PaintDemoView.cpp: CPaintDemoView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "PaintDemo.h"
#endif

#include "PaintDemoDoc.h"
#include "PaintDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPaintDemoView

IMPLEMENT_DYNCREATE(CPaintDemoView, CView)

BEGIN_MESSAGE_MAP(CPaintDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
	ON_COMMAND(ID_Straight, &CPaintDemoView::OnStraight)
	ON_UPDATE_COMMAND_UI(ID_Straight, &CPaintDemoView::OnUpdateStraight)
	ON_COMMAND(ID_Rectangle, &CPaintDemoView::OnRectangle)
	ON_UPDATE_COMMAND_UI(ID_Rectangle, &CPaintDemoView::OnUpdateRectangle)
	ON_COMMAND(ID_Ellipse, &CPaintDemoView::OnEllipse)
	ON_UPDATE_COMMAND_UI(ID_Ellipse, &CPaintDemoView::OnUpdateEllipse)
	ON_COMMAND(ID_Fill, &CPaintDemoView::OnFill)
	ON_UPDATE_COMMAND_UI(ID_Fill, &CPaintDemoView::OnUpdateFill)
END_MESSAGE_MAP()

// CPaintDemoView 생성/소멸

CPaintDemoView::CPaintDemoView() noexcept
{
	CPoint a(0, 0);

	m_ptStart = a;

	/*m_ptStart.x = 0;
	m_ptStart.y = 0;*/

	m_ptEnd = CPoint(0, 0);

	/*m_ptEnd.x = 0;
	m_ptEnd.y = 0;*/

	m_bDrag = FALSE;

	m_nShape = 0;		// 도형 종류
	m_bFill = FALSE;	// 채우기
}

CPaintDemoView::~CPaintDemoView()
{

}

BOOL CPaintDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPaintDemoView 그리기

void CPaintDemoView::OnDraw(CDC* /*pDC*/)
{
	CPaintDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CPaintDemoView 인쇄

BOOL CPaintDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPaintDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPaintDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPaintDemoView 진단

#ifdef _DEBUG
void CPaintDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CPaintDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaintDemoDoc* CPaintDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaintDemoDoc)));
	return (CPaintDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CPaintDemoView 메시지 처리기

void CPaintDemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_bDrag = TRUE;

	m_ptStart.x = point.x;
	m_ptStart.y = point.y;

	CView::OnLButtonDown(nFlags, point);
}


void CPaintDemoView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_bDrag)
	{
		m_ptEnd.x = point.x;
		m_ptEnd.y = point.y;

		RedrawWindow();
	}

	CView::OnMouseMove(nFlags, point);
}


void CPaintDemoView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_bDrag)
	{
		m_bDrag = FALSE;
		m_ptEnd.x = point.x;
		m_ptEnd.y = point.y;

		RedrawWindow();
	}

	CView::OnLButtonUp(nFlags, point);
}


void CPaintDemoView::OnPaint()
{
	CPaintDC dc(this);

	switch (m_nShape)
	{
		case 0:		// 직선
		{
			if (m_bFill == TRUE)
			{
				CBrush myBrush(RGB(255, 0, 0));
				CBrush* pOldBrush = dc.SelectObject(&myBrush);

				dc.MoveTo(m_ptStart);
				dc.LineTo(m_ptEnd);

				dc.SelectObject(pOldBrush);

			}
			else
			{
				dc.MoveTo(m_ptStart);
				dc.LineTo(m_ptEnd);
			}
		}
		break;

		case 1:		// 네모
		{
			if (m_bFill == TRUE)
			{
				CBrush myBrush(RGB(255, 0, 0));
				CBrush* pOldBrush = dc.SelectObject(&myBrush);

				dc.Rectangle(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y);

				dc.SelectObject(pOldBrush);
			}
			else
			{
				dc.Rectangle(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y);
			}
		}
		break;

		case 2:		// 동그라미
		{
			if (m_bFill == TRUE)
			{
				CBrush myBrush(RGB(255, 0, 0));
				CBrush* pOldBrush = dc.SelectObject(&myBrush);

				dc.Ellipse(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y);

				dc.SelectObject(pOldBrush);
			}
			else
			{
				dc.Ellipse(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y);
			}
		}
		break;

	}

	/*// 채우기
	if (m_bFill)
	{

	}
	else
	{
		CBrush myBrush(RGB(255, 0, 0));
		CBrush* pOldBrush = dc.SelectObject(&myBrush);

		dc.SelectObject(pOldBrush);
	}*/

}

// 직선
void CPaintDemoView::OnStraight()
{
	m_nShape = 0;
}


void CPaintDemoView::OnUpdateStraight(CCmdUI* pCmdUI)
{
	if (m_nShape == 0)
	{
		pCmdUI->SetCheck(1);
	}
	else
	{
		pCmdUI->SetCheck(0);
	}
}

// 네모
void CPaintDemoView::OnRectangle()
{
	m_nShape = 1;
}


void CPaintDemoView::OnUpdateRectangle(CCmdUI* pCmdUI)
{
	if (m_nShape == 1)
	{
		pCmdUI->SetCheck(1);
	}
	else
	{
		pCmdUI->SetCheck(0);
	}
}

// 동그라미
void CPaintDemoView::OnEllipse()
{
	m_nShape = 2;
}


void CPaintDemoView::OnUpdateEllipse(CCmdUI* pCmdUI)
{
	if (m_nShape == 2)
	{
		pCmdUI->SetCheck(1);
	}
	else
	{
		pCmdUI->SetCheck(0);
	}
}

// 채우기
void CPaintDemoView::OnFill()
{
	if (m_bFill) //	채우기 활성화
	{
		m_bFill = FALSE;
	}
	else		 // 채우기 비활성화
	{
		m_bFill = TRUE;
	}
}


void CPaintDemoView::OnUpdateFill(CCmdUI* pCmdUI)
{
	if (m_bFill)	//	채우기 활성화
	{
		pCmdUI->SetCheck(1);
	}
	else			// 채우기 비활성화
	{
		pCmdUI->SetCheck(0);
	}
}
