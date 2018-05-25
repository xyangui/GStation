#pragma once

// DlgToolBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgToolBar window

class CDlgToolBar : public CToolBar 
{   
protected:                
	// Generated message map functions
	//{{AFX_MSG(CDlgToolBar)
	afx_msg LRESULT OnIdleUpdateCmdUI(WPARAM wParam, LPARAM);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};        

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.
