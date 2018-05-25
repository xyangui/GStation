// UAVSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TF1D.h"
#include "UAVSetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUAVSetDlg dialog


CUAVSetDlg::CUAVSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUAVSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUAVSetDlg)
	m_sType = _T("");
	m_nTime = 5;
	m_nDistance = 150;
	m_sBT = _T("");
	m_nAlttoground = 0;
	m_dPitch = 0.0;
	m_dRoll = 0.0;
	m_sReceive = _T("");
	//}}AFX_DATA_INIT
	bReceive = TRUE;
	m_sStrReceived = "";
}


void CUAVSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUAVSetDlg)
	DDX_Control(pDX, IDC_ANGLESET, m_cAngleSet);
	DDX_Control(pDX, IDC_ANGLEGET, m_cAngleGet);
	DDX_Control(pDX, IDC_ROLL, m_cRoll);
	DDX_Control(pDX, IDC_PITCH, m_cPitch);
	DDX_Control(pDX, IDC_RECEIVE, m_cReceive);
	DDX_Control(pDX, IDC_AIRTOZERO, m_cAirtozero);
	DDX_Control(pDX, IDOK, m_cOK);
	DDX_Control(pDX, IDC_PHOTOSET, m_cPhotoset);
	DDX_Control(pDX, IDC_BTSET, m_cBTset);
	DDX_Control(pDX, IDC_ALTSET, m_cAltset);
	DDX_Control(pDX, IDC_BT, m_cBT);
	DDX_Control(pDX, IDC_TYPE, m_cType);
	DDX_Control(pDX, IDC_MSCOMM1, m_Com);
	DDX_CBString(pDX, IDC_TYPE, m_sType);
	DDX_Text(pDX, IDC_TIME, m_nTime);
	DDX_Text(pDX, IDC_DISTANCE, m_nDistance);
	DDX_CBString(pDX, IDC_BT, m_sBT);
	DDX_Text(pDX, IDC_ALTTOGROUND, m_nAlttoground);
	DDX_Text(pDX, IDC_PITCH, m_dPitch);
	DDX_Text(pDX, IDC_ROLL, m_dRoll);
	DDX_Text(pDX, IDC_RECEIVE, m_sReceive);
	//}}AFX_DATA_MAP
	m_nFlag = 10;
}


BEGIN_MESSAGE_MAP(CUAVSetDlg, CDialog)
	//{{AFX_MSG_MAP(CUAVSetDlg)
	ON_BN_CLICKED(IDC_PHOTOSET, OnPhotoset)
	ON_BN_CLICKED(IDC_BTSET, OnBtset)
	ON_BN_CLICKED(IDC_ALTSET, OnAltset)
	ON_BN_CLICKED(IDC_AIRTOZERO, OnAirtozero)
	ON_BN_CLICKED(IDC_ANGLEGET, OnAngleget)
	ON_BN_CLICKED(IDC_ANGLESET, OnAngleset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUAVSetDlg message handlers

void CUAVSetDlg::OnPhotoset() 
{
	// TODO: Add your control notification handler code here

	int type;
	int check;
	CString str;
	CByteArray hexdata;
	int dis_h,dis_l;
	
	UpdateData(TRUE);
	
	if(m_sType == "等距拍摄")
		type = 0;
	else type = 1;

	if(type == 0)
		str.Format("注意：拍照设置为：%s,设定间隔为%dm",m_sType,m_nDistance);
	else 
		str.Format("注意：拍照设置为：%s,设定间隔为%ds",m_sType,m_nTime);
	
	if(AfxMessageBox(str,MB_YESNO) == IDNO)
		return;

	dis_h = m_nDistance/256;
	dis_l = m_nDistance%256;
	check = 0;
	check = (45+5+type+m_nTime+dis_l+dis_h)%256;
		CString m_strSendString = "";
		m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x2d,0,5,type,m_nTime,dis_l,dis_h,0,check);
		String2Hex(m_strSendString ,hexdata);
		m_Com.SetOutput(COleVariant(hexdata));//发送数据
//	AfxMessageBox("secusse");


}

