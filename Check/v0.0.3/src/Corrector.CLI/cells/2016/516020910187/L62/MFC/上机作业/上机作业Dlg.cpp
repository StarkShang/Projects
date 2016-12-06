
// �ϻ���ҵDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ϻ���ҵ.h"
#include "�ϻ���ҵDlg.h"
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
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C�ϻ���ҵDlg �Ի���



C�ϻ���ҵDlg::C�ϻ���ҵDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
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

void C�ϻ���ҵDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C�ϻ���ҵDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_WM_MBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON1, &C�ϻ���ҵDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C�ϻ���ҵDlg::OnBnClickedButton2)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// C�ϻ���ҵDlg ��Ϣ�������

BOOL C�ϻ���ҵDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//OnInitDialog��
	//����Ա��������ֵ
	CWnd*pCanvasWnd = GetDlgItem(IDC_CANVAS);
	canvasDC = pCanvasWnd->GetDC();
	pCanvasWnd->Detach();
	m_scaleOfBox = 10;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�ϻ���ҵDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C�ϻ���ҵDlg::OnPaint()
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
		//OnPoint��
		//��ȡCanvas�ڶԻ����е�λ��
		CWnd*pCanvasWnd = GetDlgItem(IDC_CANVAS);
		CRect rect;
		pCanvasWnd->GetWindowRect(&rect);
		ScreenToClient(rect);
		m_ShiftPoint.x = rect.left;
		m_ShiftPoint.y = rect.top;
		//��ʼ��С��
		ball = new Ball();
		ball->m_rowIndex = 0;
		ball->m_colIndex = 0;
		//��ȡ��ͼ���򲢼��㷽�����
		pCanvasWnd->GetWindowRect(&rect);
		m_colNumOfBoxes = rect.Width() / m_scaleOfBox - 1;
		m_rowNumOfBoxes = rect.Height() / m_scaleOfBox - 1;
		//��ʼ������
		boxes = new Box*[m_rowNumOfBoxes];
		for (int i = 0; i < m_rowNumOfBoxes; i++) {
			boxes[i] = new Box[m_colNumOfBoxes];
			for (int j = 0; j < m_colNumOfBoxes; j++) {
				boxes[i][j].top = i*m_scaleOfBox + 1;
				boxes[i][j]. bottom = (i + 1)*m_scaleOfBox + 2;
				boxes[i][j].left = j*m_scaleOfBox + 1;
				boxes[i][j].right = (j + 1)*m_scaleOfBox + 2;
			}
		}
		//�����ʼ�����ֹ��
		boxes[0][0].m_isEnd = true;
		boxes[m_rowNumOfBoxes - 1][m_colNumOfBoxes - 1].m_isEnd = true;
		//����InitCanvas������ʼ����Ϸ
		InitCanvas();

		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C�ϻ���ҵDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C�ϻ���ҵDlg::InitCanvas()
{
	//���ò�������ˢ
	CBrush brush(RGB(255, 255, 255));
	auto oldBrush = canvasDC->SelectObject(&brush);
	oldBrush->DeleteObject();
	//��������������Ϸ����
	m_StartGame = false;
	//���»�����Ϸ����
	for (int i = 0; i < m_rowNumOfBoxes; i++) {
		for (int j = 0; j < m_colNumOfBoxes; j++) {
			boxes[i][j].m_isSelected = false;
			canvasDC->Rectangle(boxes[i][j]);
		}
	}
	//�����ʼλ�ú���ֹλ��
	CBrush greenBrush(RGB(0, 255, 0));
	canvasDC->FillRect(boxes[0][0].GetContent(), &greenBrush);
	canvasDC->FillRect(
		boxes[m_rowNumOfBoxes - 1][m_colNumOfBoxes - 1].GetContent(),
		&greenBrush);
}


void C�ϻ���ҵDlg::UpdateBox(int rowIndex, int colIndex)
{
	//�����������ֻ�ˢ
	CBrush rBrush(RGB(255,0, 0));
	CBrush gBrush(RGB(0,255, 0));
	//�жϷ����Ƿ���Ч
	//����Ч�������÷���״̬Ϊѡ�в����������Ӧ����ɫ
	if (rowIndex >= 0 && rowIndex < m_rowNumOfBoxes&&
		colIndex >= 0 && colIndex < m_colNumOfBoxes) {
		boxes[rowIndex][colIndex].m_isSelected = true;
		if (boxes[rowIndex][colIndex].m_isEnd)
			canvasDC->FillRect(boxes[rowIndex][colIndex].GetContent(), &gBrush);
		else
			canvasDC->FillRect(boxes[rowIndex][colIndex].GetContent(), &rBrush);
	}
}


