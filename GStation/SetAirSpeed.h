#if !defined(AFX_SETAIRSPEED_H__F46F4FB7_465E_4B5A_A15C_92A8E5CCB18C__INCLUDED_)
#define AFX_SETAIRSPEED_H__F46F4FB7_465E_4B5A_A15C_92A8E5CCB18C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetAirSpeed.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetAirSpeed dialog

class CSetAirSpeed : public CPropertyPage
{
	DECLARE_DYNCREATE(CSetAirSpeed)

// Construction
public:
	CSetAirSpeed();
	~CSetAirSpeed();

// Dialog Data
	//{{AFX_DATA(CSetAirSpeed)
	enum { IDD = IDD_SET_AIRSPEED };
	int		m_iAirSpeedValue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSetAirSpeed)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSetAirSpeed)
	afx_msg void OnButtonAirSpeedToZero();
	afx_msg void OnButtonAirSpeedCapture();
	afx_msg void OnButtonAirSpeedSet();
	afx_msg void OnButtonAirSpeedDefault();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETAIRSPEED_H__F46F4FB7_465E_4B5A_A15C_92A8E5CCB18C__INCLUDED_)
