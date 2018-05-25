// IniFile.h: interface for the CIniFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INIFILE_H__5E72B83B_B834_498F_98CB_A460D979B268__INCLUDED_)
#define AFX_INIFILE_H__5E72B83B_B834_498F_98CB_A460D979B268__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CIniFile  
{
public:
	CIniFile(CString strDirectory);
	virtual ~CIniFile();

	int	m_iBT;  //²¨ÌØÂÊ
	int	m_iCom; //´®¿Ú
};

#endif // !defined(AFX_INIFILE_H__5E72B83B_B834_498F_98CB_A460D979B268__INCLUDED_)
