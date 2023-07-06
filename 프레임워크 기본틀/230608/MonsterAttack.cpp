#include "stdafx.h"
#include "MonsterAttack.h"
#include "MessageBlock.h"
#include "Attack_Bar.h"
#include "Attack_Motion.h"
#include "CollisionMgr.h"

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

}

void CMonsterAttack::Update(void)
{
    CObjMgr::Get_Instance()->Update();

    CObj* pAttack = CObjMgr::Get_Instance()->Get_Objects(BAR).front();

    if (pAttack->Get_Speed() == 0) {
        if (m_dwTime + 700 < GetTickCount64()) {
            CObjMgr::Get_Instance()->Add_Object(ATTACK, CAbstractFactory<CAttackMotion>::Create());
            if ((pAttack->Get_Info().fX > 350.f) && (pAttack->Get_Info().fX < 450.f)) {
                pAttack->Set_Attack(30);
            }
        }
    }

}

void CMonsterAttack::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();



    if (m_dwTime + 4000 < GetTickCount64()) {
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