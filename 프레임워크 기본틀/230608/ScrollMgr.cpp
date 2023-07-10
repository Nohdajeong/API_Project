#include "stdafx.h"
#include "ScrollMgr.h"

CScrollMgr* CScrollMgr::m_pInstance = nullptr;

CScrollMgr::CScrollMgr()
	: m_fScrollX(0.f), m_fScrollY(0.f)
{
}


CScrollMgr::~CScrollMgr()
{
}

void CScrollMgr::Scroll_Lock(float _fX, float _fY)
{
	if (0.f < m_fScrollX)
		m_fScrollX = 0.f;

	if (0.f < m_fScrollY)
		m_fScrollY = 0.f;


	if (WINCX - _fX > m_fScrollX)
		m_fScrollX = WINCX - _fX;

	if (WINCY - _fY > m_fScrollY)
		m_fScrollY = WINCY - _fY;

}
