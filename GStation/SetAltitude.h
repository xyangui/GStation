#if !defined(AFX_SETALTITUDE_H__CA0E78FA_70EB_40D1_8E1E_4B88588A964E__INCLUDED_)
#define AFX_SETALTITUDE_H__CA0E78FA_70EB_40D1_8E1E_4B88588A964E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetAltitude.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetAltitude dialog

class CSetAltitude : public CPropertyPage
{
	DECLARE_DYNCREATE(CSetAltitude)

// Construction
public:
	CSetAltitude();
	~CSetAltitude();

// Dialog Data
	//{{AFX_DATA(CSetAltitude)
	enum { IDD = IDD_SET_ALTITUDE };
	short	m_sAltitude;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSetAltitude)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSetAltitude)
	afx_msg void OnButtonSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETALTITUDE_H__CA0E78FA_70EB_40D1_8E1E_4B88588A964E__INCLUDED_)
