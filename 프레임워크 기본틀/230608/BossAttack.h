#pragma once
#include "State.h"
#include "Boss.h"

class BossAttack : public IState<Boss, BossState>
{
public:
	BossAttack();
	~BossAttack();
public:
	// IState��(��) ���� ��ӵ�
	virtual void Initialize(Boss& _Actor) override;
	virtual BossState Update(Boss& _Actor) override;
	virtual void Late_Update(Boss& _Actor) override;
	virtual void Render(HDC hDC, Boss& _Actor) override;
	virtual void Release(Boss& _Actor) override;
};