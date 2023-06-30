#pragma once
#include "ObjS1.h"

class CPlayerS1 : public CObjS1 {
public:
	enum STATE { IDLE, WALK, STATE_END };

public:
	CPlayerS1();
	virtual ~CPlayerS1();

public:
	virtual void Initialize(void)	override;
	virtual int Update(void)		override;
	virtual void Late_Update(void)	override;
	virtual void Render(HDC hDC)	override;
	virtual void Release(void)		override;

private:
	void		Key_Input(void);
	void		OffSet(void);
	void		Motion_Change(void);

private:
	float				m_fDistance;

	bool				m_bJump;
	float				m_fPower;
	float				m_fTime;

	float				m_fJumpSpeed;

	STATE				m_eCurState;
	STATE				m_ePreState;

};