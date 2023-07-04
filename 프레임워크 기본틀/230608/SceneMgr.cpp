#include "stdafx.h"
#include "SceneMgr.h"

CSceneMgr*	CSceneMgr::m_pInstance = nullptr;

CSceneMgr::CSceneMgr()
	: m_eCurScene(RUIN), m_ePreScene(SCENE_END), m_pScene(nullptr)
{
}

CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::Scene_Change(SCENEID eScene)
{
	m_eCurScene = eScene;

	if (m_ePreScene != m_eCurScene)
	{
		Safe_Delete(m_pScene);

		switch (m_eCurScene)
		{
		case RUIN:
			m_pScene = new CStage1;
			break;

		case FLOWEY:
			m_pScene = new CStage2;
			break;

		case MONSTER_MATCH:
			m_pScene = new CBattle;
			break;

		case MONSTER_IDLE:
			m_pScene = new CIdle;
			break;

		case MONSTER_ATTACK:
			m_pScene = new CAttack;
			break;

		case MONSTER_PHASE:
			m_pScene = new CMonsterPhase;
			break;
		}

		m_pScene->Initialize();

		m_ePreScene = m_eCurScene;
	}

}

void CSceneMgr::Update()
{
	m_pScene->Update();
}

void CSceneMgr::Late_Update()
{
	m_pScene->Late_Update();
}

void CSceneMgr::Render(HDC hDC)
{
	m_pScene->Render(hDC);
}

void CSceneMgr::Release()
{
	Safe_Delete(m_pScene);
}
