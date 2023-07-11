#include "stdafx.h"
#include "Stage_Toriel.h"
#include "CollisionMgr.h"
#include "SoundMgr.h"
#include "MessageTextBlock.h"
#include "Save.h"
#include "TorielNPC.h"
#include "Toriel_Wall.h"
#include "Mushroom.h"

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

	CSoundMgr::Get_Instance()->PlayBGM(L"FallenDown.mp3", g_fSound);

	CObjMgr::Get_Instance()->Get_Player()->Set_Pos(400.f, 1150.f);
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Map/Toriel.bmp", L"Toriel_map");
	CObjMgr::Get_Instance()->Add_Object(STAGE_OBJ, CAbstractFactory<CSave>::Create());

	CObjMgr::Get_Instance()->Add_Object(WALL, CAbstractFactory<CMushroom>::Create());

	CObjMgr::Get_Instance()->Add_Object(NPC, CAbstractFactory<CTorielNPC>::Create(400.f, 250.f));

	CScrollMgr::Get_Instance()->Scroll_reset(0.f, -500.f);

	Walls();
}

void CStage3::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CStage3::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();

	CScrollMgr::Get_Instance()->Scroll_Lock(800, 1200);

	CCollisionMgr::Collision_RectEx(
		CObjMgr::Get_Instance()->Get_Objects(PLAYER),
		CObjMgr::Get_Instance()->Get_Objects(WALL));

	CObj* pPlayer = CObjMgr::Get_Instance()->Get_Player();

	if (CCollisionMgr::Check_Collision(
		CObjMgr::Get_Instance()->Get_Objects(PLAYER),
		CObjMgr::Get_Instance()->Get_Objects(NPC)))
			CSceneMgr::Get_Instance()->Scene_Change(BOSS_MATCH);
	 
	if (CCollisionMgr::Check_Collision(
		CObjMgr::Get_Instance()->Get_Objects(PLAYER),
		CObjMgr::Get_Instance()->Get_Objects(STAGE_OBJ)))
		CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageTextBlock>::Create(400.f, 500.f));

	if (1200.f < pPlayer->Get_Info().fY)
		CSceneMgr::Get_Instance()->Scene_Change(FLOWEY);

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
	CSoundMgr::Get_Instance()->StopSound(SOUND_BGM);
}

void CStage3::Walls()
{
	for (int i = 0; i < 3; i++) {
		CObjMgr::Get_Instance()->Add_Object(WALL, CAbstractFactory<CTorielWall>::Create(100.f + i * 100.f, 250.f));
		CObjMgr::Get_Instance()->Add_Object(WALL, CAbstractFactory<CTorielWall>::Create(500.f + i * 100.f, 250.f));
	}
}
