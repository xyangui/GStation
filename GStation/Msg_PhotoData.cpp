// Msg_PhotoData.cpp: implementation of the CMsg_PhotoData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "Msg_PhotoData.h"

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

CMsg_PhotoData::CMsg_PhotoData()
{
	
}

const int CMsg_PhotoData::MSG_ID = 0x2e;//命令类型，十进制46
const int CMsg_PhotoData::MSG_SIZE_PAYLOAD_LENGTH = 24;//不包括命令类型、大小、校验和，共24个字节

CMsg_PhotoData::~CMsg_PhotoData()
{

}

void CMsg_PhotoData::Unpack(CPayload payload)
{
	payload.resetIndex();
	num = payload.getU2();
	time = (double)payload.getU4h();
	lon = (double)payload.getI4h() / 10000000;
	lat = (double)payload.getI4h() / 10000000;
	alt = payload.getI4h() / 1000;//long是长整型，这里整除了吧
	pitch = (double)payload.getI2() / 10;
	roll = (double)payload.getI2() / 10;
	heading = (double)payload.getI2() / 10;
/*	int num;         //照片序号
	double time;     //周时间（毫秒）
	double lon;      //经度
	double lat;      //纬度
	long alt;        //高度
	double pitch;    //俯仰角
	double roll;     //滚转角
	double heading;  //航向角
*/
}

CPacket CMsg_PhotoData::Pack(int iStart, int iEnd)
{
	CPacket  packet;
	packet.m_msgid = MSG_ID;
	packet.m_len = 4;

	packet.payload.putU2h(iStart);
	packet.payload.putU2h(iEnd);

	packet.generateCRC();

	return packet;
}