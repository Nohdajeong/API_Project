#include "stdafx.h"
#include "MonsterBattle.h"
#include "Look.h"
#include "MyButton.h"
#include "MessageBlock.h"

CBattle::CBattle()
{
}

CBattle::~CBattle()
{
    Release();
}

void CBattle::Initialize(void)
{
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Back_Monster.bmp", L"Back_Monster");

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Fight.bmp", L"Fight");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Act.bmp", L"Act");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Item.bmp", L"Item");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Mercy.bmp", L"Mercy");

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

void CBattle::Update(void)
{
    CObjMgr::Get_Instance()->Update();
}

void CBattle::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();


}

void CBattle::Render(HDC hDC)
{
    AddFontResourceA("NeoµÕ±Ù¸ð.ttf");

    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Monster");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
    CObjMgr::Get_Instance()->Render(hDC);

    SetBkMode(hDC, 1);
    SetTextColor(hDC, RGB(255, 255, 255));
    HFONT	hFont, oldFont;

    hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("NeoµÕ±Ù¸ð"));
    oldFont = (HFONT)SelectObject(hDC, hFont);

    TextOut(hDC, 70.f, 500.f, L"FRISK", lstrlen(L"FRISK"));


}

void CBattle::Release(void)
{
}
