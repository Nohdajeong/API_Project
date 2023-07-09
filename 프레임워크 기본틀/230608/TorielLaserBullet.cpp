#include "stdafx.h"
#include "TorielLaserBullet.h"
#include "ObjMgr.h"
#include "SceneMgr.h"

CTorielLaserBullet::CTorielLaserBullet()
	:m_dwTime(GetTickCount64()), m_iTime(0), m_fRange(0.f)
{
}

CTorielLaserBullet::~CTorielLaserBullet()
{
	Release();
}

void CTorielLaserBullet::Initialize(void)
{
	m_tInfo.fCX = 15.f;
	m_tInfo.fCY = 15.f;

	m_fSpeed = 1.f;
	m_fRange = 30.f;
	m_iAttack = 2;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Monster/Toriel_Bullet.bmp", L"Toriel_Bullet");

	m_eRender = GAMEOBJECT;

}

int CTorielLaserBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;	

	float fWidth = 500.f - m_tInfo.fX;
	float fHeight = 500.f - m_tInfo.fY;

	float fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);
	float fRadian = acosf(fWidth / fDiagonal);

	m_fAngle = fRadian * 180.f / PI;

	if (m_tInfo.fY < 500.f)
		m_fAngle *= -1.f;


	m_fAngle += 3.f;
	m_tInfo.fX -= m_fSpeed * cosf(m_fAngle * (PI / 180.f));
	m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * (PI / 180.f));

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CTorielLaserBullet::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_PHASE)
		m_bDead = false;
	else
		m_bDead = true;

}

void CTorielLaserBullet::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Toriel_Bullet");


	if (m_tInfo.fY > 330.f && m_tInfo.fY < 480.f && (m_tRect.left > 290.f) && (m_tRect.right < 515.f)) {
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

void CTorielLaserBullet::Release(void)
{
}

