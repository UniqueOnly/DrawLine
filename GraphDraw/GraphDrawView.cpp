// GraphDrawView.cpp : implementation of the CGraphDrawView class
//

#include "stdafx.h"
#include "GraphDraw.h"

#include "GraphDrawDoc.h"
#include "GraphDrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGraphDrawView

IMPLEMENT_DYNCREATE(CGraphDrawView, CView)

BEGIN_MESSAGE_MAP(CGraphDrawView, CView)
	//{{AFX_MSG_MAP(CGraphDrawView)
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraphDrawView construction/destruction

CGraphDrawView::CGraphDrawView()
{
	// TODO: add construction code here

}

CGraphDrawView::~CGraphDrawView()
{
}

BOOL CGraphDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGraphDrawView drawing

void CGraphDrawView::OnDraw(CDC* pDC)
{
	CGraphDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CGraphDrawView printing

BOOL CGraphDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGraphDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGraphDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGraphDrawView diagnostics

#ifdef _DEBUG
void CGraphDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphDrawDoc* CGraphDrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphDrawDoc)));
	return (CGraphDrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGraphDrawView message handlers

void CGraphDrawView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CMenu menu, *nMenu, *getMenu;
	//得到当前鼠标位置
	GetCursorPos(&point); 
	nMenu = new CMenu;
	nMenu->CreatePopupMenu();
 	menu.LoadMenu(IDR_MAINFRAME);
 	getMenu = menu.GetSubMenu(3);
 	nMenu->AppendMenu(MF_POPUP, (UINT)getMenu->m_hMenu, "图像生成算法");
 	getMenu = menu.GetSubMenu(4);
	nMenu->AppendMenu(MF_POPUP, (UINT)getMenu->m_hMenu, "清空");
 	nMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd());
	
	CView::OnRButtonDown(nFlags, point);
}
