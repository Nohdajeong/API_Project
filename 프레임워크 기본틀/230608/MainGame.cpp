#include "stdafx.h"
#include "MainGame.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "LineMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "BmpMgr.h"

CMainGame::CMainGame() : m_dwTime(GetTickCount64()), m_iFPS(0)
{
	ZeroMemory(m_szFPS, sizeof(m_szFPS));
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	srand((unsigned int)time(NULL));

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Back.bmp", L"Back");
	CSoundMgr::Get_Instance()->Initialize();

	CSceneMgr::Get_Instance()->Scene_Change(INTRO);


}

void CMainGame::Update()
{
	CSceneMgr::Get_Instance()->Update();
}


void CMainGame::Late_Update()
{
	CSceneMgr::Get_Instance()->Late_Update();
}

void CMainGame::Render()
{
	++m_iFPS;

	if (m_dwTime + 2000 < GetTickCount64())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount64();
	}

	AddFontResourceA("NeoµÕ±Ù¸ð.ttf");
	AddFontResourceA("DeterminationSansK.ttf");
	AddFontResourceA("DeterminationSansK.otf");


	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back");

	HFONT	hFont, oldFont;

	hFont = CreateFont(25, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("NeoµÕ±Ù¸ð"));
	oldFont = (HFONT)SelectObject(hMemDC, hFont);

	CSceneMgr::Get_Instance()->Render(hMemDC);

	BitBlt(m_hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);


}

void CMainGame::Release()
{
	CBmpMgr::Destroy_Instance();
	CScrollMgr::Destroy_Instance();
	CKeyMgr::Destroy_Instance();
	CObjMgr::Destroy_Instance();
	CSceneMgr::Destroy_Instance();
	CSoundMgr::Destroy_Instance();
	CBmpMgr::Destroy_Instance();

	ReleaseDC(g_hWnd, m_hDC);
}
