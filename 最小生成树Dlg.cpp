// 最小生成树Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "最小生成树.h"
#include "最小生成树Dlg.h"
#include "tu.h"
#include<windows.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	m_jz = _T("");
	m_num = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Text(pDX, IDC_EDIT2, m_jz);
	DDX_Text(pDX, IDC_EDIT1, m_num);
	DDV_MinMaxInt(pDX, m_num, 0, 10);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2)
	ON_WM_LBUTTONDOWN()
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CMyDlg::OnChangeEdit2() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here

}

///////////////////////////////////////////////////////////重点////////////////////////////////////////////////////////////////////
tu pit;					//图
int cs = 0;				//记录鼠标点击次数
int sc = 0;				//0:一键；1：自动；2:手动
bool finish = false;	//坐标是否设置完成
bool change = true;		//头节点更换是否完成
char jd = '0';			//节点输出名称

POINT pt = {585,36};//刷新最小生成树框
SIZE size = {290,280};
CRect rect(pt,size);
CBrush brush(RGB(240,240,240)); 

POINT pt2 = {750,330};//刷新代价
SIZE size2 = {20,20};
CRect rect2(pt2,size2);
CBrush brush2(RGB(240, 240, 240)); 

void button(HDC& hdc, CClientDC& dc, int sc)//按钮函数
{
	dc.FillRect(&rect,&brush); 
	dc.FillRect(&rect2,&brush2); 
	pit.print(hdc, dc, sc);
}

void CMyDlg::OnButton1() //一键生成
{
	sc = 0;
	GetDlgItem(IDC_BUTTON4)->EnableWindow(true);
	CClientDC dc(this);
	HDC hdc;
	hdc=::GetDC(m_hWnd);
	button(hdc, dc, sc);
}

void CMyDlg::OnButton2() //自动生成
{
	sc = 1;
	GetDlgItem(IDC_BUTTON4)->EnableWindow(true);
	CClientDC dc(this);
	HDC hdc;
	hdc=::GetDC(m_hWnd);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(false);  
	GetDlgItem(IDC_BUTTON2)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(false);
	button(hdc, dc, sc);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(true);  
	GetDlgItem(IDC_BUTTON2)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(true);
}

int bt3 = 0;
void CMyDlg::OnButton3() //手动生成
{
	CClientDC dc(this);
	HDC hdc;
	hdc=::GetDC(m_hWnd);
	if(sc != 2 || bt3 >= pit.dlnum())
	{
		dc.FillRect(&rect,&brush); 
		dc.FillRect(&rect2,&brush2); 
		sc = 2;
		bt3 = 0;
	}
	GetDlgItem(IDC_BUTTON4)->EnableWindow(false);
	bt3 ++;
	pit.print(hdc, dc, sc);
}

void CMyDlg::OnLButtonDown(UINT nFlags, CPoint point) //鼠标监听
{
	CClientDC dc(this);
	if(cs < pit.ok() && point.x > 260 && point.x < 540 && point.y > 15 && point.y < 315)
	{	
		dc.Ellipse(point.x + 20, point.y + 25, point.x - 5, point.y - 5);//一个圆
		pit.setxy(point.x, point.y, cs);
		dc.TextOut(point.x, point.y, jd);
		cs ++;
		jd += 1;
	}
	if(cs == m_num && cs)
	{
		HDC hdc;
		hdc=::GetDC(m_hWnd);
		pit.tutotree();
		finish = true;
		cs++;
		pit.print2(hdc, dc);
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);   
		GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT1)->EnableWindow(false);
		GetDlgItem(IDC_EDIT2)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON8)->EnableWindow(false);
	}
	CDialog::OnLButtonDown(nFlags, point);
}

void CMyDlg::OnButton5() //清空
{
	pit.dele();
	Invalidate(true);
	cs = 0;
	jd = '0';
	sc = -1;
	finish = false;
	pit.chead(0);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(false);  
	GetDlgItem(IDC_BUTTON2)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(false);
	GetDlgItem(IDC_EDIT1)->EnableWindow(true);
	GetDlgItem(IDC_EDIT2)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
}

void CMyDlg::OnButton8() //生成
{
	UpdateData(true);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(false); 
	GetDlgItem(IDC_EDIT1)->EnableWindow(false);
	GetDlgItem(IDC_EDIT2)->EnableWindow(false);
	if(pit.paint(m_num, m_jz))
	{
		MessageBox("顶点个数的平方与临接矩阵输入个数不同，请重新输入");
		GetDlgItem(IDC_BUTTON8)->EnableWindow(true); 
		GetDlgItem(IDC_EDIT1)->EnableWindow(true);
		GetDlgItem(IDC_EDIT2)->EnableWindow(true);
		return;
	}
	MessageBox("请于“图”框内单击设置顶点位置");
	cs = 0;
	jd = '0';	
	finish = false;
	change = true;
}

void CMyDlg::OnButton4() //更换头节点
{
	UpdateData(true);
	if(change)
	{
		GetDlgItem(IDC_BUTTON1)->EnableWindow(false);  
		GetDlgItem(IDC_BUTTON2)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON5)->EnableWindow(false);
		GetDlgItem(IDC_EDIT1)->EnableWindow(true);
		MessageBox("请于‘顶点个数’输入框内输入头节点序号，然后再按一次更换头节点按钮（默认头节点为0）");
		change = false;
	}
	else
	{		
		if(m_num >= pit.ok())
		{
			MessageBox("输入过大，请重新输入");
			change = true;
			OnButton4();
			return;
		}
		else
		{
			GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);   
			GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
			GetDlgItem(IDC_EDIT1)->EnableWindow(false);
			CString csStr;
			csStr.Format("头节点已改为：%d", m_num);
			MessageBox(csStr);
			pit.chead(m_num);
			pit.tutotree();
			change = true;
		}
	}
}
