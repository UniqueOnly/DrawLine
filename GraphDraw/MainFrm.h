// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__42683CF2_77B4_4AD0_B098_07A299D6AFB8__INCLUDED_)
#define AFX_MAINFRM_H__42683CF2_77B4_4AD0_B098_07A299D6AFB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDdaline();
	afx_msg void OnMidpointcircle();
	afx_msg void OnMidpointellipse();
	afx_msg void OnMidpointline();
	afx_msg void OnBresenhamcircle();
	afx_msg void OnBresenhamline();
	afx_msg void OnClearcreen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	virtual void OnUpdateFrameTitle(BOOL NaDa);
	void OnControlPrint(WPARAM wParam, LPARAM lParam);
	UINT nCase;
	void showInput(CString title, int nCase);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__42683CF2_77B4_4AD0_B098_07A299D6AFB8__INCLUDED_)
