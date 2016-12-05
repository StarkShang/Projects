
// MazeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Maze.h"
#include "MazeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CRect Box::GetContent()
{return CRect(left+1,top+1,right-1,bottom-1);
}

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


// CMazeDlg �Ի���




CMazeDlg::CMazeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMazeDlg::IDD, pParent)
	, canvasDC(NULL)
	, m_StartDraw(false)
	, m_StartGame(false)
	, m_ShiftPoint(0)
	, boxes(NULL)
	, m_colNumOfBoxes(0)
	, m_rowNumOfBoxes(0)
	, m_scaleOfBox(0)
	, ball(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMazeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMazeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON2, &CMazeDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMazeDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMazeDlg ��Ϣ��������

BOOL CMazeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵������ӵ�ϵͳ�˵��С�

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

	// TODO: �ڴ����Ӷ���ĳ�ʼ������

	CWnd *pCanvasWnd=GetDlgItem(IDC_CANVAS);
	canvasDC=pCanvasWnd->GetDC();
	pCanvasWnd->Detach();
	m_scaleOfBox =10;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMazeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMazeDlg::OnPaint()
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
		CWnd *pCanvasWnd =GetDlgItem (IDC_CANVAS);
		CRect rect;
		pCanvasWnd->GetWindowRect(&rect);
		ScreenToClient(rect);
		m_ShiftPoint.x=rect.left;
		m_ShiftPoint.y=rect.top;

		ball=new Ball();
		ball->m_rowIndex =0;
		ball->m_colIndex =0;

		pCanvasWnd->GetClientRect(&rect);
		m_colNumOfBoxes =rect.Width() / m_scaleOfBox -1;
		m_rowNumOfBoxes =rect.Height() / m_scaleOfBox -1;

		boxes = new Box *[m_rowNumOfBoxes];
		for (int i=0;i<m_rowNumOfBoxes;i++){
			boxes[i]=new Box[m_colNumOfBoxes];
			for (int j=0;j<m_colNumOfBoxes;j++){
				boxes[i][j].top = i*m_scaleOfBox+1;
				boxes[i][j].bottom = (i+1)*m_scaleOfBox+2;
				boxes[i][j].left=j*m_scaleOfBox+1;
				boxes[i][j].right = (j+1)*m_scaleOfBox+2;
			}
		}

		boxes[0][0].m_isEnd =true;
		boxes[m_rowNumOfBoxes-1][m_colNumOfBoxes-1].m_isEnd=true;

		InitCanvas();

		CDialogEx::OnPaint();

	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMazeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMazeDlg::InitCanvas(void)
{CBrush brush (RGB(255,255,255));
auto oldBrush =canvasDC->SelectObject(&brush);
oldBrush->DeleteObject();

m_StartGame = false;

for (int i=0;i<m_rowNumOfBoxes;i++){
	for (int j=0;j<m_colNumOfBoxes;j++){
		boxes[i][j].m_isSelected=false;
		canvasDC->Rectangle(boxes[i][j]);
	}
}

CBrush greenBrush(RGB(0,255,0));
canvasDC->FillRect(boxes[0][0].GetContent(),&greenBrush);
canvasDC->FillRect(
	boxes[m_rowNumOfBoxes - 1][m_colNumOfBoxes-1].GetContent(),\
	&greenBrush);
}

void CMazeDlg::UpdateBox(int rowIndex, int colIndex)
{
	CBrush rBursh(RGB(255,0,0));
	CBrush gBursh(RGB(0,255,0));

	if (rowIndex >=0 && rowIndex <m_rowNumOfBoxes &&
		colIndex >= 0 && colIndex <m_colNumOfBoxes){
			boxes[rowIndex][colIndex].m_isSelected=true;
			if(boxes[rowIndex][colIndex].m_isEnd)
				canvasDC->FillRect(boxes[rowIndex][colIndex].GetContent(),&gBursh);
			else
				canvasDC->FillRect(boxes[rowIndex][colIndex].GetContent(),&rBursh);
	}
}


void CMazeDlg::UpdateBall(int rowMove, int colMove)
{
	if(m_StartGame){
		int rowIndex=ball->m_rowIndex+rowMove;
		int colIndex=ball->m_colIndex+colMove;

		if (rowIndex>=0&&rowIndex <m_rowNumOfBoxes &&
			colIndex >= 0 && colIndex< m_colNumOfBoxes){

				CBrush blackBrush (RGB(0,0,0));
				auto oldBrush=canvasDC->SelectObject(&blackBrush);
				oldBrush->DeleteObject();

				UpdateBox(ball->m_rowIndex,ball->m_colIndex);

				ball->m_rowIndex =rowIndex;
				ball->m_colIndex =colIndex;
				canvasDC->Ellipse(boxes[ball->m_rowIndex][ball->m_colIndex]);


				int choice =-1;

				if(rowIndex == m_rowNumOfBoxes-1 &&colIndex ==m_colNumOfBoxes-1)
				choice =MessageBox(TEXT("�ɹ������Ϸ������\r\n�Ƿ����¿�ʼ��"),TEXT("��ϲ��"),MB_OKCANCEL);

				else if (!boxes [rowIndex][colIndex].m_isSelected)
					choice =MessageBox(TEXT("ʧ�ܣ���Ϸ������\r\n�Ƿ����¿�ʼ��"),TEXT("����"),MB_OKCANCEL);

				if (choice==IDOK){
					InitCanvas();return;
				}
				else if (choice== IDCANCEL)
					exit (-1);
		}
	}
}


void CMazeDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ
	m_StartDraw =true;
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMazeDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ
	m_StartDraw= false;
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMazeDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ
	if (m_StartDraw && !m_StartGame){
		auto rowIndex =(point.y-m_ShiftPoint.y)/m_scaleOfBox;
		auto colIndex =(point.x-m_ShiftPoint.x)/m_scaleOfBox;
		UpdateBox(rowIndex,colIndex);
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CMazeDlg::OnBnClickedButton2()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	InitCanvas();
}


void CMazeDlg::OnBnClickedButton1()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	CBrush brush (RGB(0,0,0));
	auto oldBrush =canvasDC->SelectObject(&brush);
	oldBrush->DeleteObject();
	ball->m_rowIndex=0;
	ball->m_colIndex=0;
	canvasDC->Ellipse(boxes[ball->m_rowIndex][ball->m_colIndex]);

	m_StartGame=true;
}


BOOL CMazeDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message==WM_KEYDOWN){
		switch(pMsg->wParam){
		case VK_UP:UpdateBall(-1,0);break;
		case VK_DOWN:UpdateBall(1,0);break;
		case VK_LEFT:UpdateBall(0,-1);break;
		case VK_RIGHT:UpdateBall(0,1);break;
		}
	}
	return 0;
}