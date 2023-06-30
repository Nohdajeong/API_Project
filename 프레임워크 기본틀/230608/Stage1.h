#pragma once

#include "IStage.h"

#include "PlayerS1.h"
#include "MonsterS1.h"

#include "Bullet.h"
#include "Mouse.h"



class CStage1 : public IStage
{
public:
	CStage1();
	~CStage1();

public:
	virtual void		Initialize();
	virtual void		Update();
	virtual void		Late_Update();
	virtual void		Render(HDC hDC);
	virtual void		Release();

	virtual SCENEID		UpdateScene() override;

};

