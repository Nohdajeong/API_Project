#include "stdafx.h"
#include "TorielBattle.h"
#include "Toriel.h"
#include "MyButton.h"
#include "MessageBlock.h"
#include "PlayerState.h"
#include "SoundMgr.h"
#include "Player_Battle.h"

CTorielMatch::CTorielMatch()
    : m_iLevel(1), m_iHp(0), m_iMaxHp(0)
{
}

CTorielMatch::~CTorielMatch()
{
    Release();
}

void CTorielMatch::Initialize(void)
{
    float	g_fSound = 1.f;

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Back_Boss.bmp", L"Back_Boss");

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Fight.bmp", L"Fight");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Act.bmp", L"Act");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Item.bmp", L"Item");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Mercy.bmp", L"Mercy");

    CObjMgr::Get_Instance()->Add_Object(MONSTER, CAbstractFactory<CToriel>::Create());
    CObjMgr::Get_Instance()->Add_Object(BATTLE_PLAYER_STATE, CAbstractFactory<CPlayerBattle>::Create());
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create(400.f, 400.f));
    CObjMgr::Get_Instance()->Add_Object(PLAYER_STATE, CAbstractFactory<CPlayerState>::Create());

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

    CSoundMgr::Get_Instance()->PlaySoundW(L"TorielBattle.mp3", SOUND_BGM, g_fSound);

}

void CTorielMatch::Update(void)
{
    CObjMgr::Get_Instance()->Update();
}

void CTorielMatch::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();


}

void CTorielMatch::Render(HDC hDC)
{

    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Boss");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);
}

void CTorielMatch::Release(void)
{
    CObjMgr::Get_Instance()->Delete_ID(MESSAGEBOX);
}
