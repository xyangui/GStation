// WayPointDownDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GStation.h"
#include "WayPointDownDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWayPointDownDlg dialog


CWayPointDownDlg::CWayPointDownDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWayPointDownDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWayPointDownDlg)
	m_iDownWayPoint = 0;
	//}}AFX_DATA_INIT
}


void CWayPointDownDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWayPointDownDlg)
	DDX_Text(pDX, IDC_EDIT_DOWN_WAYPOIT, m_iDownWayPoint);
	DDV_MinMaxInt(pDX, m_iDownWayPoint, 0, 100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWayPointDownDlg, CDialog)
	//{{AFX_MSG_MAP(CWayPointDownDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWayPointDownDlg message handlers
