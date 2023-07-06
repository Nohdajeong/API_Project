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

	m_fSpeed = 2.f;
	m_iAttack = 1;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Monster/Look_Mini_Attack.bmp", L"LookMiniAttack");

	m_eRender = EFFECT;

}

int CMiniBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;	
	
	if (m_tInfo.fX > 400.f) {
			m_tInfo.fX -= m_fSpeed;
	}

	if (m_tInfo.fX < 400.f) {
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

void CMiniBullet::Release(void)
{
}
