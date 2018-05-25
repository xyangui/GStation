//{{AFX_INCLUDES()
#include "commondialog.h"
//}}AFX_INCLUDES
#if !defined(AFX_LYERSCTRDLG_H__BA9CC5B7_2AAE_4825_B3DE_BC74200B3C55__INCLUDED_)
#define AFX_LYERSCTRDLG_H__BA9CC5B7_2AAE_4825_B3DE_BC74200B3C55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LyersctrDlg.h : header file
//
#include "buttonxp.h"
/////////////////////////////////////////////////////////////////////////////
// CLyersctrDlg dialog

class CLyersctrDlg : public CDialog
{
// Construction
public:
	CString m_sGetDir;
	void OnGetDir(CString str);
	int m_nFlag;
	CString m_sFileName;
	CLyersctrDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLyersctrDlg)
	enum { IDD = IDD_LAYERSCTR };
	CButtonXP	m_cOk;
	CButtonXP	m_cCancel;
	CButtonXP	m_cOpenmap;
	CButtonXP	m_cOpenlayer;
	CButtonXP	m_cNewlayer;
	CString	m_sDirecter;
	CCommonDialog1	m_comDlg;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLyersctrDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLyersctrDlg)
	afx_msg void OnNewlayer();
	afx_msg void OnOpenlayer();
	afx_msg void OnOpenmap();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LYERSCTRDLG_H__BA9CC5B7_2AAE_4825_B3DE_BC74200B3C55__INCLUDED_)
