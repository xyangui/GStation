// Msg_PhotoMode.cpp: implementation of the CMsg_PhotoMode class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "Msg_PhotoMode.h"

#include "Packet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMsg_PhotoMode::CMsg_PhotoMode()
{

}

const int CMsg_PhotoMode::MSG_ID = 0x2c;//��������
const int CMsg_PhotoMode::MSG_SIZE_PAYLOAD_LENGTH = 1;//�������������͡���С��У��ͣ���1���ֽ�

CMsg_PhotoMode::~CMsg_PhotoMode()
{

}

CPacket CMsg_PhotoMode::GetStopContinuePhotoPack()
{
	CPacket  packet;
	packet.m_msgid = MSG_ID;
	packet.m_len = MSG_SIZE_PAYLOAD_LENGTH;

	packet.payload.putU1(0);
	packet.generateCRC();

	return packet;
}

CPacket CMsg_PhotoMode::GetStartContinuePhotoPack()
{
	CPacket  packet;
	packet.m_msgid = MSG_ID;
	packet.m_len = MSG_SIZE_PAYLOAD_LENGTH;

	packet.payload.putU1(1);
	packet.generateCRC();

	return packet;
}

CPacket CMsg_PhotoMode::GetHandPhotoOnePack()
{
	CPacket  packet;
	packet.m_msgid = MSG_ID;
	packet.m_len = MSG_SIZE_PAYLOAD_LENGTH;

	packet.payload.putU1(2);
	packet.generateCRC();

	return packet;
}
