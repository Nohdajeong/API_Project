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
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());

}

void CMonsterItem::Update(void)
{
    CObjMgr::Get_Instance()->Update();

}

void CMonsterItem::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();


    if (m_dwTime + 5000 < GetTickCount()) {
        CSceneMgr::Get_Instance()->Scene_Change(MONSTER_PHASE);
        return;
    }
}

void CMonsterItem::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Monster");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);

}

void CMonsterItem::Release(void)
{
    CObjMgr::Get_Instance()->Delete_ID(MESSAGEBOX);
}
