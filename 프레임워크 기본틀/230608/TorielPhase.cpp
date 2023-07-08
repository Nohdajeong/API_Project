#include "stdafx.h"
#include "TorielPhase.h"
#include "MessageBlock.h"
#include "CollisionMgr.h"
#include "TorielBullet.h"
#include "TorielPassBullet.h"

CTorielPhase::CTorielPhase()
{
}

CTorielPhase::~CTorielPhase()
{
    Release();
}

void CTorielPhase::Initialize(void)
{
    CObjMgr::Get_Instance()->Get_BattlePlayer()->Set_Pos(400.f, 400.f);
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());

    m_iMonsterPhase = rand() % 100;

}

void CTorielPhase::Update(void)
{
    CObj* pPlayer = CObjMgr::Get_Instance()->Get_BattlePlayer();
    CObj* pMonster = CObjMgr::Get_Instance()->Get_Monster();

    if (m_iMonsterPhase % 3 == 0) {
        if (m_preDeley + 200.f < GetTickCount64()) {
            Boss_Phase1();
            m_preDeley = GetTickCount64();
        }
    }
    else if (m_iMonsterPhase % 3 == 1) {
        if (pPlayer->Get_Hp() < 2) {
            if (m_preDeley + 50.f < GetTickCount64()) {
                Boss_Phase2();
                m_preDeley = GetTickCount64();
            }
        }
        else{
            if (m_preDeley + 200.f < GetTickCount64()) {
                Boss_Phase1();
                m_preDeley = GetTickCount64();
            }

        }
    }
    else if (m_iMonsterPhase % 3 == 2) {
        if (pPlayer->Get_Hp() < 2) {
            if (m_preDeley + 50.f < GetTickCount64()) {
                Boss_Phase2();
                m_preDeley = GetTickCount64();
            }
        }
        else {
            if (m_preDeley + 200.f < GetTickCount64()) {
                Boss_Phase1();
                m_preDeley = GetTickCount64();
            }

        }
    }


    CObjMgr::Get_Instance()->Update();

}

void CTorielPhase::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();

    CCollisionMgr::Collision_Sphere(
        CObjMgr::Get_Instance()->Get_Objects(BATTLE_PLAYER),
        CObjMgr::Get_Instance()->Get_Objects(BULLET)
    );

    if (m_dwTime + 5000 < GetTickCount64()) {
        CSceneMgr::Get_Instance()->Scene_Change(BOSS_IDLE);
        return;
    }
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

void CTorielPhase::Boss_Phase1()
{
   CObjMgr::Get_Instance()->Add_Object(BULLET, CAbstractFactory<CTorielBullet>::Create(350.f, 300.f));
   CObjMgr::Get_Instance()->Add_Object(BULLET, CAbstractFactory<CTorielBullet>::Create(450.f, 300.f));
}

void CTorielPhase::Boss_Phase2()
{
    CObjMgr::Get_Instance()->Add_Object(BULLET, CAbstractFactory<CTorielPassBullet>::Create(300.f + rand()%200, 300.f));
}

void CTorielPhase::Boss_Phase3()
{
}
