
// PaintDemoView.h: CPaintDemoView 클래스의 인터페이스
//

#pragma once


class CPaintDemoView : public CView
{
protected: // serialization에서만 만들어집니다.
	CPaintDemoView() noexcept;
	DECLARE_DYNCREATE(CPaintDemoView)
	
// 특성입니다.
public:
	CPaintDemoDoc* GetDocument() const;

// 작업입니다.
public:
	CPoint m_ptStart;
	CPoint m_ptEnd;
	BOOL m_bDrag;
	int m_nShape;	// 0:직선, 1:네모, 2:동그라미
	BOOL m_bFill;	// T:채움, F:안채움

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CPaintDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnStraight();
	afx_msg void OnUpdateStraight(CCmdUI* pCmdUI);
	afx_msg void OnRectangle();
	afx_msg void OnUpdateRectangle(CCmdUI* pCmdUI);
	afx_msg void OnEllipse();
	afx_msg void OnUpdateEllipse(CCmdUI* pCmdUI);
	afx_msg void OnFill();
	afx_msg void OnUpdateFill(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // PaintDemoView.cpp의 디버그 버전
inline CPaintDemoDoc* CPaintDemoView::GetDocument() const
   { return reinterpret_cast<CPaintDemoDoc*>(m_pDocument); }
#endif

