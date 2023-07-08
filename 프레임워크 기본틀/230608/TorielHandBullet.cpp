#include "stdafx.h"
#include "TorielHandBullet.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "SceneMgr.h"
#include "TorielMiniBullet.h"

CTorielHandBullet::CTorielHandBullet()
	:m_dwTime(GetTickCount64()), m_iTime(0), m_iDrawID(0)
{
}

CTorielHandBullet::~CTorielHandBullet()
{
	Release();
}

void CTorielHandBullet::Initialize(void)
{
	m_tInfo.fCX = 60.f;
	m_tInfo.fCY = 40.f;

	m_fSpeed = 2.f;
	m_fAngle = 5.f;
	m_iAttack = 2.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Monster/Toriel_Attack.bmp", L"Toriel_Attack");

	m_eRender = GAMEOBJECT;

}

int CTorielHandBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;	
	
	if (m_tInfo.fY > 400.f) {
		m_tInfo.fX += m_fSpeed;
		m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * (PI / 180.f));
	}
	else if (m_tInfo.fY < 400.f) {
		m_tInfo.fX -= m_fSpeed;
		m_tInfo.fY += m_fSpeed * sinf(m_fAngle * (PI / 180.f));
	}

	if (m_dwTime + 50.f < GetTickCount64()) {
		CObjMgr::Get_Instance()->Add_Object(BULLET, Create_Bullet());
		m_dwTime = GetTickCount64();
	}

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CTorielHandBullet::Late_Update(void)
{
	if (m_tInfo.fY > 400.f)
		m_iDrawID = 0;
	else if (m_tInfo.fY < 400.f)
		m_iDrawID = 1;

	if (CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_PHASE)
		m_bDead = false;
	else
		m_bDead = true;

}

void CTorielHandBullet::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Toriel_Attack");

	if (m_tInfo.fX > 300.f && m_tInfo.fX < 500.f) {
		GdiTransparentBlt(hDC,
			(int)m_tRect.left,
			(int)m_tRect.top,
			(int)m_tInfo.fCX,
			(int)m_tInfo.fCY,
			hMemDC,
			m_iDrawID * (int)m_tInfo.fCX,
			0,
			(int)m_tInfo.fCX,
			(int)m_tInfo.fCY,
			RGB(195, 134, 255));
	}
}

void CTorielHandBullet::Release(void)
{
}

CObj* CTorielHandBullet::Create_Bullet()
{
	CObj* pBullet = CAbstractFactory<CTorielMiniBullet>::Create((float)m_tInfo.fX, (float)m_tInfo.fY);
	pBullet->Set_Target(this);

	return pBullet;
}
