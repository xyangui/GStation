// SetPitchRoll.cpp : implementation file
//

#include "stdafx.h"
#include "GStation.h"
#include "SetPitchRoll.h"

#include "GStationDlg.h"
#include "Setting.h"
#include "Payload.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetPitchRoll property page

IMPLEMENT_DYNCREATE(CSetPitchRoll, CPropertyPage)

CSetPitchRoll::CSetPitchRoll() : CPropertyPage(CSetPitchRoll::IDD)
{
	//{{AFX_DATA_INIT(CSetPitchRoll)
	m_fPitch = 0.0;
	m_fRoll = 0.0;
	//}}AFX_DATA_INIT
}

CSetPitchRoll::~CSetPitchRoll()
{
}

void CSetPitchRoll::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetPitchRoll)
	DDX_Text(pDX, IDC_EDIT_PITCH, m_fPitch);
	DDX_Text(pDX, IDC_EDIT_ROLL, m_fRoll);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetPitchRoll, CPropertyPage)
	//{{AFX_MSG_MAP(CSetPitchRoll)
	ON_BN_CLICKED(IDC_BUTTON_CAPTURE, OnButtonCapture)
	ON_BN_CLICKED(IDC_BUTTON_SET, OnButtonSet)
	ON_BN_CLICKED(IDC_BUTTON_TOZERO, OnButtonToZero)
	ON_MESSAGE(WM_PITCHROLL,OnUpdateMyData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetPitchRoll message handlers

void CSetPitchRoll::OnButtonCapture() 
{
	CSetting *pSetting = (CSetting*)GetParent();
	CGStationDlg *pGStationDlg = (CGStationDlg*)pSetting->GetParent();

	CPacket Packet;
	Packet.m_msgid = 0x1e;//获取飞控安装角度偏差
	Packet.m_len = 1;

	Packet.payload.putU1(0);
	Packet.generateCRC();

	pGStationDlg->SendPacket(Packet);	
}

void CSetPitchRoll::OnButtonSet() 
{
	CSetting *pSetting = (CSetting*)GetParent();
	CGStationDlg *pGStationDlg = (CGStationDlg*)pSetting->GetParent();

	CPacket Packet;
	Packet.m_msgid = 0x1e;//设置飞控安装角度偏差
	Packet.m_len = 1;

	Packet.payload.putU1(1);
	Packet.generateCRC();

	pGStationDlg->SendPacket(Packet);		
}

void CSetPitchRoll::OnButtonToZero() 
{
	CSetting *pSetting = (CSetting*)GetParent();
	CGStationDlg *pGStationDlg = (CGStationDlg*)pSetting->GetParent();

	CPacket Packet;
	Packet.m_msgid = 0x1e;//偏置清零，恢复出厂设置
	Packet.m_len = 1;

	Packet.payload.putU1(2);
	Packet.generateCRC();

	pGStationDlg->SendPacket(Packet);		
}
LRESULT CSetPitchRoll::OnUpdateMyData(WPARAM wParam, LPARAM lParam)  
{  
	UpdateData(wParam);  
    return 1;  
} 
void CSetPitchRoll::Unpack(CPayload payload)
{
	payload.resetIndex();
	
	m_fPitch = (float)payload.getI2() / 100;
	m_fRoll = (float)payload.getI2() / 100;
}

