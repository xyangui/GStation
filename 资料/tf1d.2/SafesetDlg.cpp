// SafesetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TF1D.h"
#include "SafesetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSafesetDlg dialog


CSafesetDlg::CSafesetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSafesetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSafesetDlg)
	m_nAir_Max = 0;
	m_nAir_Min = 0;
	m_nHigh_Min = 0;
	m_nPasheng_Max = 0;
	m_nPasheng_Min = -0;
	m_nUAVV_Min = 0.0;
	m_nUAVV_Max = 0.0;
	m_nServV_Min = 0.0;
	m_nServV_Max = 0.0;
	//}}AFX_DATA_INIT
}


void CSafesetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSafesetDlg)
	DDX_Control(pDX, IDOK, m_ok);
	DDX_Control(pDX, IDCANCEL, m_cancel);
	DDX_Text(pDX, IDC_AIRMAX, m_nAir_Max);
	DDX_Text(pDX, IDC_AIRMIN, m_nAir_Min);
	DDX_Text(pDX, IDC_HIGHMIN, m_nHigh_Min);
	DDX_Text(pDX, IDC_PASHENGMAX, m_nPasheng_Max);
	DDX_Text(pDX, IDC_PASHENGMIN, m_nPasheng_Min);
	DDX_Text(pDX, IDC_UAVVMIN, m_nUAVV_Min);
	DDX_Text(pDX, IDC_UAVVMAX, m_nUAVV_Max);
	DDX_Text(pDX, IDC_SERVVMIN, m_nServV_Min);
	DDX_Text(pDX, IDC_SERVVMAX, m_nServV_Max);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSafesetDlg, CDialog)
	//{{AFX_MSG_MAP(CSafesetDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSafesetDlg message handlers
