#pragma once
#include "Define.h"

enum class BossState
{
	Idle,
	Chase,
	Attack,
	Defense,
	Groggy,
	BossState_End
};

enum BOSS_PHASE { PHASE1, PHASE2, PHASE3 };

enum MONSTER_STATE { M_IDLE, M_ATTACK, M_Search, M_DEFENSE, M_GROGY };

enum SEED_PHASE { ENABLE, UNABLE };

enum SEED_DIRECTION { SEED_LEFT, SEED_RIGHT, INIT };