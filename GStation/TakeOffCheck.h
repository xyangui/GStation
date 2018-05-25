#if !defined(AFX_TAKEOFFCHECK_H__91F7018D_36F3_4B08_9BFF_4E0122E8E469__INCLUDED_)
#define AFX_TAKEOFFCHECK_H__91F7018D_36F3_4B08_9BFF_4E0122E8E469__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TakeOffCheck.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTakeOffCheck dialog

#include "XListCtrl\XListCtrl.h"

class CTakeOffCheck : public CDialog
{
// Construction
public:
	CTakeOffCheck(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTakeOffCheck)
	enum { IDD = IDD_DLG_TAKEOFF_CHECK };
	CXListCtrl	m_List;
	//}}AFX_DATA

	CString GetPathIniFileName();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTakeOffCheck)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTakeOffCheck)
	afx_msg void OnButtonGyroscope();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TAKEOFFCHECK_H__91F7018D_36F3_4B08_9BFF_4E0122E8E469__INCLUDED_)
