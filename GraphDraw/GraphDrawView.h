// GraphDrawView.h : interface of the CGraphDrawView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPHDRAWVIEW_H__7ABAD67B_37DF_4F4F_B4F1_FC39963C778F__INCLUDED_)
#define AFX_GRAPHDRAWVIEW_H__7ABAD67B_37DF_4F4F_B4F1_FC39963C778F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGraphDrawView : public CView
{
protected: // create from serialization only
	CGraphDrawView();
	DECLARE_DYNCREATE(CGraphDrawView)

// Attributes
public:
	CGraphDrawDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraphDrawView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGraphDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGraphDrawView)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GraphDrawView.cpp
inline CGraphDrawDoc* CGraphDrawView::GetDocument()
   { return (CGraphDrawDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPHDRAWVIEW_H__7ABAD67B_37DF_4F4F_B4F1_FC39963C778F__INCLUDED_)
