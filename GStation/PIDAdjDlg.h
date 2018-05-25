//{{AFX_INCLUDES()
#include "tchart.h"
//}}AFX_INCLUDES
#if !defined(AFX_PIDADJDLG_H__78604737_4A8E_47C4_9A55_C36325D838BA__INCLUDED_)
#define AFX_PIDADJDLG_H__78604737_4A8E_47C4_9A55_C36325D838BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PIDAdjDlg.h : header file
//
#include "Msg_PIDData.h"
#include "Msg_PIDAdjustData.h"
#include "Msg_SetRPV.h"
#include "Msg_OtherPIDAdjData.h"

/////////////////////////////////////////////////////////////////////////////
// CPIDAdjDlg dialog

class CPIDAdjDlg : public CDialog
{
// Construction
public:
	CPIDAdjDlg(CWnd* pParent = NULL);   // standard constructor

	void UpDlgPIDData();
	void UpDlgPIDAdjData();
	void UpChartData();
	void UpYJData();

	COLORREF m_colorEditText; // edit控件的字体颜色
	COLORREF m_colorEditBK;  // edit控件的背景颜色
	CBrush* m_pEditBkBrush;
	
	CMsg_PIDData m_Msg_PIDData;
	CMsg_PIDAdjustData m_Msg_PIDAdjustData;
	CMsg_SetRPV m_Msg_SetRPV;
	CMsg_OtherPIDAdjData m_Msg_OtherPIDAdjData;

// Dialog Data
	//{{AFX_DATA(CPIDAdjDlg)
	enum { IDD = IDD_DLG_PIDAdjust };
	CComboBox	m_combo_SelectCH;
	CButton	m_btnSendYjData;
	CButton	m_btnSendData;
	int		m_txtBP;
	int		m_txtDh_D;
	int		m_txtDH_I;
	int		m_txtDh_P;
	int		m_txtFxd_D;
	int		m_txtFxd_I;
	int		m_txtFxd_P;
	int		m_txtFy_D;
	int		m_txtFy_I;
	int		m_txtFy_P;
	int		m_txtGdAgl_D;
	int		m_txtGdAgl_I;
	int		m_txtGuAgl_P;
	int		m_txtGdQg_D;
	int		m_txtGdQg_I;
	int		m_txtGz_D;
	int		m_txtGdQg_P;
	int		m_txtGz_I;
	int		m_txtGz_P;
	int		m_txtKsKf_D;
	int		m_txtKsKf_I;
	int		m_txtKsKf_P;
	int		m_txtKsKy_D;
	int		m_txtKsKy_I;
	int		m_txtKsKy_P;
	int		m_txtPhxz_D;
	int		m_txtPhxz_I;
	int		m_txtPhxz_P;
	int		m_txtTP;
	int		m_txtVP;
	float	m_txtAimFyDeg;
	int		m_txtAimGd;
	int		m_txtAimHx;
	int		m_txtAimKs;
	float	m_txtAimZwRate;
	int		m_txtCj;
	int		m_txtDs;
	float	m_txtFyDeg;
	float	m_txtFyRPV;
	int		m_txtGd;
	int		m_txtGdRPV;
	float	m_txtGPSgd;
	int		m_txtHx;
	int		m_txthxx;
	int		m_txtJmb;
	int		m_txtKs;
	int		m_txtKsRPV;
	int		m_txtMaxYj;
	int		m_txtMaxZwRate;
	int		m_txtMidYj;
	int		m_txtPIDModel;
	int		m_txtPxc;
	float	m_txtZwRate;
	int		m_txtZwRPV;
	CTChart	m_Chart_PID;
	float		m_txtFyGzDeg;
	CString	m_txtCtrlModel;
	BOOL	m_check_FySwitch;
	BOOL	m_check_GdSwitch;
	BOOL	m_check_GPSDhSwitch;
	BOOL	m_check_GzSwitch;
	BOOL	m_check_KsSwitch;
	BOOL	m_check_KsToYm;
	BOOL	m_check_PhxzSwitch;
	BOOL	m_check_ZwbzSwitch;
	BOOL	m_check_ZwSwitch;
	int		m_txtMinYJ;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPIDAdjDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	int m_ChartDataCount;
	bool m_IsRefresh;
	int m_combo_SelectIndex;
	int m_chartShowPointCount;
	
	void SetEditBC(CEdit* editCtrl,BOOL isNo);
	void SetEditText(CEdit* editCtrl,BOOL isNo);

	// Generated message map functions
	//{{AFX_MSG(CPIDAdjDlg)
	afx_msg void OnBtnGetpiddata();
	afx_msg void OnPaint();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnBTNSendData();
	afx_msg void OnSelendokCOMBOSelectCH();
	afx_msg void OnBTNSendFyRPV();
	afx_msg void OnBTNSendGdRPV();
	afx_msg void OnBTNSendKsRPV();
	afx_msg void OnBTNSendMaxZwRate();
	afx_msg void OnBTNSendYjData();
	afx_msg void OnBTNSendZwRPV();
	afx_msg void OnBTNGetYjData();
	afx_msg void OnBTNOpenAllCh();
	afx_msg void OnDestroy();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnCHECKFySwitch();
	afx_msg void OnCHECKKsToYm();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIDADJDLG_H__78604737_4A8E_47C4_9A55_C36325D838BA__INCLUDED_)
