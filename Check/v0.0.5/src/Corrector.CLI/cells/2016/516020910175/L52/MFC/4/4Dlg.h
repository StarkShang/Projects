
// 4Dlg.h : ͷ�ļ�
//

#pragma once
#include "atltypes.h"


// CMy4Dlg �Ի���
class CMy4Dlg : public CDialogEx
{
// ����
public:
	CMy4Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY4_DIALOG };

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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnXButtonDown(UINT nFlags, UINT nButton, CPoint point);
	afx_msg void OnXButtonUp(UINT nFlags, UINT nButton, CPoint point);
	bool m_StartDraw;
	CPoint m_PrevPoint;
	CPoint m_ShiftPoint;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};
