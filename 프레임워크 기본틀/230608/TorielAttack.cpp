#include "stdafx.h"
#include "TorielAttack.h"
#include "MessageBlock.h"
#include "Attack_Bar.h"
#include "Attack_Motion.h"

CTorielAttack::CTorielAttack()
{
}

CTorielAttack::~CTorielAttack()
{
    Release();
}

void CTorielAttack::Initialize(void)
{
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());
    CObjMgr::Get_Instance()->Add_Object(BAR, CAbstractFactory<CPlayer_Attack>::Create(400.f, 400.f));
}

void CTorielAttack::Update(void)
{
    CObjMgr::Get_Instance()->Update();

    CObj* pAttack = CObjMgr::Get_Instance()->Get_Objects(BAR).front();

    if (pAttack->Get_Speed() == 0) {
        if (m_dwTime + 700 < GetTickCount64()) {
            CObjMgr::Get_Instance()->Add_Object(ATTACK, CAbstractFactory<CAttackMotion>::Create());
        }
    }

}

void CTorielAttack::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();

    if (m_dwTime + 4000 < GetTickCount64()) {
        CSceneMgr::Get_Instance()->Scene_Change(BOSS_PHASE);
        return;
    }
}

void CTorielAttack::Render(HDC hDC)
{

    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Boss");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);

}

void CTorielAttack::Release(void)
{
    CObjMgr::Get_Instance()->Delete_ID(MESSAGEBOX);
}