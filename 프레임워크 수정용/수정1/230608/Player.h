#pragma once

#include "Obj.h"

class CPlayer final : public CObj
{
public:
	enum STATE { IDLE, WALK, STATE_END };

public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize(void)	override;
	virtual int Update(void)		override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC)	override;
	virtual void Release(void)		override;

private:
	void		Key_Input(void);
	void		Jump(void);
	void		OffSet();
	void		Motion_Change(void);
	void		Set_Location(void);


private:
	POINT				m_tPosin;
	float				m_fDistance;

	bool				m_bJump;
	float				m_fPower;
	float				m_fTime;

	STATE				m_eCurState;
	STATE				m_ePreState;

	SCENEID				m_eCurScene;
	SCENEID				m_ePreScene;

	bool				m_bStretch = false;
	DWORD				m_dwTime = GetTickCount();


};
