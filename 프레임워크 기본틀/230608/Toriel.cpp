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

    m_iHp = 220.f;
    m_iAttack = 80.f;
    m_iDefense = 80.f;

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


    if (CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_ATTACK) {
        SetBkMode(hDC, 1);
        SetTextColor(hDC, RGB(255, 255, 255));

        swprintf_s(szBuff, L"%d", m_iHp);

        TextOut(hDC, m_tInfo.fX, m_tRect.top - 50.f, szBuff, lstrlen(szBuff));
    }

}

void CToriel::Release(void)
{
}
