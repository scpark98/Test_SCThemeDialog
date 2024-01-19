
// Test_SCThemeDialogDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Test_SCThemeDialog.h"
#include "Test_SCThemeDialogDlg.h"
#include "afxdialogex.h"

#include "FirstDlg.h"
#include "../../Common/Functions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CTestSCThemeDialogDlg 대화 상자



CTestSCThemeDialogDlg::CTestSCThemeDialogDlg(CWnd* pParent /*=nullptr*/)
	: CSCThemeDialog(IDD_TEST_SCTHEMEDIALOG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestSCThemeDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CSCThemeDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_TEXT, m_static_text);
	DDX_Control(pDX, IDOK, m_button_ok);
	DDX_Control(pDX, IDCANCEL, m_button_cancel);
}

BEGIN_MESSAGE_MAP(CTestSCThemeDialogDlg, CSCThemeDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CTestSCThemeDialogDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CTestSCThemeDialogDlg::OnBnClickedCancel)
	ON_WM_WINDOWPOSCHANGED()
END_MESSAGE_MAP()


// CTestSCThemeDialogDlg 메시지 처리기

BOOL CTestSCThemeDialogDlg::OnInitDialog()
{
	CSCThemeDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_resize.Create(this);
	m_resize.Add(IDOK, 50, 100, 0, 0);
	m_resize.Add(IDCANCEL, 50, 100, 0, 0);
	m_resize.Add(IDC_STATIC_TEXT, 0, 0, 100, 100);

	// 
	//set_titlebar_color(RGB(64, 64, 255));
	//set_back_color(RGB(64, 64, 64));
	set_color_theme(CSCThemeDialog::color_theme_visualstudio);
	SetWindowText(_T("SCThemeDialogDlg"));
	set_title(_T("SCThemeDialogDlg"));

	m_static_text.set_text_color(lightsalmon);
	m_static_text.set_font_size(32);
	m_static_text.set_font_bold();
	m_button_ok.text_color(wheat);
	m_button_cancel.text_color(wheat);
	m_button_ok.back_color(cornflowerblue, true);
	m_button_cancel.back_color(cornflowerblue, true);

	m_button_ok.set_round(10);
	m_button_cancel.set_round(10);


	set_system_buttons(SC_HELP, SC_PIN, SC_MINIMIZE, SC_MAXIMIZE, SC_CLOSE);
	set_back_image(_T("JPG"), (UINT)IDB_WINDOW, true);

	RestoreWindowPosition(&theApp, this);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTestSCThemeDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CSCThemeDialog::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTestSCThemeDialogDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CSCThemeDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTestSCThemeDialogDlg::OnQueryDragIcon()
{
	TRACE(_T("dragging...\n"));
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestSCThemeDialogDlg::OnBnClickedOk()
{
	set_back_image(_T("jpg"), IDB_AUTUMN_LIVINGROOM, true);
	//set_back_image(_T("png"), _T("D:\\1.Projects_C++\\1.test\\Test_SCThemeDialog\\res\\images\\icecream.png"), true);
	CFirstDlg dlg;
	dlg.DoModal();
}


void CTestSCThemeDialogDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}


void CTestSCThemeDialogDlg::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CSCThemeDialog::OnWindowPosChanged(lpwndpos);

	// TODO: Add your message handler code here
	SaveWindowPosition(&theApp, this);
}
