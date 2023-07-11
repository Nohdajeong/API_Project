#pragma once
#include "Obj.h"
class CPlayer_Attack : public CObj
{
public:
	CPlayer_Attack();
	virtual ~CPlayer_Attack();

public:

	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	int		Damage_size(float _fX);

private:
	DWORD		m_dwTime = (DWORD)GetTickCount64();
};

