#if !defined(AFX_DOWNGPSDLG_H__D61B7744_E601_4E8C_ADC0_30E2936A325E__INCLUDED_)
#define AFX_DOWNGPSDLG_H__D61B7744_E601_4E8C_ADC0_30E2936A325E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DownGPSDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDownGPSDlg dialog

class CPayload;

class CDownGPSDlg : public CDialog
{
// Construction
public:
	CDownGPSDlg(CWnd* pParent = NULL);   // standard constructor

	void Unpack(CPayload payload);

// Dialog Data
	//{{AFX_DATA(CDownGPSDlg)
	enum { IDD = IDD_DOWN_GPS };
	int		m_iXD;
	float	m_fPDOP;
	int		m_iSatelliteNum;
	double	m_dLongitude;
	double	m_dLatitude;
	float	m_fGPSaltitude;
	float	m_fGPSspeed;
	float	m_fDirection;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownGPSDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDownGPSDlg)
	LRESULT OnUpdateMyData(WPARAM wParam, LPARAM lParam);  	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNGPSDLG_H__D61B7744_E601_4E8C_ADC0_30E2936A325E__INCLUDED_)
