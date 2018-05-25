// SetSteeringEngine.cpp : implementation file
//

#include "stdafx.h"
#include "GStation.h"
#include "SetSteeringEngine.h"

#include "GStationDlg.h"
#include "Setting.h"
#include "Payload.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetSteeringEngine property page

IMPLEMENT_DYNCREATE(CSetSteeringEngine, CPropertyPage)

CSetSteeringEngine::CSetSteeringEngine() : CPropertyPage(CSetSteeringEngine::IDD)
{
	//{{AFX_DATA_INIT(CSetSteeringEngine)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CSetSteeringEngine::~CSetSteeringEngine()
{
}

void CSetSteeringEngine::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetSteeringEngine)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetSteeringEngine, CPropertyPage)
	//{{AFX_MSG_MAP(CSetSteeringEngine)
	ON_BN_CLICKED(IDC_BUTTON_SET_LAUNCH, OnButtonSetLaunch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetSteeringEngine message handlers

void CSetSteeringEngine::OnButtonSetLaunch() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	int iDirectionOrFlap = 3;//没有选中任何一个单选状态，即初始化时

	CButton *pBtn1 = (CButton *)GetDlgItem( IDC_RADIO_LAUNCH1 ) ; 
	if ( pBtn1->GetCheck() == 1 ) 
		iDirectionOrFlap = 0;

	CButton *pBtn2 = (CButton *)GetDlgItem( IDC_RADIO_LAUNCH2 ) ; 
	if ( pBtn2->GetCheck() == 1 ) 
		iDirectionOrFlap = 1;

	if (iDirectionOrFlap == 3) {
		AfxMessageBox("请选中“控制方向舵”或者“控制副翼”！");
		return;
	}

	CPacket Packet;
	Packet.m_msgid = 0x30;//设置遥控器1通道控制对象
	Packet.m_len = 1;
	
	Packet.payload.putU1(iDirectionOrFlap);
	Packet.generateCRC();
	
	CSetting *pSetting = (CSetting*)GetParent();
	CGStationDlg *pGStationDlg = (CGStationDlg*)pSetting->GetParent();
	
	pGStationDlg->SendPacket(Packet);	
}
