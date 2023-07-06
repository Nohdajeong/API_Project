#include "stdafx.h"
#include "Attack_Bar.h"
#include "KeyMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "SceneMgr.h"
#include "Attack_Motion.h"
#include "CollisionMgr.h"

CPlayer_Attack::CPlayer_Attack()
{
}

CPlayer_Attack::~CPlayer_Attack()
{
	Release();
}

void CPlayer_Attack::Initialize(void)
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 400.f;

	m_tInfo.fCX = 17.f;
	m_tInfo.fCY = 150.f;

	m_fSpeed = 3.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/attack_line.bmp", L"Line");

	m_eRender = EFFECT;

}

int CPlayer_Attack::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	m_tInfo.fX += m_fSpeed;
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayer_Attack::Late_Update(void)
{
	if (m_tInfo.fX == 700.f || m_tInfo.fX == 100.f)
		m_fSpeed = -m_fSpeed;

	if (CKeyMgr::Get_Instance()->Key_Down(VK_SPACE))
		m_fSpeed = 0;	

	if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_ATTACK || CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_ATTACK)
		m_bDead = false;
	else
		m_bDead = true;
}

void CPlayer_Attack::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Line");
	GdiTransparentBlt(hDC,
		(int)m_tRect.left, // 복사 받을 위치 X,Y 좌표
		(int)m_tRect.top,
		(int)m_tInfo.fCX,	// 복사 받을 가로, 세로 길이
		(int)m_tInfo.fCY,
		hMemDC,			// 비트맵 이미지를 담고 있는 DC
		0,					// 비트맵을 출력할 시작 X,Y좌표
		0,
		(int)m_tInfo.fCX,		// 출력할 비트맵의 가로, 세로 사이즈
		(int)m_tInfo.fCY,
		RGB(195, 134, 255)); // 제거하고자 하는 색상

}

void CPlayer_Attack::Release(void)
{
}
