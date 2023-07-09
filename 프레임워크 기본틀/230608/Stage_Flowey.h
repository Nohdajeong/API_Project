#pragma once

#include "IScene.h"
#include "Flowey.h"
#include "SceneMgr.h"

class CStage2 : public IScene
{
public:
	CStage2();
	~CStage2();

public:
	// IStage을(를) 통해 상속됨
	virtual void Initialize();
	virtual void Update();
	virtual void Late_Update();
	virtual void Render(HDC hDC);
	virtual void Release();

private:
	bool	Search(CObj* _pTarget);
	float	m_fRange;

private:
	DWORD		m_dwTime = GetTickCount();

};

