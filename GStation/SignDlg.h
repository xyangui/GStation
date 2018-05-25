#if !defined(AFX_SIGNDLG_H__FEA7C349_5621_4CF8_B827_A2DADE15D10F__INCLUDED_)
#define AFX_SIGNDLG_H__FEA7C349_5621_4CF8_B827_A2DADE15D10F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SignDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSignDlg dialog

class CSignDlg : public CDialog
{
// Construction
public:
	CSignDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSignDlg)
	enum { IDD = IDD_DLG_SIGN };
	CString	m_strSign;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSignDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSignDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIGNDLG_H__FEA7C349_5621_4CF8_B827_A2DADE15D10F__INCLUDED_)
