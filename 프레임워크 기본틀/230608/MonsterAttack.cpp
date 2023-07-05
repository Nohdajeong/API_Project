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
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Fight.bmp", L"Fight");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Act.bmp", L"Act");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Item.bmp", L"Item");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Mercy.bmp", L"Mercy");


    CObjMgr::Get_Instance()->Add_Object(MONSTER, CAbstractFactory<CLook>::Create());
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());
    CObjMgr::Get_Instance()->Add_Object(BAR, CAbstractFactory<CPlayer_Attack>::Create(400.f, 400.f));
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CPlayerState>::Create());

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
    CObjMgr::Get_Instance()->Destroy_Instance();
}