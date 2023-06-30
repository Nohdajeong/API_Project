#pragma once

#include "Define.h"

class IScene
{
public:
	IScene() {};
	virtual ~IScene() {};

public:
	virtual void		Initialize(void)	PURE;
	virtual void		Update(void)		PURE;
	virtual void		Late_Update(void)	PURE;
	virtual void		Render(HDC hDC)		PURE;
	virtual void		Release(void)		PURE;

	virtual SCENEID		UpdateScene()		PURE;
};

