#include "stdafx.h"
#include "PlayerState.h"
#include "KeyMgr.h"
#include "ObjMgr.h"
#include "PlayerS1.h"
#include "SceneMgr.h"

CPlayerState::CPlayerState()
    : m_iLevel(0), m_iHp(0), m_iMaxHp(0)
{
}

CPlayerState::~CPlayerState()
{
	Release();
}

void CPlayerState::Initialize(void)
{
    CObj* pPlayer = CObjMgr::Get_Instance()->Get_BattlePlayer();

    m_iLevel = (pPlayer)->Get_States().iLevel;
    m_iHp = (pPlayer)->Get_States().iHp;
    m_iMaxHp = (pPlayer)->Get_States().iMaxHp;

	m_eRender = UI;

}

int CPlayerState::Update(void)
{
    if (m_bDead)
        return OBJ_DEAD;

	return OBJ_NOEVENT;
}

void CPlayerState::Late_Update(void)
{
    if (CSceneMgr::Get_Instance()->Get_SceneID() == RUIN)
        m_bDead = true;

}

void CPlayerState::Render(HDC hDC)
{
    SetBkMode(hDC, 1);
    SetTextColor(hDC, RGB(255, 255, 255));

    swprintf_s(szBuff, L"FRISK  LV %d    Hp %d/%d", m_iLevel, m_iHp, m_iMaxHp);

    TextOut(hDC, 70, 500, szBuff, lstrlen(szBuff));

}

void CPlayerState::Release(void)
{
}
