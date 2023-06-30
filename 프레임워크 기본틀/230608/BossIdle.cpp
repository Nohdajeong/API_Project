#include "stdafx.h"
#include "BossIdle.h"

BossIdle::BossIdle()
{
}

BossIdle::~BossIdle()
{
}

void BossIdle::Initialize(Boss& _Actor)
{
    m_preDeley = GetTickCount();
    m_PostDelay = GetTickCount();
}

BossState BossIdle::Update(Boss& _Actor)
{
    if (m_preDeley + 3000 < GetTickCount()) 
    {
        return BossState::Chase;
    }
    return BossState::Idle;
}

void BossIdle::Late_Update(Boss& _Actor)
{
}

void BossIdle::Render(HDC hDC, Boss& _Actor)
{
    Rectangle(hDC,
        _Actor.Get_Rect().left,
        _Actor.Get_Rect().top,
        _Actor.Get_Rect().right,
        _Actor.Get_Rect().bottom
    );

    TCHAR	szBuff[32] = L"";
    swprintf_s(szBuff, L"Idle");
    TextOut(hDC, _Actor.Get_Rect().left, _Actor.Get_Rect().top-5, szBuff, lstrlen(szBuff));
}

void BossIdle::Release(Boss& _Actor)
{
}


