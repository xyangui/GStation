// GStationDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
#include "MAPX.h"
#include "commondialog.h"
#include "instrumentpanel.h"
#include "instrumentcircle.h"
//}}AFX_INCLUDES

#if !defined(AFX_GSTATIONDLG_H__2F0E8E42_83A5_43F8_955B_57C93E6F6EAB__INCLUDED_)
#define AFX_GSTATIONDLG_H__2F0E8E42_83A5_43F8_955B_57C93E6F6EAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StaticStatus.h"
#include "DlgToolBar.h"		// dialog toolbar

/////////////////////////////////////////////////////////////////////////////
// CGStationDlg dialog

#include "Setting.h"
#include "Parser.h"
#include "Msg_Telemetry.h"
#include "Msg_WayPoint.h"
#include "Msg_PhotoData.h"
#include "Msg_PhotoNum.h"

#include "PlaneUAV.h"
#include "WayPointEditDlg.h"

#include "DownGPSDlg.h"
#include "PIDAdjDlg.h"

class CFlyGPSPointRecord;

class CGStationDlg : public CDialog
{
// Construction
public:
	CGStationDlg(CWnd* pParent = NULL);	// standard constructor

	HACCEL hAccel;//添加快捷键

// Dialog Data
	//{{AFX_DATA(CGStationDlg)
	enum { IDD = IDD_GSTATION_DIALOG };
	CScrollBar	m_ctrlScrollBar;
	CSliderCtrl	m_ctrlSlider;
	CEdit	m_cReceivedPacketType;
	CMSComm	m_MSCom;
	CMapX	m_ctrlMapX;
	CCommonDialog1	m_comDlg;
	double	m_dTeleLongitude;
	double	m_dTeleLatitude;
	int  	m_iGPSSatellite;
	float	m_fTelePitch;
	float	m_fTeleRoll;
	float	m_fTeleDirection;
	int		m_iTargetWayPointNum;
	CString	m_strTeleGroundSpeed;
	int		m_iCPVDirection;
	int		m_iCPVSpeed;
	int		m_iTargetAirSpeed;
	CInstrumentPanel	m_ctrlPanel;
	CInstrumentCircle	m_ctrlCircle;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGStationDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	CDlgToolBar   m_wndToolBar; //工具栏
	CToolTipCtrl  m_CtrlTip;    //控件提示

