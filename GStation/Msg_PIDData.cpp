// Msg_PIDData.cpp: implementation of the CMsg_PIDData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "Msg_PIDData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const int CMsg_PIDData::MSG_ID = 0x0c;//命令类型0x0c
const int CMsg_PIDData::MSG_SIZE_PAYLOAD_LENGTH = 30;//参数字节数用于检查数据包是否正确(GPS不可用时长度)


CMsg_PIDData::CMsg_PIDData()
{

}

CMsg_PIDData::~CMsg_PIDData()
{

}
//解析“各PID参数”数据包
void CMsg_PIDData::Unpack(CPayload payload)
{
	// 复位载荷索引,载荷payload中仅仅包含参数
	payload.resetIndex();
	// 开始拆包
	m_fy_P = payload.getU1();	
	m_fy_I = payload.getU1(); 
    m_fy_D = payload.getU1(); 
	 
	m_gz_P = payload.getU1(); 
	m_gz_I = payload.getU1(); 
	m_gz_D = payload.getU1(); 
		 
	m_fxd_P = payload.getU1(); 
	m_fxd_I = payload.getU1(); 
	m_fxd_D = payload.getU1(); 
		 
	m_gd_qg_P = payload.getU1(); 
	m_gd_qg_I = payload.getU1(); 
	m_gd_qg_D = payload.getU1(); 
	 
	m_ks_ky_P = payload.getU1(); 
	m_ks_ky_I = payload.getU1();
	m_ks_ky_D = payload.getU1(); 
		 
	m_VP = payload.getU1(); 
	m_TP = payload.getU1(); 
		 
	m_phxz_P = payload.getU1(); 
	m_phxz_I = payload.getU1();
	m_phxz_D = payload.getU1(); 
	 
	m_dh_P = payload.getU1(); 
	m_dh_I = payload.getU1(); 
	m_dh_D = payload.getU1(); 
	 
	m_BP = payload.getU1(); 

	m_ks_kf_P = payload.getU1();
	m_ks_kf_I = payload.getU1();
	m_ks_kf_D = payload.getU1();

	m_gd_agl_P = payload.getU1();
	m_gd_agl_I = payload.getU1();
	m_gd_agl_D = payload.getU1();
}
//返回“获取各PID参数”数据包
CPacket CMsg_PIDData::GetRequestPacket()
{
	CPacket packet;
	packet.m_msgid = MSG_ID;
	packet.m_len = 0;

	packet.generateCRC();
	return packet;
}
//返回“设置各PID参数”数据包
CPacket CMsg_PIDData::GetUpDataPacket()
{
	CPacket packet;
	packet.m_msgid = MSG_ID;
	packet.m_len = MSG_SIZE_PAYLOAD_LENGTH;

	packet.payload.putU1(m_fy_P);
	packet.payload.putU1(m_fy_I);
	packet.payload.putU1(m_fy_D);

	packet.payload.putU1(m_gz_P);
	packet.payload.putU1(m_gz_I);
	packet.payload.putU1(m_gz_D);

	packet.payload.putU1(m_fxd_P);
	packet.payload.putU1(m_fxd_I);
	packet.payload.putU1(m_fxd_D);

	packet.payload.putU1(m_gd_qg_P);
	packet.payload.putU1(m_gd_qg_I);
	packet.payload.putU1(m_gd_qg_D);

	packet.payload.putU1(m_ks_ky_P);
	packet.payload.putU1(m_ks_ky_I);
	packet.payload.putU1(m_ks_ky_D);

	packet.payload.putU1(m_VP);
	packet.payload.putU1(m_TP);

	packet.payload.putU1(m_phxz_P);
	packet.payload.putU1(m_phxz_I);
	packet.payload.putU1(m_phxz_D);

	packet.payload.putU1(m_dh_P);
	packet.payload.putU1(m_dh_I);
	packet.payload.putU1(m_dh_D);

	packet.payload.putU1(m_BP);

	packet.payload.putU1(m_ks_kf_P);
	packet.payload.putU1(m_ks_kf_I);
	packet.payload.putU1(m_ks_kf_D);

	packet.payload.putU1(m_gd_agl_P);
	packet.payload.putU1(m_gd_agl_I);
	packet.payload.putU1(m_gd_agl_D);

	packet.generateCRC();
	return packet;
}

