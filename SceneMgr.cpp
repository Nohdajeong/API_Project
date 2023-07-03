#include "stdafx.h"
#include "SceneMgr.h"
#include "BattleAttack.h"

CSceneMgr*	CSceneMgr::m_pInstance = nullptr;

CSceneMgr::CSceneMgr()
	: m_eCurScene(IDLE), m_ePreScene(BATTLE_END), m_pScene(nullptr)
{
}

CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::Scene_Change(BATTLE_SCENE eScene)
{
	m_eCurScene = eScene;

	if (m_ePreScene != m_eCurScene)
	{
		Safe_Delete(m_pScene);

		switch (m_eCurScene) {
		case IDLE:
			break;

		case FIGHT:			
			m_pScene = new CBattleAttack;
			break;

		case ACT:
			break;

		case ITEM:
			break;

		case MERCY:
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
