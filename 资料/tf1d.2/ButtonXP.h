#if !defined(AFX_BUTTONXP_H__68C59E26_AC0B_40A1_8BE8_1571A1929891__INCLUDED_)
#define AFX_BUTTONXP_H__68C59E26_AC0B_40A1_8BE8_1571A1929891__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ButtonXP.h : header file

/////////////////////////////////////////////////////////////////////////////
// CButtonXP window
class CMemDC : public CDC
{
public:
	CDC*	     m_dc;
	CBitmap      m_bitmap;
	CBitmap*	 m_hOldBitmap;
	RECT         m_rc;

	CMemDC(HDC hDC, LPRECT pRect)
	{
		m_dc = new CDC;
		
		ASSERT(hDC != NULL);
		m_dc->m_hAttribDC = hDC;
		m_dc->m_hDC = hDC;
		if (pRect != NULL)
			m_rc = *pRect;
		else
			m_dc->GetClipBox(&m_rc);
		
		CreateCompatibleDC(m_dc);
		::LPtoDP(m_dc->m_hDC, (LPPOINT)&m_rc, sizeof(RECT) / sizeof(POINT));
		m_bitmap.CreateCompatibleBitmap(m_dc, m_rc.right - m_rc.left, m_rc.bottom - m_rc.top);
		m_hOldBitmap = SelectObject(&m_bitmap);
		::DPtoLP(m_dc->m_hDC, (LPPOINT)&m_rc, sizeof(RECT) / sizeof(POINT));
		SetWindowOrg(m_rc.left, m_rc.top);
		FillSolidRect(&m_rc, m_dc->GetBkColor());
	}
	~CMemDC()
	{
		m_dc->BitBlt(m_rc.left, m_rc.top, m_rc.right - m_rc.left, m_rc.bottom - m_rc.top,
			this, m_rc.left, m_rc.top, SRCCOPY);
		SelectObject(m_hOldBitmap);
		delete m_dc;
	}
};

class CButtonXP : public CButton
{
// Construction
public:
	CButtonXP();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtonXP)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CButtonXP();

	// Generated message map functions
protected:
	//{{AFX_MSG(CButtonXP)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMouseHover(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

protected:
	CPen m_BoundryPen;               // 按钮边框画笔（颜色）
	
	CPen m_InsideBoundryPenLeft;     // 按钮内部左边框画笔（颜色）
	CPen m_InsideBoundryPenRight;    // 按钮内部右边框画笔（颜色）
	CPen m_InsideBoundryPenTop;      // 按钮内部上边框画笔（颜色）
	CPen m_InsideBoundryPenBottom;   // 按钮内部下边框画笔（颜色）

	CPen m_InsideBoundryPenLeftSel;  // 按钮被选中时内部左边框画笔（颜色）
	CPen m_InsideBoundryPenRightSel; // 按钮被选中时内部右边框画笔（颜色）
	CPen m_InsideBoundryPenTopSel;   // 按钮被选中时内部上边框画笔（颜色）
	CPen m_InsideBoundryPenBottomSel;// 按钮被选中时内部下边框画笔（颜色）

	CBrush m_FillActive;     // 被选中时按钮区域填充用画刷（颜色）
	CBrush m_FillInactive;   // 未选中时按钮区域填充用画刷（颜色）
	 
	BOOL m_bOver;            // 按钮是否有鼠标悬停标志 
	BOOL m_bTracking;        // 是否跟踪鼠标事件标志 
	BOOL m_bSelected;        // 按钮是否被选中标志 
	BOOL m_bFocus;           // 按钮是否获得焦点标志 

	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
private:
	void DoGradientFill(CDC *pDC, CRect* rect);
	void DrawInsideBorder(CDC *pDC, CRect* rect);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTONXP_H__68C59E26_AC0B_40A1_8BE8_1571A1929891__INCLUDED_)
