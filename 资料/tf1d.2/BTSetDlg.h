#if !defined(AFX_BTSETDLG_H__FD8AA8C7_3A12_44D3_9628_F1584ED64415__INCLUDED_)
#define AFX_BTSETDLG_H__FD8AA8C7_3A12_44D3_9628_F1584ED64415__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BTSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBTSetDlg dialog

class CBTSetDlg : public CDialog
{
// Construction
public:
	CBTSetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBTSetDlg)
	enum { IDD = IDD_BTSET };
	CComboBox	m_cBT;
	CString	m_sBT;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBTSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBTSetDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BTSETDLG_H__FD8AA8C7_3A12_44D3_9628_F1584ED64415__INCLUDED_)
