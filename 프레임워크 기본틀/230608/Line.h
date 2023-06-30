#pragma once

#include "Define.h"

class CLine
{
public:
	CLine();
	CLine(LINE& tLine);
	CLine(LINEPOINT& _tLpoint, LINEPOINT& _tRpoint);
	~CLine();

public:
	LINE		Get_Info() { return m_tInfo; }

public:
	void		Render(HDC hDC);

private:
	LINE		m_tInfo;
};

