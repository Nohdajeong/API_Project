#include "stdafx.h"
#include "Stage2.h"

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
}

void CStage2::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Flowey_map");

	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	BitBlt(hDC,
		iScrollX, iScrollY, 
800, 1100,
		hMemDC,			
		0,
		0,
		SRCCOPY);

	CObjMgr::Get_Instance()->Render(hDC);

	TCHAR	szBuff[32] = L"";
	swprintf_s(szBuff, L"TestStage");
	TextOut(hDC, 100, 80, szBuff, lstrlen(szBuff));
}

void CStage2::Release()
{
	CBmpMgr::Destroy_Instance();
	CObjMgr::Get_Instance()->Release();
}

SCENEID CStage2::UpdateScene()
{
	CObj* pPlayer = CObjMgr::Get_Instance()->Get_Player();
	if (200.f > pPlayer->Get_Info().fY) {
		return RUIN;
	}

	return FLOWEY;
}