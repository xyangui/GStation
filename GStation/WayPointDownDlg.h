#if !defined(AFX_WAYPOINTDOWNDLG_H__AEE9D1B6_7525_4B6B_B980_27EA25BECF4C__INCLUDED_)
#define AFX_WAYPOINTDOWNDLG_H__AEE9D1B6_7525_4B6B_B980_27EA25BECF4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WayPointDownDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWayPointDownDlg dialog

class CWayPointDownDlg : public CDialog
{
// Construction
public:
	CWayPointDownDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWayPointDownDlg)
	enum { IDD = IDD_DLG_WAYPOINT_DOWN };
	int		m_iDownWayPoint;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWayPointDownDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWayPointDownDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAYPOINTDOWNDLG_H__AEE9D1B6_7525_4B6B_B980_27EA25BECF4C__INCLUDED_)
