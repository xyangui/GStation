// PortsetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TF1D.h"
#include "PortsetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPortsetDlg dialog


CPortsetDlg::CPortsetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPortsetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPortsetDlg)
	m_sCom = _T("");
	m_sBt = _T("");
	//}}AFX_DATA_INIT
}


void CPortsetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPortsetDlg)
	DDX_Control(pDX, IDOK, m_cOK);
	DDX_Control(pDX, IDC_BT, m_cBt);
	DDX_Control(pDX, IDC_COM, m_cCom);
	DDX_CBString(pDX, IDC_COM, m_sCom);
	DDX_CBString(pDX, IDC_BT, m_sBt);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPortsetDlg, CDialog)
	//{{AFX_MSG_MAP(CPortsetDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPortsetDlg message handlers

//DEL void CPortsetDlg::OpenPort()
//DEL {
//DEL 
//DEL 	if(m_Com.GetPortOpen())
//DEL 		m_Com.SetPortOpen(FALSE);
//DEL 
//DEL 	m_Com.SetCommPort(m_nPort);       //选择com1
//DEL 	if( !m_Com.GetPortOpen())
//DEL 		m_Com.SetPortOpen(TRUE);//打开串口
//DEL 	else
//DEL 		AfxMessageBox("cannot open serial port");
//DEL 
//DEL 	m_Com.SetSettings(m_strSettings); //波特率9600，无校验，8个数据位，1个停止位
//DEL 	m_Com.SetRThreshold(1); 
//DEL 	//参数1表示每当串口接收缓冲区中有多于或等于1个字符时将引发一个接收数据的OnComm事件
//DEL 	m_Com.SetInputMode(1);
//DEL 	m_Com.SetInputLen(0);  //设置当前接收区数据长度为0
//DEL 	m_Com.GetInput();//先预读缓冲区以清除残留数据	
//DEL 
//DEL 
//DEL }


BOOL CPortsetDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

//	UpdateData(FALSE);
	m_cCom.AddString(_T("COM1"));
	m_cCom.AddString(_T("COM2"));
	m_cCom.AddString(_T("COM3"));
	m_cCom.AddString(_T("COM4"));
//	m_cCom.SetCurSel(0);


	
	m_cBt.AddString(_T("1200"));
	m_cBt.InsertString(1,_T("2400"));
	m_cBt.InsertString(2,_T("4800"));
	m_cBt.InsertString(3,_T("9600"));
	m_cBt.InsertString(4,_T("19200"));
	m_cBt.InsertString(5,_T("38400"));
	m_cBt.InsertString(6,_T("115200"));
//	m_cBt.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
