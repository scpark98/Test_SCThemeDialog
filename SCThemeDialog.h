/*
* 개발 배경 :
	- 타이틀바가 없는 themeUI의 dlg를 쉽게 상속받아 사용하기 위해 제작.
	- 타이틀바의 유무는 resource editor에서 속성 변경 또는 method로 동적 변경 가능.
	- resizable도 사용자가 정한대로 동작되며 동적 변경도 가능해야 한다.

	캡션바가 없거나 커스터마이즈 된 형태의 캡션바로 표시되는 
*/

#pragma once

// CSCThemeDialog 대화 상자

class CSCThemeDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSCThemeDialog)

public:
	CSCThemeDialog(UINT nResourceID, CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSCThemeDialog();

	//타이틀바 show/hide
	void	show_titlebar(bool titlebar);
	void	enable_resize(bool resizable);

	virtual BOOL OnInitDialog();
	virtual INT_PTR DoModal();
	virtual void OnOK() {};
	virtual void OnCancel() {};

protected:
	CRect		m_border_thickness;
	bool		m_is_resizable = true;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
};
