// Msg_PhotoNum.cpp: implementation of the CMsg_PhotoNum class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "Msg_PhotoNum.h"

#include "Payload.h"
#include "Packet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMsg_PhotoNum::CMsg_PhotoNum()
{

}

CMsg_PhotoNum::~CMsg_PhotoNum()
{

}

const int CMsg_PhotoNum::MSG_ID = 0x2f;//命令类型
const int CMsg_PhotoNum::MSG_SIZE_PAYLOAD_LENGTH = 2;//不包括命令类型、大小、校验和，共2个字节

void CMsg_PhotoNum::Unpack(CPayload payload)
{
	payload.resetIndex();
	m_iPhotoNum = payload.getU2();
}

CPacket CMsg_PhotoNum::Pack()
{
	CPacket  packet;
	packet.m_msgid = MSG_ID;
	packet.m_len = 0;

	packet.generateCRC();

	return packet;
}

