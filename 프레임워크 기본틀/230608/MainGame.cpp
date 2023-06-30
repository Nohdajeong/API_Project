#include "stdafx.h"
#include "MainGame.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "LineMgr.h"
#include "KeyMgr.h"

CMainGame::CMainGame() : m_dwTime(GetTickCount()), m_iFPS(0)
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

	m_eSceneId = RUIN;
	m_eScenes[INTRO] = new Intro();

	m_eScenes[RUIN] = new CStage1();

	m_eScenes[m_eSceneId]->Initialize();
}

void CMainGame::Update()
{
	m_eScenes[m_eSceneId]->Update();
}


void CMainGame::Late_Update()
{
	m_eScenes[m_eSceneId]->Late_Update();
}

void CMainGame::Render()
{
	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount();
	}

	m_eScenes[m_eSceneId]->Render(m_hDC);


}

void CMainGame::Release()
{
	m_eScenes[m_eSceneId]->Release();
	for (auto scene : m_eScenes) 
	{
		Safe_Delete(scene);
	}
	CObjMgr::Get_Instance()->Release();
	ReleaseDC(g_hWnd, m_hDC);
}

void CMainGame::UpdateStage()
{
	SCENEID nextStage = m_eScenes[m_eSceneId]->UpdateScene();
	if (m_eSceneId != nextStage) {
		m_eScenes[m_eSceneId]->Release();

		m_eSceneId = nextStage;
		m_eScenes[m_eSceneId]->Initialize();
	}
}
