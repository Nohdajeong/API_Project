#include "stdafx.h"
#include "TorielBullet.h"
#include "ObjMgr.h"
#include "SceneMgr.h"

CTorielBullet::CTorielBullet()
	:m_dwTime(GetTickCount64()), m_iTime(0), m_bStart(true), m_fDistance(0.f), m_fRotSpeed(0.f), m_fRotAngle(0.f)
{
	ZeroMemory(&m_tCenter, sizeof(POINT));
}

CTorielBullet::~CTorielBullet()
{
	Release();
}

void CTorielBullet::Initialize(void)
{
	m_tInfo.fCX = 15.f;
	m_tInfo.fCY = 15.f;

	m_fSpeed = 2.f;
	m_iAttack = 1;

	m_fRotSpeed = 12.f;
	m_fDistance = 20.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Monster/Toriel_Bullet.bmp", L"Toriel_Bullet");

	m_eRender = GAMEOBJECT;

}

int CTorielBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;	
	
	if (m_bStart)
	{
		m_tCenter.x = (LONG)m_tInfo.fX;
		m_tCenter.y = (LONG)m_tInfo.fY;
		m_bStart = false;
	}

	m_tCenter.x += LONG(m_fSpeed * sinf(m_fAngle * (PI / 180.f)));
	m_tCenter.y += LONG(m_fSpeed * cosf(m_fAngle * (PI / 180.f)));

	if (m_tInfo.fX < 400.f)
		m_fRotAngle += m_fRotSpeed;
	else if (m_tInfo.fX > 400.f)
		m_fRotAngle -= m_fRotSpeed;


	m_tInfo.fX = m_tCenter.x - m_fDistance * sinf(m_fRotAngle * (PI / 180.f));
	m_tInfo.fY = m_tCenter.y + m_fDistance * cosf(m_fRotAngle * (PI / 180.f));

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CTorielBullet::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_PHASE)
		m_bDead = false;
	else
		m_bDead = true;
}

void CTorielBullet::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Toriel_Bullet");

	if (m_tInfo.fY > 330.f && m_tInfo.fY < 480.f) {
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
			RGB(195, 134, 255));
	}
}

void CTorielBullet::Release(void)
{
}
