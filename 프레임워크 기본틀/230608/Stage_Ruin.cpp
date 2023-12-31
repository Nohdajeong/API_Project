#include "stdafx.h"
#include "Stage_Ruin.h"
#include "PlayerS1.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "Wall.h"

CStage1::CStage1()
{
}

CStage1::~CStage1()
{
	Release();
}

void CStage1::Initialize() 
{
	CSoundMgr::Get_Instance()->StopSound(SOUND_BGM);

	if(CSceneMgr::Get_Instance()->Get_ScenePreID() == INTRO)
		CObjMgr::Get_Instance()->Add_Object(PLAYER, CAbstractFactory<CPlayerS1>::Create(400.f, 300.f));

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Map/Ruin_Back.bmp", L"Ruin_Back");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Map/Ruin.bmp", L"Ruin");

	Walls();
}


void CStage1::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CStage1::Late_Update()
{
	CCollisionMgr::Collision_RectEx(
		CObjMgr::Get_Instance()->Get_Objects(PLAYER),
		CObjMgr::Get_Instance()->Get_Objects(WALL));

	CObjMgr::Get_Instance()->Late_Update();

	CObj* pPlayer = CObjMgr::Get_Instance()->Get_Player();

	if (CKeyMgr::Get_Instance()->Key_Down('P'))
		CSceneMgr::Get_Instance()->Scene_Change(TORIEL);

	if (CKeyMgr::Get_Instance()->Key_Down('R'))
		CSceneMgr::Get_Instance()->Scene_Change(FLOWEY);

	if (m_dwTime + 5000 < GetTickCount64()) {
		CSceneMgr::Get_Instance()->Scene_Change(MONSTER_MATCH);
		m_dwTime = (DWORD)GetTickCount64();
		return;
	}

	if ((1200.f < pPlayer->Get_Info().fX) && (330.f > pPlayer->Get_Info().fY)) {
		CSceneMgr::Get_Instance()->Scene_Change(FLOWEY);
	}


}

void CStage1::Render(HDC hDC)
{
	HDC		hBackDC = CBmpMgr::Get_Instance()->Find_Img(L"Ruin_Back");
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Ruin");

	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	BitBlt(hDC, 0, 0, 1700, 600, hBackDC, 0, 0, SRCCOPY);
	BitBlt(hDC,	iScrollX, iScrollY, 1700, 600, hMemDC, 0, 0, SRCCOPY);

	CObjMgr::Get_Instance()->Render(hDC);
}

void CStage1::Release()
{
}

void CStage1::Walls()
{
	CObjMgr::Get_Instance()->Add_Object(WALL, CAbstractFactory<CWall>::Create(140.f, 80.f));
	CObjMgr::Get_Instance()->Add_Object(WALL, CAbstractFactory<CWall>::Create(140.f, 510.f));
	CObjMgr::Get_Instance()->Add_Object(WALL, CAbstractFactory<CWall>::Create(90.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(WALL, CAbstractFactory<CWall>::Create(180.f, 560.f));

	CObjMgr::Get_Instance()->Add_Object(WALL, CAbstractFactory<CWall>::Create(615.f, 555.f));
	CObjMgr::Get_Instance()->Add_Object(WALL, CAbstractFactory<CWall>::Create(640.f, 80.f));
	CObjMgr::Get_Instance()->Add_Object(WALL, CAbstractFactory<CWall>::Create(670.f, 510.f));
	CObjMgr::Get_Instance()->Add_Object(WALL, CAbstractFactory<CWall>::Create(1650.f, 400.f));


	for (int i = 0; i < 4; i++) {
		CObjMgr::Get_Instance()->Add_Object(WALL, CAbstractFactory<CWall>::Create(240.f + i * 100, 30.f));
		CObjMgr::Get_Instance()->Add_Object(WALL, CAbstractFactory<CWall>::Create(240.f + i * 100, 570.f));
	}

	for (int i = 0; i < 2; i++) {
		CObjMgr::Get_Instance()->Add_Object(WALL, CAbstractFactory<CWall>::Create(50.f, 230.f + i * 100));
		CObjMgr::Get_Instance()->Add_Object(WALL, CAbstractFactory<CWall>::Create(750.f, 175.f + i * 100));
	}

	for (int i = 0; i < 6; i++) {
		CObjMgr::Get_Instance()->Add_Object(WALL, CAbstractFactory<CWall>::Create(750.f + 100 * (i + 1), 275.f));
	}

	for (int i = 0; i < 9; i++)
		CObjMgr::Get_Instance()->Add_Object(WALL, CAbstractFactory<CWall>::Create(670.f + 100 * (i + 1), 510.f));
}
