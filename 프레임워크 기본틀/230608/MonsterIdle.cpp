#include "stdafx.h"
#include "MonsterIdle.h"
#include "MessageBlock.h"

CMonsterIdle::CMonsterIdle()
{
}

CMonsterIdle::~CMonsterIdle()
{
    Release();
}

void CMonsterIdle::Initialize(void)
{
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());
}

void CMonsterIdle::Update(void)
{
    CObjMgr::Get_Instance()->Update();
}

void CMonsterIdle::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();

}

void CMonsterIdle::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Monster");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);

}

void CMonsterIdle::Release(void)
{
    CObjMgr::Get_Instance()->Delete_ID(MESSAGEBOX);

}
