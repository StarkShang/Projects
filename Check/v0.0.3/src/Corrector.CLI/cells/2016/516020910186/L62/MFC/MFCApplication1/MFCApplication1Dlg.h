
// MFCApplication1Dlg.h : ͷ�ļ�
//

#pragma once
#include "atltypes.h"
#include"Ball.h"
#include"Box.h"


// CMFCApplication1Dlg �Ի���
class CMFCApplication1Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CDC* canvasDC;
	bool m_StartDraw;
	bool m_StartGame;
	CPoint m_ShiftPoint;
	Box** boxes;
	int m_colNumOfBoxes;
	int m_rowNumOfBoxes;
	int m_scaleOfBox;
	Ball* ball;
	void InitCanvas();
	void UpdateBox(int rowIndex, int colIndex);
	void UpdateBall(int rowMove, int colMove);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	BOOL PreTranslateMessage(MSG* pMsg);
};
