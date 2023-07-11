#include "stdafx.h"
#include "Mouse.h"

CMouse::CMouse()
{
}

CMouse::~CMouse()
{
	Release();
}

void CMouse::Initialize(void)
{
	m_tInfo.fCX = 25.f;
	m_tInfo.fCY = 25.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Player/Player_Battle.bmp", L"Player_Battle");

}

int CMouse::Update(void)
{
	POINT	ptMouse{};

	GetCursorPos(&ptMouse);	// ���콺 ��ġ ���� ������ �Լ�

	ScreenToClient(g_hWnd, &ptMouse); // ��ũ�� ���� ��ǥ�� �츮�� ������ â ��ǥ�� ��ȯ
	
	m_tInfo.fX = (float)ptMouse.x;
	m_tInfo.fY = (float)ptMouse.y;


	__super::Update_Rect();

	ShowCursor(FALSE);

	return OBJ_NOEVENT;
}

void CMouse::Late_Update(void)
{
}

void CMouse::Render(HDC hDC)
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

void CMouse::Release(void)
{
}
