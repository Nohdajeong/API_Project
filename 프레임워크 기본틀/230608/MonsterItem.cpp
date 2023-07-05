#include "stdafx.h"
#include "MonsterItem.h"
#include "Look.h"
#include "MyButton.h"
#include "MessageBlock.h"
#include "PlayerState.h"

CMonsterItem::CMonsterItem()
{
}

CMonsterItem::~CMonsterItem()
{
    Release();
}

void CMonsterItem::Initialize(void)
{
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Fight.bmp", L"Fight");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Act.bmp", L"Act");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Item.bmp", L"Item");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Mercy.bmp", L"Mercy");

    CObjMgr::Get_Instance()->Add_Object(MONSTER, CAbstractFactory<CLook>::Create());
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());
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

void CMonsterItem::Update(void)
{
    CObjMgr::Get_Instance()->Update();
}

void CMonsterItem::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();

    if (m_dwTime + 5000 < GetTickCount())
        CSceneMgr::Get_Instance()->Scene_Change(MONSTER_PHASE);

}

void CMonsterItem::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Monster");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);

}

void CMonsterItem::Release(void)
{
    CObjMgr::Get_Instance()->Destroy_Instance();
}
