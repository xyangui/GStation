#if !defined(AFX_SETVERSION_H__3CA20AA7_CBDD_4DD9_BE87_3EE068E463B3__INCLUDED_)
#define AFX_SETVERSION_H__3CA20AA7_CBDD_4DD9_BE87_3EE068E463B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetVersion.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetVersion dialog
//#define WM_PITCHROLL   WM_USER+100
//#define WM_VERSION     WM_USER+101
class CPayload;

class CSetVersion : public CPropertyPage
{
	DECLARE_DYNCREATE(CSetVersion)

// Construction
public:
	CSetVersion();
	~CSetVersion();

	void Unpack(CPayload payload);

// Dialog Data
	//{{AFX_DATA(CSetVersion)
	enum { IDD = IDD_SET_VERSION };
	int		m_iHardWare;
	float	m_fSoft;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSetVersion)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSetVersion)
	afx_msg void OnButtonCapture();
	afx_msg void OnButtonSet();
	LRESULT OnUpdateMyData(WPARAM wParam, LPARAM lParam);  	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETVERSION_H__3CA20AA7_CBDD_4DD9_BE87_3EE068E463B3__INCLUDED_)
