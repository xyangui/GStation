#if !defined(AFX_EXPORT_H__7284EF31_0CC0_4988_9BD1_FECABABE532A__INCLUDED_)
#define AFX_EXPORT_H__7284EF31_0CC0_4988_9BD1_FECABABE532A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CJPEGExport;
class CPNGExport;
class CGIFExport;
class CBMPExport;
class CPCXExport;
class CMetafileExport;
class CNativeExport;
class CXMLExport;
class CXLSExport;
class CHTMLExport;
class CTextExport;

/////////////////////////////////////////////////////////////////////////////
// CExport wrapper class

class CExport : public COleDispatchDriver
{
public:
	CExport() {}		// Calls COleDispatchDriver default constructor
	CExport(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CExport(const CExport& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void CopyToClipboardBitmap();
	void CopyToClipboardMetafile(BOOL Enhanced);
	void SaveToBitmapFile(LPCTSTR FileName);
	void SaveToFile(LPCTSTR FileName);
	void SaveToJPEGFile(LPCTSTR FileName, BOOL Gray, long Performance, long Quality, long Width, long Height);
	void SaveToMetafile(LPCTSTR FileName);
	void SaveToMetafileEnh(LPCTSTR FileName);
	void ShowExport();
	CString SaveChartDialog();
	void ConvertTeeFileToText(LPCTSTR InputFile, LPCTSTR OutputFile);
	VARIANT Stream(long StreamType);
	CJPEGExport GetAsJPEG();
	CPNGExport GetAsPNG();
	CGIFExport GetAsGIF();
	CBMPExport GetAsBMP();
	CPCXExport GetAsPCX();
	CMetafileExport GetAsMetafile();
	CNativeExport GetAsNative();
	CXMLExport GetAsXML();
	CXLSExport GetAsXLS();
	CHTMLExport GetAsHTML();
	CTextExport GetAsText();
	void EmailFile(LPCTSTR FileName);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPORT_H__7284EF31_0CC0_4988_9BD1_FECABABE532A__INCLUDED_)
