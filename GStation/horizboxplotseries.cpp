// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "horizboxplotseries.h"

// Dispatch interfaces referenced by this interface
#include "Pointer.h"
#include "pen.h"


/////////////////////////////////////////////////////////////////////////////
// CHorizBoxPlotSeries properties

/////////////////////////////////////////////////////////////////////////////
// CHorizBoxPlotSeries operations

CPointer CHorizBoxPlotSeries::GetPointer()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CPointer(pDispatch);
}

BOOL CHorizBoxPlotSeries::GetDark3D()
{
	BOOL result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CHorizBoxPlotSeries::SetDark3D(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CPointer CHorizBoxPlotSeries::GetExtrOut()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CPointer(pDispatch);
}

CPen1 CHorizBoxPlotSeries::GetMedianPen()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CPen1(pDispatch);
}

CPointer CHorizBoxPlotSeries::GetMildOut()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CPointer(pDispatch);
}

double CHorizBoxPlotSeries::GetPosition()
{
	double result;
	InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

void CHorizBoxPlotSeries::SetPosition(double newValue)
{
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

double CHorizBoxPlotSeries::GetWhiskerLength()
{
	double result;
	InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

void CHorizBoxPlotSeries::SetWhiskerLength(double newValue)
{
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

CPen1 CHorizBoxPlotSeries::GetWhiskerPen()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CPen1(pDispatch);
}

CPointer CHorizBoxPlotSeries::GetBox()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CPointer(pDispatch);
}

double CHorizBoxPlotSeries::MaxYValue()
{
	double result;
	InvokeHelper(0x9, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
	return result;
}

double CHorizBoxPlotSeries::MinYValue()
{
	double result;
	InvokeHelper(0xa, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
	return result;
}
