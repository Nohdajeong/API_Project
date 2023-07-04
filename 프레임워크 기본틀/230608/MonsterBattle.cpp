#include "stdafx.h"
#include "MonsterBattle.h"
#include "Look.h"
#include "MyButton.h"
#include "MessageBlock.h"
#include "PlayerState.h"

CMonsterMatch::CMonsterMatch()
{
}

CMonsterMatch::~CMonsterMatch()
{
    Release();
}

void CMonsterMatch::Initialize(void)
{
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Back_Monster.bmp", L"Back_Monster");

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Fight.bmp", L"Fight");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Act.bmp", L"Act");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Item.bmp", L"Item");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Mercy.bmp", L"Mercy");

    CObjMgr::Get_Instance()->Add_Object(MONSTER, CAbstractFactory<CLook>::Create(300.f, 250.f));
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create(400.f, 400.f));
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

void CMonsterMatch::Update(void)
{
    CObjMgr::Get_Instance()->Update();
}

void CMonsterMatch::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();


}

void CMonsterMatch::Render(HDC hDC)
{
    CObjMgr::Get_Instance()->Render(hDC);
}

void CMonsterMatch::Release(void)
{
    CObjMgr::Get_Instance()->Delete_ID(MONSTER);
    CObjMgr::Get_Instance()->Delete_ID(MESSAGEBOX);
}
