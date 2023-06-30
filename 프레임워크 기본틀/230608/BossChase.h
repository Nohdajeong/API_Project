#pragma once
#include "State.h"
#include "Boss.h"
#include <wtypes.h>

class BossChase : public IState<Boss, BossState>
{
public:
	BossChase();
	~BossChase();
public:
	virtual void		Initialize(Boss& _Actor) override;
	virtual BossState	Update(Boss& _Actor) override;
	virtual void		Late_Update(Boss& _Actor) override;
	virtual void		Render(HDC hDC, Boss& _Actor) override;
	virtual void		Release(Boss& _Actor) override;
};