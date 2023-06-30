#pragma once

#include "Actor.h"
#include "Bullet.h"
#include "AbstractFactory.h"

enum class NewPlayerState 
{
	Idle,
	Walk,
	Jump,
	Fall,
	NewPlayerState_End
};

class CNewPlayer : public Actor<CNewPlayer, NewPlayerState>
{
public:
	CNewPlayer();
	virtual ~CNewPlayer();

public:
	void	Set_Jump() { m_bJump = true; }

public:
	bool		Idle();
	bool		Walk();
	bool		Move();
	JUMPSTATE	Jump();

public:
	JUMPSTATE Get_JUMPSTATE() { return m_eJumpState; }

public:
	virtual void	Initialize(void)	override;
	virtual int		Update(void)		override;
	virtual void	Late_Update(void)	override;
	virtual void	Render(HDC hDC)	override;
	virtual void	Release(void)		override;

private:
	template<typename T>
	CObj* Create_Bullet();

private:
	float				m_fDistance;

	bool				m_bJump;
	float				m_fPower;
	float				m_fTime;

	JUMPSTATE			m_eJumpState;
};