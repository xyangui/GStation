// TF1DDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mapx.h"
#include "mscomm.h"
#include "commondialog.h"
#include "_meter.h"
#include "air.h"
#include "data.h"
#include "downpoints.h"
#include "commondialog1.h"
//}}AFX_INCLUDES

#if !defined(AFX_TF1DDLG_H__F37848E4_745A_4DFE_ADF4_85EEEDA2A03D__INCLUDED_)
#define AFX_TF1DDLG_H__F37848E4_745A_4DFE_ADF4_85EEEDA2A03D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "buttonxp.h"
/////////////////////////////////////////////////////////////////////////////
// CTF1DDlg dialog

class CTF1DDlg : public CDialog
{
// Construction
public:
	CString m_sBt;
	void OnFileInit();
	void OnDrawPhotoShow(double lon,double lat,int num,double heading);
	LONG m_nDataLength;//////////数据长度
	unsigned char* pData;////////数据指针
	UINT m_nTimeFlag;
	LONG m_nDataPos;
	BOOL m_bFilesaveFlag;
	BOOL m_bTime2Flag;
	int m_nDatashowspeed;
	LONG m_lDatashowpoint;
	CString str_parth;
	CFile *fpini;
	char m_pBuff[100];
	void OnFileSaveText();
	CString m_sYaoce_Data_Save;
	void OnFileSaveRecord(int m_num);
	int m_nTotalNum_Timer;//计数器更新调用前语句总量
	int m_nTotalNum;///语句总量统计
	int m_nPhotoNum;
	void OnPhotoNumOperate(CString str,int num);
	void OnDrowDownPot(int num);
	BOOL fpFlag;
	CFile fp;
	CFile m_fp_Record;///回放记录文件
	CFile m_fp_Text; ////数据记录文件
	void OnFileSavePhotoData(CString str);
	void OnPhotoDataOperate(CString str,int num);
	long IDofFeature;
	void OnDownpotOperate(CString str,int num);
	char ConvertHexChar(char ch);
	int String2Hex(CString str, CByteArray &senddata);
	void OnUpdatePointFeatures();
	void OnUpdateMeter();
	void OnDrawPoint(double lon,double lat,int angle);
	int m_dNumLength_Yaoce;
	void OnRangePointsToMap(double lon,double lat);
	int m_dRange_Num;
	double m_Range1_Lat;
	double m_Range1_Lon;
	int m_InsertPoint_Key;//////插入航点序号
	void OnInsertPointToMap();

	void OnPointToMap();
	BOOL m_Flag_Point;
	void OnDeleteFeatures();
	int m_Row_Values_Remove[200];
	int m_dFtrsNum;//已有图元数量
	void OnGetLayerPoints();
	BOOL m_bMouseUpOK;
	CMapXDataset m_dataset;
	CMapXSelection m_Features_Select;
	void OnSomeDataInit();
	CMapXPoints m_pts;
	CString m_sLayerName_Points;
	void OnCreateOtherLayers();
//	CMapXLayer lay;
	void OnOpenMap(CString directer,CString name);
	void OnOpenLayer(CString directer,CString name);
	void OnNewLayer(CString directer,CString name);
	double m_lfDistance_All;
	short m_MapToolNum;
	double m_lfLat_MouseDown;
	double m_lfLon_MouseDown;
	void OnSafedataInit();
	void OnStaticUpdate();
	CString m_sStrReceived;
	int m_nstrnum;
	BOOL bReceive;
	void OnYaoceDataOperate(CString str,int num);
	int m_nCommandType;
	void OnOperateStr(CString str,int num);
	void GiveStrZero(int num);
	BOOL m_bHead;
	void GetStrReceived(CString str);

	struct LAYERCONTRAL{
		int m_nFlag;
		CString m_sLayerName;
		CString m_sLayerDirecte;
	} m_Layercontral;/////////////////////图层控制返回状态
	struct POINTDATA{
		int num;
		double lon;
		double lat;
		int alt;
		int spd;
		int raid;
		int time;
		int linetype;
		bool toline;
		bool toground;
		bool toslide;
		bool photo;
		bool serv1;
		bool serv2;
		bool serv3;
	} m_Potdata[200];/////////////////////航点信息结构体
	POINTDATA m_Potdata_Down[200]; ///////存储下载的航点信息

	struct PHOTODATA{
		int num;
		double time;
		double lon;
		double lat;
		long alt;
		double pitch;
		double roll;
		double heading;
	}m_Photodata;

	CData potdata;
	struct GPSDATA{
		int m_nStatus;//定位情况
		int m_nPod;  //定位质量
		int m_nSatnum;//卫星数量
		double m_dLat;
		double m_dLon;
		double m_dGPSalt;
		double m_dGPSspd;
		double m_dHangxiang;
	};/////////////////////////////////卫星信息结构体

