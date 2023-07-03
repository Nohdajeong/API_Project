#include "stdafx.h"
#include "BattleItem.h"
#include "Look.h"
#include "MessageBlock.h"
#include "MyButton.h"

CBattleItem::CBattleItem()
{
}

CBattleItem::~CBattleItem()
{
}

void CBattleItem::Initialize(void)
{
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Fight.bmp", L"Fight");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Act.bmp", L"Act");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Item.bmp", L"Item");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Mercy.bmp", L"Mercy");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Back_Monster.bmp", L"Back_Monster");

    CObjMgr::Get_Instance()->Add_Object(MONSTER, CAbstractFactory<CLook>::Create(300.f, 250.f));
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create(400.f, 400.f));


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

void CBattleItem::Update(void)
{
	CObjMgr::Get_Instance()->Update();

}

void CBattleItem::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CBattleItem::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Monster");
    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
    CObjMgr::Get_Instance()->Render(hDC);
}

void CBattleItem::Release(void)
{
    CObjMgr::Get_Instance()->Delete_ID(MONSTER);

}
