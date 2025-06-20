﻿// FirstDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Test_SCThemeDialog.h"
#include "FirstDlg.h"
#include "afxdialogex.h"

#include "../../Common/Functions.h"

// CFirstDlg 대화 상자

IMPLEMENT_DYNAMIC(CFirstDlg, CSCThemeDlg)

CFirstDlg::CFirstDlg(CWnd* pParent /*=nullptr*/)
	: CSCThemeDlg(IDD_FIRST, pParent)
{

}

CFirstDlg::~CFirstDlg()
{
}

void CFirstDlg::DoDataExchange(CDataExchange* pDX)
{
	CSCThemeDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_TITLEBAR, m_check_titlebar);
	DDX_Control(pDX, IDC_CHECK_RESIZE, m_check_resize);
}


BEGIN_MESSAGE_MAP(CFirstDlg, CSCThemeDlg)
	ON_BN_CLICKED(IDOK, &CFirstDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CFirstDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CHECK_TITLEBAR, &CFirstDlg::OnBnClickedCheckTitlebar)
	ON_BN_CLICKED(IDC_CHECK_RESIZE, &CFirstDlg::OnBnClickedCheckResize)
END_MESSAGE_MAP()


// CFirstDlg 메시지 처리기

BOOL CFirstDlg::OnInitDialog()
{
	CSCThemeDlg::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	set_color_theme(CSCColorTheme::color_theme_linkmemine);

	SetWindowLong(m_hWnd, GWL_STYLE, WS_SYSMENU | WS_DLGFRAME);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CFirstDlg::OnBnClickedOk()
{
	TRACE(_T("%s\n"), __function__);
}


void CFirstDlg::OnBnClickedCancel()
{
	TRACE(_T("%s\n"), __function__);
	CDialogEx::OnCancel();
}


void CFirstDlg::OnBnClickedCheckTitlebar()
{
	set_titlebar_height(m_check_titlebar.GetCheck() == BST_CHECKED ? 32 : 0);
}


void CFirstDlg::OnBnClickedCheckResize()
{
	enable_resize(m_check_resize.GetCheck() == BST_CHECKED);
}

