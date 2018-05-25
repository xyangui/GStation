// CRC.cpp: implementation of the CCRC class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "CRC.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCRC::CCRC(BYTE byCRC_Init_Value)
{
	CRCvalue = byCRC_Init_Value;//初始值为命令类型
}

CCRC::~CCRC()
{

}

void CCRC::update_checksum(BYTE data)
{
	CRCvalue += data;
}

void CCRC::finish_checksum()
{
	CRCvalue = CRCvalue % 256;
}

int CCRC::getCRCvalue()
{
	return CRCvalue;
}
