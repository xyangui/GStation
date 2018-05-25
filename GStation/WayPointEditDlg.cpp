// WayPointEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GStation.h"
#include "WayPointEditDlg.h"

#include "GStationDlg.h"
#include "Msg_WayPoint.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWayPointEditDlg dialog


CWayPointEditDlg::CWayPointEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWayPointEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWayPointEditDlg)
	m_iWPNum = 0;
	m_dWPLongitude = 0.0;
	m_dWPLatitude = 0.0;
	m_iWPAltitude = 0;
	m_iWPSpeed = 0;
	m_iWPRadius = 0;
	m_iWPTime = 0;
	m_iWPModel = 0;
	m_iModelNum = 0;
	m_dModelLongitude = 0.0;
	m_dModelLatitude = 0.0;
	m_iModelAltitude = 0;
	m_iModelSpeed = 0;
	m_iModelRadius = 0;
	m_iModelTime = 0;
	m_iModelModel = 0;
	//}}AFX_DATA_INIT
	m_iEditWPNum = 0;

	ReadWPModelFromIniFile();
}

void CWayPointEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWayPointEditDlg)
	DDX_Control(pDX, IDC_COMBO_SERVO3, m_comboWPServo3);
	DDX_Control(pDX, IDC_COMBO_SERVO2, m_comboWPServo2);
	DDX_Control(pDX, IDC_COMBO_SERVO1, m_comboWPServo1);
	DDX_Control(pDX, IDC_COMBO_PHOTO, m_comboWPPhoto);
	DDX_Control(pDX, IDC_COMBO_TOSLOPE, m_comboWPToSlope);
	DDX_Control(pDX, IDC_COMBO_TOGROUND, m_comboWPToGround);
	DDX_Control(pDX, IDC_COMBO_TOLINE, m_comboWPToLine);
	DDX_Control(pDX, IDC_COMBO_SERVO32, m_comboModelServo3);
	DDX_Control(pDX, IDC_COMBO_SERVO22, m_comboModelServo2);
	DDX_Control(pDX, IDC_COMBO_SERVO12, m_comboModelServo1);
	DDX_Control(pDX, IDC_COMBO_PHOTO2, m_comboModelPhoto);
	DDX_Control(pDX, IDC_COMBO_TOSLOPE2, m_comboModelToSlope);
	DDX_Control(pDX, IDC_COMBO_TOGROUND2, m_comboModelToGround);
	DDX_Control(pDX, IDC_COMBO_TOLINE2, m_comboModelToLine);
	DDX_Control(pDX, IDC_LIST, m_List);
	DDX_Text(pDX, IDC_EDIT_WP_NUM, m_iWPNum);
	DDX_Text(pDX, IDC_EDIT_WP_LONGITUDE, m_dWPLongitude);
	DDX_Text(pDX, IDC_EDIT_WP_LATITUDE, m_dWPLatitude);
	DDX_Text(pDX, IDC_EDIT_WP_ALTITUDE, m_iWPAltitude);
	DDX_Text(pDX, IDC_EDIT_WP_AIRSPEED, m_iWPSpeed);
	DDX_Text(pDX, IDC_EDIT_WP_RADIUS, m_iWPRadius);
	DDX_Text(pDX, IDC_EDIT_WP_TIME, m_iWPTime);
	DDX_Text(pDX, IDC_EDIT_WP_MODEL, m_iWPModel);
	DDX_Text(pDX, IDC_EDIT_WP_NUM2, m_iModelNum);
	DDX_Text(pDX, IDC_EDIT_WP_LONGITUDE2, m_dModelLongitude);
	DDX_Text(pDX, IDC_EDIT_WP_LATITUDE2, m_dModelLatitude);
	DDX_Text(pDX, IDC_EDIT_WP_ALTITUDE2, m_iModelAltitude);
	DDX_Text(pDX, IDC_EDIT_WP_AIRSPEED2, m_iModelSpeed);
	DDX_Text(pDX, IDC_EDIT_WP_RADIUS2, m_iModelRadius);
	DDX_Text(pDX, IDC_EDIT_WP_TIME2, m_iModelTime);
	DDX_Text(pDX, IDC_EDIT_WP_MODEL2, m_iModelModel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWayPointEditDlg, CDialog)
	//{{AFX_MSG_MAP(CWayPointEditDlg)
	ON_BN_CLICKED(IDC_BUTTON_WP_EDIT, OnButtonWPEdit)
	ON_BN_CLICKED(IDC_BUTTON_WP_SAVE, OnButtonWPSave)
	ON_BN_CLICKED(IDC_BUTTON_MODEL_EDIT, OnButtonModelEdit)
	ON_BN_CLICKED(IDC_BUTTON_MODEL_SAVE, OnButtonModelSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWayPointEditDlg message handlers

BOOL CWayPointEditDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_List.InsertColumn(0,_T("序号"), LVCFMT_LEFT, 41);
	m_List.InsertColumn(1,_T("经度"), LVCFMT_LEFT, 83);
	m_List.InsertColumn(2,_T("纬度"), LVCFMT_LEFT, 83);	
	m_List.InsertColumn(3,_T("高度(米)"), LVCFMT_LEFT, 65);
	m_List.InsertColumn(4,_T("速度(米/秒)"), LVCFMT_LEFT, 78);
	m_List.InsertColumn(5,_T("半径(米)"), LVCFMT_LEFT, 65);
	m_List.InsertColumn(6,_T("时间(秒)"), LVCFMT_LEFT, 65);
	m_List.InsertColumn(7,_T("制式"), LVCFMT_LEFT, 42);
	
	m_List.InsertColumn(8,_T("沿线"), LVCFMT_LEFT, 41);
	m_List.InsertColumn(9,_T("着陆"), LVCFMT_LEFT, 41);
	m_List.InsertColumn(10,_T("斜坡"), LVCFMT_LEFT, 41);
	m_List.InsertColumn(11,_T("相机"), LVCFMT_LEFT, 41);	
	m_List.InsertColumn(12,_T("舵机1"), LVCFMT_LEFT, 42);
	m_List.InsertColumn(13,_T("舵机2"), LVCFMT_LEFT, 42);
	m_List.InsertColumn(14,_T("舵机3"), LVCFMT_LEFT, 42);
	
	//画表格的线
	DWORD dwExStyle = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | //LVS_EX_SUBITEMIMAGES |
		LVS_EX_HEADERDRAGDROP | LVS_EX_TRACKSELECT;
	m_List.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LPARAM(dwExStyle));
	//画表格的线

	if (m_bModelToLine) 
		m_comboModelToLine.SetCurSel(1);
	else
		m_comboModelToLine.SetCurSel(0);
	if (m_bModelToGround) 
		m_comboModelToGround.SetCurSel(1);
	else
		m_comboModelToGround.SetCurSel(0);
	if (m_bModelToSlope)
		m_comboModelToSlope.SetCurSel(1);
	else
		m_comboModelToSlope.SetCurSel(0);
	if (m_bModelPhoto)
		m_comboModelPhoto.SetCurSel(1);
	else
		m_comboModelPhoto.SetCurSel(0);
	if (m_bModelServo1)
		m_comboModelServo1.SetCurSel(1);
	else
		m_comboModelServo1.SetCurSel(0);
	if (m_bModelServo2)
		m_comboModelServo2.SetCurSel(1);
	else
		m_comboModelServo2.SetCurSel(0);
	if (m_bModelServo3)
		m_comboModelServo3.SetCurSel(1);
	else
		m_comboModelServo3.SetCurSel(0);
	
	GetWPUpFromTabToList();

	if (m_iEditWPNum > 0) {//有等待编辑的航点；=0时没有
		m_List.SetSelectionMark(m_iEditWPNum - 1);
		OnButtonWPEdit(); 
	}

	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
