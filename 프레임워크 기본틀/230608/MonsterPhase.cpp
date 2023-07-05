#include "stdafx.h"
#include "MonsterPhase.h"
#include "Look.h"
#include "MyButton.h"
#include "MessageBlock.h"
#include "Player_Battle.h"
#include "LookBullet.h"
#include "CollisionMgr.h"
#include "PlayerState.h"

CMonsterPhase::CMonsterPhase()
{
}

CMonsterPhase::~CMonsterPhase()
{
    Release();
}

void CMonsterPhase::Initialize(void)
{
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Fight.bmp", L"Fight");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Act.bmp", L"Act");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Item.bmp", L"Item");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Mercy.bmp", L"Mercy");

    CObjMgr::Get_Instance()->Add_Object(MONSTER, CAbstractFactory<CLook>::Create());
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CPlayerState>::Create());
    CObjMgr::Get_Instance()->Add_Object(BATTLE_PLAYER, CAbstractFactory<CPlayerBattle>::Create(400.f, 400.f));

    for (int i = 0; i < 10; ++i) {
        
        CObjMgr::Get_Instance()->Add_Object(BULLET, CAbstractFactory<CLooKBullet>::Create((float)(rand() % 100 + 400), (float)(rand() % 100 + 400)));
    }

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

void CMonsterPhase::Update(void)
{

    CObjMgr::Get_Instance()->Update();

}

void CMonsterPhase::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();

    CCollisionMgr::Collision_Sphere(
        CObjMgr::Get_Instance()->Get_Objects(BATTLE_PLAYER),
        CObjMgr::Get_Instance()->Get_Objects(BULLET)
    );


    if (m_dwTime + 5000 < GetTickCount())
        CSceneMgr::Get_Instance()->Scene_Change(MONSTER_IDLE);
}

void CMonsterPhase::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Monster");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);

}

void CMonsterPhase::Release(void)
{
    CObjMgr::Get_Instance()->Destroy_Instance();
    }