#include "stdafx.h"
#include "BattleMercy.h"
#include "Look.h"
#include "MessageBlock.h"
#include "MyButton.h"

CBattleMercy::CBattleMercy()
{
}

CBattleMercy::~CBattleMercy()
{
	Release();
}

void CBattleMercy::Initialize(void)
{
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Fight.bmp", L"Fight");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Act.bmp", L"Act");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Item.bmp", L"Item");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Mercy.bmp", L"Mercy");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Back_Monster.bmp", L"Back_Monster");

    CObjMgr::Get_Instance()->Add_Object(MONSTER, CAbstractFactory<CLook>::Create(300.f, 250.f));
    
    CObj* pObj = CAbstractFactory<CMessageBlock>::Create(400.f, 400.f);
    pObj->Set_FrameKey(L"Item");
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, pObj);

    pObj = CAbstractFactory<CMyButton>::Create(100.f, 570.f);
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

void CBattleMercy::Update(void)
{
	CObjMgr::Get_Instance()->Update();

}

void CBattleMercy::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CBattleMercy::Render(HDC hDC)
{
	CObjMgr::Get_Instance()->Render(hDC);
}

void CBattleMercy::Release(void)
{
    CObjMgr::Get_Instance()->Delete_ID(MONSTER);

}
