#pragma once
#include "ObjS3.h"

class CPlayerS3 : public CObjS3 {
public:
	CPlayerS3();
	virtual ~CPlayerS3();

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