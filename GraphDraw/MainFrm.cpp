// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "GraphDraw.h"

#include "Draw.h"
#include "InputDialog.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

InputDialog input;

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

void CMainFrame::OnControlPrint(WPARAM wParam, LPARAM lParam)
{
	struct tInfo{
		CPoint sPoint;
		CPoint ePoint;
		int color;
	};
	//接收成功
	if(wParam == 1){
		tInfo *nMessage = (tInfo *)lParam;
		Draw draw;
		switch(input.GetCase())
		{
			case 1: draw.DDALineDraw(nMessage->sPoint, nMessage->ePoint, nMessage->color, this); break;
			case 2: draw.MiddlePointLineDraw(nMessage->sPoint, nMessage->ePoint, nMessage->color, this); break;
			case 3: draw.BresenhamLineDraw(nMessage->sPoint, nMessage->ePoint, nMessage->color, this); break;
			case 4: draw.MiddleCircleDraw(nMessage->sPoint, nMessage->ePoint.x, nMessage->color, this); break;
			case 5: draw.BresenhamCircleDraw(nMessage->sPoint, nMessage->ePoint.x, nMessage->color, this); break;
			case 6: draw.MiddleEllipseDraw(nMessage->sPoint, nMessage->ePoint.x, nMessage->ePoint.y, nMessage->color, this); break;
			default: break;
		}
	}else{
		this->MessageBox("接收失败");
	}
}

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_DDALINE, OnDdaline)
	ON_COMMAND(ID_MIDPOINTCIRCLE, OnMidpointcircle)
	ON_COMMAND(ID_MIDPOINTELLIPSE, OnMidpointellipse)
	ON_COMMAND(ID_MIDPOINTLINE, OnMidpointline)
	ON_COMMAND(ID_BRESENHAMCIRCLE, OnBresenhamcircle)
	ON_COMMAND(ID_BRESENHAMLINE, OnBresenhamline)
	ON_COMMAND(ID_CLEARCREEN, OnClearcreen)
	//添加消息响应函数
	ON_MESSAGE(WM_CONTROLPRINT, OnControlPrint)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	input.Create(IDD_DIALOG1,this);
}

void CMainFrame::OnUpdateFrameTitle(BOOL NaDa)
{
	CString csAppName;
	csAppName.Format(AFX_IDS_APP_TITLE);
	SetWindowText(csAppName);
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::showInput(CString title, int nCase)
{
	input.ShowWindow(SW_HIDE);
	input.SetWindowText(title);
	input.SetCase(nCase);
	input.InitView();
	input.ShowWindow(SW_SHOWNA);	
}


void CMainFrame::OnDdaline() 
{
	// TODO: Add your command handler code here
	this->showInput("DDA微分直线生成算法", 1);
	
}

void CMainFrame::OnMidpointline() 
{
	// TODO: Add your command handler code here
	this->showInput("中点直线生成算法", 2);

}

void CMainFrame::OnBresenhamline() 
{
	// TODO: Add your command handler code here
	this->showInput("Bresenham直线生成算法", 3);
	
}

void CMainFrame::OnMidpointcircle() 
{
	// TODO: Add your command handler code here
	this->showInput("中点圆生成算法", 4);
	
}

void CMainFrame::OnBresenhamcircle() 
{
	// TODO: Add your command handler code here
	this->showInput("Bresenham圆生成算法", 5);
	
}

void CMainFrame::OnMidpointellipse() 
{
	// TODO: Add your command handler code here
	this->showInput("中点椭圆生成算法", 6);

}

void CMainFrame::OnClearcreen() 
{
	// TODO: Add your command handler code here
	this->RedrawWindow();
}

