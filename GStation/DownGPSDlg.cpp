// DownGPSDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gstation.h"
#include "DownGPSDlg.h"

#include "Payload.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDownGPSDlg dialog


CDownGPSDlg::CDownGPSDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDownGPSDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDownGPSDlg)
	m_iXD = 0;
	m_fPDOP = 0.0f;
	m_iSatelliteNum = 0;
	m_dLongitude = 0.0;
	m_dLatitude = 0.0;
	m_fGPSaltitude = 0.0f;
	m_fGPSspeed = 0.0f;
	m_fDirection = 0.0f;
	//}}AFX_DATA_INIT
}


void CDownGPSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownGPSDlg)
	DDX_Text(pDX, IDC_EDIT_XD, m_iXD);
	DDX_Text(pDX, IDC_EDIT_PDOP, m_fPDOP);
	DDX_Text(pDX, IDC_EDIT_SNUM, m_iSatelliteNum);
	DDX_Text(pDX, IDC_EDIT_LONG, m_dLongitude);
	DDX_Text(pDX, IDC_EDIT_LAT, m_dLatitude);
	DDX_Text(pDX, IDC_EDIT_SAL, m_fGPSaltitude);
	DDX_Text(pDX, IDC_EDIT_SPEED, m_fGPSspeed);
	DDX_Text(pDX, IDC_EDIT_DIRECTION, m_fDirection);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDownGPSDlg, CDialog)
	//{{AFX_MSG_MAP(CDownGPSDlg)
	ON_MESSAGE(WM_DOWN_GPS,OnUpdateMyData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDownGPSDlg message handlers

LRESULT CDownGPSDlg::OnUpdateMyData(WPARAM wParam, LPARAM lParam)  
{  
	UpdateData(wParam);  
    return 1;  
} 

void CDownGPSDlg::Unpack(CPayload payload)
{
	payload.resetIndex();
	
	m_iXD = payload.getU1();
	m_fPDOP = (float)payload.getU2h() / 100; 

	m_iSatelliteNum = payload.getU1();
	m_dLongitude = (double)payload.getI4h() / 10000000;
	m_dLatitude = (double)payload.getI4h() / 10000000;
	m_fGPSaltitude = (float)((float)payload.getI4h() / 1000);

	//米/秒*60*60/1000=米/秒*3.6=公里/小时
	m_fGPSspeed = (float)((float)payload.getU4h()/100);//*3.6);(米/秒)
	//详见CMsg_Telemetry::Unpack(CPayload payload)
	m_fDirection = (float)((float)payload.getI4h() / 100000);
}

