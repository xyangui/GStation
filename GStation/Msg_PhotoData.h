// Msg_PhotoData.h: interface for the CMsg_PhotoData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MSG_PHOTODATA_H__A304FAAB_E87D_4862_B067_8055CDDFB59A__INCLUDED_)
#define AFX_MSG_PHOTODATA_H__A304FAAB_E87D_4862_B067_8055CDDFB59A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Message.h"
class CPayload;
class CPacket;

class CMsg_PhotoData : public CMessage  
{
public:
	CMsg_PhotoData();
	virtual ~CMsg_PhotoData();

	static const int MSG_ID;
	static const int MSG_SIZE_PAYLOAD_LENGTH;

	void Unpack(CPayload payload);
	CPacket Pack(int iStart, int iEnd);

	int num;         //照片序号
	double time;     //周时间（毫秒）
	double lon;      //经度
	double lat;      //纬度
	long alt;        //高度
	double pitch;    //俯仰角
	double roll;     //滚转角
	double heading;  //航向角

};

#endif // !defined(AFX_MSG_PHOTODATA_H__A304FAAB_E87D_4862_B067_8055CDDFB59A__INCLUDED_)
