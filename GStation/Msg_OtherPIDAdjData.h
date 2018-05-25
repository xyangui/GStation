// Msg_OtherPIDAdjData.h: interface for the CMsg_OtherPIDAdjData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MSG_OTHERPIDADJDATA_H__AF852A32_1F72_4C08_B6F2_F5E951EFB609__INCLUDED_)
#define AFX_MSG_OTHERPIDADJDATA_H__AF852A32_1F72_4C08_B6F2_F5E951EFB609__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Packet.h"
#include "Payload.h"

class CMsg_OtherPIDAdjData  
{
public:
	CMsg_OtherPIDAdjData();
	virtual ~CMsg_OtherPIDAdjData();
	/////////////////////////迎角数据开始/////////////////////////////
	CPacket GetRequestYJDataPacket();                            //返回“获取迎角数据”的数据包
	CPacket GetSetYJDataPacket(int maxDeg,int midDeg,int minDeg);//返回“设置迎角数据”的数据包
	void YJDataUnPacket(CPayload payload);                       //解析 返回的迎角数据包

	int m_YJ_maxDeg;//最大迎角值（度）
	int m_YJ_midDeg;//平飞迎角值（度）
	int m_YJ_minDeg;//最小迎角值（度）
	////////////////////////迎角数据结束////////////////////////////////

	////////////////////////导航通道数据开始///////////////////////////
	CPacket GetRequestDhDataPacket();     //返回 请求导航数据 的数据包
	void UnDhDataPacket(CPayload payload);//解析 返回的导航数据包

	int m_DH_AimWaypoint;    //目标航点
	int m_DH_YawDistance;    //偏航距
	float m_DH_PreAirLine;   //预设航线
	float m_DH_RealHeading;  //实际航向
	float m_DH_TotalYawAngle;//总的偏航角度
	int m_DH_ToAimDistance;  //离目标点距离
	////////////////////////导航通道数据结束///////////////////////////

	////////////////////////其他项 开始/////////////////////
	CPacket GetSetMaxZwRateDataPacket(int maxZwRate);
	CPacket GetSetAirspdCtrlmodelDataPacket(int airspdCtrlmodel);
	////////////////////////其他项 结束/////////////////////
};

#endif // !defined(AFX_MSG_OTHERPIDADJDATA_H__AF852A32_1F72_4C08_B6F2_F5E951EFB609__INCLUDED_)
