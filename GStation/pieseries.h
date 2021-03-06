#if !defined(AFX_PIESERIES_H__457C3CAD_9620_4140_925D_87EA5B1B3E21__INCLUDED_)
#define AFX_PIESERIES_H__457C3CAD_9620_4140_925D_87EA5B1B3E21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CValueList;
class CPieOtherSlice;
class CExplodedSlices;
class CPen1;
class CTeeShadow;

/////////////////////////////////////////////////////////////////////////////
// CPieSeries wrapper class

class CPieSeries : public COleDispatchDriver
{
public:
	CPieSeries() {}		// Calls COleDispatchDriver default constructor
	CPieSeries(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CPieSeries(const CPieSeries& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetXRadius();
	void SetXRadius(long nNewValue);
	long GetYRadius();
	void SetYRadius(long nNewValue);
	long GetXCenter();
	long GetYCenter();
	long GetCircleWidth();
	long GetCircleHeight();
	unsigned long GetCircleBackColor();
	void SetCircleBackColor(unsigned long newValue);
	BOOL GetCircled();
	void SetCircled(BOOL bNewValue);
	long GetRotationAngle();
	void SetRotationAngle(long nNewValue);
	// method 'AngleToPoint' not emitted because of invalid return type or parameter type
	double PointToAngle(long XCoord, long YCoord);
	BOOL GetUsePatterns();
	void SetUsePatterns(BOOL bNewValue);
	CValueList GetPieValues();
	BOOL GetDark3D();
	void SetDark3D(BOOL bNewValue);
	long GetExplodeBiggest();
	void SetExplodeBiggest(long nNewValue);
	CPieOtherSlice GetOtherSlice();
	CExplodedSlices GetExplodedSlice();
	CPen1 GetPiePen();
	CTeeShadow GetShadow();
	long GetAngleSize();
	void SetAngleSize(long nNewValue);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIESERIES_H__457C3CAD_9620_4140_925D_87EA5B1B3E21__INCLUDED_)
