#include "stdafx.h"
#include "TorielMercy.h"
#include "Toriel.h"
#include "MyButton.h"
#include "MessageBlock.h"
#include "PlayerState.h"
#include "SoundMgr.h"

CTorielMercy::CTorielMercy()
{
}

CTorielMercy::~CTorielMercy()
{
    Release();
}

void CTorielMercy::Initialize(void)
{
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());

}

void CTorielMercy::Update(void)
{
    CObjMgr::Get_Instance()->Update();
}

void CTorielMercy::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();

    if (m_dwTime + 10000 < GetTickCount()) {
        CSceneMgr::Get_Instance()->Scene_Change(ENDING);
        CSoundMgr::Get_Instance()->StopSound(SOUND_BGM);
    }
}

void CTorielMercy::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Boss");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);

}

void CTorielMercy::Release(void)
{
}