	struct YAOCEDATA{
		int m_nContralmodel;
		GPSDATA m_GPSdata;
		double m_dRoll;
		double m_dPitch;
		int m_nTargetWP;
		int m_nRPM;
		int m_nAirspd;
		int m_nDesired_Airspd;
		int m_nAiralt;
		int m_nDesired_Airalt;
		int m_nDesired_Heading;
		int m_nCurrentstatus;
		int m_nCte;///////////////////偏航距
		int m_nPatterntime;///////////制式航线飞行剩余时间
		int m_nStatus1;
		int m_nStatus2;///////////////第二发动机转速

		double m_fAirPress;///////////气压
//		double m_nWendu;
		double m_nDianya_Duoji;
		double m_nDianya_UAV;
		double m_fTempr;//////////////温度
//		double m_nWendu_Dianzu;
		int m_nRSSI;//////////////////接收机信号强度保留
		int check;
		double m_dGPSTime;////////////GPS时间
	}m_Yaoce_Data;///////////////////遥测数据结构体

	struct SAFEDATA{
		int	m_nAir_Max;
		int	m_nAir_Min;
		int	m_nHigh_Min;
		int	m_nPasheng_Max;
		int	m_nPasheng_Min;
		double	m_nServV_Max;
		double	m_nServV_Min;
		double	m_nUAVV_Max;
		double	m_nUAVV_Min;
	}m_Safe_data;

	struct DOWNPOT{
		int totalnum;
		int num;
		int lon4;
		int lon3;
		int lon2;
		int lon1;
		int lat4;
		int lat3;
		int lat2;
		int lat1;
		int alt_h;
		int alt_l;
		int spd;
		int r_h;
		int r_l;
		int flag;
		int time;
		int task;
		int check;
	}m_Down_Pot;

	POINTDATA m_model_Potdata;
	void OpenPort();
	int m_nPort;
	CString m_strSettings;
	int m_nButton_Flag;//作为各个自定义及原有工具使用时的鉴别标志
	void OnButtonInit();
	void OnCreateStatic();
	void CreateToolBar();
////////////////////////////////
//     动态创建静态文本框     //
////////////////////////////////
	CStatic static_bg;
	CStatic yingda;
	CStatic yingdaled;
	CStatic tongxun;
	CStatic tongxunled;
	CStatic moshi;
	CStatic moshiled;
	CStatic GPS;
	CStatic GPSled;
	CStatic weixing;
	CStatic weixingled;
	CStatic dianya_duoji;
	CStatic dianya_duojiled;
	CStatic dianya_zong;
	CStatic dianya_zongled;
	CStatic wendu;
	CStatic wenduled;
	CStatic GPSTime;
	CStatic GPSTimeled;
	CStatic qiya;
	CStatic qiyaled;
//	CStatic xitongshijian;

	CStatic pianhang;
	CStatic distance_zeropoint;
	CStatic distance_currentpoint;
	CStatic shengdian;
	CStatic zhishishijian;
	CStatic pianhang1;
	CStatic distance_zeropoint1;
	CStatic distance_currentpoint1;
	CStatic shengdian1;
	CStatic zhishishijian1;

	CStatic mousepoint;
	CStatic mousepoint1;
	CStatic currentpoint;
	CStatic currentpoint1;
	CStatic distancepoints;
	CStatic distancepoints1;
	CStatic desireddistance1;
	CStatic desireddistance;
	CStatic realdistance1;
	CStatic realdistance;
	CStatic remaindistance1;
	CStatic remaindistance;

	CStatic receiverled;
////////////////////////////////
/*
////////////////////////////////
controlmode	U1	控制模式
	24	GPS数据（详见前）
roll	I2	滚转角*10
pitch	I2	俯仰角*10
TargetWP	U1	目标航点
rpm	U1	发动机转速(转/秒)
tas	I2	空速*10(m/s)
Desired_tas	U1	目标空速（米/秒）
alt	I2	气压高度（米）
Desired_alt	I2	目标高度
Desired_heading	I2	目标航向*10（度）
currentstatus	U1	当前飞行状况
cte	I2	偏航距(米)
patterntime	U2h	制式飞行剩余时间
Status1	U1	飞行状况
Status2	U1	飞行状况

////////////////////////////////
*/
////////////////////////////////
	CToolBar toolbar;

