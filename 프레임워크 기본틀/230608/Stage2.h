#pragma once

#include "IStage.h"
#include "Flowey.h"

class CStage2 : public IStage
{
public:
	CStage2();
	~CStage2();

public:
	virtual void	Initialize() override;
	virtual void	Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release() override;
	virtual SCENEID UpdateScene() override;

};

