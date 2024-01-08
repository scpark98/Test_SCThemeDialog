// FirstDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Test_SCThemeDialog.h"
#include "FirstDlg.h"
#include "afxdialogex.h"

#include "../../Common/Functions.h"

// CFirstDlg 대화 상자

IMPLEMENT_DYNAMIC(CFirstDlg, CSCThemeDialog)

CFirstDlg::CFirstDlg(CWnd* pParent /*=nullptr*/)
	: CSCThemeDialog(IDD_FIRST, pParent)
{

}

CFirstDlg::~CFirstDlg()
{
}

void CFirstDlg::DoDataExchange(CDataExchange* pDX)
{
	CSCThemeDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_TITLEBAR, m_check_titlebar);
	DDX_Control(pDX, IDC_CHECK_RESIZE, m_check_resize);
}


BEGIN_MESSAGE_MAP(CFirstDlg, CSCThemeDialog)
	ON_BN_CLICKED(IDOK, &CFirstDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CFirstDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CHECK_TITLEBAR, &CFirstDlg::OnBnClickedCheckTitlebar)
	ON_BN_CLICKED(IDC_CHECK_RESIZE, &CFirstDlg::OnBnClickedCheckResize)
END_MESSAGE_MAP()


// CFirstDlg 메시지 처리기


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
	show_titlebar(m_check_titlebar.GetCheck() == BST_CHECKED);
}


void CFirstDlg::OnBnClickedCheckResize()
{
	enable_resize(m_check_resize.GetCheck() == BST_CHECKED);
}
