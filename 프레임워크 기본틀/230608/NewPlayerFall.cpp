#include "stdafx.h"
#include "NewPlayerFall.h"


NewPlayerFall::NewPlayerFall()
{
}

NewPlayerFall::~NewPlayerFall()
{

}

void NewPlayerFall::Initialize(CNewPlayer& _Actor)
{
    m_preDeley = GetTickCount();
    m_PostDelay = GetTickCount();
}

NewPlayerState NewPlayerFall::Update(CNewPlayer& _Actor)
{
    return OnAirUpdate(_Actor);
}

void NewPlayerFall::Late_Update(CNewPlayer& _Actor)
{
}

void NewPlayerFall::Render(HDC hDC, CNewPlayer& _Actor)
{
    Rectangle(hDC,
        _Actor.Get_Rect().left,
        _Actor.Get_Rect().top,
        _Actor.Get_Rect().right,
        _Actor.Get_Rect().bottom);

    TCHAR	szBuff[32] = L"";
    swprintf_s(szBuff, L"Fall");
    TextOut(hDC, _Actor.Get_Rect().left, _Actor.Get_Rect().top - 10, szBuff, lstrlen(szBuff));

}

void NewPlayerFall::Release(CNewPlayer& _Actor)
{
}

