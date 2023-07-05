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
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Fight.bmp", L"Fight");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Act.bmp", L"Act");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Item.bmp", L"Item");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Mercy.bmp", L"Mercy");

    CObjMgr::Get_Instance()->Add_Object(MONSTER, CAbstractFactory<CToriel>::Create());
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CPlayerState>::Create());
    CObjMgr::Get_Instance()->Add_Object(BATTLE_PLAYER, CAbstractFactory<CPlayerBattle>::Create(400.f, 400.f));

    CObj* pObj = CAbstractFactory<CMyButton>::Create(100.f, 570.f);
    pObj->Set_FrameKey(L"Fight");
    CObjMgr::Get_Instance()->Add_Object(BUTTON, pObj);

    pObj = CAbstractFactory<CMyButton>::Create(300.f, 570.f);
    pObj->Set_FrameKey(L"Act");
    CObjMgr::Get_Instance()->Add_Object(BUTTON, pObj);

    pObj = CAbstractFactory<CMyButton>::Create(500.f, 570.f);
    pObj->Set_FrameKey(L"Item");
    CObjMgr::Get_Instance()->Add_Object(BUTTON, pObj);

    pObj = CAbstractFactory<CMyButton>::Create(700.f, 570.f);
    pObj->Set_FrameKey(L"Mercy");
    CObjMgr::Get_Instance()->Add_Object(BUTTON, pObj);
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
    CObjMgr::Get_Instance()->Destroy_Instance();
    }