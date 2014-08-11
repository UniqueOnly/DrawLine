// GraphDrawDoc.h : interface of the CGraphDrawDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPHDRAWDOC_H__C2E7071E_E292_443F_83F7_65F8A1EB08F5__INCLUDED_)
#define AFX_GRAPHDRAWDOC_H__C2E7071E_E292_443F_83F7_65F8A1EB08F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGraphDrawDoc : public CDocument
{
protected: // create from serialization only
	CGraphDrawDoc();
	DECLARE_DYNCREATE(CGraphDrawDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraphDrawDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGraphDrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGraphDrawDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPHDRAWDOC_H__C2E7071E_E292_443F_83F7_65F8A1EB08F5__INCLUDED_)
