#include "stdafx.h"
#include "MiniBullet.h"
#include "ObjMgr.h"
#include "SceneMgr.h"

CMiniBullet::CMiniBullet()
	:m_dwTime(GetTickCount64()), m_iTime(0)
{
}

CMiniBullet::~CMiniBullet()
{
	Release();
}

void CMiniBullet::Initialize(void)
{
	m_tInfo.fCX = 15.f;
	m_tInfo.fCY = 15.f;

	m_fSpeed = 1.5f;
	m_iAttack = 1;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Monster/Look_Mini_Attack.bmp", L"LookMiniAttack");

	m_eRender = GAMEOBJECT;

}

int CMiniBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;	

	if (m_pTarget->Get_Info().fX > 400.f) {
			m_tInfo.fX -= m_fSpeed;
	}

	else if (m_pTarget->Get_Info().fX < 400.f) {
			m_tInfo.fX += m_fSpeed;
	}

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CMiniBullet::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_PHASE)
		m_bDead = false;
	else
		m_bDead = true;
}

void CMiniBullet::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"LookMiniAttack");

	if ((m_tRect.left > 290.f) && (m_tRect.right < 515.f)) {
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
}

void CMiniBullet::Release(void)
{
}
