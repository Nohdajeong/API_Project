#pragma once

#define		WINCX		800
#define		WINCY		600

#define		PURE		= 0
#define		PI			3.141592f

#define		OBJ_DEAD	 1
#define		OBJ_NOEVENT	 0

#define		VK_MAX		0xff

#define		TILEX		30
#define		TILEY		20

#define		TILECX		64
#define		TILECY		64

typedef struct tagInfo
{
	float	fX;		// 중점 X
	float	fY;		// 중점 Y
	float	fCX;	// 가로 길이
	float	fCY;	// 세로 길이	

}INFO;

typedef struct states {
	int		iLevel;
	int		iHp;
	int		iMaxHp;

	int		iMoney;
	
	int		iAttack;
	int		iDefense;
	
	int		iExp;
	int		iMaxExp;
} STATES;

enum DIRECTION { LEFT, RIGHT, UP, DOWN, DIR_END };

enum OBJID {	PLAYER, NPC, BATTLE_PLAYER, BATTLE_PLAYER_STATE, PLAYER_STATE, ATTACK,
				MONSTER, BULLET, MONSTER_MENTION,
				MOUSE, BUTTON, MESSAGEBOX, BAR,
				OBJID_END };

enum RENDERID { BACKGROUND, UI, GAMEOBJECT, EFFECT, RENDER_END };

enum CHANNELID { SOUND_EFFECT, SOUND_BGM, MAXCHANNEL };

enum class JUMPSTATE {JUMP, STAND, FALL};

enum SCENEID
{
	INTRO,
	RUIN, FLOWEY, TORIEL,
	MONSTER_MATCH, MONSTER_IDLE, MONSTER_ATTACK, MONSTER_PHASE, MONSTER_ACT, MONSTER_ITEM, MONSTER_MERCY,
	BOSS_MATCH, BOSS_IDLE, BOSS_ATTACK, BOSS_PHASE, BOSS_ACT, BOSS_ITEM, BOSS_MERCY,
	GAMEOVER,
	SCENE_END };

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

class CDeleteObj
{
public:
	template<typename T>
	void operator()(T& Temp)
	{
		if (Temp)
		{
			delete Temp;
			Temp = nullptr;
		}
	}
};
class CDeleteMap
{
public:
	template<typename T>
	void operator()(T& Pair)
	{
		if (Pair.second)
		{
			delete Pair.second;
			Pair.second = nullptr;
		}
	}
};

class CTag_Finder
{
public:
	CTag_Finder(const TCHAR* pString) : m_pString(pString) {}
public:
	template<typename T>
	bool operator()(T& Pair)
	{
		return !lstrcmp(m_pString, Pair.first);
	}

private:
	const TCHAR* m_pString;
};


typedef	struct tagLinePoint
{
	tagLinePoint() { ZeroMemory(this, sizeof(tagLinePoint)); }
	tagLinePoint(float _fX, float _fY) : fX(_fX), fY(_fY) {}

	float	fX;
	float	fY;

}LINEPOINT;

typedef struct tagLine
{
	tagLine() { ZeroMemory(this, sizeof(tagLine)); }
	tagLine(LINEPOINT& _tLpoint, LINEPOINT& _tRpoint)
		: tLpoint(_tLpoint), tRpoint(_tRpoint) { }

	LINEPOINT	tLpoint;
	LINEPOINT	tRpoint;

}LINE;

typedef struct tagFrame
{
	int			iFrameStart;
	int			iFrameEnd;
	int			iMotion;

	DWORD		dwSpeed;
	DWORD		dwTime;

}FRAME;

extern HWND g_hWnd;