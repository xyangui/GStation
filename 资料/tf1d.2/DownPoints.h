#if !defined(AFX_DOWNPOINTS_H__56D0DC15_5D12_4C5C_9ACE_252654AB240B__INCLUDED_)
#define AFX_DOWNPOINTS_H__56D0DC15_5D12_4C5C_9ACE_252654AB240B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DownPoints.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDownPoints dialog

class CDownPoints : public CDialog
{
// Construction
public:
	CDownPoints(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDownPoints)
	enum { IDD = IDD_DOWNPOINTS };
	int		m_nPotNum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownPoints)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDownPoints)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNPOINTS_H__56D0DC15_5D12_4C5C_9ACE_252654AB240B__INCLUDED_)
