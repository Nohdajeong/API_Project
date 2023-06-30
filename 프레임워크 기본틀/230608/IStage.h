#pragma once
#include "Define.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "ObjMgr.h"
#include "LineMgr.h"

#include "IScene.h"


class IStage : public IScene{

public:
	IStage() {};
	virtual ~IStage() {};

public:
	virtual		void		Initialize()		PURE;
	virtual		void		Update()			PURE;
	virtual		void		Late_Update()		PURE;
	virtual		void		Render(HDC hDC)		PURE;
	virtual		void		Release()			PURE;

	virtual		SCENEID		UpdateScene()		PURE;

};