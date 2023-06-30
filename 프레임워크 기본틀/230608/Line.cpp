#include "stdafx.h"
#include "Line.h"
#include "ScrollMgr.h"


CLine::CLine()
{
}

CLine::CLine(LINE& tLine)
	:m_tInfo(tLine)
{
}

CLine::CLine(LINEPOINT& _tLpoint, LINEPOINT& _tRpoint)
	: m_tInfo(_tLpoint, _tRpoint)
{
}


CLine::~CLine()
{
}

void CLine::Render(HDC hDC)
{
	float	fScrollX = CScrollMgr::Get_Instance()->Get_ScollX();

	MoveToEx(hDC, (int)(m_tInfo.tLpoint.fX + fScrollX), (int)(m_tInfo.tLpoint.fY + fScrollX), nullptr);
	LineTo(hDC, (int)m_tInfo.tRpoint.fX, (int)m_tInfo.tRpoint.fY);
}
