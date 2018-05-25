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
	
	//ÿ����ʾ����ҳ֮ǰ��������OnInitDialog()
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
		m_iBTtoPayloadU1 = 0x07;//���ﲻ֪��57600��Ӧ��U1
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
//CGStationDlg::OpenPort()����getBTCString()��
CString CSetSerialport::getBTCString()
{
	CString result;
	result.Format("%d,%s",getBTint(),"n,8,1");//������115200����У�飬8������λ��1��ֹͣλ
	return result;
}

int CSetSerialport::getComTeleInt()
{
	return m_iCurSelCom + 1;//����ֵ1����COM1,2����COM2...
}
//���ڡ��������á���ť
void CSetSerialport::OnButtonComTele() 
{
	UpdateData(TRUE);
	m_iCurSelCom = m_comboComTele.GetCurSel();
	//ֻ�����ô��ں�����û�����ӷɿأ����������Ի����е�OpenPort()

	if (!ComIsExistIsOpen(m_iCurSelCom + 1)) {
		return;//�����ڻ�ռ��ʱ����д��ini�ļ�
	}

	//д���ʼ���ļ�
	WriteComToIniFile();
}
//�����ʡ��������á���ť
void CSetSerialport::OnButtonBT() 
{
	UpdateData(TRUE);
	m_iCurSelBT = m_comboBT.GetCurSel();

	//д���ʼ���ļ�
	WriteBTToIniFile();
	
	CSetting *pSetting = (CSetting*)GetParent();
	CGStationDlg *pGStationDlg = (CGStationDlg*)pSetting->GetParent();

	CPacket Packet;
	Packet.m_msgid = 0x0f;//���ò�����
	Packet.m_len = 1;

	Packet.payload.putU1(m_iBTtoPayloadU1);
	Packet.generateCRC();

	pGStationDlg->SendPacket(Packet);
}
//ֻҪ���������ʱ�Զ�������״̬�����ͱ��浽ini.ini��
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
	
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);//д��ini�ļ�����Ӧ�ֶΣ�MFC�Դ�����	
}
//����ֵ��ȫ·�� + ��ʼ���ļ�ini�ļ���
CString CSetSerialport::GetPathIniFileName()
{
	char strBuff[256];   
	int nPos = GetCurrentDirectory(256, strBuff);   
	CString strDirectory(strBuff);//strDirectoryΪ��ǰ·��������û��"\"    
	if( nPos < 0 )   
		strDirectory = _T("");   
	
	CString strPathIniFileName;
	strPathIniFileName.Format("%s\\ini.ini",strDirectory);

	return strPathIniFileName;
}
//��ini.ini�ж������ڡ������ʺ͡�����ʱ�Զ�������״̬��������m_iCurSelCom��m_iCurSelBT��m_bListen��ֵ
void CSetSerialport::ReadComBTListenFromIniFile()
{
	CString strPathIniFileName = GetPathIniFileName();

	CString strSection = "Section1";
	CString strItemKey = "COM";
	char strBuff[256];
	
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName); //��ȡini�ļ�����Ӧ�ֶε�����
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
//�ѡ����ڡ�ֵд��ini.ini
void CSetSerialport::WriteComToIniFile()
{
	CString strPathIniFileName = GetPathIniFileName();

	CString strSection = "Section1";
	CString strItemKey = "COM";
	
	CString strValue;
	strValue.Format("%d", m_iCurSelCom);
	
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);//д��ini�ļ�����Ӧ�ֶ�	
}
//�ѡ������ʡ�ֵд��ini.ini
void CSetSerialport::WriteBTToIniFile()
{
	CString strPathIniFileName = GetPathIniFileName();
	
	CString strSection = "Section1";
	CString strItemKey = "BT";

	CString strValue;
	strValue.Format("%d", m_iCurSelBT);

	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);//д��ini�ļ�����Ӧ�ֶ�
}
//��ini.ini�������Ƿ�����ʱ�Զ�������״̬��
BOOL CSetSerialport::IsAutoListen()//CGStationDlg�õ��������
{
	ReadComBTListenFromIniFile();
	return m_bListen;
}
//�жϴ����Ƿ񲻴��ڻ����ѱ�ռ�ã�����FALSE�����ڻ��ѱ�ռ�ã�TRUE���û��Ѿ��򿪣�ComX=1,����COM1���Դ�����
BOOL CSetSerialport::ComIsExistIsOpen(int ComX)
{
	CSetting *pSetting = (CSetting*)GetParent();//CGStationDlg::OnInitDialog()�ﲻ�ܵ���ComIsExistIsOpen(int ComX)
	CGStationDlg *pGStationDlg = (CGStationDlg*)pSetting->GetParent();

	if (pGStationDlg->m_MSCom.GetCommPort() ==  ComX) {	
		AfxMessageBox("�˴����Ѿ����򿪣�");
		return TRUE; //����Ѿ�������COM�ź�ComX��һ�µģ�����TRUE
	}

	CString strCom;
	strCom.Format("COM%d", ComX);

	HANDLE hCom;
	hCom = CreateFile(strCom, GENERIC_READ | GENERIC_WRITE, 0, NULL,    
					OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL| FILE_FLAG_OVERLAPPED, NULL);  
// �����CreateFile�������˺ܴ�����ã�������������ϵͳ�豸�ļ���������豸�����ڻ��߱�ռ�ã�
//��᷵��һ�����󣬼������ INVALID_HANDLE_VALUE ���ݴ˿����жϿ�ʹ���ԡ���ϸ�μ�MSDN�еĽ��ܡ�
	if(hCom == INVALID_HANDLE_VALUE){     //���û�и��豸�����߱�����Ӧ�ó�������
		AfxMessageBox("���ڲ����ڻ����Ѿ���ռ�ã�");
		return FALSE;
	}else{
		AfxMessageBox("�˴��ڿ��ã�");
		CloseHandle(hCom);		
		return TRUE;
	}
}
//�жϴ����Ƿ񲻴��ڻ����ѱ�ռ�ã�����FALSE�����ڻ��ѱ�ռ�ã�TRUE���ã�ComX=1,����COM1���Դ�����
BOOL CSetSerialport::ComIsExist(int ComX)//CGStationDlg::OnInitDialog()���ܵ���ComIsExist(int ComX)
{
	CString strCom;
	strCom.Format("COM%d", ComX);
	
	HANDLE hCom;
	//hCom = CreateFile(strCom, GENERIC_READ | GENERIC_WRITE, 0, NULL,    
	//	OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL| FILE_FLAG_OVERLAPPED, NULL);  
	//�����CreateFile�������˺ܴ�����ã�������������ϵͳ�豸�ļ���������豸�����ڻ��߱�ռ�ã�
	//��᷵��һ�����󣬼������ INVALID_HANDLE_VALUE ���ݴ˿����жϿ�ʹ���ԡ���ϸ�μ�MSDN�еĽ��ܡ�
	hCom = CreateFile(strCom, 0, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	
	if(hCom == INVALID_HANDLE_VALUE){     //���û�и��豸�����߱�����Ӧ�ó�������
		//AfxMessageBox("���ڲ����ڻ����Ѿ���ռ�ã�");
		return FALSE;
	}else{
		//AfxMessageBox("�˴��ڿ��ã�");
		CloseHandle(hCom);		
		return TRUE;
	}
}



