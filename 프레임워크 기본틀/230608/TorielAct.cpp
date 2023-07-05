#include "stdafx.h"
#include "TorielAct.h"
#include "Toriel.h"
#include "MyButton.h"
#include "MessageBlock.h"
#include "PlayerState.h"

CTorielAct::CTorielAct()
{
}

CTorielAct::~CTorielAct()
{
    Release();
}

void CTorielAct::Initialize(void)
{
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());

}

void CTorielAct::Update(void)
{
    CObjMgr::Get_Instance()->Update();
}

void CTorielAct::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();

    if (m_dwTime + 5000 < GetTickCount())
        CSceneMgr::Get_Instance()->Scene_Change(BOSS_PHASE);


}

void CTorielAct::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Boss");


    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);

}

void CTorielAct::Release(void)
{
    CObjMgr::Get_Instance()->Delete_ID(MESSAGEBOX);
}
