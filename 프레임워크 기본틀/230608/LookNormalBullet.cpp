#include "stdafx.h"
#include "LooKNormalBullet.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "MiniBullet.h"
#include "SceneMgr.h"

CLooKNormalBullet::CLooKNormalBullet()
	:m_dwTime((DWORD)GetTickCount64()), m_iTime(0)
{
}

CLooKNormalBullet::~CLooKNormalBullet()
{
	Release();
}

void CLooKNormalBullet::Initialize(void)
{
	m_tInfo.fCX = 25.f;
	m_tInfo.fCY = 25.f;

	m_fSpeed = 2.f;
	m_fAngle = 5.f;
	m_iAttack = 2;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Monster/Look_Attack.bmp", L"Look_Attack");

	m_eRender = GAMEOBJECT;

}

int CLooKNormalBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;	
	
	if (m_tInfo.fX > 400.f)
		m_fAngle -= 5.f;
	else if (m_tInfo.fX <= 400.f)
		m_fAngle += 5.f;

	m_tInfo.fX += m_fSpeed * cosf(m_fAngle * (PI / 180.f));
	m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * (PI / 180.f));

	if (m_dwTime + 400.f < (DWORD)GetTickCount64()) {
		CObjMgr::Get_Instance()->Add_Object(BULLET, Create_Bullet());
		m_dwTime = (DWORD)GetTickCount64();
	}
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CLooKNormalBullet::Late_Update(void)
{
	if ((m_tRect.left < 290.f) || (m_tRect.right > 515.f)) {
		m_tInfo.fX *= -1.f;
	}

	if ((m_tRect.top < 310.f) || (m_tRect.bottom > 490.f)) {
		m_tInfo.fY *= -1.f;
	}

	if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_PHASE)
		m_bDead = false;
	else
		m_bDead = true;

}

void CLooKNormalBullet::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Look_Attack");

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

	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CLooKNormalBullet::Release(void)
{
}

CObj* CLooKNormalBullet::Create_Bullet()
{
	CObj* pBullet = CAbstractFactory<CMiniBullet>::Create((float)m_tInfo.fX, (float)m_tInfo.fY);
	pBullet->Set_Target(this);

	return pBullet;
}
