#pragma once
#include "Obj.h"
class CTorielLaserBullet: public CObj
{
public:
	CTorielLaserBullet();
	virtual ~CTorielLaserBullet();

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	bool		Search(CObj* _pTarget);

private:
	DWORD		m_dwTime;
	int			m_iTime;
	float		m_fRange;
};
