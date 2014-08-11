#if !defined(AFX_INPUTDIALOG_H__D893D71F_FE30_4DE7_88B8_EFAFCC24A386__INCLUDED_)
#define AFX_INPUTDIALOG_H__D893D71F_FE30_4DE7_88B8_EFAFCC24A386__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// InputDialog dialog

class InputDialog : public CDialog
{
// Construction
public:
	void InitView();
	int GetCase();
	void SetCase(int nCase);
	InputDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(InputDialog)
	enum { IDD = IDD_DIALOG1 };
	int		m_red;
	int		m_green;
	int		m_blue;
	int		m_sPointX;
	int		m_sPointY;
	int		m_ePointX;
	int		m_ePointY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(InputDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(InputDialog)
	afx_msg void OnButton1();
	afx_msg void OnResetbtn();
	afx_msg void OnDrawbtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CRect preRect;
	int nCase;
	COLORREF color;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTDIALOG_H__D893D71F_FE30_4DE7_88B8_EFAFCC24A386__INCLUDED_)
