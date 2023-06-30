#pragma once
#include "ObjS4.h"

class CPlayerS4 : public CObjS4 {
public:
	CPlayerS4();
	virtual ~CPlayerS4();

public:
	virtual void Initialize(void)	override;
	virtual int Update(void)		override;
	virtual void Late_Update(void)	override;
	virtual void Render(HDC hDC)	override;
	virtual void Release(void)		override;

private:
	void		Key_Input(void);
	void		Jump(void);

	template<typename T>
	CObj* Create_Bullet();

private:
	float				m_fDistance;

	bool				m_bJump;
	float				m_fPower;
	float				m_fTime;
};