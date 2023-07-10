#include "stdafx.h"
#include "MonsterAttack.h"
#include "MessageBlock.h"
#include "Attack_Bar.h"
#include "Attack_Motion.h"
#include "CollisionMgr.h"
#include "MonsterState.h"

CMonsterAttack::CMonsterAttack()
{
}

CMonsterAttack::~CMonsterAttack()
{
    Release();
}

void CMonsterAttack::Initialize(void)
{
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());
    CObjMgr::Get_Instance()->Add_Object(BAR, CAbstractFactory<CPlayer_Attack>::Create());
    CObjMgr::Get_Instance()->Add_Object(MONSTER_STATE, CAbstractFactory<CMonsterState>::Create());

}

void CMonsterAttack::Update(void)
{
    CObjMgr::Get_Instance()->Update();
}

void CMonsterAttack::Late_Update(void)
{
    CObj* pAttack = CObjMgr::Get_Instance()->Get_Objects(BAR).front();

    if (pAttack->Get_Speed() == 0) {
        if (m_dwTime + 700 < GetTickCount64()) {
            CObjMgr::Get_Instance()->Add_Object(ATTACK, CAbstractFactory<CAttackMotion>::Create());
        }
    }

    if (CCollisionMgr::Check_Collision(
        CObjMgr::Get_Instance()->Get_Objects(MONSTER),
        CObjMgr::Get_Instance()->Get_Objects(ATTACK))) {

        if (m_dwTime + 4000 < GetTickCount64()) {
            CObjMgr::Get_Instance()->Get_Monster()->Set_Hp(-CObjMgr::Get_Instance()->Get_Objects(BAR).front()->Get_Attack());
        }
    }

    CObjMgr::Get_Instance()->Late_Update();

    if (CObjMgr::Get_Instance()->Get_Monster()->Get_Hp() <= 0) {
        CSceneMgr::Get_Instance()->Scene_Change(MONSTER_MERCY);
        return;
    }

    else if (m_dwTime + 4000 < GetTickCount64()) {
            CSceneMgr::Get_Instance()->Scene_Change(MONSTER_PHASE);
            return;
    }
}

void CMonsterAttack::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Monster");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);

}

void CMonsterAttack::Release(void)
{
    CObjMgr::Get_Instance()->Delete_ID(MESSAGEBOX);
}