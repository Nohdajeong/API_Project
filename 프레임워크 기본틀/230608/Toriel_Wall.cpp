#include "stdafx.h"
#include "Toriel_Wall.h"
#include "ScrollMgr.h"
#include "SceneMgr.h"

CTorielWall::CTorielWall()
{
}

CTorielWall::~CTorielWall()
{
	Release();
}

void CTorielWall::Initialize(void)
{
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_eRender = GAMEOBJECT;

}

int CTorielWall::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CTorielWall::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() != TORIEL)
		m_bDead = true;
}

void CTorielWall::Render(HDC hDC)
{

}

void CTorielWall::Release(void)
{
}