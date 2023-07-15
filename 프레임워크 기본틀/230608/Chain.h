#pragma once
#include "Obj.h"
class CChain : public CObj {

public:
	CChain();
	virtual ~CChain();

public:
	virtual void	Initialize(void) override;
	virtual int		Update(void) override;
	virtual void	Late_Update(void) override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release(void) override;

	DWORD		m_dwTime = (DWORD)GetTickCount64();


private:
	int			m_iDraw;
};