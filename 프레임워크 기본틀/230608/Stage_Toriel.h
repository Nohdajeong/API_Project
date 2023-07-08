#pragma once

#include "IScene.h"
#include "SceneMgr.h"

class CStage3 : public IScene
{
public:
	CStage3();
	~CStage3();

public:
	// IStage을(를) 통해 상속됨
	virtual void Initialize();
	virtual void Update();
	virtual void Late_Update();
	virtual void Render(HDC hDC);
	virtual void Release();

private:
	DWORD		m_dwTime = GetTickCount();

};

