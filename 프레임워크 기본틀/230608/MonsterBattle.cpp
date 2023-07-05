#include "stdafx.h"
#include "MonsterBattle.h"
#include "Look.h"
#include "MyButton.h"
#include "MessageBlock.h"
#include "PlayerState.h"
#include "SoundMgr.h"
#include "Player_Battle.h"

CMonsterMatch::CMonsterMatch()
{
}

CMonsterMatch::~CMonsterMatch()
{
    Release();
}

void CMonsterMatch::Initialize(void)
{
    float	g_fSound = 1.f;

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Back_Monster.bmp", L"Back_Monster");

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Fight.bmp", L"Fight");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Act.bmp", L"Act");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Item.bmp", L"Item");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Mercy.bmp", L"Mercy");

    CObjMgr::Get_Instance()->Add_Object(MONSTER, CAbstractFactory<CLook>::Create(300.f, 250.f));
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

    CSoundMgr::Get_Instance()->PlaySoundW(L"MonsterBattle.mp3", SOUND_BGM, g_fSound);
}

void CMonsterMatch::Update(void)
{
    CObjMgr::Get_Instance()->Update();
}

void CMonsterMatch::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();


}

void CMonsterMatch::Render(HDC hDC)
{

    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back_Monster");

    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);
}

void CMonsterMatch::Release(void)
{
    CObjMgr::Get_Instance()->Delete_ID(MESSAGEBOX);
}