	CTF1DDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTF1DDlg)
	enum { IDD = IDD_UP20_DIALOG };
	CEdit	m_cTotalDis;
	CEdit	m_cShowSpeed;
	CEdit	m_cShowSite;
	CSliderCtrl	m_cSiteSlider;
	CButtonXP	m_cSendtargetpoint;
	CButtonXP	m_cOpenCPV;
	CButtonXP	m_cCPVspeed;
	CButtonXP	m_cCPVheading;
	CButtonXP	m_cCPValt;
	CButtonXP	m_cBegainfly;
	CButton	m_cCopyPoints;
	CSliderCtrl	m_cSpeedSlider;
	CEdit	m_cFrequency;
	CEdit	m_cPhotoNum;
	CEdit	m_cDataStyle;
	CButtonXP	m_cClosereceive;
	CButton	m_cSeriatePhotoStop;
	CButton	m_cAskPhotoNum;
	CButton	m_cDownPhotoData;
	CButton	m_cHeadingPhoto;
	CButton	m_cSeriatePhoto;
	CEdit	m_cPoint_Target;
	CButton	m_cDownloadPoints;
	CButton	m_cUploadPoint;
	CEdit	m_cRoll;
	CEdit	m_cPitch;
	CEdit	m_cHeading;
	CButton	m_cRangePoints;
	CButton	m_cCheckLine;
	CButton	m_cDistance;
	CButtonXP	m_cPotdata;
	CButton	m_cPoints;
	CButton	m_cAirow;
	CButton	m_cLayersCtr;
	CButton	m_cMove;
	CButton	m_cSelect;
	CButton	m_cSelectRect;
	CButton	m_cZoomOut;
	CButton	m_cZoomIn;
	CMapX	m_cMap;
	CMSComm	m_Com;
	CCommonDialog1	m_comDlg;
	BOOL	m_bCheckLine;
	BOOL	m_bMapSelectable;
	C_Meter	m_cMeter_Alt;
	C_Meter	m_cMeter_Head;
	C_Meter	m_cMeter_Rpm;
	C_Meter	m_cMeter_Spd;
	CAir	m_cAirctrl;
	int		m_nPoint_Target;
	int		m_Point_Target_Send;
	BOOL	m_bCheckRealLine;
	BOOL	m_bCheckUpLine;
	CCommonDialog2	m_comDlg2;
	int		m_nFlyspeed;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTF1DDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	void OnPolyToolUsedMap(short ToolNum, long Flags, LPDISPATCH Points, BOOL bShift, BOOL bCtrl, BOOL FAR* EnableDefault);
//	void OnPointToolUsedMap(short ToolNum, long Flags, LPDISPATCH Points, BOOL bShift, BOOL bCtrl, BOOL FAR* EnableDefault);


	// Generated message map functions
	//{{AFX_MSG(CTF1DDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnTool();
	afx_msg void OnUpdateTool(CCmdUI* pCmdUI);
	afx_msg void OnMouseDownMap(short Button, short Shift, float X, float Y);
	afx_msg void OnAirow();
	afx_msg void OnLayersctr();
	afx_msg void OnMove();
	afx_msg void OnPoints();
	afx_msg void OnSelect();
	afx_msg void OnSelectrect();
	afx_msg void OnZoomin();
	afx_msg void OnZoomout();
	afx_msg void OnPortset();
	afx_msg void OnOnCommMscomm();
	afx_msg void OnPotdata();
	afx_msg void OnDataget();
	afx_msg void OnSafeset();
	afx_msg void OnMouseMoveMap(short Button, short Shift, float X, float Y);
	afx_msg void OnDistance();
	afx_msg void OnUploadpoint();
	afx_msg void OnInsertpoint();
	afx_msg void OnLayercontral();
	afx_msg void OnCheckline();
	afx_msg void OnMouseUpMap(short Button, short Shift, float X, float Y);
	afx_msg void OnCheckmapselectable();
	afx_msg void OnKeyDownMap(short FAR* KeyCode, short Shift);
	afx_msg void OnMapDrawMap(short Flag);
	afx_msg void OnKeyUpMap(short FAR* KeyCode, short Shift);
	afx_msg void OnRangepoints();
	afx_msg void OnDownloadpoints();
	afx_msg void OnSendtargetpoint();
	afx_msg void OnUavset();
	afx_msg void OnMenuBuhuoZhongli();
	afx_msg void OnMenuBuhuoStopoil();
	afx_msg void OnMenuBuhuoMinoil();
	afx_msg void OnMenuBuhuoMaxoil();
	afx_msg void OnSeriatephoto();
	afx_msg void OnSeriatephotostop();
	afx_msg void OnHeadingphoto();
	afx_msg void OnDownphotodata();
	afx_msg void OnAskphotonum();
	afx_msg void OnClosereceive();
	afx_msg void OnCheckupline();
	afx_msg void OnCheckrealline();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnReleasedcaptureSpeedslider(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnUploadsomepoint();
	afx_msg void OnCopypoints();
	afx_msg void OnDatashow();
	afx_msg void OnYaocedata();
	afx_msg void OnYaocedatastop();
	afx_msg void OnBegainfly();
	virtual void OnCancel();
	afx_msg void OnReleasedcaptureSiteslide(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPicshow();
	afx_msg void OnBplaysiteSet();
	afx_msg void OnLineComputer();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TF1DDLG_H__F37848E4_745A_4DFE_ADF4_85EEEDA2A03D__INCLUDED_)
