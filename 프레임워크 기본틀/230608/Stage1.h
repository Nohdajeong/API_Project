#pragma once

#include "IStage.h"
#include "PlayerS1.h"

class CStage1 : public IStage
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

	virtual SCENEID		UpdateScene() override;

private:
	DWORD		m_dwTime = GetTickCount();
};

