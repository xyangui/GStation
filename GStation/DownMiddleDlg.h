#if !defined(AFX_DOWNMIDDLEDLG_H__8EFE98C6_FF8D_4068_8BFF_92DB40D2616C__INCLUDED_)
#define AFX_DOWNMIDDLEDLG_H__8EFE98C6_FF8D_4068_8BFF_92DB40D2616C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DownMiddleDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDownMiddleDlg dialog

class CDownMiddleDlg : public CDialog
{
// Construction
public:
	CDownMiddleDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDownMiddleDlg)
	enum { IDD = IDD_DOWN_MIDDLE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownMiddleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDownMiddleDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNMIDDLEDLG_H__8EFE98C6_FF8D_4068_8BFF_92DB40D2616C__INCLUDED_)
