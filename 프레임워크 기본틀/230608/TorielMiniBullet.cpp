#include "stdafx.h"
#include "TorielMiniBullet.h"
#include "ObjMgr.h"
#include "SceneMgr.h"

CTorielMiniBullet::CTorielMiniBullet()
	:m_dwTime(GetTickCount64()), m_iTime(0)
{
}

CTorielMiniBullet::~CTorielMiniBullet()
{
	Release();
}

void CTorielMiniBullet::Initialize(void)
{
	m_tInfo.fCX = 15.f;
	m_tInfo.fCY = 15.f;

	m_fSpeed = 5.f;
	m_iAttack = 1;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Monster/Toriel_Bullet.bmp", L"Toriel_Bullet");

	m_eRender = GAMEOBJECT;

}

int CTorielMiniBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;	
	
	if (m_pTarget->Get_Info().fY > 400.f) {
			m_tInfo.fY -= m_fSpeed;
	}

	else if (m_pTarget->Get_Info().fY < 400.f) {
			m_tInfo.fY += m_fSpeed;
	}

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CTorielMiniBullet::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_PHASE)
		m_bDead = false;
	else
		m_bDead = true;
}

void CTorielMiniBullet::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Toriel_Bullet");

	if ((m_tRect.left > 290.f) && (m_tRect.right < 515.f) && (m_tRect.top > 300.f) && (m_tRect.bottom < 500.f))  {
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
			RGB(195, 134, 255));
	}
}

void CTorielMiniBullet::Release(void)
{
}
