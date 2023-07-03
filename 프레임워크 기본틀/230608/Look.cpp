#include "stdafx.h"
#include "Look.h"

CLook::CLook()
{
}

CLook::~CLook()
{
	Release();
}

void CLook::Idle()
{
}

void CLook::Attack1()
{
}

void CLook::Attack2()
{
}

void CLook::Initialize(void)
{
	m_tInfo = { 300.f, 250.f, 100.f, 115.f };
	m_tStates = {};

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Monster/Monster_looks.bmp", L"Looks");

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 4;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 300;
	m_tFrame.dwTime = GetTickCount64();

	m_eRender = GAMEOBJECT;
	

	//m_States[(int)LookState::IDLE] = new LookIdle();
	//m_States[(int)LookState::ATTACK1] = new LookAttack1();
	//m_States[(int)LookState::ATTACK2] = new LookAttack2();
}

int CLook::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	//LookState nowState = m_States[(int)m_eState]->Update(*this);
	//if (m_eState != nowState)
	//{
	//	m_States[(int)m_eState]->Release(*this);

	//	m_eState = nowState;
	//	m_States[(int)m_eState]->Initialize(*this);
	//	m_States[(int)m_eState]->Update(*this);
	//}


	__super::Move_Frame();
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CLook::Late_Update(void)
{
	//m_States[(int)m_eState]->Late_Update(*this);

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

	//m_States[(int)m_eState]->Render(hDC, *this);

}

void CLook::Release(void)
{
}