#include "stdafx.h"
#include "TorielIdle.h"
#include "Toriel.h"
#include "MyButton.h"
#include "MessageBlock.h"
#include "PlayerState.h"

CTorielIdle::CTorielIdle()
{
}

CTorielIdle::~CTorielIdle()
{
    Release();
}

void CTorielIdle::Initialize(void)
{
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());
}

void CTorielIdle::Update(void)
{
    CObjMgr::Get_Instance()->Update();
}

void CTorielIdle::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();

}

void CTorielIdle::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Boss");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);

}

void CTorielIdle::Release(void)
{
    CObjMgr::Get_Instance()->Delete_ID(MESSAGEBOX);

}
