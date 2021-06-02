
// MFCApplicationView.h: CMFCApplicationView 클래스의 인터페이스
//

#pragma once


class CMFCApplicationView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCApplicationView() noexcept;
	DECLARE_DYNCREATE(CMFCApplicationView)

// 특성입니다.
public:
	CMFCApplicationDoc* GetDocument() const;

// 작업입니다.
public:
	int m_nX;
	int m_nY;
	BOOL m_bDrag;
	

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
	virtual ~CMFCApplicationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplicationView.cpp의 디버그 버전
inline CMFCApplicationDoc* CMFCApplicationView::GetDocument() const
   { return reinterpret_cast<CMFCApplicationDoc*>(m_pDocument); }
#endif

