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
    m_tInfo.fCX = 50.f;
    m_tInfo.fCY = 50.f;
    m_fSpeed = 5.f;

    //m_States[(int)TorielState::IDLE] = new TorielIdle();
    //m_States[(int)TorielState::ATTACK1] = new TorielAttack1();
    //m_States[(int)TorielState::ATTACK2] = new TorielAttack2();
    //m_States[(int)TorielState::ATTACK2] = new TorielAttack3();

}

int CToriel::Update(void)
{
    if (m_bDead)
        return OBJ_DEAD;

    TorielState nowState = m_States[(int)m_eState]->Update(*this);
    if (m_eState != nowState)
    {
        m_States[(int)m_eState]->Release(*this);

        m_eState = nowState;
        m_States[(int)m_eState]->Initialize(*this);
        m_States[(int)m_eState]->Update(*this);
    }


    __super::Update_Rect();
    return OBJ_NOEVENT;
}

void CToriel::Late_Update(void)
{
    m_States[(int)m_eState]->Late_Update(*this);

}

void CToriel::Render(HDC hDC)
{
    m_States[(int)m_eState]->Render(hDC, *this);
}

void CToriel::Release(void)
{
}
