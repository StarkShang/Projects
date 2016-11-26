
// wk104Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "wk104.h"
#include "wk104Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cwk104Dlg �Ի���




Cwk104Dlg::Cwk104Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cwk104Dlg::IDD, pParent)
	, m_StartDraw(false)
	, m_PrevPoint(0)
	, m_ShiftPoint(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cwk104Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cwk104Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON1, &Cwk104Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Cwk104Dlg ��Ϣ�������

BOOL Cwk104Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CWnd *pCanvasWnd=GetDlgItem(IDC_CANVAS);
	CRect rect;
	pCanvasWnd->GetWindowRect(&rect);
	ScreenToClient(rect);
	m_ShiftPoint.x=rect.left;
	m_ShiftPoint.y=rect.top;
	pCanvasWnd->Detach();
	m_StartDraw=false;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cwk104Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cwk104Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cwk104Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cwk104Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_StartDraw=false;

	CDialogEx::OnLButtonUp(nFlags, point);
}


void Cwk104Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_PrevPoint=point-m_ShiftPoint;
	m_StartDraw=true;

	CDialogEx::OnLButtonDown(nFlags, point);
}


void Cwk104Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(m_StartDraw)
	{
		CWnd *pCanvasWnd=GetDlgItem(IDC_CANVAS);
		CDC *pCanvasDC=pCanvasWnd->GetDC();
		CRect rect;
		pCanvasWnd->GetClientRect(&rect);
		CPoint current=point-m_ShiftPoint;
		if(m_PrevPoint.x>rect.left&&m_PrevPoint.x<rect.right&&
			m_PrevPoint.y>rect.top&&m_PrevPoint.y<rect.bottom&&
			current.x>rect.left&&current.x<rect.right&&
			current.y>rect.top&&current.y<rect.bottom)
		{
			pCanvasDC->MoveTo(m_PrevPoint);
			pCanvasDC->LineTo(current);
		}
		m_PrevPoint=current;

		pCanvasDC->Detach();
		pCanvasWnd->Detach();
	}

	CDialogEx::OnMouseMove(nFlags, point);
}


void Cwk104Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CWnd *pCanvasWnd=GetDlgItem(IDC_CANVAS);
	CDC *pCanvasDC=pCanvasWnd->GetDC();
	CRect rect;
	pCanvasWnd->GetClientRect(&rect);
	rect.left+=1;
	rect.right-=1;
	rect.top+=1;
	rect.bottom-=1;
	CBrush brush(RGB(255,255,255));
	pCanvasDC->FillRect(&rect,&brush);

	pCanvasDC->Detach();
	pCanvasWnd->Detach();
}
