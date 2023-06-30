#pragma once
#include "ObjS1.h"

class CPlayerS1 : public CObjS1 {
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

private:
	float				m_fDistance;

	bool				m_bJump;
	float				m_fPower;
	float				m_fTime;

	float				m_fJumpSpeed;
};