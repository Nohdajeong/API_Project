#include "stdafx.h"
#include "TorielPassBullet.h"
#include "ObjMgr.h"
#include "SceneMgr.h"

CTorielPassBullet::CTorielPassBullet()
	:m_dwTime(GetTickCount64()), m_iTime(0), m_fRange(0.f)
{
}

CTorielPassBullet::~CTorielPassBullet()
{
	Release();
}

void CTorielPassBullet::Initialize(void)
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;

	m_fSpeed = 1.f;
	m_iAttack = 2;
	m_fRange = 30.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Monster/looks_attack.bmp", L"LookAttack");

	m_eRender = EFFECT;

}

int CTorielPassBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;	
	
	m_pTarget = CObjMgr::Get_Instance()->Get_BattlePlayer();

	if (Search(m_pTarget)) {
		if (m_tInfo.fX < m_pTarget->Get_Info().fX)
			m_tInfo.fX -= 5.f;
		else if (m_tInfo.fX > m_pTarget->Get_Info().fX)
			m_tInfo.fX += 5.f;
	}
	m_tInfo.fY += m_fSpeed;

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CTorielPassBullet::Late_Update(void)
{
	if ((m_tRect.left < 290.f) || (m_tRect.right > 515.f)) {
		m_bDead = true;
	}

	if (CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_PHASE)
		m_bDead = false;
	else
		m_bDead = true;

}

void CTorielPassBullet::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"LookAttack");

	//GdiTransparentBlt(hDC,
	//	(int)m_tRect.left,
	//	(int)m_tRect.top,
	//	(int)m_tInfo.fCX,
	//	(int)m_tInfo.fCY,
	//	hMemDC,
	//	m_tFrame.iFrameStart * (int)m_tInfo.fCX,
	//	m_tFrame.iMotion * (int)m_tInfo.fCY,
	//	(int)m_tInfo.fCX,
	//	(int)m_tInfo.fCY,
	//	RGB(195, 134, 255));

	if (m_tInfo.fY > 330.f && m_tInfo.fY < 480.f)
		Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CTorielPassBullet::Release(void)
{
}

bool CTorielPassBullet::Search(CObj* _pTarget)
{
	if ((m_tInfo.fY + m_fRange) >= _pTarget->Get_Info().fY && (m_tInfo.fY - m_fRange) <= _pTarget->Get_Info().fY) {

		if (m_tInfo.fX > _pTarget->Get_Info().fX && (m_tInfo.fX - m_fRange) < _pTarget->Get_Info().fX)
			return true;
		else if (m_tInfo.fX < _pTarget->Get_Info().fX && (m_tInfo.fX + m_fRange) > _pTarget->Get_Info().fX)
			return true;
	}

	return false;
}
