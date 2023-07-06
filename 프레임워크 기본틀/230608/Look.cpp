#include "stdafx.h"
#include "Look.h"
#include "LookBullet.h"

CLook::CLook()
{
}

CLook::~CLook()
{
}

void CLook::Idle()
{
}

void CLook::Attack1()
{
	//if (m_preDeley + 100.f < GetTickCount()) {
	//	CObjMgr::Get_Instance()->Add_Object(BULLET, Create_Bullet<CLooKBullet>());
	//	m_preDeley = GetTickCount64();
	//}

}

void CLook::Attack2()
{
}

void CLook::Initialize(void)
{
	m_tInfo = { 300.f, 250.f, 100.f, 115.f };

	m_tStates.iHp = 50;
	m_tStates.iAttack = 5;
	m_tStates.iDefense = 4;

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

	//Attack1();

	__super::Move_Frame();
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CLook::Late_Update(void)
{

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


}

void CLook::Release(void)
{
}

//template<typename T>
//CObj* CLook::Create_Bullet()
//{
//	CObj* pBullet = CAbstractFactory<T>::Create((float)m_tInfo.fX, (float)m_tInfo.fY);
//	pBullet->Set_Angle(m_fAngle);
//	pBullet->Set_Target(this);
//
//	return pBullet;
//}