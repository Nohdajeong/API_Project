#include "stdafx.h"
#include "PlayerState.h"
#include "KeyMgr.h"
#include "ObjMgr.h"
#include "SceneMgr.h"
#include "CollisionMgr.h"

CPlayerState::CPlayerState()
    : m_dwTime((DWORD)GetTickCount64()), m_iCurHp(0)
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

    m_tInfo.fX = 400.f;
    m_tInfo.fY = 510.f;

    m_tInfo.fCX = 85.f;
    m_tInfo.fCY = 15.f;

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/hp_base.bmp", L"hp_base");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/hp_max.bmp", L"hp_max");

	m_eRender = UI;

}

int CPlayerState::Update(void)
{
    if (m_bDead)
        return OBJ_DEAD;

    __super::Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayerState::Late_Update(void)
{
    if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_ITEM || CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_ITEM) {
    
        if (m_dwTime + 4000 < (DWORD)GetTickCount64()) {
            m_iCurHp = m_iCurHp + 5;
            m_dwTime = (DWORD)GetTickCount64();
        }


        if (m_iCurHp > m_iMaxHp)
            m_iCurHp = m_iMaxHp;
    }

    if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_PHASE || CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_PHASE) {


        if (CCollisionMgr::Check_Collision(
            CObjMgr::Get_Instance()->Get_Objects(BATTLE_PLAYER),
            CObjMgr::Get_Instance()->Get_Objects(BULLET))) {

            m_iCurHp -= (int)0.1;

            if (m_iCurHp < 0)
                m_iCurHp = 0;

        }
    }


    if (CSceneMgr::Get_Instance()->Get_SceneID() == RUIN)
        m_bDead = true;

}

void CPlayerState::Render(HDC hDC)
{
    HDC     hBaseDC = CBmpMgr::Get_Instance()->Find_Img(L"hp_base");
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"hp_max");


    SetBkMode(hDC, 1);
    SetTextColor(hDC, RGB(255, 255, 255));

    swprintf_s(szBuff, L"FRISK  LV %d    Hp %d/%d", m_iLevel, m_iCurHp, m_iMaxHp);

    TextOut(hDC, 70, 500, szBuff, lstrlen(szBuff));

    GdiTransparentBlt(hDC,
        (int)m_tRect.left,
        (int)m_tRect.top,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        hBaseDC,
        0,
        0,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        RGB(195, 134, 255));

    GdiTransparentBlt(hDC,
        (int)m_tRect.left,
        (int)m_tRect.top,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        hMemDC,
        0,
        0,
        (int)m_tInfo.fCX * (m_iCurHp / m_iMaxHp),
        (int)m_tInfo.fCY,
        RGB(195, 134, 255));

}

void CPlayerState::Release(void)
{
}
