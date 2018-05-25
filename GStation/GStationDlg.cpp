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

	m_pSettingSheet = new CSetting(_T("����"));
	m_pFlyGPSPointRecord = NULL;

	m_bWayPointStationIsExist = FALSE;//��WayPointStation���Ƿ����
	m_bSignLayerIsExist = FALSE;      //��Sign�����Ƿ����	
	
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
	m_CtrlTip.RelayEvent( pMsg );//�ؼ���ʾ
	//��ӿ�ݼ�
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
	hAccel=::LoadAccelerators(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MENU));//��ӿ�ݼ�

	//��ӹ������������ڡ������ʴ�
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
	//��ӹ�����

	//����������������ʾ�����Ի�����
	m_wndToolBar.EnableToolTips(TRUE);

	//�ؼ�����������ʾ�������ڡ������ʴ�
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
		//ֻ��ִ��һ�Σ�ִ�еڶ��γ���
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

	SetTimer(1,6000,NULL);//�����1000ָ1000����=1�룬��ʾ��ǰʱ��

	//���ļ�ini.ini�������Ƿ��Զ���������m_bIsReceivePacket��ֵ	
	m_bIsReceivePacket = FALSE;//falseʱ���������ݰ���trueʱ���ղ��������ݰ���
	//���ڲ����ڣ����Ѿ���ռ�ã�����û�����ӷɿ�ʱ��=false��ֻ�д�����ȷ��ʱ��=true
	if (m_pSettingSheet->m_pageSetSerialport.IsAutoListen()) {
		if (m_pSettingSheet->m_pageSetSerialport.ComIsExist(m_pSettingSheet->m_pageSetSerialport.getComTeleInt())) {
			OpenPort();//���ڿ��ã���򿪣�����û��ɿأ�����false�����ڲ�ɿص�ûͨ�磬����true��
		}              //��OpenPort()�����򿪣�m_bIsReceivePacket = TRUE;
	}
	//�طš��������ٶ�0.5X,1X...
	m_ctrlSlider.SetRange(1,9);
	m_ctrlSlider.SetTicFreq(1);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}
