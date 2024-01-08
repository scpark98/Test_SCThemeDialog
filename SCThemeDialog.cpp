// SCThemeDialog.cpp: 구현 파일
//

#include "pch.h"
#include "Test_SCThemeDialog.h"
#include "SCThemeDialog.h"
#include "afxdialogex.h"

#include "../../Common/Functions.h"

#pragma comment(lib, "Dwmapi.lib")

// CSCThemeDialog 대화 상자

IMPLEMENT_DYNAMIC(CSCThemeDialog, CDialogEx)

CSCThemeDialog::CSCThemeDialog(UINT nResourceID, CWnd* pParent /*=nullptr*/)
	: CDialogEx(nResourceID, pParent)
{

}

CSCThemeDialog::~CSCThemeDialog()
{
}

void CSCThemeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSCThemeDialog, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_NCHITTEST()
	ON_WM_NCACTIVATE()
	ON_WM_NCCALCSIZE()
END_MESSAGE_MAP()


// CSCThemeDialog 메시지 처리기
BOOL CSCThemeDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//find border thickness
	m_is_resizable = GetWindowLongPtr(m_hWnd, GWL_STYLE) & WS_THICKFRAME;
	if (m_is_resizable)
	{
		AdjustWindowRectEx(&m_border_thickness, GetWindowLongPtr(m_hWnd, GWL_STYLE) & ~WS_CAPTION, FALSE, NULL);
		m_border_thickness.left *= -1;
		m_border_thickness.top *= -1;
	}
	else if (GetWindowLongPtr(m_hWnd, GWL_STYLE) & WS_BORDER)
	{
		SetRect(&m_border_thickness, 1, 1, 1, 1);
	}

	MARGINS margins = { 0 };
	DwmExtendFrameIntoClientArea(m_hWnd, &margins);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

INT_PTR CSCThemeDialog::DoModal()
{
	//m_isModal = TRUE;
	return CDialogEx::DoModal();
}


BOOL CSCThemeDialog::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rc;
	GetClientRect(rc);

	pDC->FillSolidRect(rc, ::GetSysColor(COLOR_3DFACE));
	return TRUE;
	//return CDialogEx::OnEraseBkgnd(pDC);
}


void CSCThemeDialog::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	DefWindowProc(WM_NCLBUTTONDOWN, HTCAPTION, MAKEWORD(point.x, point.y));

	CDialogEx::OnLButtonDown(nFlags, point);
}

//타이틀바 show/hide
void CSCThemeDialog::show_titlebar(bool titlebar)
{
	/*
	LONG oldStyle = ::GetWindowLongPtr(m_hWnd, GWL_STYLE);
	LONG newStyle = oldStyle & (show ? WS_CAPTION : ~WS_CAPTION);
	::SetWindowLongPtr(m_hWnd, GWL_STYLE, newStyle);
	SetWindowPos(NULL, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE | SWP_DRAWFRAME);
	*/
	if (titlebar)
		ModifyStyle(0, WS_CAPTION, SWP_FRAMECHANGED);
	else
		ModifyStyle(WS_CAPTION, 0, SWP_FRAMECHANGED);
}

void CSCThemeDialog::enable_resize(bool resizable)
{
	m_is_resizable = resizable;

	if (resizable)
	{
		ModifyStyle(0, WS_THICKFRAME, SWP_FRAMECHANGED);

		//find border thickness
		if (GetWindowLongPtr(m_hWnd, GWL_STYLE) & WS_THICKFRAME)
		{
			AdjustWindowRectEx(&m_border_thickness, GetWindowLongPtr(m_hWnd, GWL_STYLE) & ~WS_CAPTION, FALSE, NULL);
			m_border_thickness.left *= -1;
			m_border_thickness.top *= -1;
		}
		else if (GetWindowLongPtr(m_hWnd, GWL_STYLE) & WS_BORDER)
		{
			SetRect(&m_border_thickness, 1, 1, 1, 1);
		}

		MARGINS margins = { 0 };
		DwmExtendFrameIntoClientArea(m_hWnd, &margins);
	}
	else
	{
		ModifyStyle(WS_THICKFRAME, 0, SWP_FRAMECHANGED);
	}
}


LRESULT CSCThemeDialog::OnNcHitTest(CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (!m_is_resizable)
	{
		return CDialogEx::OnNcHitTest(point);
	}

	DWORD win_ver = get_windows_major_version();
	LRESULT result;

	if (win_ver >= 10)
	{
		result = CDialogEx::OnNcHitTest(point);

		if (result == HTCLIENT)
		{
			ScreenToClient(&point);
			if (point.y < m_border_thickness.top)
				return HTTOP;
		}
	}
	else
	{
		CRect rc;

		GetClientRect(rc);

		enum { left = 1, top = 2, right = 4, bottom = 8 };

		int hit = 0;

		if (point.x < m_border_thickness.left) hit |= left;
		if (point.x > rc.right - m_border_thickness.right) hit |= right;
		if (point.y < m_border_thickness.top) hit |= top;
		if (point.y > rc.bottom - m_border_thickness.bottom) hit |= bottom;

		if (hit & top && hit & left) return HTTOPLEFT;
		if (hit & top && hit & right) return HTTOPRIGHT;
		if (hit & bottom && hit & left) return HTBOTTOMLEFT;
		if (hit & bottom && hit & right) return HTBOTTOMRIGHT;
		if (hit & left) return HTLEFT;
		if (hit & top) return HTTOP;
		if (hit & right) return HTRIGHT;
		if (hit & bottom) return HTBOTTOM;

		return HTCLIENT;
	}

	return result;
}


BOOL CSCThemeDialog::OnNcActivate(BOOL bActive)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_is_resizable)
	{
		//return을 FALSE로 하게 되면 메시지박스가 떴을 때 액션이 동작되지 않는다.
		//또한 여기서 Invalidate()을 해주지 않으면 상단 잔상이 생긴다.
		Invalidate();
		return TRUE;// FALSE;
	}

	return CDialogEx::OnNcActivate(bActive);
}


void CSCThemeDialog::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_is_resizable)
	{
		DWORD win_ver = get_windows_major_version();

		if (win_ver < 10)
			return;

		if (lpncsp)
		{
			lpncsp->rgrc[0].left += m_border_thickness.left;
			lpncsp->rgrc[0].right -= m_border_thickness.right;
			lpncsp->rgrc[0].bottom -= m_border_thickness.bottom;
			return;
		}
	}

	CDialogEx::OnNcCalcSize(bCalcValidRects, lpncsp);
}
