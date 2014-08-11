// GraphDraw.h : main header file for the GRAPHDRAW application
//

#if !defined(AFX_GRAPHDRAW_H__B063B2D0_ECCA_4538_A823_AFC7017ECB41__INCLUDED_)
#define AFX_GRAPHDRAW_H__B063B2D0_ECCA_4538_A823_AFC7017ECB41__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGraphDrawApp:
// See GraphDraw.cpp for the implementation of this class
//

class CGraphDrawApp : public CWinApp
{
public:
	CGraphDrawApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraphDrawApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGraphDrawApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPHDRAW_H__B063B2D0_ECCA_4538_A823_AFC7017ECB41__INCLUDED_)
