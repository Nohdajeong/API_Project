#pragma once
#include "Actor.h"
#include "SceneMgr.h"

enum class LookState { IDLE, ATTACK1, ATTACK2 , StateEnd};

class CLook : public Actor<CLook, LookState> {

public:
	CLook();
	virtual ~CLook();

public:
	virtual void	Initialize(void) override;
	virtual int		Update(void) override;
	virtual void	Late_Update(void) override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release(void) override;

private:
	DWORD		m_preDeley;
	DWORD		m_PostDelay;

	TCHAR		szBuff[100] = L"";

};