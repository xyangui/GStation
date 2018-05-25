// PhotoSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TF1D.h"
#include "PhotoSetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPhotoSetDlg dialog


CPhotoSetDlg::CPhotoSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPhotoSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPhotoSetDlg)
	m_nDis = 150;
	m_nTime = 5;
	m_sType = _T("");
	//}}AFX_DATA_INIT
}


void CPhotoSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPhotoSetDlg)
	DDX_Control(pDX, IDC_COMBO_TYPE, m_cType);
	DDX_Text(pDX, IDC_DIS, m_nDis);
	DDX_Text(pDX, IDC_TIME, m_nTime);
	DDX_CBString(pDX, IDC_COMBO_TYPE, m_sType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPhotoSetDlg, CDialog)
	//{{AFX_MSG_MAP(CPhotoSetDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPhotoSetDlg message handlers

BOOL CPhotoSetDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_cType.AddString(_T("µ»æ‡≈ƒ’’"));
	m_cType.InsertString(1,_T("µ» ±≈ƒ’’"));
	
	m_cType.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
