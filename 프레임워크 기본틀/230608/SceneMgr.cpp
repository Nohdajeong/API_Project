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

		case INTRO:
			m_pScene = new Intro;
			break;

		case RUIN:
			m_pScene = new CStage1;
			break;

		case FLOWEY:
			m_pScene = new CStage2;
			break;

		case TORIEL:
			m_pScene = new CStage3;
			break;

		case MONSTER_MATCH:
			m_pScene = new CMonsterMatch;
			break;

		case MONSTER_IDLE:
			m_pScene = new CMonsterIdle;
			break;

		case MONSTER_ATTACK:
			m_pScene = new CMonsterAttack;
			break;

		case MONSTER_PHASE:
			m_pScene = new CMonsterPhase;
			break;

		case MONSTER_ACT:
			m_pScene = new CMonsterAct;
			break;

		case MONSTER_ITEM:
			m_pScene = new CMonsterItem;
			break;

		case MONSTER_MERCY:
			m_pScene = new CMonsterMercy;
			break;

		case BOSS_MATCH:
			m_pScene = new CTorielMatch;
			break;

		case BOSS_IDLE:
			m_pScene = new CTorielIdle;
			break;

		case BOSS_ATTACK:
			m_pScene = new CTorielAttack;
			break;

		case BOSS_PHASE:
			m_pScene = new CTorielPhase;
			break;

		case BOSS_ACT:
			m_pScene = new CTorielAct;
			break;

		case BOSS_ITEM:
			m_pScene = new CTorielItem;
			break;

		case BOSS_MERCY:
			m_pScene = new CTorielMercy;
			break;

		case BOSS_DIE:
			m_pScene = new CTorielDie;
			break;

		case ENDING:
			m_pScene = new Ending;
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