//�Զ��庯��������GST��ͼ������ʼ��m_ctrlMapX
void CGStationDlg::OpenMapGST(CString strPathFileNameGST)
{
	try {
		OpenMapCreateOtherLayers(strPathFileNameGST);
		
		m_ctrlMapX.SetMapUnit(miUnitKilometer);//���õ�ͼ��λΪ��ǧ�ס�		
		//m_ctrlMapX.SetAutoRedraw(FALSE);//�������仰������Ŵ���С����ͼ�޷�Ӧ
		
		//���ó�miToolTypePolyʱ����OnPolyToolUsedMap��Ϣ��Ӧ�����ﴦ��
		//���ó�miToolTypePointʱ����OnToolUsedMap��Ϣ��Ӧ�����ﴦ��
		m_ctrlMapX.CreateCustomTool(MYTOOL_DISTANCE, miToolTypePoly, miCrossCursor);      //��������
		m_ctrlMapX.CreateCustomTool(MYTOOL_WAYPOINT_POLY, miToolTypePoly, miCrossCursor); //���ƺ���
		
		m_ctrlMapX.SetCurrentTool(miArrowTool);
		
		m_ctrlMapX.GetLayers().AddUserDrawLayer("ScaleBar", 1);//������
		
		m_ctrlMapX.SetMousewheelSupport(miFullMousewheelSupport);//���ţ�����϶���������֧��
		//m_ctrlMapX.SetMousewheelSupport(miMousewheelNoAutoScroll);//���ţ����޹�����û���ֶ����к�����

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
//�Զ��庯�������õ���ǰ·������������û��"\"
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
//�Զ��庯�������������strLayerNameΪ����ͼ�㣬����TRUE�����򷵻�FALSE
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
//�Զ��庯��������·���ļ���ΪstrDirectoryFileName�ĵ�ͼ����չ��Ϊgst����������ͼ��
void CGStationDlg::OpenMapCreateOtherLayers(CString strDirectoryFileName)
{
	//OpenMap
	m_ctrlMapX.SetGeoSet(strDirectoryFileName);
	m_ctrlMapX.SetTitleText("");
	//�ر�����ͼ��Ŀ�ѡ����
	long tempnum;
	tempnum = m_ctrlMapX.GetLayers().GetCount();
	for(int i = 1; i <= tempnum; i++)
	{
		m_ctrlMapX.GetLayers().Item(i).SetSelectable(FALSE);
	}
	//CreateOtherLayers
	LPDISPATCH pDispatch;
	CMapXLayer lay;

	//����WayLine�㣬����ѡ��ġ����߲㡱����WayPointStation���洢���ǵ���վ���㣬WayLine����ʾ����֮������ߣ����洢
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
	//xyg��ӣ�����������SetLineColor������ͼ���style����֮�仯����������style��Ч
	lay.GetStyle().SetSymbolType(miSymbolTypeVector);
	((CButton*)GetDlgItem(IDC_CHECK_LAYER_WAYLINE))->SetCheck(0);//��ѡ��ġ����߲㡱����
	//lay.GetStyle().SetSymbolCharacter(74);

	//�����ɻ�ʵ�ʷ��еĺ����㣬�Ѿ���FlyGPSPoint���������CFlyGPSPointRecord�У�FlyLayer����
	//pDispatch = m_ctrlMapX.GetLayers().CreateLayer("FlyLayer",NULL);
	//m_ctrlMapX.GetLayers().Item("FlyLayer").SetSelectable(TRUE);
	//m_ctrlMapX.GetLayers().Item("FlyLayer").SetOverrideStyle(TRUE);
	//m_ctrlMapX.GetLayers().Item("FlyLayer").SetEditable(TRUE);
	//m_ctrlMapX.GetLayers().SetAnimationLayer(pDispatch);
	//m_ctrlMapX.GetLayers().SetInsertionLayer(pDispatch);

	//�����ɻ��㣬���ɻ�ͼ��㣬�˲�ֻ��һ���ɻ�ͼ�꣬���洢
	pDispatch = m_ctrlMapX.GetLayers().CreateLayer("PlaneUAV",NULL,1);

	m_ctrlMapX.GetLayers().Item("PlaneUAV").SetSelectable(TRUE);
	//m_ctrlMapX.GetLayers().Item("PlaneUAV").SetOverrideStyle(TRUE);//�����ã�����ʾ�ɻ�ͼ��bmp
	m_ctrlMapX.GetLayers().Item("PlaneUAV").SetEditable(TRUE);
	//m_ctrlMapX.GetLayers().Item("PlaneUAV").SetDrawLabelsAfter(FALSE);

	lay = m_ctrlMapX.GetLayers().Item("PlaneUAV");
	lay.GetStyle().SetLineColor(0xff0000);
	lay.GetStyle().SetLineStyle(1);
	lay.GetStyle().SetLineWidth(3);

	lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
	lay.GetStyle().GetSymbolFont().SetName("Wingdings");//���÷ɻ�ͼ��
	lay.GetStyle().SetSymbolCharacter(81);
	lay.GetStyle().SetSymbolFontHalo(TRUE);
	lay.GetStyle().SetSymbolFontColor(0x0e1eff);

	m_ctrlMapX.GetLayers().SetAnimationLayer(pDispatch);//���øò�Ϊ����ͼ��
	m_ctrlMapX.GetLayers().SetInsertionLayer(pDispatch);
	//��ʼ���ɻ�ͼ�꣬���ǲ���ʾ
	m_dTeleLongitude = 123.5037221;	//GPS�޶�λʱ����ʾ����ĳ�������
	m_dTeleLatitude = 41.7961444;
	m_PlaneUAV.InitShowFlane(m_ctrlMapX, m_dTeleLongitude, m_dTeleLatitude);//��InitShowFlaneִֻ��һ��
	lay.SetVisible(FALSE);	

	//�������صĻ��غ���㣬����WayPointDown��ʱ�����Ѿ�����ǰ�ĺ���ɾ���ˣ���֪����ɾ��
	CString strPathFileName;
	strPathFileName.Format("%s\\WayPointDown.tab", GetDirectory());

	CMapXLayerInfo layerinfo;
	if( !layerinfo.CreateDispatch( layerinfo.GetClsid() ) ) 
		return ;  
	layerinfo.SetType(miLayerInfoTypeNewTable);     //�½�ͼ������
	
	VARIANT sVt;
	sVt.vt = VT_BSTR;
	sVt.bstrVal = strPathFileName.AllocSysString();//Ӧ����ͼ����tab�ļ���
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
	layers.Add(layerinfo.m_lpDispatch, 2); //���ӡ�WayPointStation��������ͼ�㼯��

	lay = m_ctrlMapX.GetLayers().Item("WayPointDown");

	lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
	lay.GetStyle().GetSymbolFont().SetName( "Map Symbols" );//���÷���featureʹ�õ�����
	lay.GetStyle().SetSymbolCharacter(54);//���÷���featureʹ�õ��ַ������õ��ͼ��
	lay.GetStyle().SetSymbolFontHalo(FALSE);//False��ʹͼ������¶��һ������
	lay.GetStyle().SetSymbolFontColor(miColorBlue);//����ͼ����ɫ
	
	lay.GetLabelProperties().SetPosition(miPositionCL);//���ñ�עλ��//���ñ�ǩ�����1,2,3...��λ��
	lay.GetLabelProperties().SetOffset(2);//���ñ�עƫ����//���ñ�ǩ�����1,2,3...����ͼ�����ĵ��ƫ����
	lay.GetLabelProperties().GetStyle().SetTextFontColor(miColorBlue);//���ñ�ǩ�����1,2,3...��������ɫ
	lay.GetLabelProperties().GetStyle().SetTextFontShadow(TRUE);//���ñ�ǩ�����1,2,3...����Ӱ
	
	lay.SetSelectable(FALSE); //���øò�Ŀ��Ϊ����ѡ�񣬷���WayPointDown�����棬ѡ�񺽵�ʱ��ֻ��ѡ��WayPointDown�ĺ���
	lay.SetOverrideStyle(TRUE);//�ò�������Featureʹ����ͬ��style
	lay.SetEditable(TRUE);	
	lay.SetAutoLabel(TRUE);    //���øò�Ŀ��Ϊ�Զ���ע
	
	m_ctrlMapX.GetLayers().SetInsertionLayer(lay.m_lpDispatch);

	((CButton*)GetDlgItem(IDC_CHECK_WAYPOINTDOWN))->SetCheck(1);
}
//����������������ʾ�����Ի�����
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

//�˵��������ܡ������
void CGStationDlg::OnMenuListen() 
{
	if(m_MSCom.GetPortOpen()){//��������Ǵ򿪵�
		AfxMessageBox("�����Ѿ��򿪣�");
		return;
	}
	BOOL bTemp = m_pSettingSheet->m_pageSetSerialport.ComIsExist(m_pSettingSheet->m_pageSetSerialport.getComTeleInt());
	if (!bTemp) {//����û����ɿػ��ѱ�ռ��
		AfxMessageBox("�򿪴���ʧ�ܣ����ڲ����ã�");
		return;
	}
	OpenPort();
	//�رա��طš�
	GetDlgItem(IDC_BUTTON_PLAY)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_PAUSE)->EnableWindow(FALSE);
	GetDlgItem(IDC_SCROLLBAR)->EnableWindow(FALSE);
	GetDlgItem(IDC_SLIDER)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_SLIDER)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_BACK)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_BACK_POSITION)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_BACK_SPEED)->EnableWindow(FALSE);
}
//�˵��������ܡ����Ͽ������رմ���
void CGStationDlg::OnMenuClose() 
{
	m_bIsReceivePacket = FALSE;//���ܽ�������
		
	if(m_MSCom.GetPortOpen())//��������Ǵ򿪵ģ���رմ���
		m_MSCom.SetPortOpen(FALSE);	
}
//�˵��������ܡ�����Ƭλ��
void CGStationDlg::OnMenuPhotolocation() 
{
	MessageBox("δ���");	
}
//�˵�������ɼ��
void CGStationDlg::OnMenuTakeOffCheck() 
{
	CTakeOffCheck TakeOffCheck;
	TakeOffCheck.DoModal();
}
//�˵���������
void CGStationDlg::OnMenuSetting() 
{
	if( m_pSettingSheet->DoModal() == IDOK )
		return;
}
//�˵�����PID����
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
//�˵������´����ݡ���ң������
void CGStationDlg::OnMenuDownTelemetry() 
{

}
//�˵������´����ݡ����������
void CGStationDlg::OnMenuDownSteering() 
{
	CDownSteeringDlg DownSteeringDlg;
	DownSteeringDlg.DoModal();
}
//�˵������´����ݡ���GPS����
void CGStationDlg::OnMenuDownGPS() 
{
	CPacket Packet;
	Packet.m_msgid = 0x10;
	Packet.m_len = 0;
	Packet.generateCRC();
	SendPacket(Packet);	
	//���ݰ���0aff10000010�����͵��ɿغ󣬷ɿ�ֹͣ�������ݣ�UP30����վҲ����ˣ�������

	DownGPSDlg.DoModal();
}
//�˵������´����ݡ�������������
void CGStationDlg::OnMenuDownSensor() 
{
	CDownSensorDlg DownSensorDlg;
	DownSensorDlg.DoModal();	
}
//�˵������´����ݡ�������λ��
void CGStationDlg::OnMenuDownMiddle() 
{
	CDownMiddleDlg DownMiddleDlg;
	DownMiddleDlg.DoModal();
}
//�˵��������񡪡�����ֵ
void CGStationDlg::OnMenuMiddleValue() 
{
	CMsg_Capture Capture;
	CPacket Packet = Capture.GetMiddleValuePack();
	SendPacket(Packet);
}
//�˵��������񡪡���С����
void CGStationDlg::OnMenuMinWindDoor() 
{
	CMsg_Capture Capture;
	CPacket Packet = Capture.GetMinWindDoorPack();
	SendPacket(Packet);
}
//�˵��������񡪡�������
void CGStationDlg::OnMenuMaxWindDoor() 
{
	CMsg_Capture Capture;
	CPacket Packet = Capture.GetMaxWindDoorPack();
	SendPacket(Packet);
}
//�˵��������񡪡�ͣ��λ��
void CGStationDlg::OnMenuStopCarPosition() 
{
	CMsg_Capture Capture;
	CPacket Packet = Capture.GetStopCarPositionPack();
	SendPacket(Packet);
}
//�˵��������ջ������򿪽��ջ�
void CGStationDlg::OnMenuOpenReceiver() 
{
	CPacket Packet;
	Packet.m_msgid = 0x24;
	Packet.m_len = 1;
	
	Packet.payload.putU1(0);
	Packet.generateCRC();
	SendPacket(Packet);	
}
//�˵��������ջ������رս��ջ�
void CGStationDlg::OnMenuCloseReceiver() 
{
	CPacket Packet;
	Packet.m_msgid = 0x24;
	Packet.m_len = 1;
	
	Packet.payload.putU1(1);
	Packet.generateCRC();
	SendPacket(Packet);	
}
//�����ڡ������ʴ�
void CGStationDlg::OnKickIdle()
{
	SendMessageToDescendants( WM_IDLEUPDATECMDUI );//���¹�������״̬�����û���
	UpdateDialogControls( this, FALSE );	       //���¿ؼ���״̬������
}
//�������������ĺͱ���
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
//��������������ѡ��
void CGStationDlg::OnToolRect() 
{
	m_ctrlMapX.SetCurrentTool(miRectSelectTool);
}
//�����������������
void CGStationDlg::OnToolDistance() 
{
	if (m_ctrlMapX.GetCurrentTool() == MYTOOL_DISTANCE) {
		//������ʱ����ǰ������MYTOOL_DISTANCE��Ȼ�����ٴε���������������������
		//ͨ��OnUpdateToolDistance˵����ť���ڰ���״̬������miArrowTool����ť��OnUpdateToolDistance����
		m_ctrlMapX.SetCurrentTool(miArrowTool);
		m_DistancePreviousX = 0.0;
		m_DistancePreviousY = 0.0;		
	}else{
		m_ctrlMapX.SetCurrentTool(MYTOOL_DISTANCE);	
	}
}
void CGStationDlg::OnUpdateToolDistance(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck( m_ctrlMapX.GetCurrentTool() == MYTOOL_DISTANCE );//���ð���״̬�����ߵ���״̬
}
//����������ͼ��
void CGStationDlg::OnToolLayer() 
{
	CLayerDlg LayerDlg;
	LayerDlg.DoModal();	
}
//���������������ƺ���
void CGStationDlg::OnToolMouseWaypoint() 
{
	if (m_ctrlMapX.GetCurrentTool() == MYTOOL_WAYPOINT_POLY) 
		m_ctrlMapX.SetCurrentTool(miArrowTool);
	else
		m_ctrlMapX.SetCurrentTool(MYTOOL_WAYPOINT_POLY);	
}
void CGStationDlg::OnUpdateToolMouseWaypoint(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_bWayPointStationIsExist );//�����Ƿ����״̬
	pCmdUI->SetCheck( m_ctrlMapX.GetCurrentTool() == MYTOOL_WAYPOINT_POLY );
}
//�����������༭�������ݡ����Ի���
void CGStationDlg::OnToolWayPointEdit() 
{
	m_WPEditDlg.DoModal();
}
void CGStationDlg::OnUpdateToolWayPointEdit(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_bWayPointStationIsExist );
}
//������������ʾ���غ������ݡ����Ի���
void CGStationDlg::OnToolShowUavWaypoint() 
{
	CWayPointShowDlg WPShowDlg;
	WPShowDlg.DoModal();
}
//��������������켣
void CGStationDlg::OnToolCleanTrack() 
{
	
}
void CGStationDlg::OnUpdateToolCleanTrack(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( FALSE );
}
//����������������غ���㡪��up30����վ��ֻ���ڵ�ͼ����ɾ�����л��غ��㣬û�ж���ɾ�����غ������ݰ�
void CGStationDlg::OnToolCleanWayPointDown() 
{
	CMsg_WayPoint Msg_WayPoint;//������ٴ����ػ��غ��㣬����ȷ��һ��
	Msg_WayPoint.DeleteAllFeature(m_ctrlMapX, _T("WayPointDown"));
}
//�������������ƻ��غ��㡪��������������صĻ��غ���㸴�Ƶ�������Ʋ�
void CGStationDlg::OnToolWaypointCopyDownToUp() 
{
	CMsg_WayPoint Msg_WayPoint;
	Msg_WayPoint.CopyWayPointFromDownToUp(m_ctrlMapX);	
}
//�������������ƻ��غ��㡪������״̬
void CGStationDlg::OnUpdateToolWaypointCopyDownToUp(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_bWayPointStationIsExist );	
}
//������������ʽ���ߡ������
void CGStationDlg::OnToolStandardWayLine() 
{
}
void CGStationDlg::OnUpdateToolStandardWayLine(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( FALSE );	
}
//�����������ϴ����к������ݡ������
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
			//�ϴ�һ�����㣬�Զ��´�һ�����㣬�ϴ���ɾ��WayPointDown�����к���
			Msg_WayPoint.DeleteAllFeature(m_ctrlMapX, _T("WayPointDown"));
		}
	}		
}
//�����������ϴ����к������ݡ�������״̬
void CGStationDlg::OnUpdateToolUpWaypoint(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_bWayPointStationIsExist );
}
//�������������غ������ݡ������
void CGStationDlg::OnToolDownWaypoint() 
{
	CWayPointDownDlg WayPointDownDlg;
	if(WayPointDownDlg.DoModal() == IDOK)
	{	
		CMsg_WayPoint Msg_WayPoint;
		
		if (WayPointDownDlg.m_iDownWayPoint == 0) //=0�����������к��㣬ɾ��ԭ��ͼ������к���
			Msg_WayPoint.DeleteAllFeature(m_ctrlMapX, _T("WayPointDown"));
		else                                      //!=0��������ĳ�����㣬ɾ��ԭ��ͼ����Ǹ�����
			Msg_WayPoint.DeleteFeatureFromWPNum(m_ctrlMapX, _T("WayPointDown"), WayPointDownDlg.m_iDownWayPoint);
		
		CPacket Packet = Msg_WayPoint.GetWayPointPack(WayPointDownDlg.m_iDownWayPoint);
		SendPacket(Packet);//0aff1200010013�������к������ݰ�
	}	
}
//�������������غ������ݡ�������״̬
void CGStationDlg::OnUpdateToolDownWaypoint(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_bIsReceivePacket );
}
//������������������
void CGStationDlg::OnToolPromptWayline() 
{

}
//������������������
void CGStationDlg::OnUpdateToolPromptWayline(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( FALSE );
}
//�������������Ʊ�־�㡪��Sign��
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
//�������������Ʊ�־ֱ�ߡ���Sign��
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
//�������������Ʊ�־���ߡ���Sign��
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
//�������������Ʊ�־���򡪡�Sign��
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
//�����������ֶ�����һ��
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
//������������ʼ��������
void CGStationDlg::OnToolStartContinuePhoto() 
{
	if(AfxMessageBox(_T("��ʾ���Ƿ���������ģ�"),MB_YESNO|MB_ICONQUESTION) == IDNO)
		return;
	
	CMsg_PhotoMode PhotoMode;
	CPacket Packet = PhotoMode.GetStartContinuePhotoPack();
	
	SendPacket(Packet);
}
void CGStationDlg::OnUpdateToolStartcontinuephoto(CCmdUI* pCmdUI) 
{
	//pCmdUI->Enable( m_MSCom.GetPortOpen() );
}
//����������ֹͣ��������
void CGStationDlg::OnToolStopContinuePhoto() 
{
	if(AfxMessageBox(_T("��ʾ���Ƿ�ر�������ģ�"),MB_YESNO|MB_ICONQUESTION) == IDNO)
		return;
	
	CMsg_PhotoMode PhotoMode;
	CPacket Packet = PhotoMode.GetStopContinuePhotoPack();
	
	SendPacket(Packet);
}
void CGStationDlg::OnUpdateToolStopcontinuephoto(CCmdUI* pCmdUI) 
{
	//pCmdUI->Enable( m_MSCom.GetPortOpen() );	
}
//����������������Ƭλ������
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
//������������ѯ��Ƭ����
void CGStationDlg::OnToolInquirePhotonum() 
{
	CPacket Packet = m_Msg_PhotoNum.Pack();
	
	SendPacket(Packet);
}
void CGStationDlg::OnUpdateToolInquirePhotonum(CCmdUI* pCmdUI) 
{
	//pCmdUI->Enable( m_MSCom.GetPortOpen() );
}
//���˵�������ͷ
void CGStationDlg::OnMenuMouseArrow() 
{
	m_ctrlMapX.SetCurrentTool(miArrowTool);
}
//���˵������Ŵ�
void CGStationDlg::OnMenuMouseZoomInBig() 
{
	m_ctrlMapX.SetCurrentTool(miZoomInTool);//ֻ������ɼӺţ���ͼû�зŴ�
}
//���˵�������С
void CGStationDlg::OnMenuMouseZoomOutSmall() 
{
	m_ctrlMapX.SetCurrentTool(miZoomOutTool);
}
//���˵�����ƽ��
void CGStationDlg::OnMenuMouseMove() 
{
	m_ctrlMapX.SetCurrentTool(miPanTool);
}
//���˵���������
void CGStationDlg::OnMenuMouseCenter() 
{
	m_ctrlMapX.SetCurrentTool(miCenterTool);
}
//���˵�����ѡ���ƶ�
void CGStationDlg::OnMenuMouseSelectMove() 
{
	m_ctrlMapX.SetCurrentTool(miSelectTool);
}
//���˵��������뺽��
void CGStationDlg::OnMenuMouseWayPointInsert() 
{
	m_ctrlMapX.SetCurrentTool( MYTOOL_WAYPOINT_POLY );	
}
//���˵������༭����
void CGStationDlg::OnMenuMouseWayPointEdit() 
{
	CMapXLayer lay = m_ctrlMapX.GetLayers().Item("WayPointStation");
	lay.SetKeyField("num");
	
	long lCount = lay.GetSelection().GetCount();
	CString str = lay.GetSelection().Item(1).GetKeyValue();

	CWayPointEditDlg WPEditDlg;
	WPEditDlg.m_iEditWPNum = atoi(str);//��ȡ��ѡ�񺽵���ţ���1,2,3...����ͼҲ�ܶ�ѡ����
	WPEditDlg.DoModal();
}
//���˵�����ɾ������
void CGStationDlg::OnMenuMouseWayPointDelete() 
{	
	try {
		CMapXLayer lay = m_ctrlMapX.GetLayers().Item("WayPointStation");
		long lCount = lay.GetSelection().GetCount();
		lay.SetKeyField("num");
		
		for(int i = 1; i <= lCount; i++)
		{	
			CMapXFeature FeaSel = lay.GetSelection().Item(i);
			int iFeaSelNum = atoi(FeaSel.GetKeyValue());//ѡ�е�ĺ������

			lay.DeleteFeature(FeaSel);
			
			long lFeaturesCount = lay.AllFeatures().GetCount();
			//��iFeaSelNum������num���ĳ�num - 1����Ϊԭ��num��ĵ��п�����iFeaSelNumǰ�棬
			for(int j = 1; j <= lFeaturesCount; j++)//���Դ�1��lFeaturesCountѭ��
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
//���˵������ϴ�����
void CGStationDlg::OnMenuMouseWayPointUpload() 
{
	CMapXLayer lay = m_ctrlMapX.GetLayers().Item("WayPointStation");
	long lCount = lay.GetSelection().GetCount();
	if (lCount == 0) {
		AfxMessageBox(_T("��ʾ����ѡ�񺽵㣡"));
		return;
	}
	CString str = lay.GetSelection().Item(1).GetKeyValue();
	int iWayPointNum = atoi(str);
	
	CPacket  packet;
	CMsg_WayPoint Msg_WayPoint;
	//ֻ�������ΪiWayPointNum�ĺ��㣬������������
	packet = Msg_WayPoint.UpLoadOneWayPointPacket(m_ctrlMapX, iWayPointNum);
	SendPacket(packet);
	//����һ���������Ϊ�ɿ�Ҫ�ش��˺��㣬��ɾ��
	Msg_WayPoint.DeleteFeatureFromWPNum(m_ctrlMapX, _T("WayPointDown"), iWayPointNum);
}
//���˵�������ע
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
//���ơ��������á�Ŀ�꺽����Ű�ť
void CGStationDlg::OnButtonSendTargetWPNum() 
{
	CString str;
	((CEdit*)GetDlgItem(IDC_EDIT_SENDTARGET_WPNUM))->GetWindowText(str);
	int iWPNum = atoi(str);

	CPacket Packet;
	Packet.m_msgid = 0x13;//����Ŀ�꺽��
	Packet.m_len = 1;
	
	Packet.payload.putU1(iWPNum);
	Packet.generateCRC();
	SendPacket(Packet);	
}
//���ơ�����UAV����ť
void CGStationDlg::OnButtonUAV() 
{
	CPacket Packet;
	Packet.m_msgid = 0x18;//���ÿ���ģʽ
	Packet.m_len = 1;
	
	Packet.payload.putU1(0);//UAV
	Packet.generateCRC();
	SendPacket(Packet);	
}
//���ơ�����CPV����ť
void CGStationDlg::OnButtonCPV() 
{
	CPacket Packet;
	Packet.m_msgid = 0x18;//���ÿ���ģʽ
	Packet.m_len = 1;
	
	Packet.payload.putU1(3);//CPV
	Packet.generateCRC();
	SendPacket(Packet);	
}
//���ơ�����ͣ��������������ť
void CGStationDlg::OnButtonStopCar() 
{
	CPacket Packet;
	Packet.m_msgid = 0x17;//���Ʒ������Ƿ�ͣ��
	Packet.m_len = 1;

	CString str;
	((CButton*)GetDlgItem(IDC_BUTTON_STOP_CAR))->GetWindowText(str);
	if (str == _T("ͣ��")) {
		if(AfxMessageBox(_T("ȷ��ͣ���𣿼�����ͣ���̵������������յ��趨��ͣ��λ�����£�"), MB_YESNO|MB_ICONQUESTION) == IDNO)
			return;

		Packet.payload.putU1(1);//������ͣ��
		((CButton*)GetDlgItem(IDC_BUTTON_STOP_CAR))->SetWindowText(_T("����"));
	}else{
		Packet.payload.putU1(0);//���������ų�
		((CButton*)GetDlgItem(IDC_BUTTON_STOP_CAR))->SetWindowText(_T("ͣ��"));
	}
	Packet.generateCRC();
	SendPacket(Packet);	
}
//CPV���ơ������򡪡������͡���ť
void CGStationDlg::OnButtonCPVDirection() 
{
	UpdateData(TRUE);

	CPacket Packet;
	Packet.m_msgid = 0x19;//�趨CPVʱ��Ŀ�꺽��
	Packet.m_len = 2;
	
	Packet.payload.putU2h(m_iCPVDirection);//m_iCPVDirection��0��������90��������180�����ϣ�270������
	Packet.generateCRC();
	SendPacket(Packet);		
}
//CPV���ơ����ٶȡ��������͡���ť
void CGStationDlg::OnButtonCPVSpeed() 
{
	UpdateData(TRUE);
	
	CPacket Packet;
	Packet.m_msgid = 0x09;//�趨CPVʱ��Ŀ�����
	Packet.m_len = 2;
	
	Packet.payload.putU2(m_iCPVSpeed);//��/��
	Packet.generateCRC();
	SendPacket(Packet);		
}
//��ѡ�򡪡�������Ʋ㡪�����
void CGStationDlg::OnCheckWayPointStation() 
{
	if (m_bWayPointStationIsExist) {
		
		int iCheck = ((CButton*)GetDlgItem(IDC_CHECK_WAYPOINTSTATION))->GetCheck();
		if (iCheck == 0) {//ԭ���й��������հף�GetCheck()=0
			m_ctrlMapX.GetLayers().Item("WayPointStation").SetVisible(FALSE);	
			return;
		}
		//ԭ���հף������ɹ���GetCheck()=1��
		m_ctrlMapX.GetLayers().Item("WayPointStation").SetVisible(TRUE);	
	}
}
//��ѡ�򡪡�������Ʋ㡪������״̬
void CGStationDlg::OnUpdateCheckedWayPointStation( CCmdUI* pCmdUI ) 
{
	pCmdUI->Enable( m_bWayPointStationIsExist );
}
//��ѡ�򡪡����߲㡪�����
void CGStationDlg::OnCheckLayerWayline() 
{
	if (m_bWayPointStationIsExist) {
		try{
			int iCheck = ((CButton*)GetDlgItem(IDC_CHECK_LAYER_WAYLINE))->GetCheck();
			
			if (iCheck == 0) {//ԭ���й��������հף�GetCheck()=0
				m_ctrlMapX.GetLayers().Item("WayLine").SetVisible(FALSE);	
				return;
			}
			//ԭ���հף������ɹ���GetCheck()=1��
			m_ctrlMapX.GetLayers().Item("WayLine").SetVisible(TRUE);//WayLine�㣬ֻ���ߣ���WayPointStation���к���
			
			//�������m_CMapXPoints���������"WayPointStation"�ĵ㱻�ƶ��󣬺����뺽�㲻һ��
			CMapXLayer lay = m_ctrlMapX.GetLayers().Item("WayPointStation");
			int iWayPointCount = lay.AllFeatures().GetCount();
			
			m_CMapXPoints.RemoveAll();//ɾ�������¸�ֵ
			//��ΪWayPointStation��ͼԪnum��Item(i)��һ�£�m_CMapXPointsҪ���մ�С�����˳����������
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
				m_CMapXPoints.Add(point, i);//���붨�����ĳ�Ա������ɾֲ���������
				//iΪ1��Points.Count������δָ��i��׷�ӵ�β��
				if (i == 1) {
					point1 = point;
				}
				iNum++; 
			}
			//���ߣ��Ѻ�������һ����ն����
			int iPointCount = m_CMapXPoints.GetCount();
			if(iPointCount < 2) {
				AfxMessageBox("���ȱ궨����2�����㣡");
				return;
			}
			m_CMapXPoints.Add(point1);//��ӵ�һ�����㵽���ϵ�����γɷ�յĶ����
			
			//Ҫɾ�����е��ߣ����»��ߣ������߻��Ĳ���
			CMapXLayer linelay = m_ctrlMapX.GetLayers().Item("WayLine");
			long lCount = linelay.AllFeatures().GetCount();
			while (lCount > 0) {
				linelay.DeleteFeature(linelay.AllFeatures().Item(lCount));
				linelay.Refresh();
				lCount = linelay.AllFeatures().GetCount();
			}
			//���»���
			CMapXFeature feature;
			if(!feature.CreateDispatch(feature.GetClsid()))
			{
				TRACE0("Failed to create Feature object");
				return;
			}
			feature.Attach(m_ctrlMapX.GetDispatch());
			feature.SetType(miFeatureTypeLine);
			feature.SetStyle(m_ctrlMapX.GetDefaultStyle()); 
			
			feature.GetParts().Add( m_CMapXPoints );//����
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
//��ѡ�򡪡����߲㡪������״̬
void CGStationDlg::OnUpdateCheckedLayerWayLine( CCmdUI* pCmdUI )
{
	pCmdUI->Enable( m_bWayPointStationIsExist );//�к����WayPointStation�������к��߲�
}
//��ѡ�򡪡����غ���㡪�����
void CGStationDlg::OnCheckWaypointdown() 
{
	int iCheck = ((CButton*)GetDlgItem(IDC_CHECK_WAYPOINTDOWN))->GetCheck();
	if (iCheck == 0) {//ԭ���й��������հף�GetCheck()=0
		m_ctrlMapX.GetLayers().Item("WayPointDown").SetVisible(FALSE);	
		return;
	}
	//ԭ���հף������ɹ���GetCheck()=1��
	m_ctrlMapX.GetLayers().Item("WayPointDown").SetVisible(TRUE);	
}
//��ѡ�򡪡��켣�㡪�����
void CGStationDlg::OnCheckFlyPlaneGPS() 
{
	BOOL bFlyGPSPoint = FindLayer(_T("FlyGPSPoint"));//����յ��ɿ�ң�����ݣ��ʹ��ڹ켣��FlyGPSPoint
	
	int iCheck = ((CButton*)GetDlgItem(IDC_CHECK_FLYPLANEGPS))->GetCheck();
	if (iCheck == 0) {//ԭ���й��������հף�GetCheck()=0
		//m_ctrlMapX.GetLayers().Item("PlaneUAV").SetVisible(FALSE);//һֱ��ʾ�ɻ�ͼ�꣬����ȥ��FlyGPSPoint��	
		if (bFlyGPSPoint) 
			m_ctrlMapX.GetLayers().Item("FlyGPSPoint").SetVisible(FALSE);
		return;
	}
	//ԭ���հף������ɹ���GetCheck()=1��
	//m_ctrlMapX.GetLayers().Item("PlaneUAV").SetVisible(TRUE);
	if (bFlyGPSPoint) 
		m_ctrlMapX.GetLayers().Item("FlyGPSPoint").SetVisible(TRUE);
}
//��ѡ�򡪡���־�㡪�����
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
//��ѡ�򡪡���־�㡪������״̬
void CGStationDlg::OnUpdateCheckedLayerSign( CCmdUI* pCmdUI )
{
	pCmdUI->Enable( m_bSignLayerIsExist );	
}
//��ѡ�򡪡���ʾ��ע�������
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
//��ѡ�򡪡���ʾ��ע��������״̬
void CGStationDlg::OnUpdateCheckedLayerSignShowSign( CCmdUI* pCmdUI )
{
	pCmdUI->Enable( m_bSignLayerIsExist );	
}
//��ѡ�򡪡����ӵ�ͼ��
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
//�˵��������ܡ����ط�
void CGStationDlg::OnMenuPlayback() 
{
	CString strPath = GetDirectory();
	CString strDirectory;
	strDirectory.Format("%s\\record", strPath);
	m_comDlg.SetInitDir(strDirectory);
	
	m_comDlg.SetDialogTitle("ѡ��Ҫ�طŵ�tab�ļ�");
	m_comDlg.SetFilter("*.tab");
	m_comDlg.SetFileName("*.tab");
	m_comDlg.ShowOpen();
	SetCurrentDirectory(strPath);//�����������û���
	
	CString file;
	file.Empty();
	file = m_comDlg.GetFileName();
	file.TrimRight();
	CString strDirectoryFileName = file;//����·�����ļ�������չ��
	CString strFileExtensionName = m_comDlg.GetFileTitle();//ֻ���ļ�������չ��
	
	if (strDirectoryFileName.IsEmpty() || strFileExtensionName.IsEmpty()) {
		AfxMessageBox(_T("��ʾ��·�����ļ���������Ϊ�գ�"));
		return;
	}
	try{
		//������յ�ң�����ݣ������Ѿ��طŹ�һ�Σ�FlyGPSPoint�㶼���ڣ�ɾ��
		if (FindLayer(_T("FlyGPSPoint"))) {
			m_ctrlMapX.GetLayers().Remove(_T("FlyGPSPoint"));
			if (m_pFlyGPSPointRecord != NULL) {//���յ�ң������
				delete m_pFlyGPSPointRecord;
				m_pFlyGPSPointRecord = NULL;
			}
		}
		//�ѻط�Ҳ��λ��FlyGPSPoint��
		CMapXLayer lay = m_ctrlMapX.GetLayers().Add( strDirectoryFileName, 6 );//��λ��6��
		CString layername = lay.GetName();
		if (layername.Left(11) != _T("FlyGPSPoint")) {
			AfxMessageBox(_T("��ʾ����ѡ���к��й켣���tab�ļ��򿪣�"));
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
		//�رմ���
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
//�طš��������š���ť
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
	SetTimer(2,iSpeed,NULL);//�����1000ָ1000����=1��

	m_ctrlMapX.GetLayers().Item("PlaneUAV").SetVisible(TRUE);	
}
void CGStationDlg::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 1) {//���µ�ǰʱ��
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
	if (nIDEvent == 2) {//�طŶ�ʱ��
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
//�طš�������ͣ����ť
void CGStationDlg::OnButtonPause() 
{
	KillTimer(2);
}
//�طš����ط�λ�ù�����
void CGStationDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{	
	if (pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR) {//�ط���������������طŽ���
		
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
//�طš��������ٶ�0.5X,1X...
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
	
	SetTimer(2,iSpeed,NULL);//�����1000ָ1000����=1��
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
//�����ڡ���Ϣ�����������յ��ɿط����������ݰ�ʱ
void CGStationDlg::OnOnCommMscomm() 
{
	if(m_bIsReceivePacket)
	{
		if(m_MSCom.GetCommEvent() == 2)                     //�¼�ֵΪ2��ʾ���ջ����������ַ�
		{
			VARIANT variant_input = m_MSCom.GetInput();     //��������
			COleSafeArray safearray_input = variant_input;  //VARIANT�ͱ���ת��ΪColeSafeArray�ͱ���
			LONG length = safearray_input.GetOneDimSize();  //�õ���Ч���ݳ���
			
			BYTE *byte_input = new BYTE[length]; //����BYTE���� An 8-bit integerthat is not signed.
	
			for(LONG k = 0; k < length; k++)             
			{
				safearray_input.GetElement(&k, byte_input+k);//safearray_inputת��ΪBYTE������

				CPacket *pPacket = m_Parser.link_parse_BYTE(byte_input[k]);//����ʹ��pPacket����Ϊm_Parser
				if(pPacket != NULL) //�յ���Ч���ݰ�                       //�����m_Packet��Ҫ�����������ݰ�
				{
					CPacket ReceivedPacket = *pPacket;
					//��дһ���������ݰ�����
					HandleReceivedPacket(&ReceivedPacket);
				}
			}
		}
	}
}
//MapX��Ϣ���������ڵ�ͼ�ϰ�������Ҽ�ʱ
void CGStationDlg::OnMouseDownMap(short Button, short Shift, float X, float Y) 
{
	if(Button == 1)//����������
	{
		long ToolNum = m_ctrlMapX.GetCurrentTool();
		if (ToolNum == MYTOOL_DISTANCE) {
			float ScreenX = X;
			float ScreenY = Y;
			m_ctrlMapX.ConvertCoord(&ScreenX, &ScreenY, 
				&m_DistancePreviousX, &m_DistancePreviousY, miScreenToMap);
		}
	}
	if(Button == 2)//��������Ҽ�
	{
		m_ctrlMapX.SetCurrentTool(miArrowTool);//�������ߣ�����һֱ����һ������

		CMenu menu;
		menu.LoadMenu(IDR_MENU_MOUSE);
		CMenu *pMenu=NULL;  
		pMenu = menu.GetSubMenu(0);
		SetMenuDefaultItem(pMenu->m_hMenu, ID_MENU_MOUSE_ZOOMIN_BIG, FALSE);
		POINT pt;
		GetCursorPos(&pt);
		//�ж��Ƿ�ѡ��һ�����㣬�Ծ����Ƿ񼤻��Ҳ˵�
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
			if(FeaturesSelect.GetCount() >= 1)//Ψ��ɾ�����Զ�ѡ
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
//MapX��Ϣ�������������������X��Y
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

		//�����MYTOOL_DISTANCE������������µ�ǰ���룬���µ�ǰ�Ƕ�
		long ToolNum = m_ctrlMapX.GetCurrentTool();
		if (ToolNum == MYTOOL_DISTANCE && m_DistancePreviousX != 0.0 && m_DistancePreviousY != 0.0) {
			//���µ�ǰ����
			double dDistanceCurrent = m_ctrlMapX.Distance(m_DistancePreviousX, m_DistancePreviousY, MapX, MapY);
			m_StaticStatus.UpdateCurrentDistance(dDistanceCurrent);

			//���µ�ǰ�Ƕ�
			double angle;
			double dTemp = atan( (MapY - m_DistancePreviousY) / (MapX - m_DistancePreviousX) ) / 3.1415926 * 180;
			if((MapX - m_DistancePreviousX) >= 0 && (MapY - m_DistancePreviousY) >= 0)
				angle = 90 - dTemp;
			else if((MapX - m_DistancePreviousX) >= 0 && (MapY - m_DistancePreviousY) < 0)
				angle = 90 - dTemp;
			else 
				angle = 270 - dTemp;

			if (MapX == m_DistancePreviousX) {
				angle = 0;//�������0���������룬����angle = 0
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
//MapX��Ϣ������������ΪmiToolTypePoly����
void CGStationDlg::OnPolyToolUsedMap(short ToolNum, long Flags, LPDISPATCH Points, BOOL bShift, BOOL bCtrl, BOOL FAR* EnableDefault) 
{
	try {		
		//�����ߡ��������������ֻ�е�����ʱ��ִ�е�����ƶ����ʱ������
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
			m_StaticStatus.UpdateTotalDistance(dDistanceTot);//���¾�̬��ľ���ֵ
		}
		//Flags = miPolyToolEndʱ����ǰ���߻���MYTOOL_DISTANCE���ٴε����ͼʱ��Points��������ǰ��ļ���
		if (ToolNum == MYTOOL_DISTANCE && Flags == miPolyToolEnd) {
			m_DistancePreviousX = 0.0;//������ƶ���겻�ټ��㡰��ǰ���롱
			m_DistancePreviousY = 0.0;
		}
		if (ToolNum == MYTOOL_WAYPOINT_POLY && Flags == miPolyToolEnd) { 
			//�����ߡ��������ƺ��㡱//��LPDISPATCH Points���뵽�����WayPointStation��
			CMapXPoints mapxpoints;
			mapxpoints.AttachDispatch(Points, FALSE); 
			int iNewWPCount = mapxpoints.GetCount(); //�����Ӻ�������
			
			CMapXLayer lay = m_ctrlMapX.GetLayers().Item("WayPointStation");
			int iOldWPCount = lay.AllFeatures().GetCount();//��ǰ�ĺ�������
			
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
				Msg_WayPoint.SaveWayPointToTab(WayPoint, m_ctrlMapX, _T("WayPointStation"));//�Ѻ��㱣�浽tab�ļ�
			}
			//�����˵��������뺽�㡱����������
			CMapXSelection FeaturesSelect = lay.GetSelection();
			long lFeaSelCount = FeaturesSelect.GetCount();
		
			if(lFeaSelCount == 1)//ֻ��ѡ��һ���㣬�����ѡ�Ͳ�֪�����Ǹ��������Ӻ���
			{                    //��һ��ѡ�е㣬֤���ǡ����˵��������뺽�㡱��ѡ�е�MYTOOL_WAYPOINT_POLY
				lay.SetKeyField("num");
				CMapXFeature FeaSel = lay.GetSelection().Item(1);
				int iFeaSelNum = atoi(FeaSel.GetKeyValue());//ѡ�е�ĺ������
				//��iFeaSelNumԭ��������num���ĳ�num+iNewWPCount����Ϊԭ��num��ĵ��п�����iFeaSelNumǰ�棬
				for(int j = 1; j <= iOldWPCount; j++)//���Դ�1��iOldWPCountѭ��
				{
					CMapXFeature objFeature;
					objFeature = lay.AllFeatures().Item(j);
					
					int iOldNum = atoi(objFeature.GetKeyValue());
					if (iOldNum > iFeaSelNum) {

						CString str_key;
						str_key.Format("%d", iOldNum + iNewWPCount);//numԭ����ֵ����iNewWPCount
						//lay.SetKeyField("num");
						objFeature.SetKeyValue(str_key);
						objFeature.Update();
					}	
				}
				//�Ѻ�����ӵ�iNewWPCount�����num�ĳ�iFeaSelNum+1��iFeaSelNum+iNewWPCount				
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
//MapX��Ϣ��������������
void CGStationDlg::OnDrawUserLayerMap(LPDISPATCH Layer, long hOutputDC, long hAttributeDC, LPDISPATCH RectFull, LPDISPATCH RectInvalid) 
{
	//����mapinfoԴ��C++Ŀ¼�µ�Cppʵ��
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
	str.Format("ǧ��");//ԭ��Ϊ��str.Format("Miles");
	iCenterAdjustment = 60*str.GetLength();
	dc.TextOut(x1-iCenterAdjustment,-y1,str);

	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldFont);
	// detach dc so destructore won't call Release it
	dc.ReleaseAttribDC();
	dc.Detach();
}
//�Զ��庯��������ʾң�����ݵ��Ի��������
void CGStationDlg::ShowTeleToDlg(CMsg_Telemetry Msg_Telemetry)
{
	m_cReceivedPacketType.SetWindowText(_T("ң������"));
	m_StaticStatus.UpdateMsgTelemetry(&Msg_Telemetry);
	m_StaticStatus.UpdateWayPoint(&Msg_Telemetry, m_ctrlMapX);
	
	m_dTeleLongitude = Msg_Telemetry.m_GPSdata.m_dLongitude;    //����
	m_dTeleLatitude = Msg_Telemetry.m_GPSdata.m_dLatitude;      //γ��
	//m_iTeleAltitude = (int)Msg_Telemetry.m_GPSdata.m_fGPSalt; //59;
	m_iGPSSatellite = Msg_Telemetry.m_GPSdata.m_iSatelliteNum;  //GPS������
	m_strTeleGroundSpeed.Format("%.1f",Msg_Telemetry.m_GPSdata.m_fGPSspeed);//���١���GPS���ݡ���ˮƽ�ٶ�
	//m_iTelePressureAltitude = Msg_Telemetry.m_nAiralt;
	m_fTelePitch = Msg_Telemetry.m_fPitch;    //����
	m_fTeleRoll = Msg_Telemetry.m_fRoll;      //��ת
	m_fTeleDirection = (float)Msg_Telemetry.m_iTargetDirection;//ָ��
	//m_fAirPress = Msg_Telemetry.m_fAirPress;                 //�������ݡ�����ѹ
	//m_iTargetHeight = Msg_Telemetry.m_iTargetAltitude;       //Ŀ��߶�
	m_iTargetAirSpeed = Msg_Telemetry.m_iTargetAirSpeed;
	m_iTargetWayPointNum = Msg_Telemetry.m_iTargetWayPoint;    //���ơ���Ŀ�꺽��
 	
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

	m_ctrlCircle.SetAimValue(Msg_Telemetry.m_iRPM2);//�á��ڶ�������ת�١�����Ŀ��ֵ����֪�Է񣿣�
	m_ctrlCircle.SetRealValue(Msg_Telemetry.m_iRPM);//"������ת��"rpm����/�룩
	
	UpdateData(FALSE);
	//����gps��λ�ľ�γ�Ⱥ�����ʾ���ڵ�ͼ�ϵ�λ��
	//GPS��ʱ���źţ���ʱ���źţ������źű䵽���ź�ʱ����γ��ֵ��Ȼ�У���ԭ����ֵ
	if (m_dTeleLongitude != 0 && m_dTeleLatitude != 0){
		m_ctrlMapX.GetLayers().Item("PlaneUAV").SetVisible(TRUE);
		m_PlaneUAV.UpdateCurrentPosition(m_dTeleLongitude, m_dTeleLatitude);
	}else
		m_ctrlMapX.GetLayers().Item("PlaneUAV").SetVisible(FALSE);
}
//�Զ��庯���������������յ������ݰ�����
void CGStationDlg::HandleReceivedPacket(CPacket *ReceivedPacket)
{
	CMsg_WayPoint Msg_WayPoint;
	CString strTemp;
	//int iHangXiang = 76;//��λ���ȡ���λ��ͼʱ�õ�
	
	switch(ReceivedPacket->m_msgid)
	{
	case 20://���0x14�����ܣ�������´�ң������
		if (ReceivedPacket->m_len != m_Msg_Telemetry.MSG_SIZE_PAYLOAD_LENGTH) 
			break;//�յ������ݰ������붨������ݰ����Ȳ�һ��
		m_Msg_Telemetry.Unpack(ReceivedPacket->payload);
		
		//�յ�һ��"ң������"���ݰ��洢��record�ļ��ĵ�ǰ.tab�У��յ�һ���洢һ��
		if (m_pFlyGPSPointRecord == NULL) {
			//����ȵ���طţ��ʹ���FlyGPSPoint�㣬ɾ��
			if(FindLayer(_T("FlyGPSPoint")))
				m_ctrlMapX.GetLayers().Remove("FlyGPSPoint");
			//����ȵ���طţ��ʹ���FlyGPSPoint�㣬ɾ��
			m_pFlyGPSPointRecord = new CFlyGPSPointRecord(m_ctrlMapX);
			((CButton*)GetDlgItem(IDC_CHECK_FLYPLANEGPS))->SetCheck(1);//�켣�㼴FlyGPSPoint���
			
			if (m_Msg_Telemetry.m_GPSdata.m_dLongitude != 0 && m_Msg_Telemetry.m_GPSdata.m_dLatitude != 0) 
				m_ctrlMapX.ZoomTo(30, m_Msg_Telemetry.m_GPSdata.m_dLongitude, m_Msg_Telemetry.m_GPSdata.m_dLatitude);
			//���ŵ�ͼ����x��yΪ������ʾ��ͼ��30Ϊ����ֵ���Ե�ͼ��λMapUnitָ��
			//ZoomTo��ʹ�����ߺ͵�ͼ����ˢ�£���������Ŀ�ģ���ZoomToִֻ��һ��	
		}
		m_pFlyGPSPointRecord->SaveMsgTelemetry(m_ctrlMapX, &m_Msg_Telemetry);
		//�����ͬʱ�Ѿ�Ϊÿ��ң�������ڵ�ͼ����ʾһ���㣬�������溯��
		//m_pFlyGPSPointRecord->ShowSymbol(m_ctrlMapX, &m_Msg_Telemetry);//Ϊÿ��ң�������ڵ�ͼ����ʾһ����
		ShowTeleToDlg(m_Msg_Telemetry);
		break;
	//����PID�Ի��򲿷�///////////////////////////////////////////////////
	case 2://���0x02:�����ܣ�������PID������������
		if (m_pPIDAdjDlg == NULL) break;
		
		CGStationDlg::m_pPIDAdjDlg->m_Msg_PIDAdjustData.Unpack(ReceivedPacket->payload);
		CGStationDlg::m_pPIDAdjDlg->UpDlgPIDAdjData();//���� PID�������� ��PID������������
		CGStationDlg::m_pPIDAdjDlg->UpChartData();//����ͼ��ؼ�����
		break;
	case 12://���0x0c:�����ܣ���ȡ������PID����
		if (m_pPIDAdjDlg == NULL) break;
		if (ReceivedPacket->m_len != m_pPIDAdjDlg->m_Msg_PIDData.MSG_SIZE_PAYLOAD_LENGTH) 
			break;//�յ������ݰ������붨������ݰ����Ȳ�һ��

		CGStationDlg::m_pPIDAdjDlg->m_Msg_PIDData.Unpack(ReceivedPacket->payload);
		CGStationDlg::m_pPIDAdjDlg->UpDlgPIDData();//���� PID�������� ��PID����
		break;
	case 13://���0x0d ; ���ܣ����û��߻�ȡӭ�������Сƽ��ֵ
		if (m_pPIDAdjDlg == NULL) break;
		
		CGStationDlg::m_pPIDAdjDlg->m_Msg_OtherPIDAdjData.YJDataUnPacket(ReceivedPacket->payload);
		CGStationDlg::m_pPIDAdjDlg->UpYJData();//���� PID�������� �� ӭ������
		break;
	//����PID�Ի��򲿷�///////////////////////////////////////////////////
	case 16://���0x10�����ܣ������´�GPS����
		DownGPSDlg.Unpack(ReceivedPacket->payload);
		DownGPSDlg.SendMessage(WM_DOWN_GPS, FALSE);
		break;
	case 18://���0x12�����ܣ����û��߻�ȡ��������
		//OnDownpotOperate(strtemp,numtemp);
		//��⺽�����ݰ������浽tab��
		Msg_WayPoint.UnpackSaveToTab(ReceivedPacket->payload, m_ctrlMapX);
		m_cReceivedPacketType.SetWindowText(_T("���غ���"));
		//��OnDrowDownPot()��δ���
		break;
	case 26://���0x1a�����ܣ��趨�ͻ�ȡ���ټ�ϵ��
		ReceivedPacket->payload.resetIndex();
		m_pSettingSheet->m_pageSetAirSpeed.m_iAirSpeedValue = (int)ReceivedPacket->payload.getU4h();
		break;
	case 30://���0x1e�����ܣ���ȡ�����÷ɿذ�װ�Ƕȣ�������ת��ƫ��
		m_pSettingSheet->m_pageSetPitchRoll.Unpack(ReceivedPacket->payload);
		m_pSettingSheet->m_pageSetPitchRoll.SendMessage(WM_PITCHROLL, FALSE);
		break;
	case 39://���0x27�����ܣ���ȡ�����÷ɿ���Ӳ�����
		m_pSettingSheet->m_pageSetVersion.Unpack(ReceivedPacket->payload);
		m_pSettingSheet->m_pageSetVersion.SendMessage(WM_VERSION, FALSE);
		break;
	case 46://���0x2e�����ܣ��´���Ƭλ������
		//OnPhotoDataOperate(strtemp,numtemp);
		m_Msg_PhotoData.Unpack(ReceivedPacket->payload);
		m_cReceivedPacketType.SetWindowText(_T("��Ƭ����"));

		int day,hour,minter,second;
		day = (int)m_Msg_PhotoData.time/1000/3600/24;
		hour = (int)((m_Msg_PhotoData.time/1000/3600/24-day)*24);
		minter = (int)(((m_Msg_PhotoData.time/1000/3600/24-day)*24-hour)*60);
		second = (int)((((m_Msg_PhotoData.time/1000/3600/24-day)*24-hour)*60-minter)*60);
		strTemp.Format("%4d   ����%d %2d:%2d:%2d  %4.5lf    %4.5lf   %4ld     %5.2lf    %5.2lf    %5.2lf\r\n",
			m_Msg_PhotoData.num, day, hour, minter, second, m_Msg_PhotoData.lon, m_Msg_PhotoData.lat,
			m_Msg_PhotoData.alt, m_Msg_PhotoData.pitch, m_Msg_PhotoData.roll, m_Msg_PhotoData.heading);
		//OnFileSavePhotoData(strtemp);δ���
		break;
	case 47://���0x2f�����ܣ���ѯ������Ƭ����
		m_Msg_PhotoNum.Unpack(ReceivedPacket->payload);
		m_cReceivedPacketType.SetWindowText(_T("��Ƭ����"));

		strTemp.Format("���β�ѯ����Ƭ����Ϊ%d�ţ�",m_Msg_PhotoNum.m_iPhotoNum);

		//AfxMessageBox(strTemp);
		//m_cPhotoNum.SetWindowText(strTemp);
		break;
	default:
		break;
	}
}
//�Զ��庯�������򿪴��ں�����ʹOnOnCommMscomm�ܽ��յ����ݰ�
void CGStationDlg::OpenPort()
{
	m_bIsReceivePacket = FALSE;//���ܽ�������

	if(m_MSCom.GetPortOpen())//��������Ǵ򿪵ģ���رմ��ڣ�Ȼ�������´�
		m_MSCom.SetPortOpen(FALSE);

	int nPort = m_pSettingSheet->m_pageSetSerialport.getComTeleInt();
	//nPort=1ʱ����com1��nPort=2ʱ����com2
	
	m_MSCom.SetCommPort(nPort);   //ѡ��com1
	m_MSCom.SetInBufferSize(4096); //���ջ�����
	m_MSCom.SetOutBufferSize(4096);//���ͻ�����

	CString	strBT = m_pSettingSheet->m_pageSetSerialport.getBTCString();
	//strBT = ("%d,%s",getBTint(),"n,8,1");//������115200����У�飬8������λ��1��ֹͣλ
	m_MSCom.SetSettings(strBT); 

	if( !m_MSCom.GetPortOpen() )  //�������û�д����
		m_MSCom.SetPortOpen(TRUE);//�򿪴��ڡ�������ڱ�ռ�ã���ʾ���˿��Ѵ򿪡���ֱ��return����������Ͳ�ִ����
	else
		AfxMessageBox("cannot open serial port!");

	m_MSCom.SetRThreshold(1);//����1��ʾÿ�����ڽ��ջ���������1����1�������ַ�ʱ��������һ���������ݵ�OnComm�¼�
	m_MSCom.SetInputMode(1); //�������뷽ʽΪ�����Ʒ�ʽ���Զ����Ʒ�ʽ��д����
	m_MSCom.SetInputLen(0);  //���õ�ǰ���������ݳ���Ϊ0����ʾȫ����ȡ
	m_MSCom.GetInput();      //��Ԥ���������������������	

	m_bIsReceivePacket = TRUE;//���Խ�������
}
//�Զ��庯�������������ݰ�����
void CGStationDlg::SendPacket(CPacket Packet)
{
	/*////////////////////////������
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
////////////////////////////������*/

	CByteArray ByteArray;
	Packet.GetCByteArray(ByteArray);

	///////////////////////////*������
	CString str,strTemp;
	int dd = ByteArray.GetSize();
	for(int i = 0; i < dd; i++)
	{
		BYTE ss = ByteArray[i];
		strTemp.Format("%02x",ss);
		str = str + strTemp;
	}
	CString result = str;
////////////////////////������*/

	m_MSCom.SetOutput(COleVariant(ByteArray));	
}
/*
	CMapXLayers layers = m_ctrlMapX.GetLayers(); 
	CString str = layers.Item("WayPointDown").GetStyle().GetSymbolFont().GetName();//�õ��ַ���
	int dd = layers.Item("WayPointDown").GetStyle().GetSymbolCharacter();          //�õ����������С�죬ԲȦ������ȵ�
*/
void CGStationDlg::OnButtonTest() 
{
	
}
