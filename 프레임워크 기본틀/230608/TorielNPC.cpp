#include "stdafx.h"
#include "TorielNPC.h"
#include "ScrollMgr.h"
#include "SceneMgr.h"

CTorielNPC::CTorielNPC()
{
}

CTorielNPC::~CTorielNPC()
{
	Release();
}

void CTorielNPC::Initialize(void)
{
	m_tInfo.fCX = 72.f;
	m_tInfo.fCY = 102.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Monster/Toriel_stage.bmp", L"TorielStage");

	m_eRender = GAMEOBJECT;

}

int CTorielNPC::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CTorielNPC::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() != TORIEL)
		Set_Dead();
}

void CTorielNPC::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"TorielStage");

	GdiTransparentBlt(hDC,
		(int)m_tRect.left + iScrollX,
		(int)m_tRect.top + iScrollY,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		hMemDC,
		0,
		0,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(195, 134, 255));
}

void CTorielNPC::Release(void)
{
}

