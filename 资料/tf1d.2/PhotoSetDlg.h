#if !defined(AFX_PHOTOSETDLG_H__05A57228_2791_45D3_930C_BAC211FB520B__INCLUDED_)
#define AFX_PHOTOSETDLG_H__05A57228_2791_45D3_930C_BAC211FB520B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PhotoSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPhotoSetDlg dialog

class CPhotoSetDlg : public CDialog
{
// Construction
public:
	CPhotoSetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPhotoSetDlg)
	enum { IDD = IDD_PHOTOSET };
	CComboBox	m_cType;
	int		m_nDis;
	int		m_nTime;
	CString	m_sType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhotoSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPhotoSetDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PHOTOSETDLG_H__05A57228_2791_45D3_930C_BAC211FB520B__INCLUDED_)
