#include "stdafx.h"
#include "Stage4.h"

#include "NewPlayer.h"
#include "Boss.h"

CStage4::CStage4()
{
}

CStage4::~CStage4()
{
	Release();
}


void CStage4::Initialize()
{
	LINEPOINT	tLine[6] = {
		{ 100.f, 450.f },
		{ 300.f, 450.f },
		{ 500.f, 250.f },
		{ 700.f, 250.f },

		{ 100.f, 250.f },
		{ 300.f, 250.f },
	};


	CObjMgr::Get_Instance()->Add_Object(PLAYER, CAbstractFactory<CNewPlayer>::Create(tLine[1].fX, tLine[1].fY));

	CObjMgr::Get_Instance()->Add_Object(MONSTER, CAbstractFactory<Boss>::Create(tLine[2].fX + 70, tLine[2].fY));

	CLineMgr::Get_Instance()->Add_Line(tLine[0], tLine[1]);
	CLineMgr::Get_Instance()->Add_Line(tLine[1], tLine[2]);
	CLineMgr::Get_Instance()->Add_Line(tLine[2], tLine[3]);

	CLineMgr::Get_Instance()->Add_Line(tLine[4], tLine[5]);
}

void CStage4::Update()
{
	CObjMgr::Get_Instance()->Update();
}


void CStage4::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();

	CCollisionMgr::Collision_Sphere(
		CObjMgr::Get_Instance()->Get_Objects(MOUSE),
		CObjMgr::Get_Instance()->Get_Objects(MONSTER)
	);
}

void CStage4::Render(HDC hDC)
{
	Rectangle(hDC, 0, 0, WINCX, WINCY);
	Rectangle(hDC, 100, 100, WINCX - 100, WINCY - 100);

	CObjMgr::Get_Instance()->Render(hDC);
	CLineMgr::Get_Instance()->Render(hDC);

	TCHAR	szBuff[32] = L"";
	swprintf_s(szBuff, L"Stage4");
	TextOut(hDC, 100, 80, szBuff, lstrlen(szBuff));

}

void CStage4::Release()
{
	CLineMgr::Destroy_Instance();
	CObjMgr::Get_Instance()->Release();
}

SCENEID CStage4::UpdateScene()
{
	CObj* pPlayer = CObjMgr::Get_Instance()->Get_Player();
	if (100.f > pPlayer->Get_Info().fX)
	{
		return LOADING3;
	}

	return STAGE4;
}