void C�ϻ���ҵDlg::UpdateBall(int rowMove, int colMove)
{
	if (m_StartGame) {
		//����С��λ��
		int rowIndex = ball->m_rowIndex + rowMove;
		int colIndex = ball->m_colIndex + colMove;
		//�ж���λ���Ƿ���Ч
		if (rowIndex >= 0 && rowIndex < m_rowNumOfBoxes&&
			colIndex >= 0 && colIndex < m_colNumOfBoxes) {
			//���������»�ˢ
			CBrush blackBrush(RGB(0, 0, 0));
			auto oldBrush = canvasDC->SelectObject(&blackBrush);
			oldBrush->DeleteObject();
			//����UpdateBox�������·���״̬
			UpdateBox(ball->m_rowIndex, ball->m_colIndex);
			//����С��״̬
			ball->m_rowIndex = rowIndex;
			ball->m_colIndex = colIndex;
			canvasDC->Ellipse(boxes[ball->m_rowIndex][ball->m_colIndex]);
			/**********************
			**�ж���Ϸ�Ƿ����
			**���ﵽ�յ���ɹ�
			**���������Ƶ�·����ʧ��
			************************/
			int choice = -1;
			//�����յ㣬�����Ի���
			if (rowIndex == m_rowNumOfBoxes - 1 && colIndex == m_colNumOfBoxes - 1) {
				choice = MessageBox(TEXT("�ɹ�����Ŀ�ĵأ���Ϸ������\r\n�Ƿ����¿�ʼ��"),
					TEXT("��ϲ��"),MB_OKCANCEL);
			}
			//��Ϸʧ�ܣ������Ի���
			else if (!boxes[rowIndex][colIndex].m_isSelected)
				choice = MessageBox(TEXT("ʧ�ܣ���Ϸ����!\r\n�Ƿ����¿�ʼ��"),
					TEXT("���ź�"),MB_OKCANCEL);
			//���ݶԻ����ѡ�� ����������Ϸ ���� �˳�
			if (choice == IDOK) {
				InitCanvas(); return;
			}
			else if (choice == IDCANCEL)
				exit(-1);
			/******************
			**�ж���Ϸ�Ƿ����
			*********************/
		}
	}
}


//void C�ϻ���ҵDlg::OnMButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	//�򿪿�ʼ���ƵĿ���
//	m_StartDraw = true;
//
//	CDialogEx::OnMButtonDown(nFlags, point);
//}
void C�ϻ���ҵDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_StartDraw = true;
	CDialogEx::OnLButtonDown(nFlags, point);
}


void C�ϻ���ҵDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//�رտ�ʼ���ƵĿ���
	m_StartDraw = false;

	CDialogEx::OnLButtonUp(nFlags, point);
}


void C�ϻ���ҵDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//���㵱ǰ������ڵķ��񲢸��·���
	if (m_StartDraw && !m_StartGame) {
		auto rowIndex = (point.y - m_ShiftPoint.y) / m_scaleOfBox;
		auto colIndex = (point.x - m_ShiftPoint.x) / m_scaleOfBox;
		UpdateBox(rowIndex,colIndex);
	}

	CDialogEx::OnMouseMove(nFlags, point);
}


void C�ϻ���ҵDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//����InitCanvas������ʼ����Ϸ
	InitCanvas();
}


void C�ϻ���ҵDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//���ò����»�ˢ
	CBrush brush(RGB(0, 0, 0));
	auto oldBrush = canvasDC->SelectObject(&brush);
	oldBrush->DeleteObject();
	//���ò�����С��
	ball->m_rowIndex = 0;
	ball->m_colIndex = 0;
	canvasDC->Ellipse(boxes[ball->m_rowIndex][ball->m_colIndex]);
	//������Ϸ
	m_StartGame = true;
}



BOOL C�ϻ���ҵDlg::PreTranslateMessage(MSG* pMsg)
{
	//�ػ���д�����߼�
	if (pMsg->message == WM_KEYDOWN) {
		switch (pMsg->wParam) {
		case VK_UP:UpdateBall(-1, 0); break;
		case VK_DOWN:UpdateBall(1, 0); break;
		case VK_LEFT:UpdateBall(0, -1); break;
		case VK_RIGHT:UpdateBall(0, 1); break;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}
