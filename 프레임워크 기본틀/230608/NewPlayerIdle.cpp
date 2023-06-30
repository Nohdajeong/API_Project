#include "stdafx.h"
#include "NewPlayerIdle.h"


NewPlayerIdle::NewPlayerIdle()
{
}

NewPlayerIdle::~NewPlayerIdle()
{

}

void NewPlayerIdle::Initialize(CNewPlayer& _Actor)
{
    m_preDeley = GetTickCount();
    m_PostDelay = GetTickCount();
}

NewPlayerState NewPlayerIdle::Update(CNewPlayer& _Actor)
{
    return OnGroundUpdate(_Actor);
}

void NewPlayerIdle::Late_Update(CNewPlayer& _Actor)
{
}

void NewPlayerIdle::Render(HDC hDC, CNewPlayer& _Actor)
{
    Rectangle(hDC,
        _Actor.Get_Rect().left,
        _Actor.Get_Rect().top,
        _Actor.Get_Rect().right,
        _Actor.Get_Rect().bottom);

    TCHAR	szBuff[32] = L"";
    swprintf_s(szBuff, L"Idle");
    TextOut(hDC, _Actor.Get_Rect().left, _Actor.Get_Rect().top - 10, szBuff, lstrlen(szBuff));

}

void NewPlayerIdle::Release(CNewPlayer& _Actor)
{
}

