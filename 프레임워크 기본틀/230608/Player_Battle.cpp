#include "stdafx.h"
#include "Player_Battle.h"

CPlayerBattle::CPlayerBattle()
{
}

CPlayerBattle::~CPlayerBattle()
{
    Release();
}

void CPlayerBattle::Initialize(void)
{
	m_tInfo.fCX = 25.f;
	m_tInfo.fCY = 25.f;
    m_tStates = { 1, 20, 20, 0, 10, 10, 0, 30 };

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Player/Player_Battle.bmp", L"Player_Battle");

    m_eRender = GAMEOBJECT;
	m_fSpeed = 3.f;
}

int CPlayerBattle::Update(void)
{
    Key_Input();

    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CPlayerBattle::Late_Update(void)
{
	if ((m_tRect.left < 300.f) || (m_tRect.right > 500.f)) {
		m_tInfo.fX = -m_tInfo.fX;
	}

	if ((m_tRect.top < 310.f) || (m_tRect.bottom > 490.f)) {
		m_tInfo.fY = -m_tInfo.fY;
	}	
}

void CPlayerBattle::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Player_Battle");

	GdiTransparentBlt(hDC,
		(int)m_tRect.left,
		(int)m_tRect.top,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		hMemDC,	
		0,
		0,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(205, 141, 255));

}

void CPlayerBattle::Release(void)
{
}

void CPlayerBattle::Key_Input(void)
{
	if (GetAsyncKeyState(VK_LEFT)) {
		m_tInfo.fX -= m_fSpeed;
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;
	}
	else if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fY -= m_fSpeed;
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fY += m_fSpeed;
	}
}
