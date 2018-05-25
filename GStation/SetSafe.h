#if !defined(AFX_SETSAFE_H__FB25CF64_5002_47E5_9FDB_921AB693B297__INCLUDED_)
#define AFX_SETSAFE_H__FB25CF64_5002_47E5_9FDB_921AB693B297__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetSafe.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetSafe dialog

class CSetSafe : public CPropertyPage
{
	DECLARE_DYNCREATE(CSetSafe)

// Construction
public:
	CSetSafe();
	~CSetSafe();

// Dialog Data
	//{{AFX_DATA(CSetSafe)
	enum { IDD = IDD_SET_SAFE };
	float	m_fPilot_VMax;
	float	m_fPilot_VMin;
	float	m_fServo_VMin;
	float	m_fServo_VMax;
	int		m_iAirspeed_Max;
	int		m_iAirspeed_Min;
	int		m_iLowest_Alt;
	int		m_iClimb_Min;
	int		m_iClimb_Max;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSetSafe)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSetSafe)
	afx_msg void OnButtonApply();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CString GetPathIniFileName();
	void ReadValueFromIniFile();

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETSAFE_H__FB25CF64_5002_47E5_9FDB_921AB693B297__INCLUDED_)
