#pragma once
#include "Obj.h"
class CMushroom : public CObj {
public:
	enum MUSHROOMSTATE {IDLE, OPEN, DANCE, STATE_END};

public:
	CMushroom();
	virtual ~CMushroom();

public:
	virtual void	Initialize(void) override;
	virtual int		Update(void) override;
	virtual void	Late_Update(void) override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release(void) override;


private:
	void		Motion_Change(void);
	bool		Search(CObj* _pTarget);

	float		m_fRange = 0.f;
	DWORD		m_dwTime = (DWORD)GetTickCount64();

private:
	MUSHROOMSTATE				m_eCurState;
	MUSHROOMSTATE				m_ePreState;

};