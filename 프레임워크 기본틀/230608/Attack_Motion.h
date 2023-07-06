#pragma once
#include "Obj.h"

class CAttackMotion : public CObj {

public:
	CAttackMotion();
	virtual ~CAttackMotion();

public:
	virtual void Initialize(void)	override;
	virtual int Update(void)		override;
	virtual void Late_Update(void)	override;
	virtual void Render(HDC hDC)	override;
	virtual void Release(void)		override;

private:
	DWORD		m_dwTime = GetTickCount64();
};