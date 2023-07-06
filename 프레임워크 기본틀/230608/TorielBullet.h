#pragma once
#include "Obj.h"
class CTorielBullet: public CObj
{
public:
	CTorielBullet();
	virtual ~CTorielBullet();

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	DWORD		m_dwTime;
	int			m_iTime;

private:
	bool		m_bStart;
	POINT		m_tCenter;

	float		m_fRotAngle; // 총알의 회전을 위한 각도
	float		m_fRotSpeed; // 총알의 회전 속도
	float		m_fDistance;

};
