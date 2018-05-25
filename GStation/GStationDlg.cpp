// GStationDlg.cpp : implementation file
//

#include "stdafx.h"
#include <afxpriv.h>  // for WM_KICKIDLE
                      // and WM_IDLEUPDATECMDUI
#include "math.h"

#include "GStation.h"
#include "GStationDlg.h"

#include "WayPointShowDlg.h"
#include "WayPointEditDlg.h"
#include "WayPointUpDlg.h"
#include "WayPointDownDlg.h"
#include "DownPhotoDataDlg.h"
#include "LayerDlg.h"
#include "commondialog.h"
#include "FlyGPSPointRecord.h"
#include "TakeOffCheck.h"
#include "SignDlg.h"

#include "DownGPSDlg.h"
#include "DownMiddleDlg.h"
#include "DownSensorDlg.h"
#include "DownSteeringDlg.h"

#include "Msg_PhotoMode.h"
#include "Msg_Capture.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define MYTOOL_DISTANCE                 1
#define MYTOOL_WAYPOINT_POLY            2
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}
BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CGStationDlg dialog
CGStationDlg::CGStationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGStationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGStationDlg)
	m_dTeleLongitude = 0.0f;
	m_dTeleLatitude = 0.0f;
	m_iGPSSatellite = 0;
	m_fTelePitch = 0.0f;
	m_fTeleRoll = 0.0f;
	m_fTeleDirection = 0.0f;
	m_iTargetWayPointNum = 0;
	m_strTeleGroundSpeed = _T("");
	m_iCPVDirection = 0;
	m_iCPVSpeed = 0;
	m_iTargetAirSpeed = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_pSettingSheet = new CSetting(_T("设置"));
	m_pFlyGPSPointRecord = NULL;

	m_bWayPointStationIsExist = FALSE;//“WayPointStation”是否存在
	m_bSignLayerIsExist = FALSE;      //“Sign”层是否存在	
	
	m_DistancePreviousX = 0.0;
	m_DistancePreviousY = 0.0;
}
void CGStationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGStationDlg)
	DDX_Control(pDX, IDC_SCROLLBAR, m_ctrlScrollBar);
	DDX_Control(pDX, IDC_SLIDER, m_ctrlSlider);
	DDX_Control(pDX, IDC_EDIT_RECEIVED_PACKET_TYPE, m_cReceivedPacketType);
	DDX_Control(pDX, IDC_MSCOMM, m_MSCom);
	DDX_Control(pDX, IDC_MAP, m_ctrlMapX);
	DDX_Control(pDX, IDC_COMMONDIALOG1, m_comDlg);
	DDX_Text(pDX, IDC_EDIT_TELE_LONGITUDE, m_dTeleLongitude);
	DDX_Text(pDX, IDC_EDIT_TELE_LATITUDE, m_dTeleLatitude);
	DDX_Text(pDX, IDC_EDIT_TELE_GPSSATELLITE, m_iGPSSatellite);
	DDX_Text(pDX, IDC_EDIT_TELE_PITCH, m_fTelePitch);
	DDX_Text(pDX, IDC_EDIT_TELE_ROLL, m_fTeleRoll);
	DDX_Text(pDX, IDC_EDIT_TELE_DIRECTION, m_fTeleDirection);
	DDX_Text(pDX, IDC_EDIT_TARGET_WAYPOINTNUM, m_iTargetWayPointNum);
	DDX_Text(pDX, IDC_EDIT_TELE_GROUNDSPEED, m_strTeleGroundSpeed);
	DDX_Text(pDX, IDC_EDIT_CPV_DIRECTION, m_iCPVDirection);
	DDX_Text(pDX, IDC_EDIT_CPV_SPEED, m_iCPVSpeed);
	DDX_Text(pDX, IDC_EDIT_TARGET_AIRSPEED, m_iTargetAirSpeed);
	DDX_Control(pDX, IDC_INSTRUMENTPANELCTRL, m_ctrlPanel);
	DDX_Control(pDX, IDC_INSTRUMENTCIRCLECTRL, m_ctrlCircle);
	//}}AFX_DATA_MAP
}
BEGIN_MESSAGE_MAP(CGStationDlg, CDialog)
	//{{AFX_MSG_MAP(CGStationDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENU_SETTING, OnMenuSetting)
	ON_COMMAND(ID_MENU_MIDDLE_VALUE, OnMenuMiddleValue)
	ON_COMMAND(ID_MENU_MIN_WINDDOOR, OnMenuMinWindDoor)
	ON_COMMAND(ID_MENU_MAX_WINDDOOR, OnMenuMaxWindDoor)
	ON_COMMAND(ID_MENU_STOPCAR_POSITION, OnMenuStopCarPosition)	
	ON_COMMAND(ID_MENU_LISTEN, OnMenuListen)
	ON_COMMAND(ID_MENU_PLAYBACK, OnMenuPlayback)
	ON_COMMAND(ID_MENU_PHOTOLOCATION, OnMenuPhotolocation)
	ON_COMMAND(ID_TOOL_DOWN_WAYPOINT, OnToolDownWaypoint)
	ON_COMMAND(ID_TOOL_INQUIRE_PHOTONUM, OnToolInquirePhotonum)
	ON_COMMAND(ID_TOOL_DOWN_PHOTODATA, OnToolDownPhotodata)
	ON_COMMAND(ID_TOOL_HANDPHOTOONE, OnToolHandPhotoOne)
	ON_COMMAND(ID_TOOL_STARTCONTINUEPHOTO, OnToolStartContinuePhoto)
	ON_COMMAND(ID_TOOL_STOPCONTINUEPHOTO, OnToolStopContinuePhoto)
	ON_COMMAND(ID_TOOL_LAYER, OnToolLayer)
	ON_COMMAND(ID_TOOL_DISTANCE, OnToolDistance)
	ON_MESSAGE_VOID(WM_KICKIDLE, OnKickIdle)
	ON_COMMAND(ID_MENU_MOUSE_ZOOMIN_BIG, OnMenuMouseZoomInBig)
	ON_COMMAND(ID_MENU_MOUSE_ZOOMOUT_SMALL, OnMenuMouseZoomOutSmall)
	ON_COMMAND(ID_MENU_MOUSE_MOVE, OnMenuMouseMove)
	ON_COMMAND(ID_MENU_MOUSE_SELECT_MOVE, OnMenuMouseSelectMove)
	ON_COMMAND(ID_MENU_MOUSE_ARROW, OnMenuMouseArrow)
	ON_COMMAND(ID_MENU_MOUSE_CENTER, OnMenuMouseCenter)
	ON_UPDATE_COMMAND_UI(ID_TOOL_DISTANCE, OnUpdateToolDistance)
	ON_UPDATE_COMMAND_UI(ID_TOOL_DOWN_PHOTODATA, OnUpdateToolDownPhotodata)
	ON_UPDATE_COMMAND_UI(ID_TOOL_STARTCONTINUEPHOTO, OnUpdateToolStartcontinuephoto)
	ON_UPDATE_COMMAND_UI(ID_TOOL_STOPCONTINUEPHOTO, OnUpdateToolStopcontinuephoto)
	ON_UPDATE_COMMAND_UI(ID_TOOL_INQUIRE_PHOTONUM, OnUpdateToolInquirePhotonum)
	ON_UPDATE_COMMAND_UI(ID_TOOL_DOWN_WAYPOINT, OnUpdateToolDownWaypoint)
	ON_UPDATE_COMMAND_UI(ID_TOOL_HANDPHOTOONE, OnUpdateToolHandphotoone)
	ON_COMMAND(ID_TOOL_CENTER, OnToolCenter)
	ON_COMMAND(ID_TOOL_CLEAN_TRACK, OnToolCleanTrack)
	ON_UPDATE_COMMAND_UI(ID_TOOL_CLEAN_TRACK, OnUpdateToolCleanTrack)
	ON_COMMAND(ID_TOOL_WAYPOINT_COPYDOWN_TOUP, OnToolWaypointCopyDownToUp)
	ON_UPDATE_COMMAND_UI(ID_TOOL_WAYPOINT_COPYDOWN_TOUP, OnUpdateToolWaypointCopyDownToUp)
	ON_COMMAND(ID_TOOL_PROMPT_WAYLINE, OnToolPromptWayline)
	ON_UPDATE_COMMAND_UI(ID_TOOL_PROMPT_WAYLINE, OnUpdateToolPromptWayline)
	ON_COMMAND(ID_TOOL_RECT, OnToolRect)
	ON_COMMAND(ID_TOOL_SHOW_UAV_WAYPOINT, OnToolShowUavWaypoint)
	ON_COMMAND(ID_TOOL_SIGN_POINT, OnToolSignPoint)
	ON_UPDATE_COMMAND_UI(ID_TOOL_SIGN_POINT, OnUpdateToolSignPoint)
	ON_COMMAND(ID_TOOL_SIGN_LINE, OnToolSignLine)
	ON_UPDATE_COMMAND_UI(ID_TOOL_SIGN_LINE, OnUpdateToolSignLine)
	ON_COMMAND(ID_TOOL_SIGN_POLYLINE, OnToolSignPolyline)
	ON_UPDATE_COMMAND_UI(ID_TOOL_SIGN_POLYLINE, OnUpdateToolSignPolyline)
	ON_COMMAND(ID_TOOL_SIGN_POLY, OnToolSignPoly)
	ON_UPDATE_COMMAND_UI(ID_TOOL_SIGN_POLY, OnUpdateToolSignPoly)
	ON_COMMAND(ID_TOOL_MOUSE_WAYPOINT, OnToolMouseWaypoint)
	ON_UPDATE_COMMAND_UI(ID_TOOL_MOUSE_WAYPOINT, OnUpdateToolMouseWaypoint)
	ON_BN_CLICKED(IDC_CHECK_LAYER_WAYLINE, OnCheckLayerWayline)
	ON_BN_CLICKED(IDC_CHECK_LAYER_SIGN, OnCheckLayerSign)
	ON_COMMAND(ID_MENU_OPEN_RECEIVER, OnMenuOpenReceiver)
	ON_COMMAND(ID_MENU_CLOSE_RECEIVER, OnMenuCloseReceiver)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_UAV, OnButtonUAV)
	ON_BN_CLICKED(IDC_CHECK_WAYPOINTSTATION, OnCheckWayPointStation)
	ON_BN_CLICKED(IDC_CHECK_FLYPLANEGPS, OnCheckFlyPlaneGPS)
	ON_BN_CLICKED(IDC_CHECK_WAYPOINTDOWN, OnCheckWaypointdown)
	ON_COMMAND(ID_TOOL_UP_WAYPOINT, OnToolUpWayPoint)
	ON_UPDATE_COMMAND_UI(ID_TOOL_UP_WAYPOINT, OnUpdateToolUpWaypoint)
	ON_COMMAND(ID_TOOL_WAYPOINTDOWN_HIDE, OnToolCleanWayPointDown)
	ON_COMMAND(ID_TOOL_WAYPOINT_EDIT, OnToolWayPointEdit)
	ON_UPDATE_COMMAND_UI(ID_TOOL_WAYPOINT_EDIT, OnUpdateToolWayPointEdit)
	ON_COMMAND(ID_MENU_MOUSE_WAYPOINT_EDIT, OnMenuMouseWayPointEdit)
	ON_COMMAND(ID_MENU_MOUSE_WAYPOINT_INSERT, OnMenuMouseWayPointInsert)
	ON_COMMAND(ID_MENU_MOUSE_WAYPOINT_UPLOAD, OnMenuMouseWayPointUpload)
	ON_BN_CLICKED(IDC_BUTTON_SENDTARGET_WPNUM, OnButtonSendTargetWPNum)
	ON_COMMAND(ID_MENU_MOUSE_WAYPOINT_DELETE, OnMenuMouseWayPointDelete)
	ON_COMMAND(ID_MENU_TAKEOFF_CHECK, OnMenuTakeOffCheck)
	ON_COMMAND(ID_MENU_MOUSE_SIGN, OnMenuMouseSign)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, OnButtonPlay)
	ON_BN_CLICKED(IDC_BUTTON_PAUSE, OnButtonPause)
	ON_WM_HSCROLL()
	ON_COMMAND(ID_MENU_CLOSE, OnMenuClose)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER, OnReleasedcaptureSlider)
	ON_BN_CLICKED(IDC_BUTTON_CPV, OnButtonCPV)
	ON_BN_CLICKED(IDC_BUTTON_STOP_CAR, OnButtonStopCar)
	ON_BN_CLICKED(IDC_BUTTON_TEST, OnButtonTest)
	ON_BN_CLICKED(IDC_CHECK_LAYER_SIGN_SHOWSIGN, OnCheckLayerSignShowSign)
	ON_BN_CLICKED(IDC_CHECK_MAP_GST, OnCheckMapGST)
	ON_COMMAND(ID_TOOL_STANDARDWAYLINE, OnToolStandardWayLine)
	ON_UPDATE_COMMAND_UI(ID_TOOL_STANDARDWAYLINE, OnUpdateToolStandardWayLine)
	ON_BN_CLICKED(IDC_BUTTON_CPV_DIRECTION, OnButtonCPVDirection)
	ON_BN_CLICKED(IDC_BUTTON_CPV_SPEED, OnButtonCPVSpeed)
	ON_COMMAND(ID_MENU_DOWN_STEERING, OnMenuDownSteering)
	ON_COMMAND(ID_MENU_DOWN_GPS, OnMenuDownGPS)
	ON_COMMAND(ID_MENU_DOWN_SENSOR, OnMenuDownSensor)
	ON_COMMAND(ID_MENU_DOWN_MIDDLE, OnMenuDownMiddle)
	ON_COMMAND(ID_MENU_DOWN_TELEMETRY, OnMenuDownTelemetry)
	ON_COMMAND(ID_MENU_PID, OnMenuPid)
	//}}AFX_MSG_MAP
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTW,0,0xFFFF,OnToolTipText)
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTA,0,0xFFFF,OnToolTipText)
	ON_UPDATE_COMMAND_UI(IDC_CHECK_LAYER_WAYLINE, OnUpdateCheckedLayerWayLine)
	ON_UPDATE_COMMAND_UI(IDC_CHECK_LAYER_SIGN, OnUpdateCheckedLayerSign)
	ON_UPDATE_COMMAND_UI(IDC_CHECK_LAYER_SIGN_SHOWSIGN, OnUpdateCheckedLayerSignShowSign)
	ON_UPDATE_COMMAND_UI(IDC_CHECK_WAYPOINTSTATION, OnUpdateCheckedWayPointStation)
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CGStationDlg message handlers
BOOL CGStationDlg::PreTranslateMessage(MSG* pMsg) 
{
	m_CtrlTip.RelayEvent( pMsg );//控件提示
	//添加快捷键
	if(::TranslateAccelerator(GetSafeHwnd(),hAccel,pMsg))
		return true;
	return CDialog::PreTranslateMessage(pMsg);
}
BOOL CGStationDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Add "About..." menu item to system menu.
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	hAccel=::LoadAccelerators(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MENU));//添加快捷键

	//添加工具栏，来自于“经典问答”
	if (!m_wndToolBar.Create(this) || !m_wndToolBar.LoadToolBar(IDR_TOOLBAR)) {
		TRACE0("Failed to create dialog toolbar\n");
		EndDialog( IDCANCEL );
	}
	CRect rcClientStart;
	CRect rcClientNow;
	GetClientRect(rcClientStart);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 
		0, reposQuery, rcClientNow);
	CPoint ptOffset(rcClientNow.left - rcClientStart.left,
		rcClientNow.top - rcClientStart.top); 
	CRect  rcChild;					
	CWnd* pwndChild = GetWindow(GW_CHILD);
	while (pwndChild) {                               
		pwndChild->GetWindowRect(rcChild);
		ScreenToClient(rcChild);
		rcChild.OffsetRect(ptOffset);
		pwndChild->MoveWindow(rcChild, FALSE);
		pwndChild = pwndChild->GetNextWindow();
	}
	CRect rcWindow;
	GetWindowRect(rcWindow);
	rcWindow.right += rcClientStart.Width() - rcClientNow.Width();
	rcWindow.bottom += rcClientStart.Height() - rcClientNow.Height();
	MoveWindow(rcWindow, FALSE);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);
	CenterWindow();
	//添加工具栏

	//工具栏——增加提示，来自互联网
	m_wndToolBar.EnableToolTips(TRUE);

	//控件——增加提示，来自于“经典问答”
	if( !m_CtrlTip.Create( this ) )	{
		TRACE0( "Unable to create ToolTip control\n" );
	}else{
		m_CtrlTip.AddTool( &m_cReceivedPacketType, IDS_TIP_RECEIVEDPACKETTYPE );
		//m_CtrlTip.AddTool( &m_cToggleReceiver, IDS_TIP_TOGGLE_RECEIVER );
		m_CtrlTip.Activate( TRUE );
	}
	
	CString strDirectoryFileName;
	strDirectoryFileName.Format("%s\\map\\china.gst", GetDirectory());
	OpenMapGST(strDirectoryFileName);

	try {		
		m_CMapXPoints.CreateDispatch(m_CMapXPoints.GetClsid());
		//只能执行一次，执行第二次出错
	}
	catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e) {
		e->ReportError();
		e->Delete();
	}

	m_StaticStatus.Create(this);

	SetTimer(1,6000,NULL);//这里的1000指1000毫秒=1秒，显示当前时间

	//从文件ini.ini读出，是否自动监听，给m_bIsReceivePacket赋值	
	m_bIsReceivePacket = FALSE;//false时不接收数据包，true时接收并处理数据包，
	//串口不存在，或已经被占用，或者没有连接飞控时，=false；只有串口正确打开时才=true
	if (m_pSettingSheet->m_pageSetSerialport.IsAutoListen()) {
		if (m_pSettingSheet->m_pageSetSerialport.ComIsExist(m_pSettingSheet->m_pageSetSerialport.getComTeleInt())) {
			OpenPort();//串口可用，则打开；串口没插飞控，返回false，串口插飞控但没通电，返回true，
		}              //则OpenPort()正常打开，m_bIsReceivePacket = TRUE;
	}
	//回放——播放速度0.5X,1X...
	m_ctrlSlider.SetRange(1,9);
	m_ctrlSlider.SetTicFreq(1);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}
