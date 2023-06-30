#include "stdafx.h"
#include "BossS1_Idle.h"

BossS1_Idle::BossS1_Idle()
{
}

BossS1_Idle::~BossS1_Idle()
{
}

void BossS1_Idle::Initialize(Demeter& _Actor)
{
    m_preDeley = GetTickCount();
    m_PostDelay = GetTickCount();
}

BossState BossS1_Idle::Update(Demeter& _Actor)
{
    if (m_preDeley + 3000 < GetTickCount())
    {
        return BossState::Chase;
    }
    return BossState::Idle;
}

void BossS1_Idle::Late_Update(Demeter& _Actor)
{
}

void BossS1_Idle::Render(HDC hDC, Demeter& _Actor)
{
    Rectangle(hDC,
        _Actor.Get_Rect().left,
        _Actor.Get_Rect().top,
        _Actor.Get_Rect().right,
        _Actor.Get_Rect().bottom
    );

    TCHAR	szBuff[32] = L"";
    swprintf_s(szBuff, L"Idle");
    TextOut(hDC, _Actor.Get_Rect().left, _Actor.Get_Rect().top - 5, szBuff, lstrlen(szBuff));
}

void BossS1_Idle::Release(Demeter& _Actor)
{
}
