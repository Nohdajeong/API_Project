#pragma once

#include "Intro.h"
#include "Stage_Ruin.h"
#include "Stage_Flowey.h"
#include "Stage_Toriel.h"
#include "MonsterBattle.h"
#include "MonsterAttack.h"
#include "MonsterPhase.h"
#include "MonsterIdle.h"
#include "MonsterMercy.h"
#include "MonsterAct.h"
#include "MonsterItem.h"
#include "TorielAct.h"
#include "TorielAttack.h"
#include "TorielBattle.h"
#include "TorielIdle.h"
#include "TorielItem.h"
#include "TorielMercy.h"
#include "TorielPhase.h"
#include "Ending.h"

class CSceneMgr
{
private:
	CSceneMgr();
	~CSceneMgr();

public:
	SCENEID		Get_SceneID() { return m_eCurScene; }
	SCENEID		Get_ScenePreID() { return m_ePreScene; }

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

// state 패턴 : 객체는 자신이 취할 수 있는 유한한 개수를 갖고, 그 중 반드시 단 하나의 상태만을 취한다는 의미의 패턴

