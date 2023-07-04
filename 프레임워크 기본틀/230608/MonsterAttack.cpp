#include "stdafx.h"
#include "MonsterAttack.h"
#include "Look.h"
#include "MyButton.h"
#include "MessageBlock.h"

CAttack::CAttack()
{
}

CAttack::~CAttack()
{
    Release();
}

void CAttack::Initialize(void)
{
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create(400.f, 400.f));
}

void CAttack::Update(void)
{
    CObjMgr::Get_Instance()->Update();
}

void CAttack::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();

    if (m_dwTime + 5000 < GetTickCount())
        CSceneMgr::Get_Instance()->Scene_Change(MONSTER_PHASE);
}

void CAttack::Render(HDC hDC)
{
    AddFontResourceA("Neo�ձٸ�.ttf");

    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Monster");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
    CObjMgr::Get_Instance()->Render(hDC);

    SetBkMode(hDC, 1);
    SetTextColor(hDC, RGB(255, 255, 255));
    HFONT	hFont, oldFont;

    hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("Neo�ձٸ�"));
    oldFont = (HFONT)SelectObject(hDC, hFont);

    TextOut(hDC, 70.f, 500.f, L"FRISK", lstrlen(L"FRISK"));


}

void CAttack::Release(void)
{
    CObjMgr::Get_Instance()->Destroy_Instance();
}