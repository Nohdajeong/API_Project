#include "stdafx.h"
#include "Toriel.h"
#include "SceneMgr.h"

CToriel::CToriel()
    : m_iDrawID(0)
{
}

CToriel::~CToriel()
{
}

void CToriel::Initialize(void)
{
    m_tInfo = { 400.f, 190.f, 178.f, 245.f };

    m_tStates.iHp = 440.f;
    m_tStates.iAttack = 80.f;
    m_tStates.iDefense = 80.f;

    m_iHp = m_tStates.iHp;

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Monster/Toriel_bosss.bmp", L"Toriel");

    m_eRender = GAMEOBJECT;

}

int CToriel::Update(void)
{
    if (m_bDead)
        return OBJ_DEAD;

    __super::Move_Frame();
    __super::Update_Rect();
    return OBJ_NOEVENT;
}

void CToriel::Late_Update(void)
{
    if (m_tStates.iHp == 0)
        Set_Dead();

    if (CSceneMgr::Get_Instance()->Get_SceneID() == RUIN)
        Set_Dead();

}

void CToriel::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Toriel");

    if (CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_PHASE) {
        m_iDrawID = 2;
    }
    else if (CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_MERCY) {
        m_iDrawID = 1;

        if (m_dwTime + 5000 < GetTickCount64())
            m_iDrawID = 3;
    }
    else
        m_iDrawID = 0;

    GdiTransparentBlt(hDC,
        (int)m_tRect.left,
        (int)m_tRect.top,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        hMemDC,
        m_iDrawID * (int)m_tInfo.fCX,
        0,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        RGB(195, 134, 255));

}

void CToriel::Release(void)
{
}
