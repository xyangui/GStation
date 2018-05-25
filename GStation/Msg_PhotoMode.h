// Msg_PhotoMode.h: interface for the CMsg_PhotoMode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MSG_PHOTOMODE_H__329F2C42_F3AA_46D5_A39B_C7A8F3B4329A__INCLUDED_)
#define AFX_MSG_PHOTOMODE_H__329F2C42_F3AA_46D5_A39B_C7A8F3B4329A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Message.h"
class CPacket;

class CMsg_PhotoMode : public CMessage  
{
public:
	CMsg_PhotoMode();
	virtual ~CMsg_PhotoMode();

	static const int MSG_ID;
	static const int MSG_SIZE_PAYLOAD_LENGTH;

	CPacket GetStopContinuePhotoPack();
	CPacket GetStartContinuePhotoPack();
	CPacket GetHandPhotoOnePack();
};

#endif // !defined(AFX_MSG_PHOTOMODE_H__329F2C42_F3AA_46D5_A39B_C7A8F3B4329A__INCLUDED_)
