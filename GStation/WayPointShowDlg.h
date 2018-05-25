#if !defined(AFX_WAYPOINTSHOWDLG_H__4495FE98_542C_4673_975B_DF332E8260A1__INCLUDED_)
#define AFX_WAYPOINTSHOWDLG_H__4495FE98_542C_4673_975B_DF332E8260A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WayPointShowDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWayPointShowDlg dialog

class CWayPoint;

class CWayPointShowDlg : public CDialog
{
// Construction
public:
	CWayPointShowDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWayPointShowDlg)
	enum { IDD = IDD_DLG_WAYPOINT_SHOW };
	CListCtrl	m_List;
	//}}AFX_DATA

	void AddWayPointToList(CWayPoint &WayPoint, int iRowNum);
	void UpdateWayPointToList(CWayPoint &WayPoint, int iRowNum);
	void GetWPDownFromTabToList();
	void GetWayPointFromList(CWayPoint &WayPoint, int iRowNum);

	void SortList();
	int GetWayPointNumFromRowNum(int iRowNum);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWayPointShowDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWayPointShowDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAYPOINTSHOWDLG_H__4495FE98_542C_4673_975B_DF332E8260A1__INCLUDED_)
