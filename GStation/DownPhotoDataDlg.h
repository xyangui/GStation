#if !defined(AFX_DOWNPHOTODATADLG_H__8C8A9B61_FD1C_4A1E_B8AE_A789BB487B8D__INCLUDED_)
#define AFX_DOWNPHOTODATADLG_H__8C8A9B61_FD1C_4A1E_B8AE_A789BB487B8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DownPhotoDataDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDownPhotoDataDlg dialog

class CDownPhotoDataDlg : public CDialog
{
// Construction
public:
	CDownPhotoDataDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDownPhotoDataDlg)
	enum { IDD = IDD_DLG_DOWN_PHOTONUM };
	CEdit	m_cEnd;
	CEdit	m_cStart;
	int		m_iEnd;
	int		m_iStart;
	int		m_iRadio;
	//}}AFX_DATA

	int m_iReturn_Start;
	int m_iReturn_End;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownPhotoDataDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDownPhotoDataDlg)
	afx_msg void OnRadioAll();
	afx_msg void OnRadioRange();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNPHOTODATADLG_H__8C8A9B61_FD1C_4A1E_B8AE_A789BB487B8D__INCLUDED_)
