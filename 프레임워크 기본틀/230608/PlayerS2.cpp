#include "stdafx.h"
#include "PlayerS2.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "LineMgr.h"


CPlayerS2::CPlayerS2() : m_fDistance(0.f), m_bJump(false), m_fPower(0.f), m_fTime(0.f)
{
}

CPlayerS2::~CPlayerS2()
{
	Release();
}


void CPlayerS2::Initialize(void)
{
	m_tInfo.fX = 10.f;
	m_tInfo.fY = 10.f;

	m_fSpeed = 10.f;
	m_fPower = 20.f;
}

int CPlayerS2::Update(void)
{
	Key_Input();

	__super::Update_Rect();

	return OBJ_NOEVENT;
}
void CPlayerS2::Late_Update(void)
{

}

void CPlayerS2::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CPlayerS2::Release(void)
{
}

void CPlayerS2::Key_Input(void)
{
	float	fY = 0.f;

	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.fX += 250;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;
	}
}