int CUAVSetDlg::String2Hex(CString str, CByteArray &senddata)
{
	int hexdata,lowhexdata;
	int hexdatalen=0;
	int len=str.GetLength();
	
	senddata.SetSize(len/2);
	
	for(int i=0;i<len;)
	{
		char lstr,hstr=str[i];
		if(hstr==' ')
		{
			i++;
			continue;
		}
		i++;
		if(i>=len)
			break;
		lstr=str[i];
		hexdata=ConvertHexChar(hstr);
		lowhexdata=ConvertHexChar(lstr);
		if((hexdata==16)||(lowhexdata==16))
			break;
		else 
			hexdata=hexdata*16+lowhexdata;
		i++;
		senddata[hexdatalen]=(char)hexdata;
		hexdatalen++;
	}

	senddata.SetSize(hexdatalen);
	return hexdatalen;

}

char CUAVSetDlg::ConvertHexChar(char ch)
{

	if((ch>='0')&&(ch<='9'))
		return ch-0x30;
	else if((ch>='A')&&(ch<='F'))
		return ch-'A'+10;
	else if((ch>='a')&&(ch<='f'))
		return ch-'a'+10;
	else return (-1);

}

void CUAVSetDlg::OpenPort()
{
		
	if(m_Com.GetPortOpen())
		m_Com.SetPortOpen(FALSE);

	m_Com.SetCommPort(m_nPort);       //选择com1
	if( !m_Com.GetPortOpen())
		m_Com.SetPortOpen(TRUE);//打开串口
	else
		AfxMessageBox("cannot open serial port");

	m_Com.SetSettings(m_strSettings); //波特率115200，无校验，8个数据位，1个停止位
	m_Com.SetRThreshold(1); 
	//参数1表示每当串口接收缓冲区中有多于或等于1个字符时将引发一个接收数据的OnComm事件
	m_Com.SetInputMode(1);
	m_Com.SetInputLen(0);  //设置当前接收区数据长度为0
	m_Com.GetInput();//先预读缓冲区以清除残留数据	

}

BOOL CUAVSetDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//////////////////////////////////////////////////
	//             参数初始设置                     //
	//////////////////////////////////////////////////
	m_cBT.AddString(_T("1200"));
	m_cBT.InsertString(1,_T("2400"));
	m_cBT.InsertString(2,_T("4800"));
	m_cBT.InsertString(3,_T("9600"));
	m_cBT.InsertString(4,_T("19200"));
	m_cBT.InsertString(5,_T("38400"));
	m_cBT.InsertString(6,_T("115200"));
	m_cBT.SetCurSel(3);

	m_cType.AddString(_T("等距拍摄"));
	m_cType.InsertString(1,_T("定时拍摄"));
	m_cType.SetCurSel(0);

	
	
	OpenPort();////打开串口
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CUAVSetDlg::OnBtset() 
{
	// TODO: Add your control notification handler code here
	int type;
	int check;
	CString str;
	CByteArray hexdata;
	UpdateData(TRUE);
	
	if(m_sBT == "1200")
	{
		type = 0xff;
		str.Format("注意：机载波特率将设置为%s",m_sBT);
	}
	else if(m_sBT == "2400")
	{
		type = 0x7f;
		str.Format("注意：机载波特率将设置为%s",m_sBT);
	}
	else if(m_sBT == "4800")
	{
		type = 0xbf;
		str.Format("注意：机载波特率将设置为%s",m_sBT);
	}
	else if(m_sBT == "9600")
	{
		type = 0x5f;
		str.Format("注意：机载波特率将设置为%s",m_sBT);
	}
	else if(m_sBT == "19200")
	{
		type = 0x2f;
		str.Format("注意：机载波特率将设置为%s",m_sBT);
	}
	else if(m_sBT == "38400")
	{
		type = 0x17;
		str.Format("注意：机载波特率将设置为%s",m_sBT);
	}
	else if(m_sBT == "115200")
	{
		type = 0x07;
		str.Format("注意：机载波特率将设置为%s",m_sBT);
	}


	if(AfxMessageBox(str,MB_YESNO) == IDNO)
		return;

	check = 0;
	check = (0x0f+1+type)%256;
		CString m_strSendString = "";
		m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x0f,0,1,type,check);
		String2Hex(m_strSendString ,hexdata);
		m_Com.SetOutput(COleVariant(hexdata));//发送数据
