#pragma once
#include "Actor.h"

enum class BossState 
{
	Idle,
	Chase,
	Attack,
	BossState_End
};

class Boss : public Actor<Boss, BossState> {
public:
	Boss();
	~Boss();

public:
	void Idle();
	void Chase();
	void Attack();

public:
	virtual void		Initialize(void) override;
	virtual int			Update(void) override;
	virtual void		Late_Update(void) override;
	virtual void		Render(HDC hDC) override;
	virtual void		Release(void) override;

};