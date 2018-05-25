// SetSafe.cpp : implementation file
//

#include "stdafx.h"
#include "GStation.h"
#include "SetSafe.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetSafe property page

IMPLEMENT_DYNCREATE(CSetSafe, CPropertyPage)

CSetSafe::CSetSafe() : CPropertyPage(CSetSafe::IDD)
{
	//{{AFX_DATA_INIT(CSetSafe)
	m_fPilot_VMax = 12.0f;
	m_fPilot_VMin = 7.0f;
	m_fServo_VMin = 4.8f;
	m_fServo_VMax = 30.0f;
	m_iAirspeed_Max = 180;
	m_iAirspeed_Min = 55;
	m_iLowest_Alt = 150;
	m_iClimb_Min = -10;
	m_iClimb_Max = 10;
	//}}AFX_DATA_INIT
}

CSetSafe::~CSetSafe()
{
}

void CSetSafe::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetSafe)
	DDX_Text(pDX, IDC_EDIT_PILOT_VMAX, m_fPilot_VMax);
	DDX_Text(pDX, IDC_EDIT_PILOT_VMIN, m_fPilot_VMin);
	DDX_Text(pDX, IDC_EDIT_SERVO_VMIN, m_fServo_VMin);
	DDX_Text(pDX, IDC_EDIT_SERVO_VMAX, m_fServo_VMax);
	DDX_Text(pDX, IDC_EDIT_AIRSPEED_MAX, m_iAirspeed_Max);
	DDX_Text(pDX, IDC_EDIT_AIRSPEED_MIN, m_iAirspeed_Min);
	DDX_Text(pDX, IDC_EDIT_LOWEST_ALT, m_iLowest_Alt);
	DDX_Text(pDX, IDC_EDIT_CLIMB_MIN, m_iClimb_Min);
	DDX_Text(pDX, IDC_EDIT_CLIMB_MAX, m_iClimb_Max);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetSafe, CPropertyPage)
	//{{AFX_MSG_MAP(CSetSafe)
	ON_BN_CLICKED(IDC_BUTTON_APPLY, OnButtonApply)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetSafe message handlers

BOOL CSetSafe::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	ReadValueFromIniFile();
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

//返回值：全路径 + 初始化文件ini文件名
CString CSetSafe::GetPathIniFileName()
{
	char strBuff[256];   
	int nPos = GetCurrentDirectory(256, strBuff);   
	CString strDirectory(strBuff);//strDirectory为当前路径，后面没有"\"    
	if( nPos < 0 )   
		strDirectory = _T("");   
	
	CString strPathIniFileName;
	strPathIniFileName.Format("%s\\ini.ini",strDirectory);
	
	return strPathIniFileName;
}
//从ini.ini中读出飞控和舵机电压报警最大最小值
void CSetSafe::ReadValueFromIniFile()
{
	CString strPathIniFileName = GetPathIniFileName();

	if (strPathIniFileName.IsEmpty()) {
		return;
	}
	
	CString strSection = "Section2";
	char strBuff[256];

	CString strItemKey = "PlaneVoltageMax";
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName); //读取ini文件中相应字段的内容
	CString strValue = strBuff;
	
	m_fPilot_VMax = (float)atof(strValue); 
	
	strItemKey = "PlaneVoltageMin";
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName);
	strValue = strBuff;
	
	m_fPilot_VMin = (float)atof(strValue); 
	
	strItemKey = "SteeringEngineVoltageMax";
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName);
	strValue = strBuff;

	m_fServo_VMax = (float)atof(strValue); 

	strItemKey = "SteeringEngineVoltageMin";
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName);
	strValue = strBuff;
	
	m_fServo_VMin = (float)atof(strValue); 
}

void CSetSafe::OnButtonApply() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	CString strPathIniFileName = GetPathIniFileName();
	if (strPathIniFileName.IsEmpty()) {
		return;
	}
	
	CString strSection = "Section2";
	CString strItemKey = "PlaneVoltageMax";
	
	CString strValue;
	strValue.Format("%.2f", m_fPilot_VMax);
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);//写入ini文件中相应字段
	
	strItemKey = "PlaneVoltageMin";
	strValue.Format("%.2f", m_fPilot_VMin);
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);

	strItemKey = "SteeringEngineVoltageMax";
	strValue.Format("%.2f", m_fServo_VMax);
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);

	strItemKey = "SteeringEngineVoltageMin";
	strValue.Format("%.2f", m_fServo_VMin);
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);
}

