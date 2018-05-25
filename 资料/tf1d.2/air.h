#if !defined(AFX_AIR_H__7CB88DC8_349C_4056_B624_46DDD0F44554__INCLUDED_)
#define AFX_AIR_H__7CB88DC8_349C_4056_B624_46DDD0F44554__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CPicture;
class COleFont;

/////////////////////////////////////////////////////////////////////////////
// CAir wrapper class

class CAir : public CWnd
{
protected:
	DECLARE_DYNCREATE(CAir)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x902703a3, 0x6587, 0x11cf, { 0xbc, 0x8b, 0x20, 0x74, 0x2, 0xc1, 0x6, 0x27 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:
	BOOL GetEnabled();
	void SetEnabled(BOOL);
	CPicture GetBackPicture();
	void SetBackPicture(LPDISPATCH);
	COleFont GetFont();
	void SetFont(LPDISPATCH);
	short GetFonts();
	void SetFonts(short);
	long GetBevelInner();
	void SetBevelInner(long);
	long GetBevelOuter();
	void SetBevelOuter(long);
	short GetBevelWidth();
	void SetBevelWidth(short);
	short GetBorderWidth();
	void SetBorderWidth(short);
	long GetOutlineAlign();
	void SetOutlineAlign(long);
	unsigned long GetOutlineColor();
	void SetOutlineColor(unsigned long);
	CString GetOutlineTitle();
	void SetOutlineTitle(LPCTSTR);
	short GetOutlineWidth();
	void SetOutlineWidth(short);
	double GetHeadingIndicator();
	void SetHeadingIndicator(double);
	double GetCompassHeading();
	void SetCompassHeading(double);
	long GetFrameStyle();
	void SetFrameStyle(long);
	unsigned long GetFrameColor();
	void SetFrameColor(unsigned long);
	CString GetFrameShape();
	void SetFrameShape(LPCTSTR);
	double GetFrameLeft();
	void SetFrameLeft(double);
	double GetFrameTop();
	void SetFrameTop(double);
	double GetFrameRight();
	void SetFrameRight(double);
	double GetFrameBottom();
	void SetFrameBottom(double);
	CPicture GetFramePicture();
	void SetFramePicture(LPDISPATCH);
	long GetAltBarometerStyle();
	void SetAltBarometerStyle(long);
	long GetAltThousandStyle();
	void SetAltThousandStyle(long);
	double GetAltBarometer();
	void SetAltBarometer(double);
	double GetAltitude();
	void SetAltitude(double);
	CString GetCaption();
	void SetCaption(LPCTSTR);
	short GetCaptions();
	void SetCaptions(short);
	double GetCaptionX();
	void SetCaptionX(double);
	double GetCaptionY();
	void SetCaptionY(double);
	short GetCaptionFontID();
	void SetCaptionFontID(short);
	unsigned long GetCaptionColor();
	void SetCaptionColor(unsigned long);
	double GetAirspeed();
	void SetAirspeed(double);
	double GetAirspeedVFE();
	void SetAirspeedVFE(double);
	double GetAirspeedVMax();
	void SetAirspeedVMax(double);
	double GetAirspeedVNE();
	void SetAirspeedVNE(double);
	double GetAirspeedVNO();
	void SetAirspeedVNO(double);
	double GetAirspeedVS0();
	void SetAirspeedVS0(double);
	double GetAirspeedVS1();
	void SetAirspeedVS1(double);
	OLE_COLOR GetBackColor();
	void SetBackColor(OLE_COLOR);
	long GetCompassStyle();
	void SetCompassStyle(long);
	long GetDisplayMode();
	void SetDisplayMode(long);
	BOOL GetMouseControl();
	void SetMouseControl(BOOL);
	double GetAltBarometerX();
	void SetAltBarometerX(double);
	double GetAltBarometerY();
	void SetAltBarometerY(double);
	double GetAltThousandX();
	void SetAltThousandX(double);
	double GetAltThousandY();
	void SetAltThousandY(double);
	short GetAltBarometerFontID();
	void SetAltBarometerFontID(short);
	short GetAltThousandFontID();
	void SetAltThousandFontID(short);
	double GetClimbRate();
	void SetClimbRate(double);
	double GetClimbRateMax();
	void SetClimbRateMax(double);
	unsigned long GetTicColor();
	void SetTicColor(unsigned long);
	unsigned long GetNeedleColor();
	void SetNeedleColor(unsigned long);
	BOOL GetHSICompass();
	void SetHSICompass(BOOL);
	double GetHSIBearing();
	void SetHSIBearing(double);
	double GetHSIHeading();
	void SetHSIHeading(double);
	double GetHSIGlideSlopeDelta();
	void SetHSIGlideSlopeDelta(double);
	double GetHSIGlideSlopeDeviation();
	void SetHSIGlideSlopeDeviation(double);
	double GetHSICourseHeading();
	void SetHSICourseHeading(double);
	long GetHSINavigationSource();
	void SetHSINavigationSource(long);
	double GetHSICourseDelta();
	void SetHSICourseDelta(double);
	double GetHSICourseDeviation();
	void SetHSICourseDeviation(double);
	BOOL GetHSIBug();
	void SetHSIBug(BOOL);
	double GetHSIBugHeading();
	void SetHSIBugHeading(double);
	long GetHSINavPointer();
	void SetHSINavPointer(long);
	unsigned long GetHSIBearingColor();
	void SetHSIBearingColor(unsigned long);
	unsigned long GetHSICourseColor();
	void SetHSICourseColor(unsigned long);
	CString GetHSINavMarker();
	void SetHSINavMarker(LPCTSTR);
	unsigned long GetHSIBugColor();
	void SetHSIBugColor(unsigned long);
	long GetHSICourseDisplay();
	void SetHSICourseDisplay(long);
	double GetHSIDistance();
	void SetHSIDistance(double);
	long GetHSIDistanceDisplay();
	void SetHSIDistanceDisplay(long);
	double GetHSISpeed();
	void SetHSISpeed(double);
	double GetHSITime();
	void SetHSITime(double);
	long GetHSITimeSpeedDisplay();
	void SetHSITimeSpeedDisplay(long);
	double GetAHPitch();
	void SetAHPitch(double);
	double GetAHRoll();
	void SetAHRoll(double);
	unsigned long GetAHGroundColor();
	void SetAHGroundColor(unsigned long);
	unsigned long GetAHSkyColor();
	void SetAHSkyColor(unsigned long);
	double GetAHPitchRange();
	void SetAHPitchRange(double);
	double GetAHPitchScale();
	void SetAHPitchScale(double);
	long GetAHPitchStyle();
	void SetAHPitchStyle(long);
	double GetAHHeading();
	void SetAHHeading(double);
	long GetAHHeadingStyle();
	void SetAHHeadingStyle(long);
	BOOL GetAHBug();
	void SetAHBug(BOOL);
	unsigned long GetAHBugColor();
	void SetAHBugColor(unsigned long);
	double GetAHBugHeading();
	void SetAHBugHeading(double);
	double GetAHHeadingScale();
	void SetAHHeadingScale(double);
	double GetAHHeadingOffset();
	void SetAHHeadingOffset(double);
	long GetAHReferenceStyle();
	void SetAHReferenceStyle(long);
	unsigned long GetAHReferenceColor();
	void SetAHReferenceColor(unsigned long);
	double GetTCInclinometer();
	void SetTCInclinometer(double);
	double GetTCTurn();
	void SetTCTurn(double);
	double GetCIActCourse();
	void SetCIActCourse(double);
	double GetCIOrdCourse();
	void SetCIOrdCourse(double);
	double GetADFBearing();
	void SetADFBearing(double);
	double GetRMICompass();
	void SetRMICompass(double);
	BOOL GetOBIArcFlag();
	void SetOBIArcFlag(BOOL);
	BOOL GetOBIBackCourse();
	void SetOBIBackCourse(BOOL);
	double GetOBICourse();
	void SetOBICourse(double);
	double GetOBICourseDeviation();
	void SetOBICourseDeviation(double);
	double GetOBIGlideSlope();
	void SetOBIGlideSlope(double);
	BOOL GetOBIGSFlag();
	void SetOBIGSFlag(BOOL);
	BOOL GetOBINAVFlag();
	void SetOBINAVFlag(BOOL);
	long GetOBIToFrom();
	void SetOBIToFrom(long);
	BOOL GetOutline();
	void SetOutline(BOOL);
	short GetCaptionID();
	void SetCaptionID(short);
	short GetFontID();
	void SetFontID(short);
	long GetCaptionFlag();
	void SetCaptionFlag(long);
	BOOL GetAutoRedraw();
	void SetAutoRedraw(BOOL);
	float GetFontSize();
	void SetFontSize(float);
	BOOL GetFontBold();
	void SetFontBold(BOOL);
	BOOL GetFontItalic();
	void SetFontItalic(BOOL);
	BOOL GetFontStrikethru();
	void SetFontStrikethru(BOOL);
	BOOL GetFontUnderline();
	void SetFontUnderline(BOOL);
	CString GetFontName();
	void SetFontName(LPCTSTR);
	double GetValue();
	void SetValue(double);
	double GetRMIBearing1();
	void SetRMIBearing1(double);
	double GetRMIBearing2();
	void SetRMIBearing2(double);
	long GetRMIBearingType1();
	void SetRMIBearingType1(long);
	long GetRMIBearingType2();
	void SetRMIBearingType2(long);
	unsigned long GetRMIBearingColor1();
	void SetRMIBearingColor1(unsigned long);
	unsigned long GetRMIBearingColor2();
	void SetRMIBearingColor2(unsigned long);
	CString GetHeadingShape();
	void SetHeadingShape(LPCTSTR);
	unsigned long GetAltBarometerColor();
	void SetAltBarometerColor(unsigned long);
	BOOL GetSingleBuffer();
	void SetSingleBuffer(BOOL);
	long GetAHFlightDirector();
	void SetAHFlightDirector(long);
	double GetAHCuePitch();
	void SetAHCuePitch(double);
	double GetAHCueRoll();
	void SetAHCueRoll(double);
	unsigned long GetAHFlightDirectorColor();
	void SetAHFlightDirectorColor(unsigned long);
	BOOL GetFocusOutline();
	void SetFocusOutline(BOOL);
	OLE_HANDLE GetHWnd();
	void SetHWnd(OLE_HANDLE);
	short Get_DisplayMode();
	void Set_DisplayMode(short);

// Operations
public:
	void Redraw();
	void RedrawStatic();
	void ShowPropertyPage();
	void AboutBox();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AIR_H__7CB88DC8_349C_4056_B624_46DDD0F44554__INCLUDED_)
