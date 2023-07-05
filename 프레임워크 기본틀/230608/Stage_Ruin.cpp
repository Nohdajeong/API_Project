#include "stdafx.h"
#include "Stage_Ruin.h"
#include "PlayerS1.h"
#include "SceneMgr.h"
#include "SoundMgr.h"

CStage1::CStage1()
{
}

CStage1::~CStage1()
{
	Release();
}

void CStage1::Initialize() 
{
	CObjMgr::Get_Instance()->Add_Object(PLAYER, CAbstractFactory<CPlayerS1>::Create());

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Map/Ruin.bmp", L"Ruin");
	
}

void CStage1::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CStage1::Late_Update()
{

	CObjMgr::Get_Instance()->Late_Update();

	CObj* pPlayer = CObjMgr::Get_Instance()->Get_Player();

	if ((1200.f < pPlayer->Get_Info().fX) && (350.f > pPlayer->Get_Info().fY)) {
		CSceneMgr::Get_Instance()->Scene_Change(MONSTER_MATCH);
	}

}

void CStage1::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Ruin");

	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	BitBlt(hDC,	iScrollX, iScrollY, 1700, 600, hMemDC, 0, 0, SRCCOPY);

	CObjMgr::Get_Instance()->Render(hDC);
}

void CStage1::Release()
{
	CObjMgr::Get_Instance()->Destroy_Instance();
}