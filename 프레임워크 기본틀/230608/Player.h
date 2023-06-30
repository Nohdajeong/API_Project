#pragma once

#include "Obj.h"

class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize(void)	override;
	virtual int Update(void)		override;
	virtual void Late_Update(void)	override;
	virtual void Render(HDC hDC)	override;
	virtual void Release(void)		override;

private:
	virtual void		Key_Input(void);
	virtual void		Jump(void);

	template<typename T>
	CObj* Create_Bullet();

private:
	float				m_fDistance;

	bool				m_bJump;
	float				m_fPower;
	float				m_fTime;

	float				m_fJumpSpeed;
};

