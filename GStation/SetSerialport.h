#if !defined(AFX_SETSERIALPORT_H__8C8601BB_02DA_4ACA_9D86_B3B44C9655BB__INCLUDED_)
#define AFX_SETSERIALPORT_H__8C8601BB_02DA_4ACA_9D86_B3B44C9655BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetSerialport.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetSerialport dialog

class CSetSerialport : public CPropertyPage
{
	DECLARE_DYNCREATE(CSetSerialport)

// Construction
public:
	BOOL ComIsExist(int ComX);
	BOOL ComIsExistIsOpen(int ComX);
	BOOL IsAutoListen();
	int getBTint();
	int getComTeleInt();
	CString getBTCString();

	CSetSerialport();
	~CSetSerialport();

// Dialog Data
	//{{AFX_DATA(CSetSerialport)
	enum { IDD = IDD_SET_SERIALPORT };
	CComboBox	m_comboBT;
	CComboBox	m_comboComTele;
	BOOL	m_bListen;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSetSerialport)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSetSerialport)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonComTele();
	afx_msg void OnButtonBT();
	afx_msg void OnCheckListen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CString GetPathIniFileName();
	void ReadComBTListenFromIniFile();
	void WriteComToIniFile();
	void WriteBTToIniFile();
	int	m_iCurSelBT;
	int	m_iCurSelCom;
	int m_iBTtoPayloadU1;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETSERIALPORT_H__8C8601BB_02DA_4ACA_9D86_B3B44C9655BB__INCLUDED_)
