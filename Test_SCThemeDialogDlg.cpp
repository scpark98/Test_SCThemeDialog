
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
	: CSCThemeDlg(IDD_TEST_SCTHEMEDIALOG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestSCThemeDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CSCThemeDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_TEXT, m_static_text);
	DDX_Control(pDX, IDOK, m_button_ok);
	DDX_Control(pDX, IDCANCEL, m_button_cancel);
	DDX_Control(pDX, IDC_TREE, m_tree);
	DDX_Control(pDX, IDC_LIST, m_list);
}

BEGIN_MESSAGE_MAP(CTestSCThemeDialogDlg, CSCThemeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CTestSCThemeDialogDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CTestSCThemeDialogDlg::OnBnClickedCancel)
	ON_WM_WINDOWPOSCHANGED()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_ACTIVATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CTestSCThemeDialogDlg 메시지 처리기

BOOL CTestSCThemeDialogDlg::OnInitDialog()
{
	CSCThemeDlg::OnInitDialog();

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
	m_resize.Add(IDOK, 100, 100, 0, 0);
	m_resize.Add(IDCANCEL, 100, 100, 0, 0);
	m_resize.Add(IDC_STATIC_TEXT, 0, 0, 100, 0);
	m_resize.Add(IDC_TREE, 0, 0, 20, 100);
	m_resize.Add(IDC_LIST, 20, 0, 80, 100);
	// 
	//set_titlebar_color(RGB(64, 64, 255));
	//set_back_color(RGB(64, 64, 64));
	set_color_theme(CSCColorTheme::color_theme_anysupport);
	set_titlebar_icon(IDR_MAINFRAME, 20, 20);


	set_system_buttons(this, SC_HELP, SC_PIN, SC_MINIMIZE, SC_MAXIMIZE, SC_CLOSE);
	//set_use_resizable(false);
	//SetWindowText(_T("SCThemeDialogDlg"));

	//m_static_text.set_text_color(m_theme.cr_title_back);
	//m_static_text.set_back_color(m_theme.cr_back);
	m_static_text.set_color(m_theme.cr_title_back, m_theme.cr_back);
	m_static_text.set_font_size(32);
	m_static_text.set_font_bold();
	//m_static_text.set_transparent();

	//m_button_ok.set_text_color(Gdiplus::Color::Wheat);
	//m_button_cancel.set_text_color(Gdiplus::Color::Wheat);
	//m_button_ok.set_back_color(Gdiplus::Color::CornflowerBlue, true);
	//m_button_cancel.set_back_color(Gdiplus::Color::CornflowerBlue, true);

	m_button_ok.use_hover();
	m_button_ok.set_text_color(m_theme.cr_title_text);
	m_button_ok.set_back_color(m_theme.cr_title_back);
	m_button_ok.set_round(40);

	m_button_cancel.set_text_color(m_theme.cr_title_text);
	m_button_cancel.set_back_color(m_theme.cr_title_back);
	m_button_cancel.set_round(40);


	//이 코드를 넣어야 작업표시줄에서 클릭하여 minimize, restore된다.
	//작업표시줄에서 해당 앱을 shift+우클릭하여 SYSMENU를 표시할 수 있다.
	//또한 CResizeCtrl을 이용하면 resize할 때 모든 컨트롤들의 레이아웃을 자동으로 맞춰주는데
	//아래 코드를 사용하지 않으면 타이틀바가 없는 dlg는 상단에 흰색 여백 공간이 생기는 부작용이 생긴다.
	//종료 시 묻는 대화상자를 표시하는 등의 이벤트가 발생하면 main dlg가 깜빡이는 현상이 있다.
	//resizable dlg일 경우는 WS_THICKFRAME을 넣게 되는데 이를 넣으면 윈도우에서 기본 제공하는 shadow도 표시되므로
	//CWndShadow 관련 옵션을 별도로 설정할 필요가 없다.
	SetWindowLong(m_hWnd, GWL_STYLE, WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CLIPCHILDREN);

	m_tree.set_as_shell_treectrl(&m_shellimagelist);
	m_list.set_as_shell_listctrl(&m_shellimagelist);

	//메시지 창 초기화
	m_message.create(this, _T("Test_SCThemeDialog"));// , IDR_MAINFRAME);
	m_message.set_color_theme(m_theme.get_color_theme());

	//set_system_buttons(SC_HELP, SC_PIN, SC_MINIMIZE, SC_MAXIMIZE, SC_CLOSE);
	set_back_image(_T("JPG"), (UINT)IDB_WINDOW, CGdiplusBitmap::draw_mode_stretch);

	RestoreWindowPosition(&theApp, this);

	ptimer_start(0);
	long t0 = clock();
	Sleep(1234);
	long t1 = clock();
	double elapsed = ptimer_get_time(0);
	TRACE(_T("elapsed time = %f ms, clock = %ld\n"), elapsed, t1 - t0);

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
		TRACE(_T("CTestSCThemeDialogDlg::OnSysCommand. nID = %d, lParam = %ld\n"), nID, lParam);
		if (nID == SC_MAXIMIZE)
		{
			set_titlebar_height(0);
		}
		else if (nID == SC_RESTORE)
		{
			set_titlebar_height(32);
		}

		CSCThemeDlg::OnSysCommand(nID, lParam);
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
		CSCThemeDlg::OnPaint();
		/*
		CRect rc;
		GetClientRect(&rc);

		CPaintDC dc(this);

		rc.top = rc.bottom - 20;
		dc.FillSolidRect(rc, RGB(255, 0, 0));
		*/
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
	m_static_text.set_textf(_T("Test SCThemeDialog"));

	set_back_image(_T("jpg"), IDB_AUTUMN_LIVINGROOM, true);
	//set_back_image(_T("png"), _T("D:\\1.Projects_C++\\1.test\\Test_SCThemeDialog\\res\\images\\icecream.png"), true);
	CFirstDlg dlg;
	dlg.DoModal();
}


void CTestSCThemeDialogDlg::OnBnClickedCancel()
{
	if (m_message.DoModal(_T("테스트 프로그램을 종료합니다."), MB_OKCANCEL) == IDCANCEL)
		return;

	CDialogEx::OnCancel();
}


void CTestSCThemeDialogDlg::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CSCThemeDlg::OnWindowPosChanged(lpwndpos);

	// TODO: Add your message handler code here
	SaveWindowPosition(&theApp, this);
}


BOOL CTestSCThemeDialogDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN)
	{
		TRACE(_T("keydown on CTestSCThemeDialogDlg\n"));
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


BOOL CTestSCThemeDialogDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CSCThemeDlg::OnEraseBkgnd(pDC);
}


void CTestSCThemeDialogDlg::OnSize(UINT nType, int cx, int cy)
{
	CSCThemeDlg::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_static_text.m_hWnd == NULL)
		return;

	m_static_text.Invalidate();
}

void CTestSCThemeDialogDlg::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CSCThemeDlg::OnActivate(nState, pWndOther, bMinimized);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (nState == 0)
	{
		SetTimer(timer_refresh_title_area, 1, NULL);
	}
	else
	{
		KillTimer(timer_refresh_title_area);
	}
}

void CTestSCThemeDialogDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == timer_refresh_title_area)
	{
		KillTimer(nIDEvent);
		Invalidate();
		m_sys_buttons.Invalidate();
	}

	CSCThemeDlg::OnTimer(nIDEvent);
}