//	AfxMessageBox("secusse");

}

void CUAVSetDlg::OnAltset() 
{
	// TODO: Add your control notification handler code here
//	int type;
	int check;
	CString str;
	int alt_h,alt_l;
	CByteArray hexdata;
	UpdateData(TRUE);
	
	
	str.Format("注意：地面相对高度将设置为%d",m_nAlttoground);

	m_nAlttoground = m_nAlttoground*10;

	if(AfxMessageBox(str,MB_YESNO) == IDNO)
		return;

	alt_h = m_nAlttoground/256;
	alt_l = m_nAlttoground%256;
	check = 0;
	check = (0x11+2+alt_h+alt_l)%256;
		CString m_strSendString = "";
		m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x11,0,2,alt_h,alt_l,check);
		String2Hex(m_strSendString ,hexdata);
		m_Com.SetOutput(COleVariant(hexdata));//发送数据
//	AfxMessageBox("secusse");

}

void CUAVSetDlg::OnAirtozero() 
{
	// TODO: Add your control notification handler code here
	int check;
	CString str;
	CByteArray hexdata;
	UpdateData(TRUE);
	
	
	str.Format("注意：将进行空速清零");

	m_nAlttoground = m_nAlttoground*10;

	if(AfxMessageBox(str,MB_YESNO) == IDNO)
		return;

	check = 0;
	check = 0x1b;
		CString m_strSendString = "";
		m_strSendString.Format("%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x1b,0,0,check);
		String2Hex(m_strSendString ,hexdata);
		m_Com.SetOutput(COleVariant(hexdata));//发送数据
//	AfxMessageBox("secusse");
	
}

void CUAVSetDlg::OnAngleget() 
{
	// TODO: Add your control notification handler code here
	char check;
	CByteArray hexdata;
	check = 0;
	check = check+0x1e+1;
	CString m_strSendString = "";
	m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x1e,0,1,0,check);
	String2Hex(m_strSendString ,hexdata);
	m_Com.SetOutput(COleVariant(hexdata));//发送数据	
	
}

void CUAVSetDlg::OnAngleset() 
{
	// TODO: Add your control notification handler code here
	char check;
	CByteArray hexdata;
	check = 0;
	check = check+0x1e+1+1;
	CString m_strSendString = "";
	m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x1e,0,1,1,check);
	String2Hex(m_strSendString ,hexdata);
	m_Com.SetOutput(COleVariant(hexdata));//发送数据	
	
}

