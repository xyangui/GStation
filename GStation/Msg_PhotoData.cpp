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

const int CMsg_PhotoData::MSG_ID = 0x2e;//�������ͣ�ʮ����46
const int CMsg_PhotoData::MSG_SIZE_PAYLOAD_LENGTH = 24;//�������������͡���С��У��ͣ���24���ֽ�

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
	alt = payload.getI4h() / 1000;//long�ǳ����ͣ����������˰�
	pitch = (double)payload.getI2() / 10;
	roll = (double)payload.getI2() / 10;
	heading = (double)payload.getI2() / 10;
/*	int num;         //��Ƭ���
	double time;     //��ʱ�䣨���룩
	double lon;      //����
	double lat;      //γ��
	long alt;        //�߶�
	double pitch;    //������
	double roll;     //��ת��
	double heading;  //�����
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