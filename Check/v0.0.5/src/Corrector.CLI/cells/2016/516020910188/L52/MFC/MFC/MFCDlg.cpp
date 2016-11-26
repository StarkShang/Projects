
// MFCDlg.cpp : ��@��
//

#include "stdafx.h"
#include "MFC.h"
#include "MFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// �� App About �ϥ� CAboutDlg ��ܤ��

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ܤ�����
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

// �{���X��@
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


// CMFCDlg ��ܤ��




CMFCDlg::CMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCDlg::IDD, pParent)
	, m_StartDraw(false)
	, m_PrevPoint(0)
	, m_ShiftPoint(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCDlg �T���B�z�`��

BOOL CMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �N [����...] �\���[�J�t�Υ\���C

	// IDM_ABOUTBOX �����b�t�ΩR�O�d�򤧤��C
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

	// �]�w����ܤ�����ϥܡC�����ε{�����D�������O��ܤ���ɡA
	// �ج[�|�۰ʱq�Ʀ��@�~
	SetIcon(m_hIcon, TRUE);			// �]�w�j�ϥ�
	SetIcon(m_hIcon, FALSE);		// �]�w�p�ϥ�

	// TODO: �b���[�J�B�~����l�]�w
	CWnd *pCanvasWnd=GetDlgItem(IDC_CANVAS);
	CRect rect;
	pCanvasWnd->GetWindowRect(&rect);
	ScreenToClient(rect);
	m_ShiftPoint.x = rect.left;
	m_ShiftPoint.y = rect.top;
	pCanvasWnd->Detach();
	m_StartDraw = false;


	return TRUE;  // �Ǧ^ TRUE�A���D�z�ﱱ��]�w�J�I
}

void CMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �p�G�N�̤p�ƫ��s�[�J�z����ܤ���A�z�ݭn�U�C���{���X�A
// �H�Kø�s�ϥܡC���ϥΤ��/�˵��Ҧ��� MFC ���ε{���A
// �ج[�|�۰ʧ������@�~�C

void CMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ø�s���˸m���e

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N�ϥܸm����Τ�ݯx��
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �yø�ϥ�
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ��ϥΪ̩즲�̤p�Ƶ����ɡA
// �t�ΩI�s�o�ӥ\����o�����ܡC
HCURSOR CMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �b���[�J�z���T���B�z�`���{���X�M (��) �I�s�w�]��
	m_PrevPoint = point - m_ShiftPoint;
	m_StartDraw = true;

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �b���[�J�z���T���B�z�`���{���X�M (��) �I�s�w�]��
	m_StartDraw = false;
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �b���[�J�z���T���B�z�`���{���X�M (��) �I�s�w�]��
	if (m_StartDraw)
	{	
		CWnd *pCanvasWnd = GetDlgItem(IDC_CANVAS);
		CDC *pCanvasDC = pCanvasWnd->GetDC();
		CRect rect;
		pCanvasWnd->GetClientRect(&rect);
		CPoint current = point - m_ShiftPoint;
		if(m_PrevPoint.x > rect.left && m_PrevPoint.x <rect.right &&
		   m_PrevPoint.y > rect.top  && m_PrevPoint.y <rect.bottom && 
		   current.x > rect.left && current.x < rect.right &&
		   current.y > rect.top && current.y <rect.bottom)
		{
			pCanvasDC-> MoveTo(m_PrevPoint);
			pCanvasDC->LineTo(current);
		}
		m_PrevPoint = current;

		pCanvasDC->Detach();
		pCanvasWnd->Detach();
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFCDlg::OnBnClickedButton1()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	CWnd *pCanvasWnd = GetDlgItem(IDC_CANVAS);
	CDC *pCanvasDC = pCanvasWnd->GetDC();
	CRect rect;
	pCanvasWnd->GetClientRect(&rect);
	rect.left += 1;
	rect.right -= 1;
	rect.top += 1;
	rect.bottom -= 1;
	CBrush brush(RGB(255,255,255));
	pCanvasDC->FillRect(&rect, &brush);

	pCanvasDC->Detach();
	pCanvasWnd->Detach();

}
