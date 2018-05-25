//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES
#if !defined(AFX_UAVSETDLG_H__3F9E62BA_AEAD_4F1C_BF39_50E9EF52F5B9__INCLUDED_)
#define AFX_UAVSETDLG_H__3F9E62BA_AEAD_4F1C_BF39_50E9EF52F5B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UAVSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUAVSetDlg dialog
#include "Buttonxp.h"
class CUAVSetDlg : public CDialog
{
// Construction
public:
	int m_nCommandType;
	int m_nContralmodel;
	CString m_sStrReceived;
	void OnAngleOperate(CString str,int num);
	void OnYaoceDataOperate(CString str,int num);
	int m_nstrnum;
	BOOL m_bHead;
	void OnOperateStr(CString str,int num);
	void GiveStrZero(int num);
	void GetStrReceived(CString str);
	BOOL bReceive;
	void OpenPort();
	CString m_strSettings;
	int m_nPort;
	int m_nFlag;
	char ConvertHexChar(char ch);
	int String2Hex(CString str, CByteArray &senddata);
	CUAVSetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUAVSetDlg)
	enum { IDD = IDD_UAVSET };
	CButtonXP	m_cAngleSet;
	CButtonXP	m_cAngleGet;
	CEdit	m_cRoll;
	CEdit	m_cPitch;
	CEdit	m_cReceive;
	CButtonXP	m_cAirtozero;
	CButtonXP	m_cOK;
	CButtonXP	m_cPhotoset;
	CButtonXP	m_cBTset;
	CButtonXP	m_cAltset;
	CComboBox	m_cBT;
	CComboBox	m_cType;
	CMSComm	m_Com;
	CString	m_sType;
	int		m_nTime;
	int		m_nDistance;
	CString	m_sBT;
	int		m_nAlttoground;
	double	m_dPitch;
	double	m_dRoll;
	CString	m_sReceive;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUAVSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUAVSetDlg)
	afx_msg void OnPhotoset();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtset();
	afx_msg void OnAltset();
	afx_msg void OnAirtozero();
	afx_msg void OnAngleget();
	afx_msg void OnAngleset();
	afx_msg void OnOnCommMscomm1();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UAVSETDLG_H__3F9E62BA_AEAD_4F1C_BF39_50E9EF52F5B9__INCLUDED_)
