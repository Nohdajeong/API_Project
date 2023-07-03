#pragma once

#include "IBattleScene.h"

class CSceneMgr
{
private:
	CSceneMgr();
	~CSceneMgr();

public:
	void		Scene_Change(BATTLE_SCENE eScene);
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
	static CSceneMgr* m_pInstance;
	IBattleScene*					m_pScene;

	BATTLE_SCENE					m_eCurScene;
	BATTLE_SCENE					m_ePreScene;
};
