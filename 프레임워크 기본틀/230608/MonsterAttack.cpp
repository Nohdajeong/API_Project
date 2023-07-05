#include "stdafx.h"
#include "MonsterAttack.h"
#include "Look.h"
#include "MyButton.h"
#include "MessageBlock.h"
#include "Attack_Bar.h"
#include "PlayerState.h"

CMonsterAttack::CMonsterAttack()
    : m_iLevel(1), m_iHp(0), m_iMaxHp(0)
{
}

CMonsterAttack::~CMonsterAttack()
{
    Release();
}

void CMonsterAttack::Initialize(void)
{
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());
    CObjMgr::Get_Instance()->Add_Object(BAR, CAbstractFactory<CPlayer_Attack>::Create(400.f, 400.f));

}

void CMonsterAttack::Update(void)
{
    CObjMgr::Get_Instance()->Update();
}

void CMonsterAttack::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();

    if (m_dwTime + 7000 < GetTickCount())
        CSceneMgr::Get_Instance()->Scene_Change(MONSTER_PHASE);
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
    CObjMgr::Get_Instance()->Delete_ID(BAR);
}