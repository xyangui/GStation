#if !defined(AFX_AIRTOZERODLG_H__0E66B882_D98C_4824_9E09_2DAF384A47AF__INCLUDED_)
#define AFX_AIRTOZERODLG_H__0E66B882_D98C_4824_9E09_2DAF384A47AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AirToZeroDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAirToZeroDlg dialog

class CAirToZeroDlg : public CDialog
{
// Construction
public:
	CAirToZeroDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAirToZeroDlg)
	enum { IDD = IDD_AIRTOZERO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAirToZeroDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAirToZeroDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AIRTOZERODLG_H__0E66B882_D98C_4824_9E09_2DAF384A47AF__INCLUDED_)
