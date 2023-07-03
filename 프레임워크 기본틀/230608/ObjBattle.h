#pragma once
#include "Obj.h"
#include "BmpMgr.h"
#include "AbstractFactory.h"
#include "KeyMgr.h"
#include "DefineS2.h"
#include "IScene.h"
#include "IBattleScene.h"

class CObjBattle : public CObj {
public:
	CObjBattle() {};
	virtual ~CObjBattle() {};

public:
	void			Set_Scene(BATTLE_SCENE _Scene) { m_eScene = _Scene; }
	BATTLE_SCENE	Get_Scene() { return m_eScene; }

public:
	BATTLE_SCENE	m_eScene;
};