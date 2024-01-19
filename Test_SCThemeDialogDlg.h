
// Test_SCThemeDialogDlg.h: 헤더 파일
//
#pragma once

#include "../../Common/CDialog/SCThemeDialog/SCThemeDialog.h"
#include "../../Common/CStatic/SCStatic/SCStatic.h"
#include "../../Common/CButton/GdiButton/GdiButton.h"
#include "../../Common/ResizeCtrl.h"

// CTestSCThemeDialogDlg 대화 상자
class CTestSCThemeDialogDlg : public CSCThemeDialog
{
// 생성입니다.
public:
	CTestSCThemeDialogDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_SCTHEMEDIALOG_DIALOG };
#endif

protected:
	CResizeCtrl		m_resize;


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CSCStatic m_static_text;
	CGdiButton m_button_ok;
	CGdiButton m_button_cancel;
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
};
