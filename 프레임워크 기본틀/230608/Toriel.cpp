#include "stdafx.h"
#include "Toriel.h"

CToriel::CToriel()
{
}

CToriel::~CToriel()
{
    Release();
}

void CToriel::Idle()
{
}

void CToriel::Attack1()
{
}

void CToriel::Attack2()
{
}

void CToriel::Attack3()
{
}

void CToriel::Initialize(void)
{
    m_tInfo = { 400.f, 190.f, 178.f, 245.f };
    m_tStates.iAttack = 10.f;
    m_tStates.iDefense = 0.f;
    m_tStates.iHp = 50.f;

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Monster/Toriel_boss.bmp", L"Toriel");

    m_tFrame.iFrameStart = 0;
    m_tFrame.iFrameEnd = 0;
    m_tFrame.iMotion = 0;
    m_tFrame.dwSpeed = 300;
    m_tFrame.dwTime = GetTickCount64();

    m_eRender = GAMEOBJECT;

    //m_States[(int)TorielState::IDLE] = new TorielIdle();
    //m_States[(int)TorielState::ATTACK1] = new TorielAttack1();
    //m_States[(int)TorielState::ATTACK2] = new TorielAttack2();
    //m_States[(int)TorielState::ATTACK2] = new TorielAttack3();

}

int CToriel::Update(void)
{
    if (m_bDead)
        return OBJ_DEAD;

    //TorielState nowState = m_States[(int)m_eState]->Update(*this);
    //if (m_eState != nowState)
    //{
    //    m_States[(int)m_eState]->Release(*this);

    //    m_eState = nowState;
    //    m_States[(int)m_eState]->Initialize(*this);
    //    m_States[(int)m_eState]->Update(*this);
    //}


    __super::Move_Frame();
    __super::Update_Rect();
    return OBJ_NOEVENT;
}

void CToriel::Late_Update(void)
{
    //m_States[(int)m_eState]->Late_Update(*this);

}

void CToriel::Render(HDC hDC)
{
    //m_States[(int)m_eState]->Render(hDC, *this);

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
