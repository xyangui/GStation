#if !defined(AFX_POTDATADLG_H__E21392B6_F763_4312_B09F_E773D082A67A__INCLUDED_)
#define AFX_POTDATADLG_H__E21392B6_F763_4312_B09F_E773D082A67A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PotdataDlg.h : header file
//
#include "data.h"
/////////////////////////////////////////////////////////////////////////////
// CPotdataDlg dialog

class CPotdataDlg : public CDialog
{
// Construction
public:
	void OnSaveListPot(int linenum);
	int m_nScroll;
	void OnPotListInit();
	int m_nPotNum;
	void OnCreateStatic(int linenum);
	struct POINTDATA{
		int num;
		double lon;
		double lat;
		int alt;
		int spd;
		int raid;
		int time;
		int linetype;
		bool toline;
		bool toground;
		bool toslide;
		bool photo;
		bool serv1;
		bool serv2;
		bool serv3;
	} m_Potdata[200];
	CData potdata;
	POINTDATA m_model_Potdata;
	CPotdataDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPotdataDlg)
	enum { IDD = IDD_POTDATA };
	CScrollBar	m_cScroll;
	BOOL	m_nCheck_Photo;
	BOOL	m_nCheck_Serv1;
	BOOL	m_nCheck_Serv3;
	BOOL	m_nCheck_Serv2;
	BOOL	m_nCheck_Toground;
	BOOL	m_nCheck_Toline;
	BOOL	m_nCheck_Toslide;
	int		m_nMode_Alt;
	int		m_nMode_Linetype;
	int		m_nMode_Raid;
	int		m_nMode_Spd;
	int		m_nMode_Time;
	double	m_dAlt1;
	double	m_dAlt2;
	double	m_dAlt3;
	double	m_dAlt4;
	double	m_dAlt5;
	double	m_dAlt6;
	double	m_dLat1;
	double	m_dLat5;
	double	m_dLat2;
	double	m_dLat3;
	double	m_dLat4;
	double	m_dLat6;
	int		m_nLinetype1;
	int		m_nLinetype2;
	int		m_nLinetype3;
	int		m_nLinetype4;
	int		m_nLinetype5;
	int		m_nLinetype6;
	double	m_dLon1;
	double	m_dLon2;
	double	m_dLon3;
	double	m_dLon4;
	double	m_dLon5;
	double	m_dLon6;
	int		m_nNum1;
	int		m_nNum2;
	int		m_nNum3;
	int		m_nNum4;
	int		m_nNum5;
	int		m_nNum6;
	BOOL	m_bPhoto1;
	BOOL	m_bPhoto2;
	BOOL	m_bPhoto3;
	BOOL	m_bPhoto4;
	BOOL	m_bPhoto5;
	BOOL	m_bPhoto6;
	int		m_nRaid1;
	int		m_nRaid2;
	int		m_nRaid3;
	int		m_nRaid4;
	int		m_nRaid5;
	int		m_nRaid6;
	BOOL	m_bServ11;
	BOOL	m_bServ12;
	BOOL	m_bServ13;
	BOOL	m_bServ14;
	BOOL	m_bServ15;
	BOOL	m_bServ16;
	BOOL	m_bServ31;
	BOOL	m_bServ32;
	BOOL	m_bServ33;
	BOOL	m_bServ34;
	BOOL	m_bServ35;
	BOOL	m_bServ36;
	BOOL	m_bServ21;
	BOOL	m_bServ22;
	BOOL	m_bServ23;
	BOOL	m_bServ24;
	BOOL	m_bServ25;
	BOOL	m_bServ26;
	int		m_nSpd1;
	int		m_nSpd3;
	int		m_nSpd2;
	int		m_nSpd4;
	int		m_nSpd5;
	int		m_nSpd6;
	int		m_nTime1;
	int		m_nTime3;
	int		m_nTime2;
	int		m_nTime4;
	int		m_nTime5;
	int		m_nTime6;
	BOOL	m_bToGround1;
	BOOL	m_bToGround2;
	BOOL	m_bToGround3;
	BOOL	m_bToGround4;
	BOOL	m_bToGround5;
	BOOL	m_bToGround6;
	BOOL	m_bToLine1;
	BOOL	m_bToLine2;
	BOOL	m_bToLine3;
	BOOL	m_bToLine4;
	BOOL	m_bToLine5;
	BOOL	m_bToLine6;
	BOOL	m_bToSlide1;
	BOOL	m_bToSlide2;
	BOOL	m_bToSlide3;
	BOOL	m_bToSlide4;
	BOOL	m_bToSlide5;
	BOOL	m_bToSlide6;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPotdataDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPotdataDlg)
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POTDATADLG_H__E21392B6_F763_4312_B09F_E773D082A67A__INCLUDED_)
