#include "stdafx.h"
#include "Stage1.h"

CStage1::CStage1()
{
}

CStage1::~CStage1()
{
	Release();
}

void CStage1::Initialize() 
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Map/Ruin.bmp", L"Ruin");
	CObjMgr::Get_Instance()->Add_Object(PLAYER, CAbstractFactory<CPlayerS1>::Create());

}

void CStage1::Update()
{
	CObjMgr::Get_Instance()->Update();
}


void CStage1::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
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
	CBmpMgr::Destroy_Instance();
	CObjMgr::Get_Instance()->Release();
}

SCENEID CStage1::UpdateScene()
{
	int	iRand = rand() % 10000;

	CObj* pPlayer = CObjMgr::Get_Instance()->Get_Player();

	if ((1200.f < pPlayer->Get_Info().fX) && (350.f > pPlayer->Get_Info().fY)) {
			return FLOWEY;
	}



	return RUIN;
}

