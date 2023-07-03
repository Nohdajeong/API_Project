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
	// IStage��(��) ���� ��ӵ�
	virtual void Initialize();
	virtual void Update();
	virtual void Late_Update();
	virtual void Render(HDC hDC);
	virtual void Release();
	virtual SCENEID UpdateScene();

private:
	DWORD		m_dwTime = GetTickCount();

};

