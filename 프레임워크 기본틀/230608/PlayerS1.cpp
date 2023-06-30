#include "stdafx.h"
#include "PlayerS1.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "LineMgr.h"
#include "ScrollMgr.h"

CPlayerS1::CPlayerS1() : m_fDistance(0.f), m_bJump(false), m_fPower(0.f), m_fTime(0.f), m_fJumpSpeed(0.f)
{
}

CPlayerS1::~CPlayerS1()
{
	Release();
}


void CPlayerS1::Initialize(void)
{
	m_tInfo = { 400.f, 300.f, 50.f, 100.f };
	m_tStates = { 1, 20, 20, 0, 10, 10, 0, 30 };

	m_fSpeed = 10.f;
	m_fDistance = 100.f;
	m_fPower = 20.f;
}

int CPlayerS1::Update(void)
{
	Key_Input();
	OffSet();

	__super::Update_Rect();

	return OBJ_NOEVENT;
}
void CPlayerS1::Late_Update(void)
{

}

void CPlayerS1::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();

	Rectangle(hDC,
		m_tRect.left + iScrollX,
		m_tRect.top,
		m_tRect.right + iScrollX,
		m_tRect.bottom);
	
}

void CPlayerS1::Release(void)
{
}

void CPlayerS1::Key_Input(void)
{
	float	fY = 0.f;

	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;
	}

}

void CPlayerS1::OffSet(void)
{
	int	iOffSetMinX = 100;
	int	iOffSetMaxX = 700;

	int	iScrollX = int(CScrollMgr::Get_Instance()->Get_ScollX());

	if (iOffSetMinX > m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(m_fSpeed);

	if (iOffSetMaxX < m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(-m_fSpeed);


}
