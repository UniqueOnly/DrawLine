// InputDialog.cpp : implementation file
//

#include "stdafx.h"
#include "GraphDraw.h"
#include "InputDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// InputDialog dialog


InputDialog::InputDialog(CWnd* pParent /*=NULL*/)
	: CDialog(InputDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(InputDialog)
	m_red = 0;
	m_green = 0;
	m_blue = 0;
	m_sPointX = 0;
	m_sPointY = 0;
	m_ePointX = 0;
	m_ePointY = 0;
	color = 0;
	nCase = 0;
	//}}AFX_DATA_INIT

}


void InputDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(InputDialog)
	DDX_Text(pDX, IDC_EDIT5, m_red);
	DDX_Text(pDX, IDC_EDIT6, m_green);
	DDX_Text(pDX, IDC_EDIT7, m_blue);
	DDX_Text(pDX, IDC_EDIT1, m_sPointX);
	DDX_Text(pDX, IDC_EDIT2, m_sPointY);
	DDX_Text(pDX, IDC_EDIT3, m_ePointX);
	DDX_Text(pDX, IDC_EDIT4, m_ePointY);
	//}}AFX_DATA_MAP
	this->GetDlgItem(IDC_STATIC2)->GetWindowRect(&this->preRect);
	ScreenToClient(this->preRect);
	
}


BEGIN_MESSAGE_MAP(InputDialog, CDialog)
	//{{AFX_MSG_MAP(InputDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_RESETBTN, OnResetbtn)
	ON_BN_CLICKED(IDC_DRAWBTN, OnDrawbtn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// InputDialog message handlers

void InputDialog::OnButton1() 
{
	// TODO: Add your control notification handler code here

	CColorDialog nColorDialog(color);

	if(nColorDialog.DoModal() == IDOK)
	{
		this->color = nColorDialog.GetColor();
	}
	//获取数据
	this->UpdateData(TRUE);
	this->ShowWindow(SW_SHOWNA);
	this->m_red = GetRValue(this->color);
	this->m_green = GetGValue(this->color);
	this->m_blue = GetBValue(this->color);
	//更新数据
	this->UpdateData(FALSE);

}

void InputDialog::OnResetbtn() 
{
	// TODO: Add your control notification handler code here
	this->m_red = 0;
	this->m_green = 0;
	this->m_blue = 0;
	this->m_sPointX = 0;
	this->m_sPointY = 0;
	this->m_ePointX = 0;
	this->m_ePointY = 0;
	this->color = 0;
	//更新数据
	this->UpdateData(FALSE);

}

void InputDialog::OnDrawbtn() 
{
	// TODO: Add your control notification handler code here

	CWnd *fWnd = CWnd::FindWindow(NULL,_T("GraphDraw"));
	if(fWnd == NULL)
	{
		this->MessageBox("主窗口未运行！");
		return ;
	}
	struct tInfo{
		CPoint sPoint;
		CPoint ePoint;
		int color;
	};
	tInfo nMessage;
	//获取数据
	this->UpdateData(TRUE);
	nMessage.sPoint.x = this->m_sPointX;
	nMessage.sPoint.y = this->m_sPointY;
	nMessage.ePoint.x = this->m_ePointX;
	nMessage.ePoint.y = this->m_ePointY;
	nMessage.color = this->color;
	//发送结构体数据
	fWnd->SendMessage(WM_CONTROLPRINT,1,(LPARAM)&nMessage);
	
}

void InputDialog::SetCase(int nCase)
{
	this->nCase = nCase;
}

int InputDialog::GetCase()
{
	return this->nCase;
}

void InputDialog::InitView()
{
	CStatic *sTip = (CStatic *)this->GetDlgItem(IDC_STATIC1);
	CStatic *eTip = (CStatic *)this->GetDlgItem(IDC_STATIC2);
	CEdit *edit = (CEdit *)this->GetDlgItem(IDC_EDIT4);
	CRect nowRect = this->preRect;
	switch(this->nCase)
	{
		case 1: case 2: case 3: sTip->SetWindowText("起点："); eTip->SetWindowText("终点："); edit->ShowWindow(SW_SHOWNA); break;
		case 4: case 5: sTip->SetWindowText("圆心："); eTip->SetWindowText("半径："); edit->ShowWindow(SW_HIDE); break;
		case 6: sTip->SetWindowText("圆心："); eTip->SetWindowText("长轴/短轴："); edit->ShowWindow(SW_SHOWNA); nowRect.top -= 10; break;
	}
	eTip->SetWindowPos(NULL,nowRect.left,nowRect.top,0,0,SWP_NOZORDER|SWP_NOSIZE);
}
