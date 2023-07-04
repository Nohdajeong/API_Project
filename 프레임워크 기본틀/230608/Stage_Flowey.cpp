#include "stdafx.h"
#include "Stage_Flowey.h"
#include "CollisionMgr.h"
#include "PlayerS1.h"

CStage2::CStage2()
{
}

CStage2::~CStage2()
{
	Release();
}

void CStage2::Initialize()
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Map/Flowey.bmp", L"Flowey_map");
	CObjMgr::Get_Instance()->Add_Object(PLAYER, CAbstractFactory<CPlayerS1>::Create(400, 800));
	CObjMgr::Get_Instance()->Add_Object(NPC, CAbstractFactory<CFlowey>::Create());

}

void CStage2::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CStage2::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();

	CCollisionMgr::Collision_RectEx(
		CObjMgr::Get_Instance()->Get_Objects(PLAYER),
		CObjMgr::Get_Instance()->Get_Objects(NPC)
	);

	CObj* pPlayer = CObjMgr::Get_Instance()->Get_Player();

	if (200.f > pPlayer->Get_Info().fY) {
		CSceneMgr::Get_Instance()->Scene_Change(MONSTER_MATCH);
	}

}

void CStage2::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Flowey_map");

	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	BitBlt(hDC, iScrollX, iScrollY, 800, 1100, hMemDC, 0, 0, SRCCOPY);

	CObjMgr::Get_Instance()->Render(hDC);
}

void CStage2::Release()
{
	CObjMgr::Get_Instance()->Release();
}