#include "stdafx.h"
#include "Chain.h"
#include "ScrollMgr.h"
#include "SceneMgr.h"
#include "KeyMgr.h"
#include "MessageQuizBlock.h"

CChain::CChain()
{
}

CChain::~CChain()
{
	Release();
}

void CChain::Initialize(void)
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Map/chain.bmp", L"chain");

	m_iDraw = 0;

	m_eRender = GAMEOBJECT;

}

int CChain::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	if (CObjMgr::Get_Instance()->Get_Objects(NPC).front()->Get_Talk() == true)
		m_iDraw = 1;

	__super::Move_Frame();
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CChain::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() != FLOWEY)
		Set_Dead();
}

void CChain::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"chain");

	GdiTransparentBlt(hDC,
		(int)m_tRect.left + iScrollX,
		(int)m_tRect.top + iScrollY,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		hMemDC,
		m_iDraw * (int)m_tInfo.fCX,
		0,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(195, 134, 255)); // 제거하고자 하는 색상
}

void CChain::Release(void)
{
}
