#include "stdafx.h"
#include "PlayerS4.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "LineMgr.h"


CPlayerS4::CPlayerS4() : m_fDistance(0.f), m_bJump(false), m_fPower(0.f), m_fTime(0.f)
{
}

CPlayerS4::~CPlayerS4()
{
	Release();
}


void CPlayerS4::Initialize(void)
{
	m_tInfo = { 100.f, 300.f, 100.f, 100.f };
	m_fSpeed = 10.f;
	m_fDistance = 100.f;
	m_fPower = 20.f;
}

int CPlayerS4::Update(void)
{
	Key_Input();
	Jump();

	__super::Update_Rect();

	return OBJ_NOEVENT;
}
void CPlayerS4::Late_Update(void)
{

}

void CPlayerS4::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CPlayerS4::Release(void)
{
}

void CPlayerS4::Key_Input(void)
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

	if (GetAsyncKeyState(VK_SPACE))
	{
		m_bJump = true;
	}

}
void CPlayerS4::Jump(void)
{
	float	fY = 0.f;

	bool bLineCol = CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, &fY);

	if (m_bJump)
	{
		m_tInfo.fY -= (m_fPower * m_fTime) - 9.8f * m_fTime * m_fTime * 0.5f;
		m_fTime += 0.2f;

		if (bLineCol && (fY < m_tInfo.fY))
		{
			m_bJump = false;
			m_fTime = 0.f;
			m_tInfo.fY = fY;
		}
	}
	else if (bLineCol)
	{
		m_tInfo.fY = fY;
		m_fTime = 0.f;
	}
	else
	{
		m_tInfo.fY += 9.8f * m_fTime * m_fTime * 0.5f;
		m_fTime += 0.2f;
	}
}
template<typename T>
CObj* CPlayerS4::Create_Bullet()
{
	CObj* pBullet = CAbstractFactory<T>::Create((float)m_tPosin.x, (float)m_tPosin.y);
	pBullet->Set_Angle(m_fAngle);

	return pBullet;
}
