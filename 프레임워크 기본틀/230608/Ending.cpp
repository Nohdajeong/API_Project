#include "stdafx.h"
#include "Ending.h"
#include "SceneMgr.h"

void Ending::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Ending.bmp", L"Ending");

}

void Ending::Update(void)
{
}

void Ending::Late_Update(void)
{

}

void Ending::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Ending");
	BitBlt(hDC, 0, 0, 800, 600, hMemDC, 0, 0, SRCCOPY);

}

void Ending::Release(void)
{
}