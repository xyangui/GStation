#if !defined(AFX_DOWNSENSORDLG_H__A461AED7_9DFE_425B_A29E_DF83760257C9__INCLUDED_)
#define AFX_DOWNSENSORDLG_H__A461AED7_9DFE_425B_A29E_DF83760257C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DownSensorDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDownSensorDlg dialog

class CDownSensorDlg : public CDialog
{
// Construction
public:
	CDownSensorDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDownSensorDlg)
	enum { IDD = IDD_DOWN_SENSOR };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownSensorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDownSensorDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNSENSORDLG_H__A461AED7_9DFE_425B_A29E_DF83760257C9__INCLUDED_)
