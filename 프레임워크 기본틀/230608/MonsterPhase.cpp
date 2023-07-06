#include "stdafx.h"
#include "MonsterPhase.h"
#include "MessageBlock.h"
#include "LookBullet.h"
#include "CollisionMgr.h"
#include "Mention.h"
#include "LookNormalBullet.h"

CMonsterPhase::CMonsterPhase()
    : m_iMonsterPhase(0)
{
}

CMonsterPhase::~CMonsterPhase()
{
    Release();
}

void CMonsterPhase::Initialize(void)
{
    CObjMgr::Get_Instance()->Get_BattlePlayer()->Set_Pos(400.f, 400.f);
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());
    CObjMgr::Get_Instance()->Add_Object(MONSTER_MENTION, CAbstractFactory<CMention>::Create());


    m_iMonsterPhase = rand() % 100;

    if (m_iMonsterPhase % 2 == 0)
        Monster_Phase1();
    else if (m_iMonsterPhase %2 == 1)
        Monster_Phase2();
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

    if (m_dwTime + 5000 < GetTickCount64()) {
        CSceneMgr::Get_Instance()->Scene_Change(MONSTER_IDLE);
        return;
    }
}

void CMonsterPhase::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Monster");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);

}

void CMonsterPhase::Release(void)
{
    CObjMgr::Get_Instance()->Delete_ID(MESSAGEBOX);

}

void CMonsterPhase::Monster_Phase1()
{
    for (int i = 0; i < 5; ++i)
        CObjMgr::Get_Instance()->Add_Object(BULLET, CAbstractFactory<CLooKBullet>::Create(300.f + i * 50, 300.f));

}

void CMonsterPhase::Monster_Phase2()
{
    for (int i = 0; i < 3; ++i) {
        CObjMgr::Get_Instance()->Add_Object(BULLET, CAbstractFactory<CLooKNormalBullet>::Create(330.f, 400.f + i * 30));
    }
    for (int i = 0; i < 3; ++i)
        CObjMgr::Get_Instance()->Add_Object(BULLET, CAbstractFactory<CLooKNormalBullet>::Create(460.f, 430.f - i * 30));

}
