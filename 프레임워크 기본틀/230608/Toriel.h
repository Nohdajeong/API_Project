#pragma once
#include "Actor.h"

enum class TorielState { IDLE, ATTACK1, ATTACK2, ATTACK3, END };

class CToriel : public Actor<CToriel, TorielState>
{
public:
	CToriel();
	virtual ~CToriel();

public:
	virtual void		Initialize(void) override;
	virtual int			Update(void) override;
	virtual void		Late_Update(void) override;
	virtual void		Render(HDC hDC) override;
	virtual void		Release(void) override;

private:
	DWORD				m_dwTime = GetTickCount64();
	int					m_iDrawID;


};