	// Generated message map functions
	//{{AFX_MSG(CGStationDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMenuSetting();
	afx_msg void OnMenuMiddleValue();
	afx_msg void OnMenuMinWindDoor();
	afx_msg void OnMenuMaxWindDoor();
	afx_msg void OnMenuStopCarPosition();
	afx_msg void OnMenuListen();
	afx_msg void OnMenuPlayback();
	afx_msg void OnMenuPhotolocation();
	afx_msg void OnToolDownWaypoint();
	afx_msg void OnToolInquirePhotonum();
	afx_msg void OnToolDownPhotodata();
	afx_msg void OnToolHandPhotoOne();
	afx_msg void OnToolStartContinuePhoto();
	afx_msg void OnToolStopContinuePhoto();
	afx_msg void OnToolLayer();
	afx_msg void OnToolDistance();
	afx_msg void OnKickIdle();
	afx_msg void OnMenuMouseZoomInBig();
	afx_msg void OnMenuMouseZoomOutSmall();
	afx_msg void OnMenuMouseMove();
	afx_msg void OnMenuMouseSelectMove();
	afx_msg void OnMenuMouseArrow();
	afx_msg void OnMenuMouseCenter();
	afx_msg void OnOnCommMscomm();
	afx_msg void OnMouseDownMap(short Button, short Shift, float X, float Y);
	afx_msg void OnMouseMoveMap(short Button, short Shift, float X, float Y);
	afx_msg void OnPolyToolUsedMap(short ToolNum, long Flags, LPDISPATCH Points, BOOL bShift, BOOL bCtrl, BOOL FAR* EnableDefault);
	afx_msg void OnDrawUserLayerMap(LPDISPATCH Layer, long hOutputDC, long hAttributeDC, LPDISPATCH RectFull, LPDISPATCH RectInvalid);
	afx_msg void OnUpdateToolDistance(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolDownPhotodata(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolStartcontinuephoto(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolStopcontinuephoto(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolInquirePhotonum(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolDownWaypoint(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolHandphotoone(CCmdUI* pCmdUI);
	afx_msg void OnToolCenter();
	afx_msg void OnToolCleanTrack();
	afx_msg void OnUpdateToolCleanTrack(CCmdUI* pCmdUI);
	afx_msg void OnToolWaypointCopyDownToUp();
	afx_msg void OnUpdateToolWaypointCopyDownToUp(CCmdUI* pCmdUI);
	afx_msg void OnToolPromptWayline();
	afx_msg void OnUpdateToolPromptWayline(CCmdUI* pCmdUI);
	afx_msg void OnToolRect();
	afx_msg void OnToolShowUavWaypoint();
	afx_msg void OnToolSignPoint();
	afx_msg void OnUpdateToolSignPoint(CCmdUI* pCmdUI);
	afx_msg void OnToolSignLine();
	afx_msg void OnUpdateToolSignLine(CCmdUI* pCmdUI);
	afx_msg void OnToolSignPolyline();
	afx_msg void OnUpdateToolSignPolyline(CCmdUI* pCmdUI);
	afx_msg void OnToolSignPoly();
	afx_msg void OnUpdateToolSignPoly(CCmdUI* pCmdUI);
	afx_msg void OnToolMouseWaypoint();
	afx_msg void OnUpdateToolMouseWaypoint(CCmdUI* pCmdUI);
	afx_msg void OnCheckLayerWayline();
	afx_msg void OnCheckLayerSign();
	afx_msg void OnMenuOpenReceiver();
	afx_msg void OnMenuCloseReceiver();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonUAV();
	afx_msg void OnCheckWayPointStation();
	afx_msg void OnCheckFlyPlaneGPS();
	afx_msg void OnCheckWaypointdown();
	afx_msg void OnToolUpWayPoint();
	afx_msg void OnUpdateToolUpWaypoint(CCmdUI* pCmdUI);
	afx_msg void OnToolCleanWayPointDown();
	afx_msg void OnToolWayPointEdit();
	afx_msg void OnUpdateToolWayPointEdit(CCmdUI* pCmdUI);
	afx_msg void OnMenuMouseWayPointEdit();
	afx_msg void OnMenuMouseWayPointInsert();
	afx_msg void OnMenuMouseWayPointUpload();
	afx_msg void OnButtonSendTargetWPNum();
	afx_msg void OnMenuMouseWayPointDelete();
	afx_msg void OnMenuTakeOffCheck();
	afx_msg void OnMenuMouseSign();
	afx_msg void OnButtonPlay();
	afx_msg void OnButtonPause();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnMenuClose();
	afx_msg void OnReleasedcaptureSlider(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonCPV();
	afx_msg void OnButtonStopCar();
	afx_msg void OnButtonTest();
	afx_msg void OnCheckLayerSignShowSign();
	afx_msg void OnCheckMapGST();
	afx_msg void OnToolStandardWayLine();
	afx_msg void OnUpdateToolStandardWayLine(CCmdUI* pCmdUI);
	afx_msg void OnButtonCPVDirection();
	afx_msg void OnButtonCPVSpeed();
	afx_msg void OnMenuDownSteering();
	afx_msg void OnMenuDownGPS();
	afx_msg void OnMenuDownSensor();
	afx_msg void OnMenuDownMiddle();
	afx_msg void OnMenuDownTelemetry();
	afx_msg void OnMenuPid();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	afx_msg BOOL OnToolTipText(UINT nID, NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnUpdateCheckedLayerWayLine( CCmdUI* pCmdUI );
	afx_msg void OnUpdateCheckedLayerSign( CCmdUI* pCmdUI );
	afx_msg void OnUpdateCheckedLayerSignShowSign( CCmdUI* pCmdUI );
	afx_msg void OnUpdateCheckedWayPointStation( CCmdUI* pCmdUI );
	DECLARE_MESSAGE_MAP()

public:
	void OpenMapGST(CString strPathFileNameGST);	
	void OpenMapCreateOtherLayers(CString strDirectoryFileName);
	
	void OpenPort();
	void SendPacket(CPacket Packet);
	void HandleReceivedPacket(CPacket *ReceivedPacket);
	
	CSetting  *m_pSettingSheet;    //“设置”属性页
	CMapXPoints m_CMapXPoints;     //航点集合，用于在WayLine层画航线

	BOOL m_bWayPointStationIsExist;//“WayPointStation”层是否存在
	BOOL m_bSignLayerIsExist;      //“Sign”层是否存在

private:
	CString GetDirectory();              //得到当前路径函数，后面没有"\"
	BOOL FindLayer(CString strLayerName);//找到以strLayerName为名的图层
	
	CStaticStatus m_StaticStatus;//改变静态控件
	BOOL m_bIsReceivePacket;     //false时不接收数据包，true时接收并处理数据包。

	double m_DistancePreviousX;  //测量距离时，当前距离 = 鼠标点与此点的距离
	double m_DistancePreviousY;

	CParser m_Parser;            //数据包解析器
	CMsg_Telemetry m_Msg_Telemetry;
	CMsg_PhotoData m_Msg_PhotoData;
	CMsg_PhotoNum m_Msg_PhotoNum;

	void ShowTeleToDlg(CMsg_Telemetry Msg_Telemetry);

	CFlyGPSPointRecord *m_pFlyGPSPointRecord;//飞控GPS轨迹记录类，负责记录收到的遥控数据 
	CPlaneUAV m_PlaneUAV;                    //只负责移动飞机图标

	CWayPointEditDlg m_WPEditDlg;  //定义这里为了得到航点模板，否则增加航点时不停地读取ini.ini

	CDownGPSDlg DownGPSDlg;        //下传GPS数据对话框

	CPIDAdjDlg *m_pPIDAdjDlg;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GSTATIONDLG_H__2F0E8E42_83A5_43F8_955B_57C93E6F6EAB__INCLUDED_)
