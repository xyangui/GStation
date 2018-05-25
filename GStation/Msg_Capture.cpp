// Msg_Capture.cpp: implementation of the CMsg_Capture class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "Msg_Capture.h"

#include "Packet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMsg_Capture::CMsg_Capture()
{

}

const int CMsg_Capture::MSG_ID = 0x03;//命令类型，十进制3
const int CMsg_Capture::MSG_SIZE_PAYLOAD_LENGTH = 1;//不包括命令类型、大小、校验和，共1个字节

CMsg_Capture::~CMsg_Capture()
{

}

CPacket CMsg_Capture::GetMiddleValuePack()
{
	CPacket  packet;
	packet.m_msgid = MSG_ID;
	packet.m_len = MSG_SIZE_PAYLOAD_LENGTH;

	packet.payload.putU1(0);
	packet.generateCRC();

	return packet;
}


CPacket CMsg_Capture::GetMinWindDoorPack()
{
	CPacket  packet;
	packet.m_msgid = MSG_ID;
	packet.m_len = MSG_SIZE_PAYLOAD_LENGTH;

	packet.payload.putU1(2);
	packet.generateCRC();

	return packet;
}

CPacket CMsg_Capture::GetMaxWindDoorPack()
{
	CPacket  packet;
	packet.m_msgid = MSG_ID;
	packet.m_len = MSG_SIZE_PAYLOAD_LENGTH;

	packet.payload.putU1(1);
	packet.generateCRC();

	return packet;
}

CPacket CMsg_Capture::GetStopCarPositionPack()
{
	CPacket  packet;
	packet.m_msgid = MSG_ID;
	packet.m_len = MSG_SIZE_PAYLOAD_LENGTH;

	packet.payload.putU1(3);
	packet.generateCRC();

	return packet;
}
