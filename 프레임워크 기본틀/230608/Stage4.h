#pragma once



#include "IStage.h"

#include "DefineS4.h"
#include "PlayerS4.h"
#include "MonsterS4.h"

#include "Bullet.h"
#include "Mouse.h"



class CStage4 : public IStage
{
public:
	CStage4();
	~CStage4();

public:
	virtual void	Initialize() override;
	virtual void	Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release() override;
	virtual SCENEID UpdateScene() override;

};

