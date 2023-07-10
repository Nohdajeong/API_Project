#include "stdafx.h"
#include "Look.h"
#include "CollisionMgr.h"

CLook::CLook()
{
}

CLook::~CLook()
{
}

void CLook::Initialize(void)
{
	m_tInfo = { 300.f, 250.f, 100.f, 115.f };

	m_iHp = 50;
	m_iAttack = 5;
	m_iDefense = 4;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Monster/Monster_looks.bmp", L"Looks");

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 4;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 300;
	m_tFrame.dwTime = (DWORD)GetTickCount64();

	m_eRender = GAMEOBJECT;
}

int CLook::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Move_Frame();
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CLook::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() == RUIN)
		Set_Dead();

}

void CLook::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Looks");

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


	if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_ATTACK) {
		SetBkMode(hDC, 1);
		SetTextColor(hDC, RGB(255, 255, 255));

		swprintf_s(szBuff, L"%d", m_iHp);

		TextOut(hDC, m_tInfo.fX, m_tRect.top - 50.f, szBuff, lstrlen(szBuff));
	}
}

void CLook::Release(void)
{
}