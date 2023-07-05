#include "stdafx.h"
#include "MonsterMercy.h"
#include "Look.h"
#include "MyButton.h"
#include "MessageBlock.h"
#include "PlayerState.h"

CMonsterMercy::CMonsterMercy()
{
}

CMonsterMercy::~CMonsterMercy()
{
    Release();
}

void CMonsterMercy::Initialize(void)
{
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());

}

void CMonsterMercy::Update(void)
{
    CObjMgr::Get_Instance()->Update();
}

void CMonsterMercy::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();

    if (m_dwTime + 5000 < GetTickCount())
        CSceneMgr::Get_Instance()->Scene_Change(FLOWEY);

}

void CMonsterMercy::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Monster");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);

}

void CMonsterMercy::Release(void)
{
    CObjMgr::Get_Instance()->Destroy_Instance();
}
