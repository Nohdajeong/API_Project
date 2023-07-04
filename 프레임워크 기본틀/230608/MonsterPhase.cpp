#include "stdafx.h"
#include "MonsterPhase.h"
#include "Look.h"
#include "MyButton.h"
#include "MessageBlock.h"
#include "Player_Battle.h"
#include "LookBullet.h"

CMonsterPhase::CMonsterPhase()
{
}

CMonsterPhase::~CMonsterPhase()
{
    Release();
}

void CMonsterPhase::Initialize(void)
{
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Back_Monster.bmp", L"Back_Monster");

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Fight.bmp", L"Fight");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Act.bmp", L"Act");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Item.bmp", L"Item");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Mercy.bmp", L"Mercy");

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


    CObjMgr::Get_Instance()->Add_Object(MONSTER, CAbstractFactory<CLook>::Create(300.f, 250.f));
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create(400.f, 400.f));
    CObjMgr::Get_Instance()->Add_Object(BATTLE_PLAYER, CAbstractFactory<CPlayerBattle>::Create(400.f, 400.f));
    
    for (int i = 0; i < 10; ++i) {
        
        CObjMgr::Get_Instance()->Add_Object(BULLET, CAbstractFactory<CLooKBullet>::Create((float)(rand() % 100 + 400), (float)(rand() % 100 + 400)));
    }

}

void CMonsterPhase::Update(void)
{

    CObjMgr::Get_Instance()->Update();

}

void CMonsterPhase::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();

    if (m_dwTime + 5000 < GetTickCount())
        CSceneMgr::Get_Instance()->Scene_Change(MONSTER_IDLE);
}

void CMonsterPhase::Render(HDC hDC)
{
    CObjMgr::Get_Instance()->Render(hDC);

}

void CMonsterPhase::Release(void)
{
    CObjMgr::Get_Instance()->Destroy_Instance();
}
