#include "stdafx.h"
#include "TorielAttack.h"
#include "Toriel.h"
#include "MyButton.h"
#include "MessageBlock.h"
#include "Attack_Bar.h"
#include "PlayerState.h"

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
}

void CTorielAttack::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();

    if (m_dwTime + 7000 < GetTickCount())
        CSceneMgr::Get_Instance()->Scene_Change(BOSS_PHASE);
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