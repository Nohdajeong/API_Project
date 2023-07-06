#include "stdafx.h"
#include "Toriel.h"

CToriel::CToriel()
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

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Monster/Toriel_boss.bmp", L"Toriel");

    m_tFrame.iFrameStart = 0;
    m_tFrame.iFrameEnd = 0;
    m_tFrame.iMotion = 0;
    m_tFrame.dwSpeed = 300;
    m_tFrame.dwTime = (DWORD)GetTickCount64();

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
}

void CToriel::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Toriel");

    GdiTransparentBlt(hDC,
        (int)m_tRect.left,
        (int)m_tRect.top,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        hMemDC,
        m_tFrame.iFrameStart * (int)m_tInfo.fCX,
        m_tFrame.iMotion * (int)m_tInfo.fCY,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        RGB(195, 134, 255));

}

void CToriel::Release(void)
{
}
