#pragma once
#include "ObjBattle.h"

class CPlayerS2 : public CObjBattle {
public:
	CPlayerS2();
	virtual ~CPlayerS2();

public:
	virtual void Initialize(void)	override;
	virtual int Update(void)		override;
	virtual void Late_Update(void)	override;
	virtual void Render(HDC hDC)	override;
	virtual void Release(void)		override;


private:
	void		Key_Input(void);

private:
	float				m_fDistance;

	bool				m_bJump;
	float				m_fPower;
	float				m_fTime;
};