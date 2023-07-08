#include "stdafx.h"
#include "Stage_Toriel.h"
#include "CollisionMgr.h"
#include "SoundMgr.h"
#include "MessageBlock.h"

CStage3::CStage3()
{
}

CStage3::~CStage3()
{
	Release();
}

void CStage3::Initialize()
{
	float	g_fSound = 1.f;

	CObjMgr::Get_Instance()->Get_Player()->Set_Pos(400.f, 1150.f);
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Map/Toriel.bmp", L"Toriel_map");
	CScrollMgr::Get_Instance()->Scroll_reset(0.f, -500.f);

}

void CStage3::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CStage3::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();

	CObj* pPlayer = CObjMgr::Get_Instance()->Get_Player();

	if (250.f > pPlayer->Get_Info().fY) {
		CSceneMgr::Get_Instance()->Scene_Change(BOSS_MATCH);
	}

}

void CStage3::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Toriel_map");

	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	BitBlt(hDC, iScrollX, iScrollY, 800, 1200, hMemDC, 0, 0, SRCCOPY);

	CObjMgr::Get_Instance()->Render(hDC);
}

void CStage3::Release()
{
}