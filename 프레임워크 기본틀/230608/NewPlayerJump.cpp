#include "stdafx.h"
#include "NewPlayerJump.h"


NewPlayerJump::NewPlayerJump()
{
}

NewPlayerJump::~NewPlayerJump()
{

}

void NewPlayerJump::Initialize(CNewPlayer& _Actor)
{
    m_preDeley = GetTickCount();
    m_PostDelay = GetTickCount();
    
}

NewPlayerState NewPlayerJump::Update(CNewPlayer& _Actor)
{
    return OnAirUpdate(_Actor);
}

void NewPlayerJump::Late_Update(CNewPlayer& _Actor)
{
}

void NewPlayerJump::Render(HDC hDC, CNewPlayer& _Actor)
{
    Rectangle(hDC,
        _Actor.Get_Rect().left,
        _Actor.Get_Rect().top,
        _Actor.Get_Rect().right,
        _Actor.Get_Rect().bottom);

    TCHAR	szBuff[32] = L"";
    swprintf_s(szBuff, L"Jump");
    TextOut(hDC, _Actor.Get_Rect().left, _Actor.Get_Rect().top - 10, szBuff, lstrlen(szBuff));

}

void NewPlayerJump::Release(CNewPlayer& _Actor)
{
}

