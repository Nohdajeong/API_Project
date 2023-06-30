#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "LineMgr.h"


CPlayer::CPlayer() : m_fDistance(0.f), m_bJump(false), m_fPower(0.f), m_fTime(0.f)
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	m_tInfo = { 100.f, 300.f, 100.f, 100.f };
	m_fSpeed = 10.f;
	m_fDistance = 100.f;
	m_fPower = 20.f;
}

int CPlayer::Update(void)
{
	Key_Input();
	Jump();

	__super::Update_Rect();

	return OBJ_NOEVENT;
}
void CPlayer::Late_Update(void)
{

}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);

	TCHAR	szBuff[32] = L"";
	swprintf_s(szBuff, L"%f", m_fJumpSpeed);
	TextOut(hDC, m_tRect.left, m_tRect.top - 10, szBuff, lstrlen(szBuff));
}

void CPlayer::Release(void)
{
}

void CPlayer::Key_Input(void)
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

void CPlayer::Jump(void)
{
	float	fY = 0.f;

	bool bLineCol = CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, &fY);

	if (m_bJump)
	{
		m_fJumpSpeed = (m_fPower * m_fTime) - 9.8f * m_fTime * m_fTime * 0.5f;
		m_tInfo.fY -= m_fJumpSpeed;
		m_fTime += 0.2f;

		if (bLineCol && (fY < m_tInfo.fY))
		{
			m_bJump = false;
			m_fTime = 0.f;
			m_tInfo.fY = fY;
			m_fJumpSpeed = 0.f;
		}
	}
	else if (bLineCol)
	{
		m_tInfo.fY = fY;
		m_fTime = 0.f;
		m_fJumpSpeed = 0.f;
	}
	else
	{
		m_fJumpSpeed = 9.8f * m_fTime * m_fTime * 0.5f;
		m_tInfo.fY += m_fJumpSpeed;
		m_fTime += 0.2f;
	}
}


template<typename T>
CObj* CPlayer::Create_Bullet()
{
	CObj* pBullet = CAbstractFactory<T>::Create((float)m_tPosin.x, (float)m_tPosin.y);
	pBullet->Set_Angle(m_fAngle);

	return pBullet;
}

//CObj* CPlayer::Create_Shield()
//{
//	CObj* pShield = CAbstractFactory<CShield>::Create();
//	pShield->Set_Target(this);
//
//	return pShield;
//}
