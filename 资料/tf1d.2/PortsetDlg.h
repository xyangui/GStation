//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES
#if !defined(AFX_PORTSETDLG_H__8C57972D_C465_480E_ABEA_A958D4997831__INCLUDED_)
#define AFX_PORTSETDLG_H__8C57972D_C465_480E_ABEA_A958D4997831__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PortsetDlg.h : header file
//
#include "buttonxp.h"
/////////////////////////////////////////////////////////////////////////////
// CPortsetDlg dialog

class CPortsetDlg : public CDialog
{
// Construction
public:
	int m_nPort;
	CString m_strSettings;
	CPortsetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPortsetDlg)
	enum { IDD = IDD_PORTSET };
	CButtonXP	m_cOK;
	CComboBox	m_cBt;
	CComboBox	m_cCom;
	CString	m_sCom;
	CString	m_sBt;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPortsetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPortsetDlg)

	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PORTSETDLG_H__8C57972D_C465_480E_ABEA_A958D4997831__INCLUDED_)
