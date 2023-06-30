#pragma once
#include "State.h"
#include "Demeter.h"

class BossS1_Idle:public IState<Demeter, BossState>
{
public:
	 BossS1_Idle();
	~BossS1_Idle();

public:
	virtual void		Initialize(Demeter& _Actor) override;
	virtual BossState	Update(Demeter& _Actor) override;
	virtual void		Late_Update(Demeter& _Actor) override;
	virtual void		Render(HDC hDC, Demeter& _Actor) override;
	virtual void		Release(Demeter& _Actor) override;
};

