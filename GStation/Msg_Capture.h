// Msg_Capture.h: interface for the CMsg_Capture class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MSG_CAPTURE_H__7F36D85A_7232_4D30_B3D2_F482CC4D281B__INCLUDED_)
#define AFX_MSG_CAPTURE_H__7F36D85A_7232_4D30_B3D2_F482CC4D281B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Message.h"
class CPacket;

class CMsg_Capture : public CMessage  
{
public:
	CMsg_Capture();
	virtual ~CMsg_Capture();

	static const int MSG_ID;
	static const int MSG_SIZE_PAYLOAD_LENGTH;

	CPacket GetMiddleValuePack();
	CPacket GetMinWindDoorPack();
	CPacket GetMaxWindDoorPack();
	CPacket GetStopCarPositionPack();
};

#endif // !defined(AFX_MSG_CAPTURE_H__7F36D85A_7232_4D30_B3D2_F482CC4D281B__INCLUDED_)
