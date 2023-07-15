#include "stdafx.h"
#include "Intro.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "KeyMgr.h"

void Intro::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Intro.bmp", L"Intro");


}

void Intro::Update(void)
{
	float	g_fSound = 1.f;

	if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
		CSoundMgr::Get_Instance()->PlayBGM(L"Intro.mp3", g_fSound);

}

void Intro::Late_Update(void)
{
	if (GetAsyncKeyState(VK_SPACE))
	{

		CSceneMgr::Get_Instance()->Scene_Change(RUIN);
	}

}

void Intro::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Intro");
	BitBlt(hDC, 0, 0, 800, 600, hMemDC, 0, 0, SRCCOPY);

}

void Intro::Release(void)
{
}