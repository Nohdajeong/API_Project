#include "stdafx.h"
#include "NewPlayer.h"
#include "LineMgr.h"
#include "KeyMgr.h"

#include "NewPlayerIdle.h"
#include "NewPlayerWalk.h"
#include "NewPlayerJump.h"
#include "NewPlayerFall.h"


CNewPlayer::CNewPlayer()
{
	m_eDir = DOWN;
	m_eJumpState = JUMPSTATE::STAND;
}

CNewPlayer::~CNewPlayer()
{
}

bool CNewPlayer::Idle()
{
	return true;
}

bool CNewPlayer::Walk()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
		m_eDir = LEFT;
		return true;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;
		m_eDir = RIGHT;
		return true;
	}
	return false;
}

bool CNewPlayer::Move()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.fX -= m_fSpeed / 2;
		return true;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_fSpeed / 2;
		return true;
	}
	return false;
}



JUMPSTATE CNewPlayer::Jump(void)
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

			m_eJumpState = JUMPSTATE::STAND;
			return m_eJumpState;
		}
		m_eJumpState = JUMPSTATE::JUMP;
		return m_eJumpState;
	}
	else if (bLineCol)
	{
		m_tInfo.fY = fY;
		m_fTime = 0.f;

		m_eJumpState = JUMPSTATE::STAND;
		return m_eJumpState;
	}
	else
	{
		m_tInfo.fY += 9.8f * m_fTime * m_fTime * 0.5f;
		m_fTime += 0.2f;

		m_eJumpState = JUMPSTATE::FALL;
		return m_eJumpState;
	}
}




void CNewPlayer::Initialize(void)
{
	m_tInfo = { 100.f, 300.f, 100.f, 100.f };
	m_fSpeed = 10.f;
	m_fDistance = 100.f;
	m_fPower = 20.f;

	m_States[(int)NewPlayerState::Idle] = new NewPlayerIdle();
	m_States[(int)NewPlayerState::Walk] = new NewPlayerWalk();
	m_States[(int)NewPlayerState::Jump] = new NewPlayerJump();

	m_eState = NewPlayerState::Idle;
	m_States[(int)m_eState]->Initialize(*this);
}

int CNewPlayer::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	NewPlayerState nowState = m_States[(int)m_eState]->Update(*this);
	if (m_eState != nowState)
	{
		m_States[(int)m_eState]->Release(*this);

		m_eState = nowState;
		m_States[(int)m_eState]->Initialize(*this);
		m_States[(int)m_eState]->Update(*this);
	}

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CNewPlayer::Late_Update(void)
{
	m_States[(int)m_eState]->Late_Update(*this);
}

void CNewPlayer::Render(HDC hDC)
{
	m_States[(int)m_eState]->Render(hDC, *this);
}

void CNewPlayer::Release(void)
{
	for (int i = 0; i < (int)NewPlayerState::NewPlayerState_End; ++i) {
		Safe_Delete(m_States[i]);
	}
}
