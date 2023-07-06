#include "stdafx.h"
#include "TorielPhase.h"
#include "Toriel.h"
#include "MyButton.h"
#include "MessageBlock.h"
#include "Player_Battle.h"
#include "CollisionMgr.h"
#include "PlayerState.h"

CTorielPhase::CTorielPhase()
{
}

CTorielPhase::~CTorielPhase()
{
    Release();
}

void CTorielPhase::Initialize(void)
{
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());
}

void CTorielPhase::Update(void)
{

    CObjMgr::Get_Instance()->Update();

}

void CTorielPhase::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();

    CCollisionMgr::Collision_Sphere(
        CObjMgr::Get_Instance()->Get_Objects(BATTLE_PLAYER),
        CObjMgr::Get_Instance()->Get_Objects(BULLET)
    );


    if (m_dwTime + 5000 < GetTickCount())
        CSceneMgr::Get_Instance()->Scene_Change(BOSS_IDLE);
}

void CTorielPhase::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Boss");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);

}

void CTorielPhase::Release(void)
{
    CObjMgr::Get_Instance()->Delete_ID(MESSAGEBOX);
}