//增加一个航点WayPoint，显示在表格的iRowNum行，iRowNum从0行开始
void CWayPointEditDlg::AddWayPointToList(CWayPoint &WayPoint, int iRowNum)
{
	CString str;
	str.Format("%d", WayPoint.iNum);
	m_List.InsertItem(iRowNum, str);

	UpdateWayPointToList(WayPoint, iRowNum);
}
//把一个航点WayPoint，显示在表格的iRowNum行，iRowNum从0行开始
void CWayPointEditDlg::UpdateWayPointToList(CWayPoint &WayPoint, int iRowNum)
{
	//WayPoint——>List
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
		str = _T("是");
	else
		str = _T("否");
	m_List.SetItemText(iRowNum, 8, str);
	if (WayPoint.bToGround) 
		str = _T("是");
	else
		str = _T("否");
	m_List.SetItemText(iRowNum, 9, str);
	if (WayPoint.bToSlope) 
		str = _T("是");
	else
		str = _T("否");
	m_List.SetItemText(iRowNum, 10, str);

	if (WayPoint.bPhoto) 
		str = _T("是");
	else
		str = _T("否");
	m_List.SetItemText(iRowNum, 11, str);	
	if (WayPoint.bServo1) 
		str = _T("是");
	else
		str = _T("否");
	m_List.SetItemText(iRowNum, 12, str);
	if (WayPoint.bServo2) 
		str = _T("是");
	else
		str = _T("否");
	m_List.SetItemText(iRowNum, 13, str);
	if (WayPoint.bServo3) 
		str = _T("是");
	else
		str = _T("否");
	m_List.SetItemText(iRowNum, 14, str);
}
//从tab文件中读出WayPointStation航点，并显示在表格中
void CWayPointEditDlg::GetWPUpFromTabToList()
{
	CGStationDlg *pGStationDlg = (CGStationDlg*)GetParent();
	CMapXLayer lay = pGStationDlg->m_ctrlMapX.GetLayers().Item("WayPointStation");

	int iWayPointCount = lay.AllFeatures().GetCount();
	CWayPoint WayPoint;
	
	for(int i = 1; i <= iWayPointCount; i++)
	{
		//tab——>WayPoint
		lay.SetKeyField("num");

		CString strKey;
		strKey.Format("%d", i);
		long key = lay.FeatureIDFromFeatureName(strKey);
		
		CMapXFeature objFeature;
		objFeature = lay.AllFeatures().Item(key);
		//这样取得的objFeature是按照num从1,2,3...顺序取得的
		WayPoint.iNum = i;//=objFeature.GetKeyValue();

		CMapXPoint pt = objFeature.GetPoint();
		WayPoint.dLongitude = pt.GetX();
		WayPoint.dLatitude = pt.GetY();
	
		lay.SetKeyField("altitude");
		WayPoint.iAltitude = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("speed");
		WayPoint.iSpeed = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("radius");
		WayPoint.iRadius = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("flag");
		int iFlag = atoi(objFeature.GetKeyValue());
		WayPoint.iStandardModel = iFlag & 7;

		int c;//获取字节单位
		c = iFlag & 8;
		if(c == 0)
			WayPoint.bToLine = FALSE;
		else
			WayPoint.bToLine = TRUE;
		
		c = iFlag & 16;
		if(c == 0)
			WayPoint.bToGround = FALSE;
		else
			WayPoint.bToGround = TRUE;
		
		c = iFlag & 32;
		if(c == 0)
			WayPoint.bToSlope = FALSE;
		else
			WayPoint.bToSlope = TRUE;
		
		c = iFlag & 64;
		if(c == 0)
			WayPoint.bPhoto = FALSE;
		else
			WayPoint.bPhoto = TRUE;

		lay.SetKeyField("time");
		WayPoint.iTime = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("servo");
		int iServo = atoi(objFeature.GetKeyValue());

		c = iServo & 1;
		if(c == 0)
			WayPoint.bServo1 = FALSE;
		else
			WayPoint.bServo1 = TRUE;		
		c = iServo & 2;
		if(c == 0)
			WayPoint.bServo2 = FALSE;
		else
			WayPoint.bServo2 = TRUE;
		c = iServo & 4;
		if(c == 0)
			WayPoint.bServo3 = FALSE;
		else
			WayPoint.bServo3 = TRUE;
        //WayPoint——>List
		AddWayPointToList(WayPoint, i-1);
	}
}
//把一个航点WayPoint显示在编辑航点区域，等待编辑
void CWayPointEditDlg::EditOneWayPointFromList(CWayPoint &WayPoint)
{
	//WayPoint——>Edit
	GetDlgItem(IDC_EDIT_WP_NUM)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_WP_LONGITUDE)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_WP_LATITUDE)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_WP_ALTITUDE)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_WP_AIRSPEED)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_WP_RADIUS)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_WP_TIME)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_WP_MODEL)->EnableWindow(TRUE);
	m_comboWPToLine.EnableWindow(TRUE);
	m_comboWPToGround.EnableWindow(TRUE);
	m_comboWPToSlope.EnableWindow(TRUE);
	m_comboWPPhoto.EnableWindow(TRUE);
	m_comboWPServo1.EnableWindow(TRUE);
	m_comboWPServo2.EnableWindow(TRUE);
	m_comboWPServo3.EnableWindow(TRUE);
	
	m_iWPNum = WayPoint.iNum;
	m_dWPLongitude = WayPoint.dLongitude;
	m_dWPLatitude = WayPoint.dLatitude;
	m_iWPAltitude = WayPoint.iAltitude;
	m_iWPSpeed = WayPoint.iSpeed;
	m_iWPRadius = WayPoint.iRadius;
	m_iWPTime = WayPoint.iTime;
	m_iWPModel = WayPoint.iStandardModel;

	if (WayPoint.bToLine) 
		m_comboWPToLine.SetCurSel(1);
	else
		m_comboWPToLine.SetCurSel(0);
	if (WayPoint.bToGround) 
		m_comboWPToGround.SetCurSel(1);
	else
		m_comboWPToGround.SetCurSel(0);
	if (WayPoint.bToSlope)
		m_comboWPToSlope.SetCurSel(1);
	else
		m_comboWPToSlope.SetCurSel(0);
	if (WayPoint.bPhoto)
		m_comboWPPhoto.SetCurSel(1);
	else
		m_comboWPPhoto.SetCurSel(0);
	if (WayPoint.bServo1)
		m_comboWPServo1.SetCurSel(1);
	else
		m_comboWPServo1.SetCurSel(0);
	if (WayPoint.bServo2)
		m_comboWPServo2.SetCurSel(1);
	else
		m_comboWPServo2.SetCurSel(0);
	if (WayPoint.bServo3)
		m_comboWPServo3.SetCurSel(1);
	else
		m_comboWPServo3.SetCurSel(0);

	UpdateData(FALSE);
}
//得到表格中iRowNum行的航点，iRowNum：:0,1,2...。
void CWayPointEditDlg::GetWayPointFromList(CWayPoint &WayPoint, int iRowNum)
{
	//List——>WayPoint
	CString str = m_List.GetItemText(iRowNum, 0);//iRowNum为行号:0,1,2。0为列
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
	if (str == _T("是")) 
		WayPoint.bToLine = TRUE;
	else
		WayPoint.bToLine = FALSE;
	str = m_List.GetItemText(iRowNum, 9);
	if (str == _T("是")) 
		WayPoint.bToGround = TRUE;
	else
		WayPoint.bToGround = FALSE;
	str = m_List.GetItemText(iRowNum, 10);
	if (str == _T("是")) 
		WayPoint.bToSlope = TRUE;
	else
		WayPoint.bToSlope = FALSE;
	str = m_List.GetItemText(iRowNum, 11);
	if (str == _T("是")) 
		WayPoint.bPhoto = TRUE;
	else
		WayPoint.bPhoto = FALSE;
	str = m_List.GetItemText(iRowNum, 12);
	if (str == _T("是")) 
		WayPoint.bServo1 = TRUE;
	else
		WayPoint.bServo1 = FALSE;
	str = m_List.GetItemText(iRowNum, 13);
	if (str == _T("是")) 
		WayPoint.bServo2 = TRUE;
	else
		WayPoint.bServo2 = FALSE;
	str = m_List.GetItemText(iRowNum, 14);
	if (str == _T("是")) 
		WayPoint.bServo3 = TRUE;
	else
		WayPoint.bServo3 = FALSE;
}
//编辑航点按钮
void CWayPointEditDlg::OnButtonWPEdit() 
{
	int iItemSel = m_List.GetSelectionMark();// .GetNextItem(-1, LVNI_SELECTED);
	if (iItemSel > -1) {//没有选中项时nItemSel=-1
		CWayPoint WayPoint;
		//List——>WayPoint
		GetWayPointFromList(WayPoint, iItemSel);
		//WayPoint——>Edit
		EditOneWayPointFromList(WayPoint);
	}
}
//保存航点
void CWayPointEditDlg::OnButtonWPSave() 
{
	//Edit——>WayPoint
	UpdateData(TRUE);
	CWayPoint WayPoint;
	
	WayPoint.iNum = m_iWPNum;
	WayPoint.dLongitude = m_dWPLongitude;
	WayPoint.dLatitude = m_dWPLatitude;
	WayPoint.iAltitude = m_iWPAltitude;
	WayPoint.iSpeed = m_iWPSpeed;
	WayPoint.iRadius = m_iWPRadius;
	WayPoint.iTime = m_iWPTime;
	WayPoint.iStandardModel = m_iWPModel;

	if (m_comboWPToLine.GetCurSel() == 1) 
		WayPoint.bToLine = TRUE;
	else
		WayPoint.bToLine = FALSE;
	if (m_comboWPToGround.GetCurSel() == 1) 
		WayPoint.bToGround = TRUE;
	else
		WayPoint.bToGround = FALSE;
	if (m_comboWPToSlope.GetCurSel() == 1) 
		WayPoint.bToSlope = TRUE;
	else
		WayPoint.bToSlope = FALSE;	
	if (m_comboWPPhoto.GetCurSel() == 1) 
		WayPoint.bPhoto = TRUE;
	else
		WayPoint.bPhoto = FALSE;	
	if (m_comboWPServo1.GetCurSel() == 1) 
		WayPoint.bServo1 = TRUE;
	else
		WayPoint.bServo1 = FALSE;
	if (m_comboWPServo2.GetCurSel() == 1) 
		WayPoint.bServo2 = TRUE;
	else
		WayPoint.bServo2 = FALSE;	
	if (m_comboWPServo3.GetCurSel() == 1) 
		WayPoint.bServo3 = TRUE;
	else
		WayPoint.bServo3 = FALSE;
	//WayPoint——>List
	UpdateWayPointToList(WayPoint, WayPoint.iNum-1);
	
	//WayPoint——>tab	//更新航点，不是增加
	try {  
		int iFlag = WayPoint.iStandardModel + WayPoint.bToLine * 8 + 
			WayPoint.bToGround * 16 + WayPoint.bToSlope * 32 + 
			WayPoint.bPhoto * 64;
		int iTime = (WayPoint.iTime + 5) / 10;//整除不对
		int iServo = WayPoint.bServo1 + WayPoint.bServo2 * 2 +
			WayPoint.bServo3 * 4;
	
		CGStationDlg *pGStationDlg = (CGStationDlg*)GetParent();		
		CMapXLayer lay = pGStationDlg->m_ctrlMapX.GetLayers().Item("WayPointStation");

		CString strKey;
		strKey.Format("%d", WayPoint.iNum);
		int key = lay.FeatureIDFromFeatureName(strKey);
		
		CMapXFeature objFeature;
		objFeature = lay.AllFeatures().Item(key);

		objFeature.GetPoint().Set(WayPoint.dLongitude, WayPoint.dLatitude);
		CString str_key;
		
		lay.SetKeyField("altitude");
		str_key.Format("%d",WayPoint.iAltitude);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.SetKeyField("speed");
		str_key.Format("%d",WayPoint.iSpeed);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.SetKeyField("radius");
		str_key.Format("%d",WayPoint.iRadius);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.SetKeyField("flag");
		str_key.Format("%d",iFlag);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.SetKeyField("time");
		str_key.Format("%d",iTime);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.SetKeyField("servo");
		str_key.Format("%d",iServo);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.SetKeyField("num");//num就是图中的序号1,2,3...
		str_key.Format("%d",WayPoint.iNum);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.Refresh();//如果不刷新，序号，1,2,3...只显示一半，
	}
	catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e) {
		e->ReportError();
		e->Delete();
	}

	GetDlgItem(IDC_EDIT_WP_NUM)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_WP_LONGITUDE)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_WP_LATITUDE)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_WP_ALTITUDE)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_WP_AIRSPEED)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_WP_RADIUS)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_WP_TIME)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_WP_MODEL)->EnableWindow(FALSE);
	m_comboWPToLine.EnableWindow(FALSE);
	m_comboWPToGround.EnableWindow(FALSE);
	m_comboWPToSlope.EnableWindow(FALSE);
	m_comboWPPhoto.EnableWindow(FALSE);
	m_comboWPServo1.EnableWindow(FALSE);
	m_comboWPServo2.EnableWindow(FALSE);
	m_comboWPServo3.EnableWindow(FALSE);
}
/*
//得到表格中iRowNum行的航点序号
int CWayPointEditDlg::GetWayPointNumFromRowNum(int iRowNum)
{
	CString str = m_List.GetItemText(iRowNum, 0);//iRowNum为行号:0,1,2。0为列
	return atoi(str);
}
//给表格重新排序
void CWayPointEditDlg::SortList()
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
}*/
//编辑模板
void CWayPointEditDlg::OnButtonModelEdit() 
{
	UpdateData(FALSE);
	//GetDlgItem(IDC_EDIT_WP_NUM2)->EnableWindow(TRUE);
	//GetDlgItem(IDC_EDIT_WP_LONGITUDE2)->EnableWindow(TRUE);
	//GetDlgItem(IDC_EDIT_WP_LATITUDE2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_WP_ALTITUDE2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_WP_AIRSPEED2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_WP_RADIUS2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_WP_TIME2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_WP_MODEL2)->EnableWindow(TRUE);
	m_comboModelToLine.EnableWindow(TRUE);
	m_comboModelToGround.EnableWindow(TRUE);
	m_comboModelToSlope.EnableWindow(TRUE);
	m_comboModelPhoto.EnableWindow(TRUE);
	m_comboModelServo1.EnableWindow(TRUE);
	m_comboModelServo2.EnableWindow(TRUE);
	m_comboModelServo3.EnableWindow(TRUE);
}
//保存模板
void CWayPointEditDlg::OnButtonModelSave() 
{
	UpdateData(TRUE);
	//GetDlgItem(IDC_EDIT_WP_NUM2)->EnableWindow(FALSE);
	//GetDlgItem(IDC_EDIT_WP_LONGITUDE2)->EnableWindow(FALSE);
	//GetDlgItem(IDC_EDIT_WP_LATITUDE2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_WP_ALTITUDE2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_WP_AIRSPEED2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_WP_RADIUS2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_WP_TIME2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_WP_MODEL2)->EnableWindow(FALSE);
	m_comboModelToLine.EnableWindow(FALSE);
	m_comboModelToGround.EnableWindow(FALSE);
	m_comboModelToSlope.EnableWindow(FALSE);
	m_comboModelPhoto.EnableWindow(FALSE);
	m_comboModelServo1.EnableWindow(FALSE);
	m_comboModelServo2.EnableWindow(FALSE);
	m_comboModelServo3.EnableWindow(FALSE);

	CString strPathIniFileName = GetPathIniFileName();
	CString strSection = "WayPointModel";
	CString strItemKey = "iModelAltitude";
	CString strValue;

	strValue.Format("%d", m_iModelAltitude);
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);//写入ini文件中相应字段

	strItemKey = "iModelSpeed";	
	strValue.Format("%d", m_iModelSpeed);
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);

	strItemKey = "iModelRadius";	
	strValue.Format("%d", m_iModelRadius);
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);

	strItemKey = "iModelTime";	
	strValue.Format("%d", m_iModelTime);
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);

	strItemKey = "iModelModel";	
	strValue.Format("%d", m_iModelModel);
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);

	if (m_comboModelToLine.GetCurSel() == 1) 
		m_bModelToLine = TRUE;
	else
		m_bModelToLine = FALSE;
	if (m_comboModelToGround.GetCurSel() == 1) 
		m_bModelToGround = TRUE;
	else
		m_bModelToGround = FALSE;
	if (m_comboModelToSlope.GetCurSel() == 1) 
		m_bModelToSlope = TRUE;
	else
		m_bModelToSlope = FALSE;	
	if (m_comboModelPhoto.GetCurSel() == 1) 
		m_bModelPhoto = TRUE;
	else
		m_bModelPhoto = FALSE;	
	if (m_comboModelServo1.GetCurSel() == 1) 
		m_bModelServo1 = TRUE;
	else
		m_bModelServo1 = FALSE;
	if (m_comboModelServo2.GetCurSel() == 1) 
		m_bModelServo2 = TRUE;
	else
		m_bModelServo2 = FALSE;	
	if (m_comboModelServo3.GetCurSel() == 1) 
		m_bModelServo3 = TRUE;
	else
		m_bModelServo3 = FALSE;

	if (m_bModelToLine) {
		strValue = _T("TRUE");
	}else{
		strValue = _T("FALSE");
	}
	strItemKey = "bModelToLine";	
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);

	if (m_bModelToGround) {
		strValue = _T("TRUE");
	}else{
		strValue = _T("FALSE");
	}
	strItemKey = "bModelToGround";	
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);

	if (m_bModelToSlope) {
		strValue = _T("TRUE");
	}else{
		strValue = _T("FALSE");
	}
	strItemKey = "bModelToSlope";	
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);

	if (m_bModelPhoto) {
		strValue = _T("TRUE");
	}else{
		strValue = _T("FALSE");
	}
	strItemKey = "bModelPhoto";	
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);

	if (m_bModelServo1) {
		strValue = _T("TRUE");
	}else{
		strValue = _T("FALSE");
	}
	strItemKey = "bModelServo1";	
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);

	if (m_bModelServo2) {
		strValue = _T("TRUE");
	}else{
		strValue = _T("FALSE");
	}
	strItemKey = "bModelServo2";	
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);

	if (m_bModelServo3) {
		strValue = _T("TRUE");
	}else{
		strValue = _T("FALSE");
	}
	strItemKey = "bModelServo3";	
	WritePrivateProfileString(strSection,strItemKey,strValue,strPathIniFileName);
}
//用模板给WayPoint赋值，因为构造函数已经调用ReadWPModelFromIniFile();所以保证航点模板与ini的值是一致的
void CWayPointEditDlg::GetWayPointFromModel(CWayPoint &WayPoint)
{
	WayPoint.iNum = m_iModelNum;
	WayPoint.dLongitude = m_dModelLongitude;
	WayPoint.dLatitude = m_dModelLatitude;
	WayPoint.iAltitude = m_iModelAltitude;
	WayPoint.iSpeed = m_iModelSpeed;
	WayPoint.iRadius = m_iModelRadius;
	WayPoint.iTime = m_iModelTime;
	WayPoint.iStandardModel = m_iModelModel;

	WayPoint.bToLine = m_bModelToLine;
	WayPoint.bToGround = m_bModelToGround;
	WayPoint.bToSlope = m_bModelToSlope;
	WayPoint.bPhoto = m_bModelPhoto;
	WayPoint.bServo1 = m_bModelServo1;
	WayPoint.bServo2 = m_bModelServo2;
	WayPoint.bServo3 = m_bModelServo3;
/*
	if (m_comboModelToLine.GetCurSel() == 1) //出错
		WayPoint.bToLine = TRUE;
	else
		WayPoint.bToLine = FALSE;
	if (m_comboModelToGround.GetCurSel() == 1) 
		WayPoint.bToGround = TRUE;
	else
		WayPoint.bToGround = FALSE;
	if (m_comboModelToSlope.GetCurSel() == 1) 
		WayPoint.bToSlope = TRUE;
	else
		WayPoint.bToSlope = FALSE;	
	if (m_comboModelPhoto.GetCurSel() == 1) 
		WayPoint.bPhoto = TRUE;
	else
		WayPoint.bPhoto = FALSE;	
	if (m_comboModelServo1.GetCurSel() == 1) 
		WayPoint.bServo1 = TRUE;
	else
		WayPoint.bServo1 = FALSE;
	if (m_comboModelServo2.GetCurSel() == 1) 
		WayPoint.bServo2 = TRUE;
	else
		WayPoint.bServo2 = FALSE;	
	if (m_comboModelServo3.GetCurSel() == 1) 
		WayPoint.bServo3 = TRUE;
	else
		WayPoint.bServo3 = FALSE;*/
}
//返回值：全路径 + 初始化文件ini文件名
CString CWayPointEditDlg::GetPathIniFileName()
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
//从ini.ini中读出航点模板
void CWayPointEditDlg::ReadWPModelFromIniFile()
{
	CString strPathIniFileName = GetPathIniFileName();
	
	CString strSection = "WayPointModel";
	CString strItemKey = "iModelAltitude";
	char strBuff[256];
	
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName); //读取ini文件中相应字段的内容
	CString strValue = strBuff;
	m_iModelAltitude = atoi(strValue); 
	
	strItemKey = "iModelSpeed";
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName);
	strValue = strBuff;
	m_iModelSpeed = atoi(strValue); 

	strItemKey = "iModelRadius";
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName);
	strValue = strBuff;
	m_iModelRadius = atoi(strValue); 
	
	strItemKey = "iModelTime";
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName);
	strValue = strBuff;
	m_iModelTime = atoi(strValue); 

	strItemKey = "iModelModel";
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName);
	strValue = strBuff;
	m_iModelModel = atoi(strValue); 

	strItemKey = "bModelToLine";
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName);
	strValue = strBuff;
	if (strValue == _T("TRUE")) {
		m_bModelToLine = TRUE;
	}else{
		m_bModelToLine = FALSE;
	}

	strItemKey = "bModelToGround";
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName);
	strValue = strBuff;
	if (strValue == _T("TRUE")) {
		m_bModelToGround = TRUE;
	}else{
		m_bModelToGround = FALSE;
	}

	strItemKey = "bModelToSlope";
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName);
	strValue = strBuff;
	if (strValue == _T("TRUE")) {
		m_bModelToSlope = TRUE;
	}else{
		m_bModelToSlope = FALSE;
	}

	strItemKey = "bModelPhoto";
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName);
	strValue = strBuff;
	if (strValue == _T("TRUE")) {
		m_bModelPhoto = TRUE;
	}else{
		m_bModelPhoto = FALSE;
	}

	strItemKey = "bModelServo1";
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName);
	strValue = strBuff;
	if (strValue == _T("TRUE")) {
		m_bModelServo1 = TRUE;
	}else{
		m_bModelServo1 = FALSE;
	}

	strItemKey = "bModelServo2";
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName);
	strValue = strBuff;
	if (strValue == _T("TRUE")) {
		m_bModelServo2 = TRUE;
	}else{
		m_bModelServo2 = FALSE;
	}

	strItemKey = "bModelServo3";
	GetPrivateProfileString(strSection,strItemKey,NULL,strBuff,80,strPathIniFileName);
	strValue = strBuff;
	if (strValue == _T("TRUE")) {
		m_bModelServo3 = TRUE;
	}else{
		m_bModelServo3 = FALSE;
	}
}
