#if !defined(AFX_ALTSETDLG_H__B7E87F0D_44D8_4581_A20F_FEEC1964CCA6__INCLUDED_)
#define AFX_ALTSETDLG_H__B7E87F0D_44D8_4581_A20F_FEEC1964CCA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AltSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAltSetDlg dialog

class CAltSetDlg : public CDialog
{
// Construction
public:
	CAltSetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAltSetDlg)
	enum { IDD = IDD_ALTSET };
	int		m_nAlt;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAltSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAltSetDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALTSETDLG_H__B7E87F0D_44D8_4581_A20F_FEEC1964CCA6__INCLUDED_)
