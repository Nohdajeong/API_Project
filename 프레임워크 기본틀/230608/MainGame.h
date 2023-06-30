#pragma once

#include "Define.h"
#include "Intro.h"
#include "Stage1.h"



class CMainGame
{

public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize();
	void		Update();
	void		Late_Update();
	void		Render();
	void		Release();
	void		UpdateStage();

private:
	HDC			m_hDC;

	list<CObj*>	m_ObjList[OBJID_END];

	DWORD		m_dwTime;
	int			m_iFPS;
	TCHAR		m_szFPS[32];

	SCENEID		m_eSceneId;
	IScene*		m_eScenes[SCENE_END];

	bool		m_bMapEdit;
};

