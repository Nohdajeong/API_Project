#include "stdafx.h"
#include "MonsterAct.h"
#include "MessageBlock.h"

CMonsterAct::CMonsterAct()
{
}

CMonsterAct::~CMonsterAct()
{
    Release();
}

void CMonsterAct::Initialize(void)
{
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());
    CObjMgr::Get_Instance()->Get_BattlePlayer()->Set_Pos(100.f, 570.f);
}

void CMonsterAct::Update(void)
{
    CObjMgr::Get_Instance()->Update();
}

void CMonsterAct::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();

    if (m_dwTime + 5000 < GetTickCount()) {
        CSceneMgr::Get_Instance()->Scene_Change(MONSTER_PHASE);
        return;
    }
}

void CMonsterAct::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Monster");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);

}

void CMonsterAct::Release(void)
{
    CObjMgr::Get_Instance()->Delete_ID(MESSAGEBOX);
}
