// Msg_PhotoNum.h: interface for the CMsg_PhotoNum class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MSG_PHOTONUM_H__2E44AD7C_0C66_4E6A_BDE1_30DCF8864819__INCLUDED_)
#define AFX_MSG_PHOTONUM_H__2E44AD7C_0C66_4E6A_BDE1_30DCF8864819__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Message.h"
class CPayload;
class CPacket;

class CMsg_PhotoNum : public CMessage  
{
public:
	CMsg_PhotoNum();
	virtual ~CMsg_PhotoNum();

	static const int MSG_ID;
	static const int MSG_SIZE_PAYLOAD_LENGTH;
	
	void Unpack(CPayload payload);
	CPacket Pack();

	int m_iPhotoNum;
};

#endif // !defined(AFX_MSG_PHOTONUM_H__2E44AD7C_0C66_4E6A_BDE1_30DCF8864819__INCLUDED_)
