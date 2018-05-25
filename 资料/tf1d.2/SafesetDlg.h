#if !defined(AFX_SAFESETDLG_H__C7DBAE64_BF90_4F6B_BD97_F64AF719DA38__INCLUDED_)
#define AFX_SAFESETDLG_H__C7DBAE64_BF90_4F6B_BD97_F64AF719DA38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SafesetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSafesetDlg dialog
#include "Buttonxp.h"

class CSafesetDlg : public CDialog
{
// Construction
public:
	CSafesetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSafesetDlg)
	enum { IDD = IDD_SAFESET };
	CButtonXP	m_ok;
	CButtonXP	m_cancel;
	int		m_nAir_Max;
	int		m_nAir_Min;
	int		m_nHigh_Min;
	int		m_nPasheng_Max;
	int		m_nPasheng_Min;
	double	m_nUAVV_Min;
	double	m_nUAVV_Max;
	double	m_nServV_Min;
	double	m_nServV_Max;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSafesetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSafesetDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAFESETDLG_H__C7DBAE64_BF90_4F6B_BD97_F64AF719DA38__INCLUDED_)
