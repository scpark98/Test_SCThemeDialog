#pragma once

#include "SCThemeDialog.h"

// CFirstDlg 대화 상자

class CFirstDlg : public CSCThemeDialog
{
	DECLARE_DYNAMIC(CFirstDlg)

public:
	CFirstDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CFirstDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIRST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CButton m_check_titlebar;
	afx_msg void OnBnClickedCheckTitlebar();
	CButton m_check_resize;
	afx_msg void OnBnClickedCheckResize();
};
