// DownPoints.cpp : implementation file
//

#include "stdafx.h"
#include "TF1D.h"
#include "DownPoints.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDownPoints dialog


CDownPoints::CDownPoints(CWnd* pParent /*=NULL*/)
	: CDialog(CDownPoints::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDownPoints)
	m_nPotNum = 0;
	//}}AFX_DATA_INIT
}


void CDownPoints::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownPoints)
	DDX_Text(pDX, IDC_POTNUM, m_nPotNum);
	DDV_MinMaxInt(pDX, m_nPotNum, 0, 100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDownPoints, CDialog)
	//{{AFX_MSG_MAP(CDownPoints)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDownPoints message handlers
