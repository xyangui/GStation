// WayPointShowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gstation.h"
#include "WayPointShowDlg.h"

#include "GStationDlg.h"
#include "Msg_WayPoint.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWayPointShowDlg dialog


CWayPointShowDlg::CWayPointShowDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWayPointShowDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWayPointShowDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWayPointShowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWayPointShowDlg)
	DDX_Control(pDX, IDC_LIST, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWayPointShowDlg, CDialog)
	//{{AFX_MSG_MAP(CWayPointShowDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWayPointShowDlg message handlers

BOOL CWayPointShowDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_List.InsertColumn(0,_T("���"), LVCFMT_LEFT, 41);
	m_List.InsertColumn(1,_T("����"), LVCFMT_LEFT, 83);
	m_List.InsertColumn(2,_T("γ��"), LVCFMT_LEFT, 83);	
	m_List.InsertColumn(3,_T("�߶�(��)"), LVCFMT_LEFT, 65);
	m_List.InsertColumn(4,_T("�ٶ�(��/��)"), LVCFMT_LEFT, 78);
	m_List.InsertColumn(5,_T("�뾶(��)"), LVCFMT_LEFT, 65);
	m_List.InsertColumn(6,_T("ʱ��(��)"), LVCFMT_LEFT, 65);
	m_List.InsertColumn(7,_T("��ʽ"), LVCFMT_LEFT, 42);
	
	m_List.InsertColumn(8,_T("����"), LVCFMT_LEFT, 41);
	m_List.InsertColumn(9,_T("��½"), LVCFMT_LEFT, 41);
	m_List.InsertColumn(10,_T("б��"), LVCFMT_LEFT, 41);
	m_List.InsertColumn(11,_T("���"), LVCFMT_LEFT, 41);	
	m_List.InsertColumn(12,_T("���1"), LVCFMT_LEFT, 42);
	m_List.InsertColumn(13,_T("���2"), LVCFMT_LEFT, 42);
	m_List.InsertColumn(14,_T("���3"), LVCFMT_LEFT, 42);
	
	//��������
	DWORD dwExStyle = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | //LVS_EX_SUBITEMIMAGES |
		LVS_EX_HEADERDRAGDROP | LVS_EX_TRACKSELECT;
	m_List.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LPARAM(dwExStyle));
	//��������
	
	GetWPDownFromTabToList();

	SortList();
	
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CWayPointShowDlg::GetWPDownFromTabToList()
{
	CGStationDlg *pGStationDlg = (CGStationDlg*)GetParent();

	VARIANT lyrVt;
	lyrVt.vt = VT_DISPATCH;
	lyrVt.pdispVal = pGStationDlg->m_ctrlMapX.GetLayers().Item("WayPointDown");
	lyrVt.pdispVal->AddRef();
	
	CMapXDataset MapXDataset = pGStationDlg->m_ctrlMapX.GetDatasets().Add(miDataSetLayer,lyrVt);
	
	CMapXLayer lay = pGStationDlg->m_ctrlMapX.GetLayers().Item("WayPointDown");
	int iWayPointCount = lay.AllFeatures().GetCount();
	//int num2 = MapXDataset.GetRowCount();//Dataset��¼��
	CWayPoint WayPoint;
	
	for(int i = 1; i <= iWayPointCount; i++)
	{
		//tab����>WayPoint
		CMapXPoint pt = lay.AllFeatures().Item(i).GetPoint();
		WayPoint.dLongitude = pt.GetX();
		WayPoint.dLatitude = pt.GetY();

		//���浽m_CMapXPoints�У�m_CMapXPoints�������ô�С���Զ�����////�����浽CGStationDlg�е�m_CMapXPoints��
		//pGStationDlg->m_CMapXPoints.Add(pt, i);//iΪ1��Points.Count����//m_CMapXPointsû�õ����Ѿ�ɾ��
		
		CString str;
		str.Format("%d",i);
		lay.SetKeyField("num");
		lay.AllFeatures().Item(i).SetKeyValue(str);
		
		VARIANT Vt;
		Vt = MapXDataset.GetRowValues(i).Item(1).GetValue();
		double value = Vt.date;
		WayPoint.iNum = (int)value;
		
		Vt = MapXDataset.GetRowValues(i).Item(2).GetValue();
		value = Vt.date;
		WayPoint.iAltitude = (int)value;
		
		Vt = MapXDataset.GetRowValues(i).Item(3).GetValue();
		value = Vt.date;
		WayPoint.iSpeed = (int)value;
		
		Vt = MapXDataset.GetRowValues(i).Item(4).GetValue();
		value = Vt.date;
		WayPoint.iRadius = (int)value;
		
		Vt = MapXDataset.GetRowValues(i).Item(5).GetValue();
		value = Vt.date;
		WayPoint.iStandardModel = (int)value & 7;
		
		int c;//��ȡ�ֽڵ�λ
		c = (int)value & 8;
		if(c == 0)
			WayPoint.bToLine = FALSE;
		else
			WayPoint.bToLine = TRUE;
		
		c = (int)value & 16;
		if(c == 0)
			WayPoint.bToGround = FALSE;
		else
			WayPoint.bToGround = TRUE;
		
		c = (int)value & 32;
		if(c == 0)
			WayPoint.bToSlope = FALSE;
		else
			WayPoint.bToSlope = TRUE;
		
		c = (int)value & 64;
		if(c == 0)
			WayPoint.bPhoto = FALSE;
		else
			WayPoint.bPhoto = TRUE;
		
		Vt = MapXDataset.GetRowValues(i).Item(6).GetValue();
		value = Vt.date;
		WayPoint.iTime = (int)(value * 10);
		
		Vt = MapXDataset.GetRowValues(i).Item(7).GetValue();
		value = Vt.date;
		c=(int)value & 1;
		if(c == 0)
			WayPoint.bServo1 = FALSE;
		else
			WayPoint.bServo1 = TRUE;
		
		c=(int)value & 2;
		if(c == 0)
			WayPoint.bServo2 = FALSE;
		else
			WayPoint.bServo2 = TRUE;
		
		c=(int)value & 4;
		if(c == 0)
			WayPoint.bServo3 = FALSE;
		else
			WayPoint.bServo3 = TRUE;
        //WayPoint����>List
		AddWayPointToList(WayPoint, i-1);
	}
}
void CWayPointShowDlg::AddWayPointToList(CWayPoint &WayPoint, int iRowNum)
{
	CString str;
	str.Format("%d", WayPoint.iNum);
	m_List.InsertItem(iRowNum, str);
	
	UpdateWayPointToList(WayPoint, iRowNum);
}
void CWayPointShowDlg::UpdateWayPointToList(CWayPoint &WayPoint, int iRowNum)
{
	//WayPoint����>List
	CString str;
	str.Format("%d", WayPoint.iNum);
	m_List.SetItemText(iRowNum, 0, str);
	
	str.Format("%f", WayPoint.dLongitude);
	m_List.SetItemText(iRowNum, 1, str);
	str.Format("%f", WayPoint.dLatitude);
	m_List.SetItemText(iRowNum, 2, str);
	str.Format("%d", WayPoint.iAltitude);
	m_List.SetItemText(iRowNum, 3, str);
	str.Format("%d", WayPoint.iSpeed);
	m_List.SetItemText(iRowNum, 4, str);
	str.Format("%d", WayPoint.iRadius);
	m_List.SetItemText(iRowNum, 5, str);
	str.Format("%d", WayPoint.iTime);
	m_List.SetItemText(iRowNum, 6, str);
	str.Format("%d", WayPoint.iStandardModel);
	m_List.SetItemText(iRowNum, 7, str);
	
	if (WayPoint.bToLine) 
		str = _T("��");
	else
		str = _T("��");
	m_List.SetItemText(iRowNum, 8, str);
	if (WayPoint.bToGround) 
		str = _T("��");
	else
		str = _T("��");
	m_List.SetItemText(iRowNum, 9, str);
	if (WayPoint.bToSlope) 
		str = _T("��");
	else
		str = _T("��");
	m_List.SetItemText(iRowNum, 10, str);
	
	if (WayPoint.bPhoto) 
		str = _T("��");
	else
		str = _T("��");
	m_List.SetItemText(iRowNum, 11, str);	
	if (WayPoint.bServo1) 
		str = _T("��");
	else
		str = _T("��");
	m_List.SetItemText(iRowNum, 12, str);
	if (WayPoint.bServo2) 
		str = _T("��");
	else
		str = _T("��");
	m_List.SetItemText(iRowNum, 13, str);
	if (WayPoint.bServo3) 
		str = _T("��");
	else
		str = _T("��");
	m_List.SetItemText(iRowNum, 14, str);
}
//�õ������iRowNum�еĺ��㣬iRowNum��:0,1,2...��
void CWayPointShowDlg::GetWayPointFromList(CWayPoint &WayPoint, int iRowNum)
{
	//List����>WayPoint
	CString str = m_List.GetItemText(iRowNum, 0);//iRowNumΪ�к�:0,1,2��0Ϊ��
	WayPoint.iNum = atoi(str);
	
	str = m_List.GetItemText(iRowNum, 1);
	WayPoint.dLongitude = atof(str);
	str = m_List.GetItemText(iRowNum, 2);
	WayPoint.dLatitude = atof(str);
	str = m_List.GetItemText(iRowNum, 3);
	WayPoint.iAltitude = atoi(str);
	str = m_List.GetItemText(iRowNum, 4);
	WayPoint.iSpeed = atoi(str);
	str = m_List.GetItemText(iRowNum, 5);
	WayPoint.iRadius = atoi(str);
	str = m_List.GetItemText(iRowNum, 6);
	WayPoint.iTime = atoi(str);
	str = m_List.GetItemText(iRowNum, 7);
	WayPoint.iStandardModel = atoi(str);
	
	str = m_List.GetItemText(iRowNum, 8);
	if (str == _T("��")) 
		WayPoint.bToLine = TRUE;
	else
		WayPoint.bToLine = FALSE;
	str = m_List.GetItemText(iRowNum, 9);
	if (str == _T("��")) 
		WayPoint.bToGround = TRUE;
	else
		WayPoint.bToGround = FALSE;
	str = m_List.GetItemText(iRowNum, 10);
	if (str == _T("��")) 
		WayPoint.bToSlope = TRUE;
	else
		WayPoint.bToSlope = FALSE;
	str = m_List.GetItemText(iRowNum, 11);
	if (str == _T("��")) 
		WayPoint.bPhoto = TRUE;
	else
		WayPoint.bPhoto = FALSE;
	str = m_List.GetItemText(iRowNum, 12);
	if (str == _T("��")) 
		WayPoint.bServo1 = TRUE;
	else
		WayPoint.bServo1 = FALSE;
	str = m_List.GetItemText(iRowNum, 13);
	if (str == _T("��")) 
		WayPoint.bServo2 = TRUE;
	else
		WayPoint.bServo2 = FALSE;
	str = m_List.GetItemText(iRowNum, 14);
	if (str == _T("��")) 
		WayPoint.bServo3 = TRUE;
	else
		WayPoint.bServo3 = FALSE;
}
//�õ������iRowNum�еĺ������
int CWayPointShowDlg::GetWayPointNumFromRowNum(int iRowNum)
{
	CString str = m_List.GetItemText(iRowNum, 0);//iRowNumΪ�к�:0,1,2��0Ϊ��
	return atoi(str);
}
//�������������
void CWayPointShowDlg::SortList()
{
	int iRowCount = m_List.GetItemCount();
	for(int i = 0; i < iRowCount-1; i++)
	{
		int iWPNumI = GetWayPointNumFromRowNum(i);
		int iRowNumExchange = i;

		for(int j = i+1; j < iRowCount; j++)
		{
			int iWPNumJ = GetWayPointNumFromRowNum(j);

			if (iWPNumI > iWPNumJ) {
				iRowNumExchange = j;
			}
		}
		if (iRowNumExchange != i) {
			CWayPoint WayPointI;
			GetWayPointFromList(WayPointI, i);

			CWayPoint WayPointExchange;
			GetWayPointFromList(WayPointExchange, iRowNumExchange);

			UpdateWayPointToList(WayPointExchange, i);
			UpdateWayPointToList(WayPointI, iRowNumExchange);
		}
	}
}