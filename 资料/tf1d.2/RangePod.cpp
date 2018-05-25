// RangePod.cpp : implementation file
//

#include "stdafx.h"
#include "TF1D.h"
#include "RangePod.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRangePod dialog


CRangePod::CRangePod(CWnd* pParent /*=NULL*/)
	: CDialog(CRangePod::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRangePod)
	m_First_Lat = 0.0;
	m_First_Lon = 0.0;
	m_In_Dis = 0;
	m_Linenum = 0;
	m_Second_Lat = 0.0;
	m_Second_Lon = 0.0;
	m_lfPointDis = 0.0;
	//}}AFX_DATA_INIT
}


void CRangePod::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRangePod)
	DDX_Text(pDX, IDC_FIRST_LAT, m_First_Lat);
	DDX_Text(pDX, IDC_FIRST_LON, m_First_Lon);
	DDX_Text(pDX, IDC_IN_DIS, m_In_Dis);
	DDX_Text(pDX, IDC_LINENUM, m_Linenum);
	DDX_Text(pDX, IDC_SECOND_LAT, m_Second_Lat);
	DDX_Text(pDX, IDC_SECOND_LON, m_Second_Lon);
	DDX_Text(pDX, IDC_POINTDIS, m_lfPointDis);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRangePod, CDialog)
	//{{AFX_MSG_MAP(CRangePod)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRangePod message handlers
