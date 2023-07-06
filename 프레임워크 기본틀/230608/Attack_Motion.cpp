#include "stdafx.h"
#include "Attack_Motion.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "BmpMgr.h"
#include "SoundMgr.h"
#include "SceneMgr.h"

CAttackMotion::CAttackMotion()
{
}

CAttackMotion::~CAttackMotion()
{
	Release();
}


void CAttackMotion::Initialize(void)
{
	CObj* pMonster = CObjMgr::Get_Instance()->Get_Monster();
	CObj* pPlayerAttack = CObjMgr::Get_Instance()->Get_Objects(BAR).front();

	m_tInfo.fX = pMonster->Get_Info().fX;
	m_tInfo.fY = pMonster->Get_Info().fY;
	m_iAttack = pPlayerAttack->Get_Attack();

	m_tInfo.fCX = 26.f;
	m_tInfo.fCY = 110.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/attack_motion.bmp", L"attack_motion");
	
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 5;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 150;
	m_tFrame.dwTime = (DWORD)GetTickCount64();

	m_eRender = EFFECT;

}

int CAttackMotion::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Move_Frame();
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CAttackMotion::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_ATTACK || CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_ATTACK)
		m_bDead = false;
	else
		m_bDead = true;

}

void CAttackMotion::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"attack_motion");

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

	swprintf_s(szBuff, L"%d", m_iAttack);
	TextOut(hDC, (int)(m_tInfo.fX + 80.f), (int)(m_tInfo.fY - 20.f), szBuff, lstrlen(szBuff));

}

void CAttackMotion::Release(void)
{
}