#if !defined(AFX_LINECOMPUTERDLG_H__2D924A60_DD40_41F9_9FD2_18C492017FF1__INCLUDED_)
#define AFX_LINECOMPUTERDLG_H__2D924A60_DD40_41F9_9FD2_18C492017FF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LineComputerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLineComputerDlg dialog

class CLineComputerDlg : public CDialog
{
// Construction
public:
	int m_nJingtou;
	CLineComputerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLineComputerDlg)
	enum { IDD = IDD_LINECOMPUTER };
	CButton	m_cCancel;
	CButton	m_cOK;
	CComboBox	m_cJingtou;
	int		m_nAlt;
	int		m_nForphotonum;
	double	m_dLength;
	int		m_nLinediepian;
	int		m_nLinedis;
	int		m_nPhotodiepian;
	int		m_nPhotodis;
	int		m_nPhotolength;
	int		m_nPhotowidth;
	double	m_dTotaldis;
	double	m_dWidth;
	double	m_dFenbianlv;
	CString	m_sJingtou;
	double	m_dFortime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLineComputerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLineComputerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnComputer();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINECOMPUTERDLG_H__2D924A60_DD40_41F9_9FD2_18C492017FF1__INCLUDED_)
