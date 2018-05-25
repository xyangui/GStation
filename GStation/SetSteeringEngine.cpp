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

	int iDirectionOrFlap = 3;//û��ѡ���κ�һ����ѡ״̬������ʼ��ʱ

	CButton *pBtn1 = (CButton *)GetDlgItem( IDC_RADIO_LAUNCH1 ) ; 
	if ( pBtn1->GetCheck() == 1 ) 
		iDirectionOrFlap = 0;

	CButton *pBtn2 = (CButton *)GetDlgItem( IDC_RADIO_LAUNCH2 ) ; 
	if ( pBtn2->GetCheck() == 1 ) 
		iDirectionOrFlap = 1;

	if (iDirectionOrFlap == 3) {
		AfxMessageBox("��ѡ�С����Ʒ���桱���ߡ����Ƹ�����");
		return;
	}

	CPacket Packet;
	Packet.m_msgid = 0x30;//����ң����1ͨ�����ƶ���
	Packet.m_len = 1;
	
	Packet.payload.putU1(iDirectionOrFlap);
	Packet.generateCRC();
	
	CSetting *pSetting = (CSetting*)GetParent();
	CGStationDlg *pGStationDlg = (CGStationDlg*)pSetting->GetParent();
	
	pGStationDlg->SendPacket(Packet);	
}
