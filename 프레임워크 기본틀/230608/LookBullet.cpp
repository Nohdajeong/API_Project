#include "stdafx.h"
#include "LookBullet.h"
#include "ObjMgr.h"
#include "SceneMgr.h"

CLooKBullet::CLooKBullet()
	:m_dwTime((DWORD)GetTickCount64()), m_iTime(0)
{
}

CLooKBullet::~CLooKBullet()
{
	Release();
}

void CLooKBullet::Initialize(void)
{
	m_tInfo.fCX = 25.f;
	m_tInfo.fCY = 25.f;

	m_fSpeed = 1.f;
	m_iAttack = 2;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Monster/Look_Attack.bmp", L"Look_Attack");

	m_eRender = GAMEOBJECT;

}

int CLooKBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;	
	
	m_pTarget = CObjMgr::Get_Instance()->Get_BattlePlayer();

	if (m_pTarget) {
		float fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
		float fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

		float fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);
		float fRadian = acosf(fWidth / fDiagonal);

		m_fAngle = fRadian * 180.f / PI;

		if (m_tInfo.fY < m_pTarget->Get_Info().fY)
			m_fAngle *= -1.f;
	}

	m_tInfo.fX += m_fSpeed * cosf(m_fAngle * (PI / 180.f));
	m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * (PI / 180.f));

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CLooKBullet::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_PHASE)
		m_bDead = false;
	else
		m_bDead = true;

}

void CLooKBullet::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Look_Attack");

	GdiTransparentBlt(hDC,
		(int)m_tRect.left,
		(int)m_tRect.top,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		hMemDC,
		0,
		0,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(205, 141, 255));
}

void CLooKBullet::Release(void)
{
}
