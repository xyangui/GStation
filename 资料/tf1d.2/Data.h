// Data.h: interface for the CData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATA_H__8F6C549E_0C95_4E43_80EB_890F4FDF4F61__INCLUDED_)
#define AFX_DATA_H__8F6C549E_0C95_4E43_80EB_890F4FDF4F61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CData  
{
public:
	CData();
	virtual ~CData();

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
	}m_Potdata[200];
};

#endif // !defined(AFX_DATA_H__8F6C549E_0C95_4E43_80EB_890F4FDF4F61__INCLUDED_)
