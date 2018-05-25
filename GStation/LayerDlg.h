//{{AFX_INCLUDES()
#include "commondialog.h"
//}}AFX_INCLUDES
#if !defined(AFX_LAYERDLG_H__0C29FE5E_6FD8_4FFB_ABF0_BFC75547BFA0__INCLUDED_)
#define AFX_LAYERDLG_H__0C29FE5E_6FD8_4FFB_ABF0_BFC75547BFA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LayerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLayerDlg dialog

class CLayerDlg : public CDialog
{
// Construction
public:
	CLayerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLayerDlg)
	enum { IDD = IDD_DLG_LAYER };
	CComboBox	m_comboLayer;
	CString	m_strDirectoryFileName;//包含路径和文件名和扩展名
	CCommonDialog1	m_comDlg;
	//}}AFX_DATA

	CString m_strFileExtensionName;//只有文件名和扩展名

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLayerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLayerDlg)
	afx_msg void OnButtonNew();
	afx_msg void OnButtonOpen();
	afx_msg void OnButtonMap();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString GetDirectory();

	enum ClickBtnType
	{
		New,  
		Open,
		Map,
	} ClickButtonType;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAYERDLG_H__0C29FE5E_6FD8_4FFB_ABF0_BFC75547BFA0__INCLUDED_)
