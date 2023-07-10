#include "stdafx.h"
#include "PlayerState.h"
#include "KeyMgr.h"
#include "ObjMgr.h"
#include "PlayerS1.h"
#include "SceneMgr.h"
#include "CollisionMgr.h"

CPlayerState::CPlayerState()
    : m_iLevel(0), m_iCurHp(0), m_iMaxHp(0), m_dwTime(GetTickCount64())
{
}

CPlayerState::~CPlayerState()
{
	Release();
}

void CPlayerState::Initialize(void)
{
    CObj* pPlayer = CObjMgr::Get_Instance()->Get_BattlePlayer();

    m_iLevel = (pPlayer)->Get_Level();
    m_iMaxHp = (pPlayer)->Get_MaxHp();
    m_iCurHp = (pPlayer)->Get_Hp();
    m_iAttack = 1;

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
    if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_ITEM || CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_ITEM) {
    
        if (m_dwTime + 4000 < GetTickCount64()) {
            m_iCurHp = m_iCurHp + 5;
            m_dwTime = GetTickCount64();
        }


        if (m_iCurHp > m_iMaxHp)
            m_iCurHp = m_iMaxHp;
    }

    if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_PHASE || CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_PHASE) {


        if (CCollisionMgr::Check_Collision(
            CObjMgr::Get_Instance()->Get_Objects(BATTLE_PLAYER),
            CObjMgr::Get_Instance()->Get_Objects(BULLET))) {

            m_iCurHp -= 0.1;

            if (m_iCurHp < 0)
                m_iCurHp = 0;

        }
    }


    if (CSceneMgr::Get_Instance()->Get_SceneID() == RUIN)
        m_bDead = true;

}

void CPlayerState::Render(HDC hDC)
{
    SetBkMode(hDC, 1);
    SetTextColor(hDC, RGB(255, 255, 255));

    swprintf_s(szBuff, L"FRISK  LV %d    Hp %d/%d", m_iLevel, m_iCurHp, m_iMaxHp);

    TextOut(hDC, 70, 500, szBuff, lstrlen(szBuff));

}

void CPlayerState::Release(void)
{
}
