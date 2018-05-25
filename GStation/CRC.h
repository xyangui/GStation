// CRC.h: interface for the CCRC class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CRC_H__8252544D_D714_4DD3_8BC3_927789A77833__INCLUDED_)
#define AFX_CRC_H__8252544D_D714_4DD3_8BC3_927789A77833__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCRC  
{
public:
	int getCRCvalue();
	void finish_checksum();
	void update_checksum(BYTE data);

	CCRC(BYTE byCRC_Init_Value);
	virtual ~CCRC();

private:
	int CRCvalue;	
};

#endif // !defined(AFX_CRC_H__8252544D_D714_4DD3_8BC3_927789A77833__INCLUDED_)
