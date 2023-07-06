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
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;

	m_fSpeed = 2.f;
	m_iAttack = 1;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Monster/looks_attack.bmp", L"LookAttack");

	m_eRender = EFFECT;

}

int CMiniBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;	
	
	if (m_tInfo.fX > 400.f) {
			m_tInfo.fX -= m_fSpeed;

			if (m_tInfo.fX == 400.f)
				m_bDead = true;
	}

	if (m_tInfo.fX < 400.f) {
			m_tInfo.fX += m_fSpeed;

			if (m_tInfo.fX == 400.f)
				m_bDead = true;

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

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMiniBullet::Release(void)
{
}
