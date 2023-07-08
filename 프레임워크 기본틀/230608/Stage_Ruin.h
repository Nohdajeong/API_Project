#pragma once

#include "IScene.h"

class CStage1 : public IScene
{
public:
	CStage1();
	~CStage1();

public:
	virtual void		Initialize() override;
	virtual void		Update() override;
	virtual void		Late_Update() override;
	virtual void		Render(HDC hDC) override;
	virtual void		Release() override;

private:
	DWORD		m_dwTime = GetTickCount();
};

