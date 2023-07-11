#include "stdafx.h"
#include "Wall.h"
#include "SceneMgr.h"

CWall::CWall()
{
}

CWall::~CWall()
{
	Release();
}

void CWall::Initialize(void)
{
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_eRender = GAMEOBJECT;

}

int CWall::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CWall::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() != RUIN)
		m_bDead = true;
}

void CWall::Render(HDC hDC)
{

}

void CWall::Release(void)
{
}