#pragma once
#include "Obj.h"
class CTeacher : public CObj {
public:
	CTeacher();
	virtual ~CTeacher();

public:
	virtual void	Initialize(void) override;
	virtual int		Update(void) override;
	virtual void	Late_Update(void) override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release(void) override;


private:
	bool		Search(CObj* _pTarget);

	float		m_fRange = 0.f;
	DWORD		m_dwTime = (DWORD)GetTickCount64();


};