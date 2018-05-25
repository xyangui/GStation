#if !defined(AFX_DOWNSTEERINGDLG_H__36984454_7551_46E5_9F26_02D9BB62BCD7__INCLUDED_)
#define AFX_DOWNSTEERINGDLG_H__36984454_7551_46E5_9F26_02D9BB62BCD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DownSteeringDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDownSteeringDlg dialog

class CDownSteeringDlg : public CDialog
{
// Construction
public:
	CDownSteeringDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDownSteeringDlg)
	enum { IDD = IDD_DOWN_STEERING };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownSteeringDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDownSteeringDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNSTEERINGDLG_H__36984454_7551_46E5_9F26_02D9BB62BCD7__INCLUDED_)
