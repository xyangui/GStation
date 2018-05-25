#if !defined(AFX_WAYPOINTEDITDLG_H__EC3A350F_07AD_47FE_876C_34450A8FAAF7__INCLUDED_)
#define AFX_WAYPOINTEDITDLG_H__EC3A350F_07AD_47FE_876C_34450A8FAAF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WayPointEditDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWayPointEditDlg dialog

class CWayPoint;

class CWayPointEditDlg : public CDialog
{
// Construction
public:
	CWayPointEditDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWayPointEditDlg)
	enum { IDD = IDD_DLG_WAYPOINT_EDIT };
	CComboBox	m_comboWPServo3;
	CComboBox	m_comboWPServo2;
	CComboBox	m_comboWPServo1;
	CComboBox	m_comboWPPhoto;
	CComboBox	m_comboWPToSlope;
	CComboBox	m_comboWPToGround;
	CComboBox	m_comboWPToLine;
	CComboBox	m_comboModelServo3;
	CComboBox	m_comboModelServo2;
	CComboBox	m_comboModelServo1;
	CComboBox	m_comboModelPhoto;
	CComboBox	m_comboModelToSlope;
	CComboBox	m_comboModelToGround;
	CComboBox	m_comboModelToLine;
	CListCtrl	m_List;
	int		m_iWPNum;
	double	m_dWPLongitude;
	double	m_dWPLatitude;
	int		m_iWPAltitude;
	int		m_iWPSpeed;
	int		m_iWPRadius;
	int		m_iWPTime;
	int		m_iWPModel;
	int		m_iModelNum;
	double	m_dModelLongitude;
	double	m_dModelLatitude;
	int		m_iModelAltitude;
	int		m_iModelSpeed;
	int		m_iModelRadius;
	int		m_iModelTime;
	int		m_iModelModel;
	//}}AFX_DATA

	void AddWayPointToList(CWayPoint &WayPoint, int iRowNum);
	void UpdateWayPointToList(CWayPoint &WayPoint, int iRowNum);
	void GetWPUpFromTabToList();
	void GetWayPointFromList(CWayPoint &WayPoint, int iRowNum);

	//void SortList();
	//int GetWayPointNumFromRowNum(int iRowNum);

	void EditOneWayPointFromList(CWayPoint &WayPoint);
	void GetWayPointFromModel(CWayPoint &WayPoint);

	int m_iEditWPNum;
	void ReadWPModelFromIniFile();
	CString GetPathIniFileName();

	BOOL	m_bModelServo3;
	BOOL	m_bModelServo2;
	BOOL	m_bModelServo1;
	BOOL	m_bModelPhoto;
	BOOL	m_bModelToSlope;
	BOOL	m_bModelToGround;
	BOOL	m_bModelToLine;
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWayPointEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWayPointEditDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonWPEdit();
	afx_msg void OnButtonWPSave();
	afx_msg void OnButtonModelEdit();
	afx_msg void OnButtonModelSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAYPOINTEDITDLG_H__EC3A350F_07AD_47FE_876C_34450A8FAAF7__INCLUDED_)
