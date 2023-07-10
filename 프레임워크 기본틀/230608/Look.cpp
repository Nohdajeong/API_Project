#include "stdafx.h"
#include "Look.h"
#include "CollisionMgr.h"
#include "SoundMgr.h"
#include "MonsterState.h"

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
	m_iMaxHp = 50;

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
//»õÄÞ´ÞÄÞ Àß¸Ô¾ú´Ù -±«µµ 139
void CLook::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() == RUIN)
		Set_Dead();

}

void CLook::Render(HDC hDC)
{
	float g_fSound = 3.f;


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

	if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_MERCY) {
		m_tFrame.iFrameStart = 0;
		m_tFrame.iFrameEnd = 0;
		m_tFrame.iMotion = 1;

	}
}

void CLook::Release(void)
{
}