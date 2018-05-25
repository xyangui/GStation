// TakeOffCheck.cpp : implementation file
//

#include "stdafx.h"
#include "gstation.h"
#include "TakeOffCheck.h"

#include "GStationDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTakeOffCheck dialog


CTakeOffCheck::CTakeOffCheck(CWnd* pParent /*=NULL*/)
	: CDialog(CTakeOffCheck::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTakeOffCheck)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTakeOffCheck::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTakeOffCheck)
	DDX_Control(pDX, IDC_LIST, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTakeOffCheck, CDialog)
	//{{AFX_MSG_MAP(CTakeOffCheck)
	ON_BN_CLICKED(IDC_BUTTON_GYROSCOPE, OnButtonGyroscope)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTakeOffCheck message handlers

void InitListCtrl(CXListCtrl& CtrlList, TCHAR *	lpszHeaders[], int colwidths[], int nCol)
{
	CtrlList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_TRACKSELECT | LVS_EX_GRIDLINES);
	
	// set column width according to window rect
	CRect rect;
	CtrlList.GetWindowRect(&rect);
	
	int w = rect.Width() - 2;
	
	int i;
	int total_cx = 0;
	LV_COLUMN lvcolumn;
	memset(&lvcolumn, 0, sizeof(lvcolumn));
	
	// add columns
	for (i = 0; ; i++)
	{
		if (lpszHeaders[i] == NULL)
			break;
		
		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvcolumn.fmt =  (i == 0) ? LVCFMT_LEFT : LVCFMT_CENTER;
		lvcolumn.pszText = lpszHeaders[i];
		lvcolumn.iSubItem = i;
		lvcolumn.cx = (lpszHeaders[i+1] == NULL) ? w - total_cx - 2 : (w * colwidths[i]) / 7;//40为所有列宽之和
        //xyg
		if (i == 0) 
			lvcolumn.cx = 31;
		if (i == 1) 
			lvcolumn.cx = 40;
        //xyg
		total_cx += lvcolumn.cx;
		CtrlList.InsertColumn(i, &lvcolumn);
	}
	
	// create the image CtrlList from bitmap resource
	VERIFY(CtrlList.m_cImageList.Create(IDB_CHECKBOXES, 16, 3, RGB(255, 0, 255)));
	CtrlList.m_HeaderCtrl.SetImageList(&CtrlList.m_cImageList);
	
	// iterate through header items and attach the image list
	HDITEM hditem;
	
	for (i = 0; i < CtrlList.m_HeaderCtrl.GetItemCount(); i++)
	{
		hditem.mask = HDI_IMAGE | HDI_FORMAT;
		CtrlList.m_HeaderCtrl.GetItem(i, &hditem);
		hditem.fmt |=  HDF_IMAGE;
		if (i == 0)
			hditem.iImage = XHEADERCTRL_UNCHECKED_IMAGE;
		else
			hditem.iImage = XHEADERCTRL_NO_IMAGE;
		
		CtrlList.m_HeaderCtrl.SetItem(i, &hditem);
	}
	
	memset(&lvcolumn, 0, sizeof(lvcolumn));
	
	// set the format again - must do this twice or first column does not get set
	for (i = 0; ; i++)
	{
		if (lpszHeaders[i] == NULL)
			break;
		
		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM;
		lvcolumn.fmt = (i == 2) ? LVCFMT_LEFT : LVCFMT_CENTER;
		lvcolumn.iSubItem = i;
		CtrlList.SetColumn(i, &lvcolumn);
	}
}
BOOL CTakeOffCheck::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	int nColWidth[] = { 1, 1, 50 };//设置列宽	
	TCHAR *	pHeader[] = { _T(""), _T("序号"), _T("项目"), NULL };
	InitListCtrl(m_List, pHeader, nColWidth, 3);
	
	// insert the items and subitems into the CtrlList
	m_List.LockWindowUpdate();// ***** lock window updates while filling CtrlList *****
	
	CString strPathIniFileName = GetPathIniFileName();
	CString strSection = "TakeOffCheck";
	
	char strBuff[256];
	CString str, strValue;

	for (int nItem = 0; nItem < 28; nItem++)
	{
		str = _T("");
		m_List.InsertItem(nItem, str);
		m_List.SetCheckbox(nItem, 0, 1);

		str.Format("%d", nItem + 1);
		m_List.SetItemText(nItem, 1, str);

		GetPrivateProfileString(strSection,str,NULL,strBuff,80,strPathIniFileName);//读取ini中字段的内容
		str.Format(" %s", strBuff);
		m_List.SetItemText(nItem, 2, str);
	}
	
	m_List.UnlockWindowUpdate();	// ***** unlock window updates ******/
/*
	m_List.InsertColumn(0,_T("序号"), LVCFMT_LEFT, 45);
	m_List.InsertColumn(1,_T("项目"), LVCFMT_LEFT, 500);

	//画表格的线
	DWORD dwExStyle = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | //LVS_EX_SUBITEMIMAGES |
		LVS_EX_HEADERDRAGDROP | LVS_EX_TRACKSELECT;
	m_List.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LPARAM(dwExStyle));
	//画表格的线

	CString strPathIniFileName = GetPathIniFileName();
	CString strSection = "TakeOffCheck";
	
	char strBuff[256];
	CString str, strValue;

	for(int i = 1; i <= 28; i++)
	{
		str.Format("%d", i);
		m_List.InsertItem(i - 1, str);
		
		GetPrivateProfileString(strSection,str,NULL,strBuff,80,strPathIniFileName); //读取ini文件中相应字段的内容
		strValue = strBuff;

		m_List.SetItemText(i - 1, 1, strValue);
	}
*/	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
//返回值：全路径 + 初始化文件ini文件名
CString CTakeOffCheck::GetPathIniFileName()
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
//陀螺清零
void CTakeOffCheck::OnButtonGyroscope() 
{
	if(AfxMessageBox(_T("注意：在保证飞控不动的情况下，自动标定陀螺零点！"), MB_YESNO|MB_ICONQUESTION) == IDNO)
		return;
	
	CGStationDlg *pGStationDlg = (CGStationDlg*)GetParent();
	
	CPacket Packet;
	Packet.m_msgid = 0x28;//在保证飞控不动的情况下，自动标定陀螺零点
	Packet.m_len = 0;
	Packet.generateCRC();
	
	pGStationDlg->SendPacket(Packet);
}