BEGIN_EVENTSINK_MAP(CUAVSetDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CUAVSetDlg)
	ON_EVENT(CUAVSetDlg, IDC_MSCOMM1, 1 /* OnComm */, OnOnCommMscomm1, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CUAVSetDlg::OnOnCommMscomm1() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here

	VARIANT variant_inp;
	COleSafeArray safearray_inp;
	LONG len,k;
	BYTE rxdata[2048]; //设置BYTE数组 An 8-bit integerthat is not signed.
	CString strtemp;
	CString inttemp;
//	int checktemp;
	CString strtemp2;

	if(bReceive)
	{
	
//		m_nLengthGed=0;
		if(m_Com.GetCommEvent()==2)     //事件值为2表示接收缓冲区内有字符
		{
			strtemp="";
			variant_inp = m_Com.GetInput();   //读缓冲区
			safearray_inp = variant_inp;           //VARIANT型变量转换为ColeSafeArray型变量
			len=safearray_inp.GetOneDimSize(); //得到有效数据长度
			for(k=0;k<len;k++)
				safearray_inp.GetElement(&k,rxdata+k);//转换为BYTE型数组
//			m_nLengthGed = len;//总数据长度

			for(k=0;k<len;k++)             //将数组转换为Cstring型变量
			{
				const unsigned char bt=*(unsigned char*)(rxdata+k);//无符号型
				strtemp.Format("%d",bt); //以十进制形式保存数据
				GetStrReceived(strtemp);//数据处理
//				m_cReceive.SetWindowText(strtemp);

			}
		}
	}
	
}

void CUAVSetDlg::GetStrReceived(CString str)
{
	if(str == "10")//0X0A判断，是则字头标志为TRUE
	{
		m_bHead = TRUE;
	}
	if(m_bHead == TRUE)//字头标志为真，则检查下一个字符是否为0xFF，是则为帧开始，标志恢复FALSE
	{
		if(str == "255")
		{
			GiveStrZero(m_nstrnum);			
			m_bHead = FALSE;
			m_nstrnum = 0;
		}
		else if(str =="10")
		{
			m_bHead = TRUE;
		}
		else
		{
			m_bHead = FALSE;
		}
	}
	
	OnOperateStr(str,m_nstrnum);
	m_sStrReceived +=str;
	if(m_nstrnum>90)
		m_nstrnum = 90;
//	m_pBuff[m_nstrnum] = atoi(str);
	m_nstrnum++;
}

void CUAVSetDlg::GiveStrZero(int num)
{

	m_sStrReceived = "";

}

void CUAVSetDlg::OnOperateStr(CString str, int num)
{
	CString strtemp;
	int numtemp;
	strtemp = str;
	numtemp = num;

	if(numtemp ==1)
	{
		m_nCommandType = atoi(strtemp);
//		m_nTotalNum++;///接收语句的总量统计
	}
	switch(m_nCommandType)
	{
	case 20:
		OnYaoceDataOperate(strtemp,numtemp);
		break;
	case 30:///偏置角计算
		OnAngleOperate(strtemp,numtemp);
		break;
	default:
		break;
	}

}

void CUAVSetDlg::OnYaoceDataOperate(CString str, int num)
{
	int tempnum;
	CString targettemp;
	switch(num)
	{
	case 4://///////////////控制模式
		tempnum = atoi(str);
		m_nContralmodel = tempnum;
		if(m_nContralmodel>=16)
			m_cReceive.SetWindowText("已应答");
		else
			m_cReceive.SetWindowText("");
		break;
	default:
		break;
	}

}

void CUAVSetDlg::OnAngleOperate(CString str, int num)
{
		int tempnum;
	CString strtemp;
	switch(num)
	{

	case 4:////数据
		tempnum = atoi(str);
		m_dPitch = tempnum*256;
		break;
	case 5:///
		tempnum = atoi(str);
		m_dPitch += tempnum;
		if(m_dPitch>20000)
			m_dPitch = 65536-m_dPitch;
		m_dPitch = m_dPitch/100;
		strtemp.Format("%lf",m_dPitch);
		m_cPitch.SetWindowText(strtemp);
		break;
	case 6:////数据
		tempnum = atoi(str);
		m_dRoll = tempnum*256;
		break;
	case 7:///
		tempnum = atoi(str);
		m_dRoll += tempnum;
		if(m_dRoll>20000)
			m_dRoll = 65536-m_dRoll;
		m_dRoll = m_dRoll/100;
		strtemp.Format("%lf",m_dRoll);
		m_cRoll.SetWindowText(strtemp);
		break;

	default:
		break;
	}


}
