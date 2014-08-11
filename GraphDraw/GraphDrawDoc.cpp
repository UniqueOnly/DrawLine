// GraphDrawDoc.cpp : implementation of the CGraphDrawDoc class
//

#include "stdafx.h"
#include "GraphDraw.h"

#include "GraphDrawDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGraphDrawDoc

IMPLEMENT_DYNCREATE(CGraphDrawDoc, CDocument)

BEGIN_MESSAGE_MAP(CGraphDrawDoc, CDocument)
	//{{AFX_MSG_MAP(CGraphDrawDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraphDrawDoc construction/destruction

CGraphDrawDoc::CGraphDrawDoc()
{
	// TODO: add one-time construction code here

}

CGraphDrawDoc::~CGraphDrawDoc()
{
}

BOOL CGraphDrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	this->SetTitle("GraphDraw");

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGraphDrawDoc serialization

void CGraphDrawDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGraphDrawDoc diagnostics

#ifdef _DEBUG
void CGraphDrawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGraphDrawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGraphDrawDoc commands