//自定义函数——打开GST地图，并初始化m_ctrlMapX
void CGStationDlg::OpenMapGST(CString strPathFileNameGST)
{
	try {
		OpenMapCreateOtherLayers(strPathFileNameGST);
		
		m_ctrlMapX.SetMapUnit(miUnitKilometer);//设置地图单位为“千米”		
		//m_ctrlMapX.SetAutoRedraw(FALSE);//如果有这句话，点击放大缩小，地图无反应
		
		//设置成miToolTypePoly时，在OnPolyToolUsedMap消息响应函数里处理
		//设置成miToolTypePoint时，在OnToolUsedMap消息响应函数里处理
		m_ctrlMapX.CreateCustomTool(MYTOOL_DISTANCE, miToolTypePoly, miCrossCursor);      //测量距离
		m_ctrlMapX.CreateCustomTool(MYTOOL_WAYPOINT_POLY, miToolTypePoly, miCrossCursor); //绘制航点
		
		m_ctrlMapX.SetCurrentTool(miArrowTool);
		
		m_ctrlMapX.GetLayers().AddUserDrawLayer("ScaleBar", 1);//比例尺
		
		m_ctrlMapX.SetMousewheelSupport(miFullMousewheelSupport);//缩放，外加拖动，鼠标滚轮支持
		//m_ctrlMapX.SetMousewheelSupport(miMousewheelNoAutoScroll);//缩放，仅限滚动，没发现二者有何区别

		((CButton*)GetDlgItem(IDC_CHECK_MAP_GST))->SetCheck(1);
	}
	catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e) {
		e->ReportError();
		e->Delete();
	}
}
//自定义函数——得到当前路径函数，后面没有"\"
CString CGStationDlg::GetDirectory()
{
	char strBuff[256];   
	int nPos = GetCurrentDirectory(256, strBuff);   
	CString csFullPath(strBuff);    
	if( nPos < 0 )   
		return CString("");   
	else   
		return csFullPath;   
}
//自定义函数——如果存在strLayerName为名的图层，返回TRUE，否则返回FALSE
BOOL CGStationDlg::FindLayer(CString strLayerName)
{
	CMapXLayers layers = m_ctrlMapX.GetLayers();
    for(int i=0; i<layers.GetCount(); i++)
	{
		if(layers.Item(i+1).GetName() == strLayerName) 
			return TRUE;
	}
	return FALSE;
}
//自定义函数——打开路径文件名为strDirectoryFileName的地图，扩展名为gst，创建其他图层
void CGStationDlg::OpenMapCreateOtherLayers(CString strDirectoryFileName)
{
	//OpenMap
	m_ctrlMapX.SetGeoSet(strDirectoryFileName);
	m_ctrlMapX.SetTitleText("");
	//关闭已有图层的可选择性
	long tempnum;
	tempnum = m_ctrlMapX.GetLayers().GetCount();
	for(int i = 1; i <= tempnum; i++)
	{
		m_ctrlMapX.GetLayers().Item(i).SetSelectable(FALSE);
	}
	//CreateOtherLayers
	LPDISPATCH pDispatch;
	CMapXLayer lay;

	//创建WayLine层，即多选框的“航线层”，“WayPointStation”存储的是地面站航点，WayLine层显示航点之间的连线，不存储
	pDispatch = m_ctrlMapX.GetLayers().CreateLayer("WayLine",NULL);
	// create temporary layer on top for drawing on.	
	lay = m_ctrlMapX.GetLayers().Item("WayLine");
	lay.SetSelectable(TRUE);
	lay.SetOverrideStyle(TRUE);
	lay.SetEditable(TRUE);	
	//m_ctrlMapX.GetLayers().SetInsertionLayer(pDispatch);
	lay.GetStyle().SetLineColor(0x0000ff);
	lay.GetStyle().SetLineStyle(63);
	lay.GetStyle().SetLineWidth(1);
	//xyg添加，以上设置完SetLineColor，整个图层的style都随之变化，单独设置style无效
	lay.GetStyle().SetSymbolType(miSymbolTypeVector);
	((CButton*)GetDlgItem(IDC_CHECK_LAYER_WAYLINE))->SetCheck(0);//多选框的“航线层”不打勾
	//lay.GetStyle().SetSymbolCharacter(74);

	//创建飞机实际飞行的航迹层，已经被FlyGPSPoint所替代，在CFlyGPSPointRecord中，FlyLayer无用
	//pDispatch = m_ctrlMapX.GetLayers().CreateLayer("FlyLayer",NULL);
	//m_ctrlMapX.GetLayers().Item("FlyLayer").SetSelectable(TRUE);
	//m_ctrlMapX.GetLayers().Item("FlyLayer").SetOverrideStyle(TRUE);
	//m_ctrlMapX.GetLayers().Item("FlyLayer").SetEditable(TRUE);
	//m_ctrlMapX.GetLayers().SetAnimationLayer(pDispatch);
	//m_ctrlMapX.GetLayers().SetInsertionLayer(pDispatch);

	//创建飞机层，即飞机图标层，此层只有一个飞机图标，不存储
	pDispatch = m_ctrlMapX.GetLayers().CreateLayer("PlaneUAV",NULL,1);

	m_ctrlMapX.GetLayers().Item("PlaneUAV").SetSelectable(TRUE);
	//m_ctrlMapX.GetLayers().Item("PlaneUAV").SetOverrideStyle(TRUE);//不禁用，不显示飞机图标bmp
	m_ctrlMapX.GetLayers().Item("PlaneUAV").SetEditable(TRUE);
	//m_ctrlMapX.GetLayers().Item("PlaneUAV").SetDrawLabelsAfter(FALSE);

	lay = m_ctrlMapX.GetLayers().Item("PlaneUAV");
	lay.GetStyle().SetLineColor(0xff0000);
	lay.GetStyle().SetLineStyle(1);
	lay.GetStyle().SetLineWidth(3);

	lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
	lay.GetStyle().GetSymbolFont().SetName("Wingdings");//设置飞机图标
	lay.GetStyle().SetSymbolCharacter(81);
	lay.GetStyle().SetSymbolFontHalo(TRUE);
	lay.GetStyle().SetSymbolFontColor(0x0e1eff);

	m_ctrlMapX.GetLayers().SetAnimationLayer(pDispatch);//设置该层为动画图层
	m_ctrlMapX.GetLayers().SetInsertionLayer(pDispatch);
	//初始化飞机图标，但是不显示
	m_dTeleLongitude = 123.5037221;	//GPS无定位时，显示沈阳某点的坐标
	m_dTeleLatitude = 41.7961444;
	m_PlaneUAV.InitShowFlane(m_ctrlMapX, m_dTeleLongitude, m_dTeleLatitude);//让InitShowFlane只执行一次
	lay.SetVisible(FALSE);	

	//创建下载的机载航点层，加载WayPointDown层时，就已经把以前的航点删除了，不知哪里删的
	CString strPathFileName;
	strPathFileName.Format("%s\\WayPointDown.tab", GetDirectory());

	CMapXLayerInfo layerinfo;
	if( !layerinfo.CreateDispatch( layerinfo.GetClsid() ) ) 
		return ;  
	layerinfo.SetType(miLayerInfoTypeNewTable);     //新建图层类型
	
	VARIANT sVt;
	sVt.vt = VT_BSTR;
	sVt.bstrVal = strPathFileName.AllocSysString();//应该是图层与tab文件绑定
	layerinfo.AddParameter("FileSpec", sVt); 
	layerinfo.AddParameter("Name",COleVariant("WayPointDown"));
	
	CMapXFields fields;
	if( !fields.CreateDispatch( fields.GetClsid() ) )
		return ; 
	fields.AddIntegerField("num",FALSE); 
	fields.AddFloatField("altitude",FALSE);
	fields.AddFloatField("speed",FALSE);
	fields.AddIntegerField("radius",FALSE);
	fields.AddSmallIntField("flag",FALSE);
	fields.AddSmallIntField("time",FALSE);
	fields.AddSmallIntField("servo",FALSE);
	
	VARIANT vField;
	vField.vt = VT_DISPATCH;
	vField.pdispVal = fields.m_lpDispatch;
	layerinfo.AddParameter("Fields", vField);
	
	CString strTemp = _T("1");
	sVt.bstrVal= strTemp.AllocSysString();
	layerinfo.AddParameter("OverwriteFile", sVt); 
	
	CMapXLayers layers = m_ctrlMapX.GetLayers();
	layers.Add(layerinfo.m_lpDispatch, 2); //增加“WayPointStation”到现有图层集合

	lay = m_ctrlMapX.GetLayers().Item("WayPointDown");

	lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
	lay.GetStyle().GetSymbolFont().SetName( "Map Symbols" );//设置符号feature使用的字体
	lay.GetStyle().SetSymbolCharacter(54);//设置符号feature使用的字符，设置点的图标
	lay.GetStyle().SetSymbolFontHalo(FALSE);//False能使图标下面露出一条红线
	lay.GetStyle().SetSymbolFontColor(miColorBlue);//设置图标颜色
	
	lay.GetLabelProperties().SetPosition(miPositionCL);//设置标注位置//设置标签（序号1,2,3...）位置
	lay.GetLabelProperties().SetOffset(2);//设置标注偏移量//设置标签（序号1,2,3...）与图标中心点的偏移量
	lay.GetLabelProperties().GetStyle().SetTextFontColor(miColorBlue);//设置标签（序号1,2,3...）字体颜色
	lay.GetLabelProperties().GetStyle().SetTextFontShadow(TRUE);//设置标签（序号1,2,3...）阴影
	
	lay.SetSelectable(FALSE); //设置该层目标为不可选择，否则WayPointDown在上面，选择航点时，只能选择WayPointDown的航点
	lay.SetOverrideStyle(TRUE);//该层中所有Feature使用相同的style
	lay.SetEditable(TRUE);	
	lay.SetAutoLabel(TRUE);    //设置该层目标为自动标注
	
	m_ctrlMapX.GetLayers().SetInsertionLayer(lay.m_lpDispatch);

	((CButton*)GetDlgItem(IDC_CHECK_WAYPOINTDOWN))->SetCheck(1);
}
//工具栏——增加提示，来自互联网
BOOL CGStationDlg::OnToolTipText(UINT nID, NMHDR* pNMHDR, LRESULT* pResult)
{
	ASSERT(pNMHDR->code == TTN_NEEDTEXTA || pNMHDR->code == TTN_NEEDTEXTW);
    // if there is a top level routing frame then let it handle the message
    if (GetRoutingFrame() != NULL) return FALSE;
    // to be thorough we will need to handle UNICODE versions of the message also !!
    TOOLTIPTEXTA* pTTTA = (TOOLTIPTEXTA*)pNMHDR;
    TOOLTIPTEXTW* pTTTW = (TOOLTIPTEXTW*)pNMHDR;
    TCHAR szFullText[512];
    CString strTipText;
    nID = pNMHDR->idFrom;
    if (pNMHDR->code == TTN_NEEDTEXTA && (pTTTA->uFlags & TTF_IDISHWND) ||
        pNMHDR->code == TTN_NEEDTEXTW && (pTTTW->uFlags & TTF_IDISHWND)) {
        // idFrom is actually the HWND of the tool 
        nID = ::GetDlgCtrlID((HWND)nID);
    }
    if (nID != 0) // will be zero on a separator
    {
        AfxLoadString(nID, szFullText);
        strTipText=szFullText;	
#ifndef _UNICODE
        if (pNMHDR->code == TTN_NEEDTEXTA) {
            lstrcpyn(pTTTA->szText, strTipText, sizeof(pTTTA->szText));
        }else{
            _mbstowcsz(pTTTW->szText, strTipText, sizeof(pTTTW->szText));
        }
#else
        if (pNMHDR->code == TTN_NEEDTEXTA) {
            _wcstombsz(pTTTA->szText, strTipText,sizeof(pTTTA->szText));
        }else{
            lstrcpyn(pTTTW->szText, strTipText, sizeof(pTTTW->szText));
        }
#endif
        *pResult = 0;
        // bring the tooltip window above other popup windows
        ::SetWindowPos(pNMHDR->hwndFrom, HWND_TOP, 0, 0, 0, 0,
            SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOMOVE|SWP_NOOWNERZORDER);
        return TRUE;
    }
    return FALSE;
}

void CGStationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX){
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}else{
		CDialog::OnSysCommand(nID, lParam);
	}
}
// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
void CGStationDlg::OnPaint() 
{
	if (IsIconic()){
		CPaintDC dc(this); // device context for painting
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}else{
		CDialog::OnPaint();
	}
}
// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGStationDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//菜单——功能——监控
void CGStationDlg::OnMenuListen() 
{
	if(m_MSCom.GetPortOpen()){//如果串口是打开的
		AfxMessageBox("串口已经打开！");
		return;
	}
	BOOL bTemp = m_pSettingSheet->m_pageSetSerialport.ComIsExist(m_pSettingSheet->m_pageSetSerialport.getComTeleInt());
	if (!bTemp) {//串口没插入飞控或已被占用
		AfxMessageBox("打开串口失败，串口不可用！");
		return;
	}
	OpenPort();
	//关闭“回放”
	GetDlgItem(IDC_BUTTON_PLAY)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_PAUSE)->EnableWindow(FALSE);
	GetDlgItem(IDC_SCROLLBAR)->EnableWindow(FALSE);
	GetDlgItem(IDC_SLIDER)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_SLIDER)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_BACK)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_BACK_POSITION)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_BACK_SPEED)->EnableWindow(FALSE);
}
//菜单——功能——断开——关闭串口
void CGStationDlg::OnMenuClose() 
{
	m_bIsReceivePacket = FALSE;//不能接收数据
		
	if(m_MSCom.GetPortOpen())//如果串口是打开的，则关闭串口
		m_MSCom.SetPortOpen(FALSE);	
}
//菜单——功能——照片位置
void CGStationDlg::OnMenuPhotolocation() 
{
	MessageBox("未完成");	
}
//菜单——起飞检查
void CGStationDlg::OnMenuTakeOffCheck() 
{
	CTakeOffCheck TakeOffCheck;
	TakeOffCheck.DoModal();
}
//菜单——设置
void CGStationDlg::OnMenuSetting() 
{
	if( m_pSettingSheet->DoModal() == IDOK )
		return;
}
//菜单——PID调整
void CGStationDlg::OnMenuPid() 
{
	m_pPIDAdjDlg = new CPIDAdjDlg();
	m_pPIDAdjDlg->DoModal();
	delete m_pPIDAdjDlg;
	m_pPIDAdjDlg = NULL;

	CPacket Packet;
	Packet.m_msgid = 0x14;
	Packet.m_len = 0;
	Packet.generateCRC();
	SendPacket(Packet);	
}
//菜单——下传数据——遥测数据
void CGStationDlg::OnMenuDownTelemetry() 
{

}
//菜单——下传数据——舵机数据
void CGStationDlg::OnMenuDownSteering() 
{
	CDownSteeringDlg DownSteeringDlg;
	DownSteeringDlg.DoModal();
}
//菜单——下传数据——GPS数据
void CGStationDlg::OnMenuDownGPS() 
{
	CPacket Packet;
	Packet.m_msgid = 0x10;
	Packet.m_len = 0;
	Packet.generateCRC();
	SendPacket(Packet);	
	//数据包：0aff10000010。发送到飞控后，飞控停止发送数据，UP30地面站也是如此？？？？

	DownGPSDlg.DoModal();
}
//菜单——下传数据——传感器数据
void CGStationDlg::OnMenuDownSensor() 
{
	CDownSensorDlg DownSensorDlg;
	DownSensorDlg.DoModal();	
}
//菜单——下传数据——中立位置
void CGStationDlg::OnMenuDownMiddle() 
{
	CDownMiddleDlg DownMiddleDlg;
	DownMiddleDlg.DoModal();
}
//菜单——捕获——中立值
void CGStationDlg::OnMenuMiddleValue() 
{
	CMsg_Capture Capture;
	CPacket Packet = Capture.GetMiddleValuePack();
	SendPacket(Packet);
}
//菜单——捕获——最小风门
void CGStationDlg::OnMenuMinWindDoor() 
{
	CMsg_Capture Capture;
	CPacket Packet = Capture.GetMinWindDoorPack();
	SendPacket(Packet);
}
//菜单——捕获——最大风门
void CGStationDlg::OnMenuMaxWindDoor() 
{
	CMsg_Capture Capture;
	CPacket Packet = Capture.GetMaxWindDoorPack();
	SendPacket(Packet);
}
//菜单——捕获——停车位置
void CGStationDlg::OnMenuStopCarPosition() 
{
	CMsg_Capture Capture;
	CPacket Packet = Capture.GetStopCarPositionPack();
	SendPacket(Packet);
}
//菜单——接收机——打开接收机
void CGStationDlg::OnMenuOpenReceiver() 
{
	CPacket Packet;
	Packet.m_msgid = 0x24;
	Packet.m_len = 1;
	
	Packet.payload.putU1(0);
	Packet.generateCRC();
	SendPacket(Packet);	
}
//菜单——接收机——关闭接收机
void CGStationDlg::OnMenuCloseReceiver() 
{
	CPacket Packet;
	Packet.m_msgid = 0x24;
	Packet.m_len = 1;
	
	Packet.payload.putU1(1);
	Packet.generateCRC();
	SendPacket(Packet);	
}
//来自于“经典问答”
void CGStationDlg::OnKickIdle()
{
	SendMessageToDescendants( WM_IDLEUPDATECMDUI );//更新工具栏的状态，禁用或按下
	UpdateDialogControls( this, FALSE );	       //更新控件的状态，禁用
}
//工具栏——中心和比例
void CGStationDlg::OnToolCenter() 
{
	try {
		m_ctrlMapX.PropertyPage();
	}
	catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e) {
		e->ReportError();
		e->Delete();
	}
}
//工具栏——矩形选择
void CGStationDlg::OnToolRect() 
{
	m_ctrlMapX.SetCurrentTool(miRectSelectTool);
}
//工具栏——距离测量
void CGStationDlg::OnToolDistance() 
{
	if (m_ctrlMapX.GetCurrentTool() == MYTOOL_DISTANCE) {
		//到这里时，当前工具是MYTOOL_DISTANCE，然后又再次点击工具栏——距离测量，
		//通过OnUpdateToolDistance说明按钮处于按下状态，设置miArrowTool，按钮被OnUpdateToolDistance弹起
		m_ctrlMapX.SetCurrentTool(miArrowTool);
		m_DistancePreviousX = 0.0;
		m_DistancePreviousY = 0.0;		
	}else{
		m_ctrlMapX.SetCurrentTool(MYTOOL_DISTANCE);	
	}
}
void CGStationDlg::OnUpdateToolDistance(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck( m_ctrlMapX.GetCurrentTool() == MYTOOL_DISTANCE );//设置按下状态，或者弹起状态
}
//工具栏——图层
void CGStationDlg::OnToolLayer() 
{
	CLayerDlg LayerDlg;
	LayerDlg.DoModal();	
}
//工具栏——鼠标绘制航点
void CGStationDlg::OnToolMouseWaypoint() 
{
	if (m_ctrlMapX.GetCurrentTool() == MYTOOL_WAYPOINT_POLY) 
		m_ctrlMapX.SetCurrentTool(miArrowTool);
	else
		m_ctrlMapX.SetCurrentTool(MYTOOL_WAYPOINT_POLY);	
}
void CGStationDlg::OnUpdateToolMouseWaypoint(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_bWayPointStationIsExist );//设置是否禁用状态
	pCmdUI->SetCheck( m_ctrlMapX.GetCurrentTool() == MYTOOL_WAYPOINT_POLY );
}
//工具栏——编辑航点数据——对话框
void CGStationDlg::OnToolWayPointEdit() 
{
	m_WPEditDlg.DoModal();
}
void CGStationDlg::OnUpdateToolWayPointEdit(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_bWayPointStationIsExist );
}
//工具栏——显示机载航点数据——对话框
void CGStationDlg::OnToolShowUavWaypoint() 
{
	CWayPointShowDlg WPShowDlg;
	WPShowDlg.DoModal();
}
//工具栏——清除轨迹
void CGStationDlg::OnToolCleanTrack() 
{
	
}
void CGStationDlg::OnUpdateToolCleanTrack(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( FALSE );
}
//工具栏——清除机载航点层——up30地面站：只是在地图层中删除所有机载航点，没有定义删除机载航点数据包
void CGStationDlg::OnToolCleanWayPointDown() 
{
	CMsg_WayPoint Msg_WayPoint;//清除后再次下载机载航点，可以确认一下
	Msg_WayPoint.DeleteAllFeature(m_ctrlMapX, _T("WayPointDown"));
}
//工具栏——复制机载航点——点击——从下载的机载航点层复制到航点设计层
void CGStationDlg::OnToolWaypointCopyDownToUp() 
{
	CMsg_WayPoint Msg_WayPoint;
	Msg_WayPoint.CopyWayPointFromDownToUp(m_ctrlMapX);	
}
//工具栏——复制机载航点——更新状态
void CGStationDlg::OnUpdateToolWaypointCopyDownToUp(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_bWayPointStationIsExist );	
}
//工具栏——制式航线——点击
void CGStationDlg::OnToolStandardWayLine() 
{
}
void CGStationDlg::OnUpdateToolStandardWayLine(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( FALSE );	
}
//工具栏——上传所有航点数据——点击
void CGStationDlg::OnToolUpWayPoint() 
{
	CWayPointUpDlg WayPointUpDlg;
	if(WayPointUpDlg.DoModal() == IDOK)
	{
		CMsg_WayPoint Msg_WayPoint;
		
		CPacket packet;
		BOOL bOK = Msg_WayPoint.UpLoadAllWayPointPacket(packet, m_ctrlMapX);
		if (bOK) {	
			SendPacket(packet);
			//上传一个航点，自动下传一个航点，上传后删除WayPointDown的所有航点
			Msg_WayPoint.DeleteAllFeature(m_ctrlMapX, _T("WayPointDown"));
		}
	}		
}
//工具栏——上传所有航点数据——更新状态
void CGStationDlg::OnUpdateToolUpWaypoint(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_bWayPointStationIsExist );
}
//工具栏——下载航点数据——点击
void CGStationDlg::OnToolDownWaypoint() 
{
	CWayPointDownDlg WayPointDownDlg;
	if(WayPointDownDlg.DoModal() == IDOK)
	{	
		CMsg_WayPoint Msg_WayPoint;
		
		if (WayPointDownDlg.m_iDownWayPoint == 0) //=0代表下载所有航点，删除原来图层的所有航点
			Msg_WayPoint.DeleteAllFeature(m_ctrlMapX, _T("WayPointDown"));
		else                                      //!=0代表下载某个航点，删除原来图层的那个航点
			Msg_WayPoint.DeleteFeatureFromWPNum(m_ctrlMapX, _T("WayPointDown"), WayPointDownDlg.m_iDownWayPoint);
		
		CPacket Packet = Msg_WayPoint.GetWayPointPack(WayPointDownDlg.m_iDownWayPoint);
		SendPacket(Packet);//0aff1200010013下载所有航点数据包
	}	
}
//工具栏——下载航点数据——更新状态
void CGStationDlg::OnUpdateToolDownWaypoint(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_bIsReceivePacket );
}
//工具栏——立即航线
void CGStationDlg::OnToolPromptWayline() 
{

}
//工具栏——立即航线
void CGStationDlg::OnUpdateToolPromptWayline(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( FALSE );
}
//工具栏——绘制标志点——Sign层
void CGStationDlg::OnToolSignPoint() 
{
	if (m_ctrlMapX.GetCurrentTool() == miAddPointTool) 
		m_ctrlMapX.SetCurrentTool(miArrowTool);
	else
		m_ctrlMapX.SetCurrentTool(miAddPointTool);	
}
void CGStationDlg::OnUpdateToolSignPoint(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_bSignLayerIsExist );	
	pCmdUI->SetCheck( m_ctrlMapX.GetCurrentTool() == miAddPointTool );
}
//工具栏——绘制标志直线——Sign层
void CGStationDlg::OnToolSignLine() 
{	
	if (m_ctrlMapX.GetCurrentTool() == miAddLineTool) 
		m_ctrlMapX.SetCurrentTool(miArrowTool);
	else
		m_ctrlMapX.SetCurrentTool(miAddLineTool);	
}
void CGStationDlg::OnUpdateToolSignLine(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_bSignLayerIsExist );
	pCmdUI->SetCheck( m_ctrlMapX.GetCurrentTool() == miAddLineTool );
}
//工具栏——绘制标志折线——Sign层
void CGStationDlg::OnToolSignPolyline() 
{
	if (m_ctrlMapX.GetCurrentTool() == miAddPolylineTool) 
		m_ctrlMapX.SetCurrentTool(miArrowTool);
	else
		m_ctrlMapX.SetCurrentTool(miAddPolylineTool);
}
void CGStationDlg::OnUpdateToolSignPolyline(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_bSignLayerIsExist );	
	pCmdUI->SetCheck( m_ctrlMapX.GetCurrentTool() == miAddPolylineTool );
}
//工具栏——绘制标志区域——Sign层
void CGStationDlg::OnToolSignPoly() 
{	
	if (m_ctrlMapX.GetCurrentTool() == miAddRegionTool) 
		m_ctrlMapX.SetCurrentTool(miArrowTool);
	else
		m_ctrlMapX.SetCurrentTool(miAddRegionTool);
}
void CGStationDlg::OnUpdateToolSignPoly(CCmdUI* pCmdUI) 
{	
	pCmdUI->Enable( m_bSignLayerIsExist );
	pCmdUI->SetCheck( m_ctrlMapX.GetCurrentTool() == miAddRegionTool );
}
//工具栏——手动拍照一张
void CGStationDlg::OnToolHandPhotoOne() 
{
	CMsg_PhotoMode PhotoMode;
	CPacket Packet = PhotoMode.GetHandPhotoOnePack();
	SendPacket(Packet);
}
void CGStationDlg::OnUpdateToolHandphotoone(CCmdUI* pCmdUI) 
{
	//pCmdUI->Enable( m_MSCom.GetPortOpen() );
}
//工具栏——开始连续拍照
void CGStationDlg::OnToolStartContinuePhoto() 
{
	if(AfxMessageBox(_T("提示：是否开启相机连拍？"),MB_YESNO|MB_ICONQUESTION) == IDNO)
		return;
	
	CMsg_PhotoMode PhotoMode;
	CPacket Packet = PhotoMode.GetStartContinuePhotoPack();
	
	SendPacket(Packet);
}
void CGStationDlg::OnUpdateToolStartcontinuephoto(CCmdUI* pCmdUI) 
{
	//pCmdUI->Enable( m_MSCom.GetPortOpen() );
}
//工具栏——停止连续拍照
void CGStationDlg::OnToolStopContinuePhoto() 
{
	if(AfxMessageBox(_T("提示：是否关闭相机连拍？"),MB_YESNO|MB_ICONQUESTION) == IDNO)
		return;
	
	CMsg_PhotoMode PhotoMode;
	CPacket Packet = PhotoMode.GetStopContinuePhotoPack();
	
	SendPacket(Packet);
}
void CGStationDlg::OnUpdateToolStopcontinuephoto(CCmdUI* pCmdUI) 
{
	//pCmdUI->Enable( m_MSCom.GetPortOpen() );	
}
//工具栏——下载照片位置数据
void CGStationDlg::OnToolDownPhotodata() 
{
	CDownPhotoDataDlg DownPhotoDataDlg;
	if(DownPhotoDataDlg.DoModal() == IDOK)
	{
		CPacket Packet = m_Msg_PhotoData.Pack(DownPhotoDataDlg.m_iReturn_Start, 
			DownPhotoDataDlg.m_iReturn_End);
		
		SendPacket(Packet);
	}	
}
void CGStationDlg::OnUpdateToolDownPhotodata(CCmdUI* pCmdUI) 
{
	//pCmdUI->Enable( m_MSCom.GetPortOpen() );	
}
//工具栏——查询照片数量
void CGStationDlg::OnToolInquirePhotonum() 
{
	CPacket Packet = m_Msg_PhotoNum.Pack();
	
	SendPacket(Packet);
}
void CGStationDlg::OnUpdateToolInquirePhotonum(CCmdUI* pCmdUI) 
{
	//pCmdUI->Enable( m_MSCom.GetPortOpen() );
}
//鼠标菜单——箭头
void CGStationDlg::OnMenuMouseArrow() 
{
	m_ctrlMapX.SetCurrentTool(miArrowTool);
}
//鼠标菜单——放大
void CGStationDlg::OnMenuMouseZoomInBig() 
{
	m_ctrlMapX.SetCurrentTool(miZoomInTool);//只是鼠标变成加号，地图没有放大
}
//鼠标菜单——缩小
void CGStationDlg::OnMenuMouseZoomOutSmall() 
{
	m_ctrlMapX.SetCurrentTool(miZoomOutTool);
}
//鼠标菜单——平移
void CGStationDlg::OnMenuMouseMove() 
{
	m_ctrlMapX.SetCurrentTool(miPanTool);
}
//鼠标菜单——中心
void CGStationDlg::OnMenuMouseCenter() 
{
	m_ctrlMapX.SetCurrentTool(miCenterTool);
}
//鼠标菜单——选择—移动
void CGStationDlg::OnMenuMouseSelectMove() 
{
	m_ctrlMapX.SetCurrentTool(miSelectTool);
}
//鼠标菜单——插入航点
void CGStationDlg::OnMenuMouseWayPointInsert() 
{
	m_ctrlMapX.SetCurrentTool( MYTOOL_WAYPOINT_POLY );	
}
//鼠标菜单——编辑航点
void CGStationDlg::OnMenuMouseWayPointEdit() 
{
	CMapXLayer lay = m_ctrlMapX.GetLayers().Item("WayPointStation");
	lay.SetKeyField("num");
	
	long lCount = lay.GetSelection().GetCount();
	CString str = lay.GetSelection().Item(1).GetKeyValue();

	CWayPointEditDlg WPEditDlg;
	WPEditDlg.m_iEditWPNum = atoi(str);//获取所选择航点序号，从1,2,3...。地图也能多选航点
	WPEditDlg.DoModal();
}
//鼠标菜单——删除航点
void CGStationDlg::OnMenuMouseWayPointDelete() 
{	
	try {
		CMapXLayer lay = m_ctrlMapX.GetLayers().Item("WayPointStation");
		long lCount = lay.GetSelection().GetCount();
		lay.SetKeyField("num");
		
		for(int i = 1; i <= lCount; i++)
		{	
			CMapXFeature FeaSel = lay.GetSelection().Item(i);
			int iFeaSelNum = atoi(FeaSel.GetKeyValue());//选中点的航点序号

			lay.DeleteFeature(FeaSel);
			
			long lFeaturesCount = lay.AllFeatures().GetCount();
			//把iFeaSelNum后面点的num，改成num - 1，因为原来num大的点有可能在iFeaSelNum前面，
			for(int j = 1; j <= lFeaturesCount; j++)//所以从1到lFeaturesCount循环
			{
				CMapXFeature objFeature;
				objFeature = lay.AllFeatures().Item(j);
				
				int iOldNum = atoi(objFeature.GetKeyValue());
				if (iOldNum > iFeaSelNum) {
					
					CString str_key;
					str_key.Format("%d", iOldNum - 1);
					
					objFeature.SetKeyValue(str_key);
					objFeature.Update();
				}	
			}
		}
		lay.Pack(miPackAll);
		lay.Refresh();
	}
	catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e) {
		e->ReportError();
		e->Delete();
	}
}
//鼠标菜单——上传航点
void CGStationDlg::OnMenuMouseWayPointUpload() 
{
	CMapXLayer lay = m_ctrlMapX.GetLayers().Item("WayPointStation");
	long lCount = lay.GetSelection().GetCount();
	if (lCount == 0) {
		AfxMessageBox(_T("提示：请选择航点！"));
		return;
	}
	CString str = lay.GetSelection().Item(1).GetKeyValue();
	int iWayPointNum = atoi(str);
	
	CPacket  packet;
	CMsg_WayPoint Msg_WayPoint;
	//只更新序号为iWayPointNum的航点，航点总数不变
	packet = Msg_WayPoint.UpLoadOneWayPointPacket(m_ctrlMapX, iWayPointNum);
	SendPacket(packet);
	//更新一个航点后，因为飞控要回传此航点，先删除
	Msg_WayPoint.DeleteFeatureFromWPNum(m_ctrlMapX, _T("WayPointDown"), iWayPointNum);
}
//鼠标菜单——标注
void CGStationDlg::OnMenuMouseSign() 
{
	CSignDlg SignDlg;
	if (SignDlg.DoModal() == IDOK) {
		CMapXLayer lay = m_ctrlMapX.GetLayers().Item("Sign");
		lay.SetKeyField("label");
	
		CMapXFeature FeaSel = lay.GetSelection().Item(1);
		FeaSel.SetKeyValue(SignDlg.m_strSign);
		FeaSel.Update();
		lay.Refresh();
	}
}
//控制——“设置”目标航点序号按钮
void CGStationDlg::OnButtonSendTargetWPNum() 
{
	CString str;
	((CEdit*)GetDlgItem(IDC_EDIT_SENDTARGET_WPNUM))->GetWindowText(str);
	int iWPNum = atoi(str);

	CPacket Packet;
	Packet.m_msgid = 0x13;//设置目标航点
	Packet.m_len = 1;
	
	Packet.payload.putU1(iWPNum);
	Packet.generateCRC();
	SendPacket(Packet);	
}
//控制——“UAV”按钮
void CGStationDlg::OnButtonUAV() 
{
	CPacket Packet;
	Packet.m_msgid = 0x18;//设置控制模式
	Packet.m_len = 1;
	
	Packet.payload.putU1(0);//UAV
	Packet.generateCRC();
	SendPacket(Packet);	
}
//控制——“CPV”按钮
void CGStationDlg::OnButtonCPV() 
{
	CPacket Packet;
	Packet.m_msgid = 0x18;//设置控制模式
	Packet.m_len = 1;
	
	Packet.payload.putU1(3);//CPV
	Packet.generateCRC();
	SendPacket(Packet);	
}
//控制——“停车”“开车”按钮
void CGStationDlg::OnButtonStopCar() 
{
	CPacket Packet;
	Packet.m_msgid = 0x17;//控制发动机是否停车
	Packet.m_len = 1;

	CString str;
	((CButton*)GetDlgItem(IDC_BUTTON_STOP_CAR))->GetWindowText(str);
	if (str == _T("停车")) {
		if(AfxMessageBox(_T("确定停车吗？即控制停车继电器，将风门收到设定的停车位置以下？"), MB_YESNO|MB_ICONQUESTION) == IDNO)
			return;

		Packet.payload.putU1(1);//发动机停车
		((CButton*)GetDlgItem(IDC_BUTTON_STOP_CAR))->SetWindowText(_T("开车"));
	}else{
		Packet.payload.putU1(0);//发动机可着车
		((CButton*)GetDlgItem(IDC_BUTTON_STOP_CAR))->SetWindowText(_T("停车"));
	}
	Packet.generateCRC();
	SendPacket(Packet);	
}
//CPV控制——航向——“发送”按钮
void CGStationDlg::OnButtonCPVDirection() 
{
	UpdateData(TRUE);

	CPacket Packet;
	Packet.m_msgid = 0x19;//设定CPV时的目标航向
	Packet.m_len = 2;
	
	Packet.payload.putU2h(m_iCPVDirection);//m_iCPVDirection：0度正北，90度正东，180度正南，270度正西
	Packet.generateCRC();
	SendPacket(Packet);		
}
//CPV控制——速度——“发送”按钮
void CGStationDlg::OnButtonCPVSpeed() 
{
	UpdateData(TRUE);
	
	CPacket Packet;
	Packet.m_msgid = 0x09;//设定CPV时的目标空速
	Packet.m_len = 2;
	
	Packet.payload.putU2(m_iCPVSpeed);//米/秒
	Packet.generateCRC();
	SendPacket(Packet);		
}
//复选框——航点设计层——点击
void CGStationDlg::OnCheckWayPointStation() 
{
	if (m_bWayPointStationIsExist) {
		
		int iCheck = ((CButton*)GetDlgItem(IDC_CHECK_WAYPOINTSTATION))->GetCheck();
		if (iCheck == 0) {//原来有勾，点击后空白，GetCheck()=0
			m_ctrlMapX.GetLayers().Item("WayPointStation").SetVisible(FALSE);	
			return;
		}
		//原来空白，点击后成勾，GetCheck()=1；
		m_ctrlMapX.GetLayers().Item("WayPointStation").SetVisible(TRUE);	
	}
}
//复选框——航点设计层——更新状态
void CGStationDlg::OnUpdateCheckedWayPointStation( CCmdUI* pCmdUI ) 
{
	pCmdUI->Enable( m_bWayPointStationIsExist );
}
//复选框——航线层——点击
void CGStationDlg::OnCheckLayerWayline() 
{
	if (m_bWayPointStationIsExist) {
		try{
			int iCheck = ((CButton*)GetDlgItem(IDC_CHECK_LAYER_WAYLINE))->GetCheck();
			
			if (iCheck == 0) {//原来有勾，点击后空白，GetCheck()=0
				m_ctrlMapX.GetLayers().Item("WayLine").SetVisible(FALSE);	
				return;
			}
			//原来空白，点击后成勾，GetCheck()=1；
			m_ctrlMapX.GetLayers().Item("WayLine").SetVisible(TRUE);//WayLine层，只有线，而WayPointStation才有航点
			
			//必须更新m_CMapXPoints，否则如果"WayPointStation"的点被移动后，航线与航点不一致
			CMapXLayer lay = m_ctrlMapX.GetLayers().Item("WayPointStation");
			int iWayPointCount = lay.AllFeatures().GetCount();
			
			m_CMapXPoints.RemoveAll();//删除后，重新赋值
			//因为WayPointStation的图元num与Item(i)不一致，m_CMapXPoints要按照从小到大的顺序重新排序
			lay.SetKeyField("num");
			int iNum = 0;
			CMapXPoint point1;
		
			for(int i = 1; i <= iWayPointCount; i++)
			{
				CMapXPoint point;
				for(int j = 1;j <= iWayPointCount; j++)
				{	
					CMapXFeature Fea = lay.AllFeatures().Item(j);
					int iFeaNum = atoi(Fea.GetKeyValue());

					if (iFeaNum == iNum + 1) { 
						point = Fea.GetPoint();
						break;
					}
				}
				m_CMapXPoints.Add(point, i);//必须定义成类的成员，定义成局部变量出错
				//i为1至Points.Count整数，未指定i，追加到尾部
				if (i == 1) {
					point1 = point;
				}
				iNum++; 
			}
			//画线，把航点连成一个封闭多边形
			int iPointCount = m_CMapXPoints.GetCount();
			if(iPointCount < 2) {
				AfxMessageBox("请先标定至少2个航点！");
				return;
			}
			m_CMapXPoints.Add(point1);//添加第一个航点到集合的最后，形成封闭的多边形
			
			//要删除所有的线，重新画线，否则航线画的不对
			CMapXLayer linelay = m_ctrlMapX.GetLayers().Item("WayLine");
			long lCount = linelay.AllFeatures().GetCount();
			while (lCount > 0) {
				linelay.DeleteFeature(linelay.AllFeatures().Item(lCount));
				linelay.Refresh();
				lCount = linelay.AllFeatures().GetCount();
			}
			//重新画线
			CMapXFeature feature;
			if(!feature.CreateDispatch(feature.GetClsid()))
			{
				TRACE0("Failed to create Feature object");
				return;
			}
			feature.Attach(m_ctrlMapX.GetDispatch());
			feature.SetType(miFeatureTypeLine);
			feature.SetStyle(m_ctrlMapX.GetDefaultStyle()); 
			
			feature.GetParts().Add( m_CMapXPoints );//画线
			m_ctrlMapX.GetLayers().Item("WayLine").AddFeature(feature);

		} catch (COleDispatchException *e) {
			e->ReportError();
			e->Delete();
			return;
		} catch (COleException *e) {
			e->ReportError();
			e->Delete();
			return;
		}
	}
}
//复选框——航线层——更新状态
void CGStationDlg::OnUpdateCheckedLayerWayLine( CCmdUI* pCmdUI )
{
	pCmdUI->Enable( m_bWayPointStationIsExist );//有航点层WayPointStation，才能有航线层
}
//复选框——机载航点层——点击
void CGStationDlg::OnCheckWaypointdown() 
{
	int iCheck = ((CButton*)GetDlgItem(IDC_CHECK_WAYPOINTDOWN))->GetCheck();
	if (iCheck == 0) {//原来有勾，点击后空白，GetCheck()=0
		m_ctrlMapX.GetLayers().Item("WayPointDown").SetVisible(FALSE);	
		return;
	}
	//原来空白，点击后成勾，GetCheck()=1；
	m_ctrlMapX.GetLayers().Item("WayPointDown").SetVisible(TRUE);	
}
//复选框——轨迹层——点击
void CGStationDlg::OnCheckFlyPlaneGPS() 
{
	BOOL bFlyGPSPoint = FindLayer(_T("FlyGPSPoint"));//如果收到飞控遥测数据，就存在轨迹层FlyGPSPoint
	
	int iCheck = ((CButton*)GetDlgItem(IDC_CHECK_FLYPLANEGPS))->GetCheck();
	if (iCheck == 0) {//原来有勾，点击后空白，GetCheck()=0
		//m_ctrlMapX.GetLayers().Item("PlaneUAV").SetVisible(FALSE);//一直显示飞机图标，可以去掉FlyGPSPoint点	
		if (bFlyGPSPoint) 
			m_ctrlMapX.GetLayers().Item("FlyGPSPoint").SetVisible(FALSE);
		return;
	}
	//原来空白，点击后成勾，GetCheck()=1；
	//m_ctrlMapX.GetLayers().Item("PlaneUAV").SetVisible(TRUE);
	if (bFlyGPSPoint) 
		m_ctrlMapX.GetLayers().Item("FlyGPSPoint").SetVisible(TRUE);
}
//复选框——标志层——点击
void CGStationDlg::OnCheckLayerSign() 
{
	if (m_bSignLayerIsExist) {
		
		int iCheck = ((CButton*)GetDlgItem(IDC_CHECK_LAYER_SIGN))->GetCheck();
		if (iCheck == 1) {	
			m_ctrlMapX.GetLayers().Item("Sign").SetVisible(TRUE);
		}else{
			m_ctrlMapX.GetLayers().Item("Sign").SetVisible(FALSE);	
		}	
	}
}
//复选框——标志层——更新状态
void CGStationDlg::OnUpdateCheckedLayerSign( CCmdUI* pCmdUI )
{
	pCmdUI->Enable( m_bSignLayerIsExist );	
}
//复选框——显示标注——点击
void CGStationDlg::OnCheckLayerSignShowSign() 
{
	if (m_bSignLayerIsExist) {
		
		int iCheck = ((CButton*)GetDlgItem(IDC_CHECK_LAYER_SIGN_SHOWSIGN))->GetCheck();
		if (iCheck == 1) {	
			m_ctrlMapX.GetLayers().Item("Sign").SetAutoLabel(TRUE);
		}else{
			m_ctrlMapX.GetLayers().Item("Sign").SetAutoLabel(FALSE);
		}	
	}
}
//复选框——显示标注——更新状态
void CGStationDlg::OnUpdateCheckedLayerSignShowSign( CCmdUI* pCmdUI )
{
	pCmdUI->Enable( m_bSignLayerIsExist );	
}
//复选框——电子地图层
void CGStationDlg::OnCheckMapGST() 
{
	long num;
	num = m_ctrlMapX.GetLayers().GetCount();
	
	int iCheck = ((CButton*)GetDlgItem(IDC_CHECK_MAP_GST))->GetCheck();
	if (iCheck == 1) {	
		for(int i = 1; i <= num; i++)
		{
			m_ctrlMapX.GetLayers().Item(i).SetVisible(TRUE);
		}
	}else{
		for(int i = 1; i <= num; i++)
		{
			m_ctrlMapX.GetLayers().Item(i).SetVisible(FALSE);
		}
		m_ctrlMapX.GetLayers().Item("ScaleBar").SetVisible(TRUE);
	}
	OnCheckWayPointStation(); 
	OnCheckLayerWayline(); 
	OnCheckWaypointdown(); 
	OnCheckFlyPlaneGPS();
	OnCheckLayerSign();
	OnCheckLayerSignShowSign();	

	if (m_pFlyGPSPointRecord == NULL) 
		m_ctrlMapX.GetLayers().Item("PlaneUAV").SetVisible(FALSE);
	else
		m_ctrlMapX.GetLayers().Item("PlaneUAV").SetVisible(TRUE);
}
//菜单——功能——回放
void CGStationDlg::OnMenuPlayback() 
{
	CString strPath = GetDirectory();
	CString strDirectory;
	strDirectory.Format("%s\\record", strPath);
	m_comDlg.SetInitDir(strDirectory);
	
	m_comDlg.SetDialogTitle("选择要回放的tab文件");
	m_comDlg.SetFilter("*.tab");
	m_comDlg.SetFileName("*.tab");
	m_comDlg.ShowOpen();
	SetCurrentDirectory(strPath);//还得他妈设置回来
	
	CString file;
	file.Empty();
	file = m_comDlg.GetFileName();
	file.TrimRight();
	CString strDirectoryFileName = file;//包含路径和文件名和扩展名
	CString strFileExtensionName = m_comDlg.GetFileTitle();//只有文件名和扩展名
	
	if (strDirectoryFileName.IsEmpty() || strFileExtensionName.IsEmpty()) {
		AfxMessageBox(_T("提示：路径和文件名都不能为空！"));
		return;
	}
	try{
		//如果先收到遥测数据，或者已经回放过一次，FlyGPSPoint层都存在，删除
		if (FindLayer(_T("FlyGPSPoint"))) {
			m_ctrlMapX.GetLayers().Remove(_T("FlyGPSPoint"));
			if (m_pFlyGPSPointRecord != NULL) {//先收到遥测数据
				delete m_pFlyGPSPointRecord;
				m_pFlyGPSPointRecord = NULL;
			}
		}
		//把回放也定位于FlyGPSPoint层
		CMapXLayer lay = m_ctrlMapX.GetLayers().Add( strDirectoryFileName, 6 );//定位第6层
		CString layername = lay.GetName();
		if (layername.Left(11) != _T("FlyGPSPoint")) {
			AfxMessageBox(_T("提示：请选择有航行轨迹层的tab文件打开！"));
			m_ctrlMapX.GetLayers().Remove(layername);
			return;
		}
		int iCount = lay.AllFeatures().GetCount();
		if (iCount < 1){
			GetDlgItem(IDC_BUTTON_PLAY)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON_PAUSE)->EnableWindow(FALSE);
			GetDlgItem(IDC_SCROLLBAR)->EnableWindow(FALSE);
			GetDlgItem(IDC_SLIDER)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_SLIDER)->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_BACK)->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_BACK_POSITION)->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_BACK_SPEED)->EnableWindow(FALSE);
			return;
		}
		//关闭串口
		OnMenuClose();
	
		GetDlgItem(IDC_BUTTON_PLAY)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON_PAUSE)->EnableWindow(TRUE);
		GetDlgItem(IDC_SCROLLBAR)->EnableWindow(TRUE);
		GetDlgItem(IDC_SLIDER)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_SLIDER)->EnableWindow(TRUE);
		GetDlgItem(IDC_STATIC_BACK)->EnableWindow(TRUE);
		GetDlgItem(IDC_STATIC_BACK_POSITION)->EnableWindow(TRUE);
		GetDlgItem(IDC_STATIC_BACK_SPEED)->EnableWindow(TRUE);

		m_ctrlSlider.SetPos(2);
		((CEdit*)GetDlgItem(IDC_EDIT_SLIDER))->SetWindowText(_T("1X"));

		m_ctrlScrollBar.SetScrollRange(1, iCount);
		m_ctrlScrollBar.SetScrollPos(1);
		
	} catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
		return;
	} catch (COleException *e) {
		e->ReportError();
		e->Delete();
		return;
	}
}
//回放——“播放”按钮
void CGStationDlg::OnButtonPlay() 
{
	int iSpeed;
	int iSlider = m_ctrlSlider.GetPos();
	switch(iSlider)
	{
	case 1:	iSpeed = 3000; break;
	case 2:	iSpeed = 2000; break;
	case 3:	iSpeed = 1000; break;
	case 4:	iSpeed = 800;  break;
	case 5:	iSpeed = 600;  break;
	case 6:	iSpeed = 400;  break;
	case 7:	iSpeed = 200;  break;
	case 8:	iSpeed = 100;  break;
	case 9:	iSpeed = 50;   break;
	default:iSpeed = 1000; break;
	}
	SetTimer(2,iSpeed,NULL);//这里的1000指1000毫秒=1秒

	m_ctrlMapX.GetLayers().Item("PlaneUAV").SetVisible(TRUE);	
}
void CGStationDlg::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 1) {//更新当前时间
		CTime time = CTime::GetCurrentTime();
		
		CString strTemp;
		if (time.GetMinute() < 10) 
			strTemp.Format("%d-%d-%d-%d:0%d", time.GetYear(), time.GetMonth(), 
			    time.GetDay(), time.GetHour(), time.GetMinute());
		else
			strTemp.Format("%d-%d-%d-%d:%d", time.GetYear(), time.GetMonth(), 
			    time.GetDay(), time.GetHour(), time.GetMinute());
		GetDlgItem(IDC_STATIC_TIME)->SetWindowText(strTemp);
	}
	if (nIDEvent == 2) {//回放定时器
		try{
			UpdateData(TRUE);
			int iPosition = m_ctrlScrollBar.GetScrollPos();
			
			CMsg_Telemetry Msg_Telemetry;
			//tab->Msg_Telemetry
			CFlyGPSPointRecord  FlyGPSPointRecord;
			FlyGPSPointRecord.GetMsgTelemetryFromTab(m_ctrlMapX, Msg_Telemetry, iPosition);
			
			ShowTeleToDlg(Msg_Telemetry);
			
			iPosition++;
			int iCount = m_ctrlMapX.GetLayers().Item("FlyGPSPoint").AllFeatures().GetCount();

			if (iPosition > iCount) 
				KillTimer(2);
			else
				m_ctrlScrollBar.SetScrollPos(iPosition);
			
		} catch (COleDispatchException *e) {
			e->ReportError();
			e->Delete();
			return;
		} catch (COleException *e) {
			e->ReportError();
			e->Delete();
			return;
		}
	}
	CDialog::OnTimer(nIDEvent);
}
//回放——“暂停”按钮
void CGStationDlg::OnButtonPause() 
{
	KillTimer(2);
}
//回放——回放位置滚动条
void CGStationDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{	
	if (pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR) {//回放上面滚动条——回放进度
		
		int iCount = m_ctrlMapX.GetLayers().Item("FlyGPSPoint").AllFeatures().GetCount();

		int iPosition = m_ctrlScrollBar.GetScrollPos();
		switch(nSBCode) 
		{
		case SB_LINELEFT: iPosition--; break;
		case SB_LINERIGHT: iPosition++; break;
		case SB_PAGELEFT: iPosition -= 5; break;
		case SB_PAGERIGHT: iPosition += 5; break;
		case SB_THUMBTRACK: iPosition = nPos; break;
		case SB_LEFT: iPosition = 1; break;
		case SB_RIGHT: iPosition = iCount; break;
		default: break;
		}
		if (iPosition > iCount) 
			iPosition = iCount;
		if (iPosition < 1)
			iPosition = 1;
		m_ctrlScrollBar.SetScrollPos(iPosition);
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
//回放——播放速度0.5X,1X...
void CGStationDlg::OnReleasedcaptureSlider(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int iSpeed;
	CString str;
	int iSlider = m_ctrlSlider.GetPos();
	switch(iSlider)
	{
	case 1:	iSpeed = 3000; str = _T("0.5X"); break;
	case 2:	iSpeed = 2000; str = _T("1X");   break;
	case 3:	iSpeed = 1000; str = _T("2X");	 break;
	case 4:	iSpeed = 800; str = _T("4X");    break;
	case 5:	iSpeed = 600; str = _T("8X");    break;
	case 6:	iSpeed = 400; str = _T("16X");   break;
	case 7:	iSpeed = 200; str = _T("32X");   break;
	case 8:	iSpeed = 100; str = _T("64X");   break;
	case 9:	iSpeed = 50; str = _T("128X");   break;
	default: iSpeed = 1000;                  break;
	}
	((CEdit*)GetDlgItem(IDC_EDIT_SLIDER))->SetWindowText(str);
	
	SetTimer(2,iSpeed,NULL);//这里的1000指1000毫秒=1秒
	*pResult = 0;
}
BEGIN_EVENTSINK_MAP(CGStationDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CGStationDlg)
	ON_EVENT(CGStationDlg, IDC_MSCOMM, 1 /* OnComm */, OnOnCommMscomm, VTS_NONE)
	ON_EVENT(CGStationDlg, IDC_MAP, -605 /* MouseDown */, OnMouseDownMap, VTS_I2 VTS_I2 VTS_R4 VTS_R4)
	ON_EVENT(CGStationDlg, IDC_MAP, -606 /* MouseMove */, OnMouseMoveMap, VTS_I2 VTS_I2 VTS_R4 VTS_R4)
	ON_EVENT(CGStationDlg, IDC_MAP, 11 /* PolyToolUsed */, OnPolyToolUsedMap, VTS_I2 VTS_I4 VTS_DISPATCH VTS_BOOL VTS_BOOL VTS_PBOOL)
	ON_EVENT(CGStationDlg, IDC_MAP, 10 /* DrawUserLayer */, OnDrawUserLayerMap, VTS_DISPATCH VTS_I4 VTS_I4 VTS_DISPATCH VTS_DISPATCH)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()
//“串口”消息函数——在收到飞控发过来的数据包时
void CGStationDlg::OnOnCommMscomm() 
{
	if(m_bIsReceivePacket)
	{
		if(m_MSCom.GetCommEvent() == 2)                     //事件值为2表示接收缓冲区内有字符
		{
			VARIANT variant_input = m_MSCom.GetInput();     //读缓冲区
			COleSafeArray safearray_input = variant_input;  //VARIANT型变量转换为ColeSafeArray型变量
			LONG length = safearray_input.GetOneDimSize();  //得到有效数据长度
			
			BYTE *byte_input = new BYTE[length]; //设置BYTE数组 An 8-bit integerthat is not signed.
	
			for(LONG k = 0; k < length; k++)             
			{
				safearray_input.GetElement(&k, byte_input+k);//safearray_input转换为BYTE型数组

				CPacket *pPacket = m_Parser.link_parse_BYTE(byte_input[k]);//不能使用pPacket，因为m_Parser
				if(pPacket != NULL) //收到有效数据包                       //里面的m_Packet还要继续接收数据包
				{
					CPacket ReceivedPacket = *pPacket;
					//编写一个处理数据包函数
					HandleReceivedPacket(&ReceivedPacket);
				}
			}
		}
	}
}
//MapX消息函数——在地图上按鼠标左右键时
void CGStationDlg::OnMouseDownMap(short Button, short Shift, float X, float Y) 
{
	if(Button == 1)//点击的是左键
	{
		long ToolNum = m_ctrlMapX.GetCurrentTool();
		if (ToolNum == MYTOOL_DISTANCE) {
			float ScreenX = X;
			float ScreenY = Y;
			m_ctrlMapX.ConvertCoord(&ScreenX, &ScreenY, 
				&m_DistancePreviousX, &m_DistancePreviousY, miScreenToMap);
		}
	}
	if(Button == 2)//点击的是右键
	{
		m_ctrlMapX.SetCurrentTool(miArrowTool);//更换工具，否则一直是上一个工具

		CMenu menu;
		menu.LoadMenu(IDR_MENU_MOUSE);
		CMenu *pMenu=NULL;  
		pMenu = menu.GetSubMenu(0);
		SetMenuDefaultItem(pMenu->m_hMenu, ID_MENU_MOUSE_ZOOMIN_BIG, FALSE);
		POINT pt;
		GetCursorPos(&pt);
		//判断是否选定一个航点，以决定是否激活变灰菜单
		if (m_bWayPointStationIsExist) {
			CMapXLayer lay = m_ctrlMapX.GetLayers().Item("WayPointStation");

			CMapXSelection FeaturesSelect = lay.GetSelection();
			if(FeaturesSelect.GetCount() == 1)
			{
				pMenu->EnableMenuItem(ID_MENU_MOUSE_WAYPOINT_INSERT,MF_ENABLED);
				pMenu->EnableMenuItem(ID_MENU_MOUSE_WAYPOINT_EDIT,MF_ENABLED);
				pMenu->EnableMenuItem(ID_MENU_MOUSE_WAYPOINT_UPLOAD,MF_ENABLED);
				pMenu->EnableMenuItem(ID_MENU_MOUSE_WAYLINE_INSERT,MF_ENABLED);
			}
			if(FeaturesSelect.GetCount() >= 1)//唯独删除可以多选
			{
				pMenu->EnableMenuItem(ID_MENU_MOUSE_WAYPOINT_DELETE,MF_ENABLED);
			}
		}
		if (m_bSignLayerIsExist) {
			CMapXLayer lay = m_ctrlMapX.GetLayers().Item("Sign");
			
			CMapXSelection FeaturesSelect = lay.GetSelection();
			if(FeaturesSelect.GetCount() == 1)
				pMenu->EnableMenuItem(ID_MENU_MOUSE_SIGN,MF_ENABLED);
		}
		pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, pt.x, pt.y, this, NULL); 
		menu.DestroyMenu(); 
	}	
}
//MapX消息函数——更新鼠标坐标X和Y
void CGStationDlg::OnMouseMoveMap(short Button, short Shift, float X, float Y) 
{
	try {
		float ScreenX = X;
		float ScreenY = Y;
		double MapX, MapY;
		CString strX,strY;

		m_ctrlMapX.ConvertCoord(&ScreenX, &ScreenY, &MapX, &MapY, miScreenToMap);
		strX.Format("%2.7f", MapX);
		//GetDlgItem(IDC_STATICX)->SetWindowText(str);
		strY.Format("%2.7f", MapY);
		//GetDlgItem(IDC_STATICY)->SetWindowText(str);
		m_StaticStatus.UpdateXY(strX,strY);

		//如果是MYTOOL_DISTANCE距离测量，更新当前距离，更新当前角度
		long ToolNum = m_ctrlMapX.GetCurrentTool();
		if (ToolNum == MYTOOL_DISTANCE && m_DistancePreviousX != 0.0 && m_DistancePreviousY != 0.0) {
			//更新当前距离
			double dDistanceCurrent = m_ctrlMapX.Distance(m_DistancePreviousX, m_DistancePreviousY, MapX, MapY);
			m_StaticStatus.UpdateCurrentDistance(dDistanceCurrent);

			//更新当前角度
			double angle;
			double dTemp = atan( (MapY - m_DistancePreviousY) / (MapX - m_DistancePreviousX) ) / 3.1415926 * 180;
			if((MapX - m_DistancePreviousX) >= 0 && (MapY - m_DistancePreviousY) >= 0)
				angle = 90 - dTemp;
			else if((MapX - m_DistancePreviousX) >= 0 && (MapY - m_DistancePreviousY) < 0)
				angle = 90 - dTemp;
			else 
				angle = 270 - dTemp;

			if (MapX == m_DistancePreviousX) {
				angle = 0;//上面除以0，出现乱码，所以angle = 0
			}
			m_StaticStatus.UpdateCurrentAngle(angle);
		}
	}
	catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e) {
		e->ReportError();
		e->Delete();
	}	
}
//MapX消息函数——工具为miToolTypePoly类型
void CGStationDlg::OnPolyToolUsedMap(short ToolNum, long Flags, LPDISPATCH Points, BOOL bShift, BOOL bCtrl, BOOL FAR* EnableDefault) 
{
	try {		
		//“工具——距离测量”，只有点击鼠标时才执行到这里，移动鼠标时不到这
		if (ToolNum == MYTOOL_DISTANCE) {
			CMapXPoints pts;
			long n;
			long i;
			
			pts.AttachDispatch(Points, FALSE); // don't auto release
			double dDistanceTot = 0.0;
			n = pts.GetCount();
			for (i=1; i<n; i++)
			{
				CMapXPoint pt1 = pts.Item(i);
				CMapXPoint pt2 = pts.Item(i+1);
				double d = m_ctrlMapX.Distance(pt1.GetX(), pt1.GetY(), pt2.GetX(), pt2.GetY());
				dDistanceTot += d;
			}
			m_StaticStatus.UpdateTotalDistance(dDistanceTot);//更新静态框的距离值
		}
		//Flags = miPolyToolEnd时，当前工具还是MYTOOL_DISTANCE，再次点击地图时，Points不包含以前点的集合
		if (ToolNum == MYTOOL_DISTANCE && Flags == miPolyToolEnd) {
			m_DistancePreviousX = 0.0;//归零后，移动鼠标不再计算“当前距离”
			m_DistancePreviousY = 0.0;
		}
		if (ToolNum == MYTOOL_WAYPOINT_POLY && Flags == miPolyToolEnd) { 
			//“工具——鼠标绘制航点”//把LPDISPATCH Points插入到航点层WayPointStation中
			CMapXPoints mapxpoints;
			mapxpoints.AttachDispatch(Points, FALSE); 
			int iNewWPCount = mapxpoints.GetCount(); //新增加航点数量
			
			CMapXLayer lay = m_ctrlMapX.GetLayers().Item("WayPointStation");
			int iOldWPCount = lay.AllFeatures().GetCount();//以前的航点数量
			
			for(int i = iOldWPCount + 1; i <= iOldWPCount + iNewWPCount; i++)
			{
				CMapXPoint mapxpoint;
				mapxpoint.CreateDispatch(mapxpoint.GetClsid());
				mapxpoint = mapxpoints.Item(i - iOldWPCount);
				
				CWayPoint WayPoint;
				m_WPEditDlg.GetWayPointFromModel(WayPoint);

				WayPoint.iNum = i;
				WayPoint.dLongitude = mapxpoint.GetX();
				WayPoint.dLatitude = mapxpoint.GetY();

				CMsg_WayPoint Msg_WayPoint;
				Msg_WayPoint.SaveWayPointToTab(WayPoint, m_ctrlMapX, _T("WayPointStation"));//把航点保存到tab文件
			}
			//“鼠标菜单——插入航点”，重新排序
			CMapXSelection FeaturesSelect = lay.GetSelection();
			long lFeaSelCount = FeaturesSelect.GetCount();
		
			if(lFeaSelCount == 1)//只能选中一个点，如果多选就不知道在那个点后面添加航点
			{                    //有一个选中点，证明是“鼠标菜单——插入航点”里选中的MYTOOL_WAYPOINT_POLY
				lay.SetKeyField("num");
				CMapXFeature FeaSel = lay.GetSelection().Item(1);
				int iFeaSelNum = atoi(FeaSel.GetKeyValue());//选中点的航点序号
				//把iFeaSelNum原来后面点的num，改成num+iNewWPCount，因为原来num大的点有可能在iFeaSelNum前面，
				for(int j = 1; j <= iOldWPCount; j++)//所以从1到iOldWPCount循环
				{
					CMapXFeature objFeature;
					objFeature = lay.AllFeatures().Item(j);
					
					int iOldNum = atoi(objFeature.GetKeyValue());
					if (iOldNum > iFeaSelNum) {

						CString str_key;
						str_key.Format("%d", iOldNum + iNewWPCount);//num原来的值增加iNewWPCount
						//lay.SetKeyField("num");
						objFeature.SetKeyValue(str_key);
						objFeature.Update();
					}	
				}
				//把后面添加的iNewWPCount个点的num改成iFeaSelNum+1到iFeaSelNum+iNewWPCount				
				for(int i = iFeaSelNum + 1; i <= iFeaSelNum + iNewWPCount; i++)
				{
					CMapXFeature objFeature;
					objFeature = lay.AllFeatures().Item(i + iOldWPCount - iFeaSelNum);//=iOldWPCount+1+2+3...iNewWPCount
					
					CString str_key;
					str_key.Format("%d",i);
					
					objFeature.SetKeyValue(str_key);
					objFeature.Update();
				}
				lay.Refresh();
			}
		}
	}
	catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e) {
		e->ReportError();
		e->Delete();
	}
}
//MapX消息函数——比例尺
void CGStationDlg::OnDrawUserLayerMap(LPDISPATCH Layer, long hOutputDC, long hAttributeDC, LPDISPATCH RectFull, LPDISPATCH RectInvalid) 
{
	//来自mapinfo源码C++目录下的Cpp实例
	float barWidth =(float)0.5, barHeight =(float)0.08;
	float startX =(float).3, startY =(float).3;
	long x1, y1;
	int i;
	// attach to dc that mapx passed us so we can use 
	// mfc CDC object. (we will detach before exiting this method
	CDC dc;
	CPen pen;
	CBrush brushRed, brushWhite, *pOldBrush;
	CFont *pOldFont;
	
	pen.CreatePen(0,1,(COLORREF)0);
	brushRed.CreateSolidBrush(255);
	brushWhite.CreateSolidBrush(16777215);

	dc.Attach((HDC)hOutputDC);
	dc.SetAttribDC((HDC)hAttributeDC);
	//Set map mode to HI-English
	dc.SetMapMode(MM_HIENGLISH);
	//Set pen to black
	CPen *pOldPen = dc.SelectObject(&pen);
	pOldBrush = dc.SelectObject(&brushRed);

	//convert to HiEnglish, Conversion needed because one HIENGLISH unit is .001 inch
	x1=(long)(startX*1000);
	y1=(long)(startY*1000);
	barWidth*=1000;
	barHeight*=1000;

	for (i=0; i<=1; i++) {
		long x2 =(long)(barWidth+x1);
		long y2 =(long)(barHeight+y1);
		//First Section
		if (i==0) {
			dc.SelectObject(&brushRed); //Red
		} else {
			dc.SelectObject(&brushWhite); //White
		}
		// with mapMode HIENGLISH, positive is x to the right, positive y is up
		dc.Rectangle(x1, -y1, x2, -y2);
		// Second Section 
		x1=x2;
		x2=(long)(barWidth+x1);
		if (i==0) {
			dc.SelectObject(&brushWhite); //White
		} else {
			dc.SelectObject(&brushRed); //Red
		}
		dc.Rectangle(x1, -y1, x2, -y2);
		// Third Section 
		x1=x2;
		x2=(long)(barWidth*2+x1);
		if (i==0) {
			dc.SelectObject(&brushRed); //Red
		} else {
			dc.SelectObject(&brushWhite); //White
		}
		dc.Rectangle(x1, -y1, x2, -y2);
		// Reset Values for bottom bar pass
		x1=(long)(startX*1000);
		y1=y2;
	}  // End For
	// Calculate Pixels Per Inch
	CPoint pt(1000, 1000); // In HIENGLISH 1000 units = 1 inch
	dc.LPtoDP(&pt);  // Convert inch to pixel
	long lPixPerInch = pt.x;

	CRect rc;
	CDialog::GetClientRect(&rc);

	float screenX, screenY;
	double mapX1, mapY1;
	// subtract lPixPerInch from center to get 1 inch to left of Center
	screenX = (float)(rc.right/2-lPixPerInch);
	screenY = (float)(rc.bottom/2);
	try { 
		m_ctrlMapX.ConvertCoord(&screenX, &screenY, &mapX1, &mapY1, miScreenToMap);
	}
	catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e) {
		e->ReportError();
		e->Delete();	
	}
	double mapX2, mapY2;
	// add lPixPerInch to center to get 1 inch to right of Center
	screenX = (float)(rc.right/2+lPixPerInch);
	screenY = (float)(rc.bottom/2);
	try {
		m_ctrlMapX.ConvertCoord(&screenX, &screenY, &mapX2, &mapY2, miScreenToMap);
	}
	catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e) {
		e->ReportError();
		e->Delete();	
	}
	CFont font;
	font.CreatePointFont(100, "Arial", &dc);

	pOldFont = dc.SelectObject(&font);
	dc.SetTextColor(0);	//Black
	dc.SetBkMode(TRANSPARENT);
	// Output ScaleBar start Label = 0
	x1=(long)(startX*1000);
	y1=(long)((startY-.2)*1000);
	dc.TextOut(x1,-y1,"0");
	// Output label for distance of 1 inch
	x1=(long)(barWidth*2+startX*1000);

	CString str;
	str.Format("%.0f",m_ctrlMapX.Distance(mapX1, mapY1, mapX2, mapY2)/2);
	// Need to center text over center line.  will move it 60 units for each character
	int iCenterAdjustment = 60*str.GetLength();
	dc.TextOut(x1-iCenterAdjustment,-y1,str);

	// Output label for distance of 2 inches
	x1=(long)(barWidth*4+startX*1000);

	str.Format("%.0f",m_ctrlMapX.Distance(mapX1, mapY1, mapX2, mapY2));
	// Need to center text over end line.  will move it 60 units for each character
	iCenterAdjustment = 60*str.GetLength();
	dc.TextOut(x1-iCenterAdjustment,-y1,str);

	// Output label for Units "Miles"
	x1=(long)(barWidth*2+startX*1000);
	y1=(long)((startY+.2)*1000);
	// Need to center text over center line.  will move it 60 units for each character
	str.Format("千米");//原来为：str.Format("Miles");
	iCenterAdjustment = 60*str.GetLength();
	dc.TextOut(x1-iCenterAdjustment,-y1,str);

	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldFont);
	// detach dc so destructore won't call Release it
	dc.ReleaseAttribDC();
	dc.Detach();
}
//自定义函数——显示遥测数据到对话框界面中
void CGStationDlg::ShowTeleToDlg(CMsg_Telemetry Msg_Telemetry)
{
	m_cReceivedPacketType.SetWindowText(_T("遥测数据"));
	m_StaticStatus.UpdateMsgTelemetry(&Msg_Telemetry);
	m_StaticStatus.UpdateWayPoint(&Msg_Telemetry, m_ctrlMapX);
	
	m_dTeleLongitude = Msg_Telemetry.m_GPSdata.m_dLongitude;    //经度
	m_dTeleLatitude = Msg_Telemetry.m_GPSdata.m_dLatitude;      //纬度
	//m_iTeleAltitude = (int)Msg_Telemetry.m_GPSdata.m_fGPSalt; //59;
	m_iGPSSatellite = Msg_Telemetry.m_GPSdata.m_iSatelliteNum;  //GPS卫星数
	m_strTeleGroundSpeed.Format("%.1f",Msg_Telemetry.m_GPSdata.m_fGPSspeed);//地速——GPS数据——水平速度
	//m_iTelePressureAltitude = Msg_Telemetry.m_nAiralt;
	m_fTelePitch = Msg_Telemetry.m_fPitch;    //俯仰
	m_fTeleRoll = Msg_Telemetry.m_fRoll;      //滚转
	m_fTeleDirection = (float)Msg_Telemetry.m_iTargetDirection;//指向
	//m_fAirPress = Msg_Telemetry.m_fAirPress;                 //大气数据——气压
	//m_iTargetHeight = Msg_Telemetry.m_iTargetAltitude;       //目标高度
	m_iTargetAirSpeed = Msg_Telemetry.m_iTargetAirSpeed;
	m_iTargetWayPointNum = Msg_Telemetry.m_iTargetWayPoint;    //控制——目标航点
 	
 	m_ctrlPanel.UpDate(
 		(int)Msg_Telemetry.m_fRoll,
 		(int)Msg_Telemetry.m_fPitch,
  		(int)Msg_Telemetry.m_GPSdata.m_fDirection,
 		Msg_Telemetry.m_iTargetDirection,
 		Msg_Telemetry.m_iAirSpeed,
 		Msg_Telemetry.m_iTargetAirSpeed,
		Msg_Telemetry.m_iAirAltitude,
		Msg_Telemetry.m_iTargetAltitude,
		Msg_Telemetry.m_GPSdata.m_fDirection);

	m_ctrlCircle.SetAimValue(Msg_Telemetry.m_iRPM2);//用“第二发动机转速”当成目标值，不知对否？？
	m_ctrlCircle.SetRealValue(Msg_Telemetry.m_iRPM);//"发动机转速"rpm（米/秒）
	
	UpdateData(FALSE);
	//根据gps定位的经纬度航向显示船在地图上的位置
	//GPS有时有信号，有时无信号，从有信号变到无信号时，经纬度值依然有，是原来的值
	if (m_dTeleLongitude != 0 && m_dTeleLatitude != 0){
		m_ctrlMapX.GetLayers().Item("PlaneUAV").SetVisible(TRUE);
		m_PlaneUAV.UpdateCurrentPosition(m_dTeleLongitude, m_dTeleLatitude);
	}else
		m_ctrlMapX.GetLayers().Item("PlaneUAV").SetVisible(FALSE);
}
//自定义函数——处理所有收到的数据包函数
void CGStationDlg::HandleReceivedPacket(CPacket *ReceivedPacket)
{
	CMsg_WayPoint Msg_WayPoint;
	CString strTemp;
	//int iHangXiang = 76;//单位：度。定位地图时用到
	
	switch(ReceivedPacket->m_msgid)
	{
	case 20://命令：0x14；功能：请求和下传遥测数据
		if (ReceivedPacket->m_len != m_Msg_Telemetry.MSG_SIZE_PAYLOAD_LENGTH) 
			break;//收到的数据包长度与定义的数据包长度不一致
		m_Msg_Telemetry.Unpack(ReceivedPacket->payload);
		
		//收到一个"遥测数据"数据包存储到record文件的当前.tab中，收到一个存储一个
		if (m_pFlyGPSPointRecord == NULL) {
			//如果先点击回放，就存在FlyGPSPoint层，删除
			if(FindLayer(_T("FlyGPSPoint")))
				m_ctrlMapX.GetLayers().Remove("FlyGPSPoint");
			//如果先点击回放，就存在FlyGPSPoint层，删除
			m_pFlyGPSPointRecord = new CFlyGPSPointRecord(m_ctrlMapX);
			((CButton*)GetDlgItem(IDC_CHECK_FLYPLANEGPS))->SetCheck(1);//轨迹层即FlyGPSPoint层打勾
			
			if (m_Msg_Telemetry.m_GPSdata.m_dLongitude != 0 && m_Msg_Telemetry.m_GPSdata.m_dLatitude != 0) 
				m_ctrlMapX.ZoomTo(30, m_Msg_Telemetry.m_GPSdata.m_dLongitude, m_Msg_Telemetry.m_GPSdata.m_dLatitude);
			//缩放地图，以x，y为中心显示地图，30为缩放值，以地图单位MapUnit指定
			//ZoomTo能使比例尺和地图不断刷新，放在这里目的，让ZoomTo只执行一次	
		}
		m_pFlyGPSPointRecord->SaveMsgTelemetry(m_ctrlMapX, &m_Msg_Telemetry);
		//保存的同时已经为每个遥测数据在地图上显示一个点，不用下面函数
		//m_pFlyGPSPointRecord->ShowSymbol(m_ctrlMapX, &m_Msg_Telemetry);//为每个遥测数据在地图上显示一个点
		ShowTeleToDlg(m_Msg_Telemetry);
		break;
	//马劲松PID对话框部分///////////////////////////////////////////////////
	case 2://命令：0x02:；功能：请求发送PID调节所需数据
		if (m_pPIDAdjDlg == NULL) break;
		
		CGStationDlg::m_pPIDAdjDlg->m_Msg_PIDAdjustData.Unpack(ReceivedPacket->payload);
		CGStationDlg::m_pPIDAdjDlg->UpDlgPIDAdjData();//更新 PID调整窗口 的PID调整所需数据
		CGStationDlg::m_pPIDAdjDlg->UpChartData();//更新图表控件数据
		break;
	case 12://命令：0x0c:；功能：获取或设置PID参数
		if (m_pPIDAdjDlg == NULL) break;
		if (ReceivedPacket->m_len != m_pPIDAdjDlg->m_Msg_PIDData.MSG_SIZE_PAYLOAD_LENGTH) 
			break;//收到的数据包长度与定义的数据包长度不一致

		CGStationDlg::m_pPIDAdjDlg->m_Msg_PIDData.Unpack(ReceivedPacket->payload);
		CGStationDlg::m_pPIDAdjDlg->UpDlgPIDData();//更新 PID调整窗口 的PID参数
		break;
	case 13://命令：0x0d ; 功能：设置或者获取迎角最大最小平飞值
		if (m_pPIDAdjDlg == NULL) break;
		
		CGStationDlg::m_pPIDAdjDlg->m_Msg_OtherPIDAdjData.YJDataUnPacket(ReceivedPacket->payload);
		CGStationDlg::m_pPIDAdjDlg->UpYJData();//更新 PID调整窗口 的 迎角数据
		break;
	//马劲松PID对话框部分///////////////////////////////////////////////////
	case 16://命令：0x10；功能：请求下传GPS数据
		DownGPSDlg.Unpack(ReceivedPacket->payload);
		DownGPSDlg.SendMessage(WM_DOWN_GPS, FALSE);
		break;
	case 18://命令：0x12；功能：设置或者获取航点数据
		//OnDownpotOperate(strtemp,numtemp);
		//拆解航点数据包，保存到tab中
		Msg_WayPoint.UnpackSaveToTab(ReceivedPacket->payload, m_ctrlMapX);
		m_cReceivedPacketType.SetWindowText(_T("下载航点"));
		//看OnDrowDownPot()；未完成
		break;
	case 26://命令：0x1a；功能：设定和获取空速计系数
		ReceivedPacket->payload.resetIndex();
		m_pSettingSheet->m_pageSetAirSpeed.m_iAirSpeedValue = (int)ReceivedPacket->payload.getU4h();
		break;
	case 30://命令：0x1e；功能：获取或设置飞控安装角度，俯仰滚转角偏差
		m_pSettingSheet->m_pageSetPitchRoll.Unpack(ReceivedPacket->payload);
		m_pSettingSheet->m_pageSetPitchRoll.SendMessage(WM_PITCHROLL, FALSE);
		break;
	case 39://命令：0x27；功能：获取或设置飞控软硬件序号
		m_pSettingSheet->m_pageSetVersion.Unpack(ReceivedPacket->payload);
		m_pSettingSheet->m_pageSetVersion.SendMessage(WM_VERSION, FALSE);
		break;
	case 46://命令：0x2e；功能：下传照片位置数据
		//OnPhotoDataOperate(strtemp,numtemp);
		m_Msg_PhotoData.Unpack(ReceivedPacket->payload);
		m_cReceivedPacketType.SetWindowText(_T("照片数据"));

		int day,hour,minter,second;
		day = (int)m_Msg_PhotoData.time/1000/3600/24;
		hour = (int)((m_Msg_PhotoData.time/1000/3600/24-day)*24);
		minter = (int)(((m_Msg_PhotoData.time/1000/3600/24-day)*24-hour)*60);
		second = (int)((((m_Msg_PhotoData.time/1000/3600/24-day)*24-hour)*60-minter)*60);
		strTemp.Format("%4d   星期%d %2d:%2d:%2d  %4.5lf    %4.5lf   %4ld     %5.2lf    %5.2lf    %5.2lf\r\n",
			m_Msg_PhotoData.num, day, hour, minter, second, m_Msg_PhotoData.lon, m_Msg_PhotoData.lat,
			m_Msg_PhotoData.alt, m_Msg_PhotoData.pitch, m_Msg_PhotoData.roll, m_Msg_PhotoData.heading);
		//OnFileSavePhotoData(strtemp);未完成
		break;
	case 47://命令：0x2f；功能：查询本次照片数量
		m_Msg_PhotoNum.Unpack(ReceivedPacket->payload);
		m_cReceivedPacketType.SetWindowText(_T("照片数量"));

		strTemp.Format("本次查询的照片数量为%d张！",m_Msg_PhotoNum.m_iPhotoNum);

		//AfxMessageBox(strTemp);
		//m_cPhotoNum.SetWindowText(strTemp);
		break;
	default:
		break;
	}
}
//自定义函数——打开串口函数。使OnOnCommMscomm能接收到数据包
void CGStationDlg::OpenPort()
{
	m_bIsReceivePacket = FALSE;//不能接收数据

	if(m_MSCom.GetPortOpen())//如果串口是打开的，则关闭串口，然后再重新打开
		m_MSCom.SetPortOpen(FALSE);

	int nPort = m_pSettingSheet->m_pageSetSerialport.getComTeleInt();
	//nPort=1时代表com1，nPort=2时代表com2
	
	m_MSCom.SetCommPort(nPort);   //选择com1
	m_MSCom.SetInBufferSize(4096); //接收缓冲区
	m_MSCom.SetOutBufferSize(4096);//发送缓冲区

	CString	strBT = m_pSettingSheet->m_pageSetSerialport.getBTCString();
	//strBT = ("%d,%s",getBTint(),"n,8,1");//波特率115200，无校验，8个数据位，1个停止位
	m_MSCom.SetSettings(strBT); 

	if( !m_MSCom.GetPortOpen() )  //如果串口没有打开则打开
		m_MSCom.SetPortOpen(TRUE);//打开串口。如果串口被占用，提示“端口已打开”后直接return，后面的语句就不执行了
	else
		AfxMessageBox("cannot open serial port!");

	m_MSCom.SetRThreshold(1);//参数1表示每当串口接收缓冲区中有1个及1个以上字符时，将引发一个接收数据的OnComm事件
	m_MSCom.SetInputMode(1); //设置输入方式为二进制方式，以二进制方式读写数据
	m_MSCom.SetInputLen(0);  //设置当前接收区数据长度为0，表示全部读取
	m_MSCom.GetInput();      //先预读缓冲区以清除残留数据	

	m_bIsReceivePacket = TRUE;//可以接收数据
}
//自定义函数——发送数据包函数
void CGStationDlg::SendPacket(CPacket Packet)
{
	/*////////////////////////测试用
		char check;
	CByteArray hexdata;
	check = 0;
	check = check+0x2e+4;
	CString m_strSendString = "";
	m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x2e,0,4,0,0,0,0,check);
	String2Hex(m_strSendString ,hexdata);

		int dd = hexdata.GetSize();
		for(int i = 0; i < dd; i++)
		{
			BYTE ss = hexdata[i];
		}
////////////////////////////测试用*/

	CByteArray ByteArray;
	Packet.GetCByteArray(ByteArray);

	///////////////////////////*测试用
	CString str,strTemp;
	int dd = ByteArray.GetSize();
	for(int i = 0; i < dd; i++)
	{
		BYTE ss = ByteArray[i];
		strTemp.Format("%02x",ss);
		str = str + strTemp;
	}
	CString result = str;
////////////////////////测试用*/

	m_MSCom.SetOutput(COleVariant(ByteArray));	
}
/*
	CMapXLayers layers = m_ctrlMapX.GetLayers(); 
	CString str = layers.Item("WayPointDown").GetStyle().GetSymbolFont().GetName();//得到字符集
	int dd = layers.Item("WayPointDown").GetStyle().GetSymbolCharacter();          //得到点符号数，小旗，圆圈，方框等等
*/
void CGStationDlg::OnButtonTest() 
{
	
}
