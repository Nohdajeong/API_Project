#include "stdafx.h"
#include "Player_Battle.h"
#include "SceneMgr.h"

CPlayerBattle::CPlayerBattle()
{
}

CPlayerBattle::~CPlayerBattle()
{
    Release();
}

void CPlayerBattle::Initialize(void)
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 400.f;
	m_tInfo.fCX = 25.f;
	m_tInfo.fCY = 25.f;

	m_tStates.iAttack = 10;
	m_tStates.iMaxHp = 20;
	m_tStates.iDefense = 10;
	m_tStates.iLevel = 1;

	m_iHp = 16;

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Player/Player_Battle.bmp", L"Player_Battle");

    m_eRender = GAMEOBJECT;
	m_fSpeed = 3.f;
}

int CPlayerBattle::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

    Key_Input();

    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CPlayerBattle::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_PHASE || CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_PHASE) {
		if ((m_tRect.left < 290.f) || (m_tRect.right > 515.f)) {
			m_tInfo.fX *= -1.f;
		}

		if ((m_tRect.top < 310.f) || (m_tRect.bottom > 490.f)) {
			m_tInfo.fY *= -1.f;
		}
	}

	if (CSceneMgr::Get_Instance()->Get_SceneID() == RUIN)
		m_bDead = true;

}

void CPlayerBattle::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Player_Battle");

	if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_PHASE || CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_PHASE) {
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

	//else if (CSceneMgr::Get_Instance()->Get_SceneID() != BOSS_MATCH) {
	//	GdiTransparentBlt(hDC,
	//		(int)m_tRect.left,
	//		(int)m_tRect.top,
	//		(int)m_tInfo.fCX,
	//		(int)m_tInfo.fCY,
	//		hMemDC,
	//		0,
	//		0,
	//		(int)m_tInfo.fCX,
	//		(int)m_tInfo.fCY,
	//		RGB(205, 141, 255));

	//}
}

void CPlayerBattle::Release(void)
{
}

void CPlayerBattle::Key_Input(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_PHASE || CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_PHASE) {

		if (GetAsyncKeyState(VK_LEFT)) {
			m_tInfo.fX -= m_fSpeed;
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			m_tInfo.fX += m_fSpeed;
		}
		else if (GetAsyncKeyState(VK_UP))
		{
			m_tInfo.fY -= m_fSpeed;
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			m_tInfo.fY += m_fSpeed;
		}
	}
}
