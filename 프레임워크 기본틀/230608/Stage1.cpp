#include "stdafx.h"
#include "Stage1.h"
#include "KeyMgr.h"

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
	
}

void CStage1::Update()
{
	CObjMgr::Get_Instance()->Update();
}


void CStage1::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();

	CCollisionMgr::Collision_Sphere(
		CObjMgr::Get_Instance()->Get_Objects(MOUSE),
		CObjMgr::Get_Instance()->Get_Objects(MONSTER)
	);
}

void CStage1::Render(HDC hDC)
{
	Rectangle(hDC, 0, 0, WINCX, WINCY);

	CObjMgr::Get_Instance()->Render(hDC);
	CLineMgr::Get_Instance()->Render(hDC);

	TCHAR	szBuff[32] = L"";
	swprintf_s(szBuff, L"TestStage");
	TextOut(hDC, 100, 80, szBuff, lstrlen(szBuff));
}

void CStage1::Release()
{
	CLineMgr::Destroy_Instance();
	CObjMgr::Get_Instance()->Release();
}

SCENEID CStage1::UpdateScene()
{
	CObj* pPlayer = CObjMgr::Get_Instance()->Get_Player();
	if (1500.f < pPlayer->Get_Info().fX) {
		return FLOWEY;
	}

	return RUIN;
}

