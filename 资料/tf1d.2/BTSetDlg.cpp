// BTSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TF1D.h"
#include "BTSetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBTSetDlg dialog


CBTSetDlg::CBTSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBTSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBTSetDlg)
	m_sBT = _T("");
	//}}AFX_DATA_INIT
}


void CBTSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBTSetDlg)
	DDX_Control(pDX, IDC_COMBO_BT, m_cBT);
	DDX_CBString(pDX, IDC_COMBO_BT, m_sBT);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBTSetDlg, CDialog)
	//{{AFX_MSG_MAP(CBTSetDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBTSetDlg message handlers

BOOL CBTSetDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_cBT.AddString(_T("9600"));
	m_cBT.InsertString(1,_T("19200"));
	m_cBT.InsertString(2,_T("38400"));
	m_cBT.InsertString(3,_T("115200"));
	m_cBT.SetCurSel(0);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
