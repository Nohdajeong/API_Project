#pragma once

#include "DefineS2.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "BmpMgr.h"
#include "ObjBattle.h"

class IBattleScene
{
public:
	IBattleScene() {};
	virtual ~IBattleScene() {};

public:
	virtual void		Initialize(void)	PURE;
	virtual void		Update(void)		PURE;
	virtual void		Late_Update(void)	PURE;
	virtual void		Render(HDC hDC)		PURE;
	virtual void		Release(void)		PURE;
};

