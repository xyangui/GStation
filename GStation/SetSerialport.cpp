// SetSerialport.cpp : implementation file
//

#include "stdafx.h"
#include "GStation.h"
#include "SetSerialport.h"

#include "GStationDlg.h"
#include "Setting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetSerialport property page

IMPLEMENT_DYNCREATE(CSetSerialport, CPropertyPage)

CSetSerialport::CSetSerialport() : CPropertyPage(CSetSerialport::IDD)
{
	//{{AFX_DATA_INIT(CSetSerialport)
	//m_bListen = TRUE;
	//}}AFX_DATA_INIT
	//m_iCurSelBT = 7;        //m_comboBT.InsertString(7,_T("115200"));
	m_iBTtoPayloadU1 = 0x07;
	//m_iCurSelCom = 0;       //m_comboComTele.AddString(_T("1"));

	ReadComBTListenFromIniFile();
}

CSetSerialport::~CSetSerialport()
{
}

void CSetSerialport::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetSerialport)
	DDX_Control(pDX, IDC_BT, m_comboBT);
	DDX_Control(pDX, IDC_COM_TELE, m_comboComTele);
	DDX_Check(pDX, IDC_CHECK_LISTEN, m_bListen);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetSerialport, CPropertyPage)
	//{{AFX_MSG_MAP(CSetSerialport)
	ON_BN_CLICKED(IDC_BUTTON_COMTELE, OnButtonComTele)
	ON_BN_CLICKED(IDC_BUTTON_BT, OnButtonBT)
	ON_BN_CLICKED(IDC_CHECK_LISTEN, OnCheckListen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetSerialport message handlers

BOOL CSetSerialport::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	//每次显示属性页之前，都运行OnInitDialog()
	m_comboComTele.AddString(_T("1"));
	m_comboComTele.AddString(_T("2"));
	m_comboComTele.AddString(_T("3"));
	m_comboComTele.AddString(_T("4"));
	m_comboComTele.AddString(_T("5"));
	m_comboComTele.AddString(_T("6"));
	m_comboComTele.AddString(_T("7"));
	m_comboComTele.AddString(_T("8"));
	m_comboComTele.AddString(_T("9"));
	m_comboComTele.AddString(_T("10"));
	m_comboComTele.AddString(_T("11"));

	m_comboBT.AddString(_T("1200"));
	m_comboBT.InsertString(1,_T("2400"));
	m_comboBT.InsertString(2,_T("4800"));
	m_comboBT.InsertString(3,_T("9600"));
	m_comboBT.InsertString(4,_T("19200"));
	m_comboBT.InsertString(5,_T("38400"));
	m_comboBT.InsertString(6,_T("57600"));
	m_comboBT.InsertString(7,_T("115200"));

	ReadComBTListenFromIniFile();
	m_comboComTele.SetCurSel(m_iCurSelCom);
	m_comboBT.SetCurSel(m_iCurSelBT);

	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

int CSetSerialport::getBTint()
{
	int result;
	switch(m_iCurSelBT)
	{
	case 0:
		result = 1200;//0xff
		m_iBTtoPayloadU1 = 0xff;
		break;
	case 1:
		result = 2400;//0x7f
		m_iBTtoPayloadU1 = 0x7f;
		break;
	case 2:
		result = 4800;//0xbf
		m_iBTtoPayloadU1 = 0xbf;
		break;
	case 3:
		result = 9600;//0x5f
		m_iBTtoPayloadU1 = 0x5f;
		break;
	case 4:
		result = 19200;//0x2f
		m_iBTtoPayloadU1 = 0x2f;
		break;
	case 5:
		result = 38400;//0x17
		m_iBTtoPayloadU1 = 0x17;
		break;
	case 6:
		result = 57600;
		m_iBTtoPayloadU1 = 0x07;//这里不知道57600对应的U1
		break;
	case 7:
		result = 115200;//0x07
		m_iBTtoPayloadU1 = 0x07;
		break;
	default:
		break;
	}
	return result;
}
//CGStationDlg::OpenPort()调用getBTCString()，
CString CSetSerialport::getBTCString()
{
	CString result;
	result.Format("%d,%s",getBTint(),"n,8,1");//波特率115200，无校验，8个数据位，1个停止位
	return result;
}

int CSetSerialport::getComTeleInt()
{
	return m_iCurSelCom + 1;//返回值1代表COM1,2代表COM2...
}
//串口——“设置”按钮
void CSetSerialport::OnButtonComTele() 
{
	UpdateData(TRUE);
	m_iCurSelCom = m_comboComTele.GetCurSel();
	//只是设置串口号数，没有连接飞控，连接在主对话框中的OpenPort()

	if (!ComIsExistIsOpen(m_iCurSelCom + 1)) {
		return;//不存在或被占用时，不写入ini文件
	}

	//写入初始化文件
	WriteComToIniFile();
}
//波特率——“设置”按钮
void CSetSerialport::OnButtonBT() 
{
	UpdateData(TRUE);
	m_iCurSelBT = m_comboBT.GetCurSel();

	//写入初始化文件
	WriteBTToIniFile();
	
	CSetting *pSetting = (CSetting*)GetParent();
	CGStationDlg *pGStationDlg = (CGStationDlg*)pSetting->GetParent();

	CPacket Packet;
	Packet.m_msgid = 0x0f;//设置波特率
	Packet.m_len = 1;

	Packet.payload.putU1(m_iBTtoPayloadU1);
	Packet.generateCRC();

	pGStationDlg->SendPacket(Packet);
}
//只要点击“启动时自动进入监控状态”，就保存到ini.ini中
void CSetSerialport::OnCheckListen() 
{
	UpdateData(TRUE);

	CString strPathIniFileName = GetPathIniFileName();

	CString strSection = "Section1";
	CString strItemKey = "LISTEN";

	CString strValue;
	if (m_bListen) {
		strValue = _T("TRUE");
	}else{
		strValue = _T("FALSE");
	}
	
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);//写入ini文件中相应字段，MFC自带函数	
}
//返回值：全路径 + 初始化文件ini文件名
CString CSetSerialport::GetPathIniFileName()
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
//从ini.ini中读出串口、波特率和“启动时自动进入监控状态”，并给m_iCurSelCom，m_iCurSelBT和m_bListen赋值
void CSetSerialport::ReadComBTListenFromIniFile()
{
	CString strPathIniFileName = GetPathIniFileName();

	CString strSection = "Section1";
	CString strItemKey = "COM";
	char strBuff[256];
	
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName); //读取ini文件中相应字段的内容
	CString strValue = strBuff;

	m_iCurSelCom = atoi(strValue); 
	
	strItemKey = "BT";
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName);
	strValue = strBuff;

	m_iCurSelBT = atoi(strValue); 

	strItemKey = "LISTEN";
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName);
	strValue = strBuff;

	if (strValue == _T("TRUE")) {
		m_bListen = TRUE;
	}else{
		m_bListen = FALSE;
	}
}
//把“串口”值写入ini.ini
void CSetSerialport::WriteComToIniFile()
{
	CString strPathIniFileName = GetPathIniFileName();

	CString strSection = "Section1";
	CString strItemKey = "COM";
	
	CString strValue;
	strValue.Format("%d", m_iCurSelCom);
	
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);//写入ini文件中相应字段	
}
//把“波特率”值写入ini.ini
void CSetSerialport::WriteBTToIniFile()
{
	CString strPathIniFileName = GetPathIniFileName();
	
	CString strSection = "Section1";
	CString strItemKey = "BT";

	CString strValue;
	strValue.Format("%d", m_iCurSelBT);

	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);//写入ini文件中相应字段
}
//读ini.ini，返回是否“启动时自动进入监控状态”
BOOL CSetSerialport::IsAutoListen()//CGStationDlg用到这个函数
{
	ReadComBTListenFromIniFile();
	return m_bListen;
}
//判断串口是否不存在或者已被占用，返回FALSE不存在或已被占用，TRUE可用或已经打开，ComX=1,代表COM1，以此类推
BOOL CSetSerialport::ComIsExistIsOpen(int ComX)
{
	CSetting *pSetting = (CSetting*)GetParent();//CGStationDlg::OnInitDialog()里不能调用ComIsExistIsOpen(int ComX)
	CGStationDlg *pGStationDlg = (CGStationDlg*)pSetting->GetParent();

	if (pGStationDlg->m_MSCom.GetCommPort() ==  ComX) {	
		AfxMessageBox("此串口已经被打开！");
		return TRUE; //如果已经代开的COM号和ComX是一致的，返回TRUE
	}

	CString strCom;
	strCom.Format("COM%d", ComX);

	HANDLE hCom;
	hCom = CreateFile(strCom, GENERIC_READ | GENERIC_WRITE, 0, NULL,    
					OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL| FILE_FLAG_OVERLAPPED, NULL);  
// 这里的CreateFile函数起了很大的作用，可以用来创建系统设备文件，如果该设备不存在或者被占用，
//则会返回一个错误，即下面的 INVALID_HANDLE_VALUE ，据此可以判断可使用性。详细参见MSDN中的介绍。
	if(hCom == INVALID_HANDLE_VALUE){     //如果没有该设备，或者被其他应用程序在用
		AfxMessageBox("串口不存在或者已经被占用！");
		return FALSE;
	}else{
		AfxMessageBox("此串口可用！");
		CloseHandle(hCom);		
		return TRUE;
	}
}
//判断串口是否不存在或者已被占用，返回FALSE不存在或已被占用，TRUE可用，ComX=1,代表COM1，以此类推
BOOL CSetSerialport::ComIsExist(int ComX)//CGStationDlg::OnInitDialog()里能调用ComIsExist(int ComX)
{
	CString strCom;
	strCom.Format("COM%d", ComX);
	
	HANDLE hCom;
	//hCom = CreateFile(strCom, GENERIC_READ | GENERIC_WRITE, 0, NULL,    
	//	OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL| FILE_FLAG_OVERLAPPED, NULL);  
	//这里的CreateFile函数起了很大的作用，可以用来创建系统设备文件，如果该设备不存在或者被占用，
	//则会返回一个错误，即下面的 INVALID_HANDLE_VALUE ，据此可以判断可使用性。详细参见MSDN中的介绍。
	hCom = CreateFile(strCom, 0, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	
	if(hCom == INVALID_HANDLE_VALUE){     //如果没有该设备，或者被其他应用程序在用
		//AfxMessageBox("串口不存在或者已经被占用！");
		return FALSE;
	}else{
		//AfxMessageBox("此串口可用！");
		CloseHandle(hCom);		
		return TRUE;
	}
}



