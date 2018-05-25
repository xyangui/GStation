// DownMiddleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gstation.h"
#include "DownMiddleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDownMiddleDlg dialog


CDownMiddleDlg::CDownMiddleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDownMiddleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDownMiddleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDownMiddleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownMiddleDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDownMiddleDlg, CDialog)
	//{{AFX_MSG_MAP(CDownMiddleDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDownMiddleDlg message handlers
