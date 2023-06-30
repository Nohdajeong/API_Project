#include "stdafx.h"
#include "NewPlayerWalk.h"


NewPlayerWalk::NewPlayerWalk()
{
}

NewPlayerWalk::~NewPlayerWalk()
{

}

void NewPlayerWalk::Initialize(CNewPlayer& _Actor)
{
    m_preDeley = GetTickCount();
    m_PostDelay = GetTickCount();
}

NewPlayerState NewPlayerWalk::Update(CNewPlayer& _Actor)
{
    return OnGroundUpdate(_Actor);
}

void NewPlayerWalk::Late_Update(CNewPlayer& _Actor)
{
}

void NewPlayerWalk::Render(HDC hDC, CNewPlayer& _Actor)
{
    Rectangle(hDC,
        _Actor.Get_Rect().left,
        _Actor.Get_Rect().top,
        _Actor.Get_Rect().right,
        _Actor.Get_Rect().bottom);

    TCHAR	szBuff[32] = L"";
    swprintf_s(szBuff, L"Walk");
    TextOut(hDC, _Actor.Get_Rect().left, _Actor.Get_Rect().top - 10, szBuff, lstrlen(szBuff));
}

void NewPlayerWalk::Release(CNewPlayer& _Actor)
{
}

