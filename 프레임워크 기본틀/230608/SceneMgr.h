#pragma once

#include "Intro.h"
#include "Stage_Ruin.h"
#include "Stage_Flowey.h"
#include "MonsterBattle.h"
#include "MonsterAttack.h"
#include "MonsterPhase.h"
#include "MonsterIdle.h"

class CSceneMgr
{
private:
	CSceneMgr();
	~CSceneMgr();

public:
	SCENEID		Get_SceneID() { return m_eCurScene; }

public:
	void		Scene_Change(SCENEID eScene);
	void		Update();
	void		Late_Update();
	void		Render(HDC hDC);
	void		Release();

public:
	static CSceneMgr*		Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CSceneMgr;
		}

		return m_pInstance;
	}
	static void		Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CSceneMgr*		m_pInstance;
	IScene*					m_pScene;

	SCENEID					m_eCurScene;
	SCENEID					m_ePreScene;
};

// state ���� : ��ü�� �ڽ��� ���� �� �ִ� ������ ������ ����, �� �� �ݵ�� �� �ϳ��� ���¸��� ���Ѵٴ� �ǹ��� ����

