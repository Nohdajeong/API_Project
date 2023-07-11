#include "stdafx.h"
#include "TorielDie.h"
#include "MessageBlock.h"
#include "SoundMgr.h"
#include "TorielDieMention.h"

CTorielDie::CTorielDie()
{
}

CTorielDie::~CTorielDie()
{
    Release();
}

void CTorielDie::Initialize(void)
{
    CObjMgr::Get_Instance()->Get_BattlePlayer()->Set_Pos(400.f, 450.f);
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create());
    CObjMgr::Get_Instance()->Add_Object(MONSTER_MENTION, CAbstractFactory<CTorielDieMention>::Create(600.f, 190.f));
}

void CTorielDie::Update(void)
{
    CObjMgr::Get_Instance()->Update();
}

void CTorielDie::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();

    if (m_dwTime + 8000 < GetTickCount()) {
        CSoundMgr::Get_Instance()->StopSound(SOUND_BGM);
        CSceneMgr::Get_Instance()->Scene_Change(ENDING);
    }
}

void CTorielDie::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Boss");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);

}

void CTorielDie::Release(void)
{
}
