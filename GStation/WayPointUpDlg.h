#if !defined(AFX_WAYPOINTUPDLG_H__33C67110_0CFF_4A62_A391_8291060ABED6__INCLUDED_)
#define AFX_WAYPOINTUPDLG_H__33C67110_0CFF_4A62_A391_8291060ABED6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WayPointUpDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWayPointUpDlg dialog

class CWayPointUpDlg : public CDialog
{
// Construction
public:
	CWayPointUpDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWayPointUpDlg)
	enum { IDD = IDD_DLG_WAYPOINT_UP };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWayPointUpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWayPointUpDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAYPOINTUPDLG_H__33C67110_0CFF_4A62_A391_8291060ABED6__INCLUDED_)
