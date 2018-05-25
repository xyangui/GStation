// Msg_OtherPIDAdjData.cpp: implementation of the CMsg_OtherPIDAdjData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "Msg_OtherPIDAdjData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMsg_OtherPIDAdjData::CMsg_OtherPIDAdjData()
{

}

CMsg_OtherPIDAdjData::~CMsg_OtherPIDAdjData()
{

}

/////////////////////////迎角数据开始/////////////////////////////
//返回“获取迎角数据”的数据包
CPacket CMsg_OtherPIDAdjData::GetRequestYJDataPacket()
{
	CPacket packet;
	packet.m_msgid = 0x0D;
	packet.m_len = 0;

	packet.generateCRC();
	return packet;
}

//返回“设置迎角数据”的数据包
CPacket CMsg_OtherPIDAdjData::GetSetYJDataPacket(int maxDeg,int midDeg,int minDeg)
{
	CPacket packet;
	packet.m_msgid = 0x0D;
	packet.m_len = 6;
	
	packet.payload.putI2(maxDeg);
	packet.payload.putI2(midDeg);
	packet.payload.putI2(minDeg);
	
	packet.generateCRC();
	return packet;
}

//解析 返回的迎角数据包
void CMsg_OtherPIDAdjData::YJDataUnPacket(CPayload payload)
{
	// 复位载荷索引,载荷payload中仅仅包含参数
	payload.resetIndex();
	// 开始拆包
	m_YJ_maxDeg = payload.getI2();//马劲松原来用的是：.getU2();	
	m_YJ_midDeg = payload.getI2();//马劲松原来用的是：.getU2();	 
    m_YJ_minDeg = payload.getI2();//马劲松原来用的是：.getU2();	 
    // 拆包结束
}
////////////////////////迎角数据结束////////////////////////////////

////////////////////////导航通道数据开始///////////////////////////
//返回 请求导航数据 的数据包
CPacket CMsg_OtherPIDAdjData::GetRequestDhDataPacket()
{
	CPacket packet;
	packet.m_msgid = 0x16;
	packet.m_len = 0;

	packet.generateCRC();
	return packet;
}

//解析 返回的导航数据包
void CMsg_OtherPIDAdjData::UnDhDataPacket(CPayload payload)
{	
	// 复位载荷索引,载荷payload中仅仅包含参数
	payload.resetIndex();
	//开始拆包
	m_DH_AimWaypoint = payload.getU1();
	m_DH_YawDistance = payload.getI2();
	m_DH_PreAirLine = (float)(payload.getI2()/10.0);
	m_DH_RealHeading = (float)(payload.getI2()/10.0);
	m_DH_TotalYawAngle = (float)(payload.getI2()/10.0);
	m_DH_ToAimDistance = payload.getU2();
	//拆包结束

}
////////////////////////导航通道数据结束///////////////////////////

////////////////////////其他项 开始/////////////////
//返回 设置最大转弯速率或坡度 的数据包
CPacket CMsg_OtherPIDAdjData::GetSetMaxZwRateDataPacket(int maxZwRate)
{
	CPacket packet;
	packet.m_msgid = 0x33;
	packet.m_len = 1;
	packet.payload.putU1(maxZwRate);
	packet.generateCRC();
	return packet;
}

//返回  设置空速控制模式 的数据包
CPacket CMsg_OtherPIDAdjData::GetSetAirspdCtrlmodelDataPacket(int airspdCtrlmodel)
{
	CPacket packet;
	packet.m_msgid = 0x34;
	packet.m_len = 1;
	packet.payload.putU1(airspdCtrlmodel);
	packet.generateCRC();
	return packet;
}
////////////////////////其他项 结束/////////////////
