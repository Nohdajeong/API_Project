#pragma once
#include "Obj.h"
class CMonsterState : public CObj
{
public:
	CMonsterState();
	virtual ~CMonsterState();

public:

	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	TCHAR		szBuff[100] = L"";
	int			m_iLevel;
	int			m_iCurHp;
	int			m_iMaxHp;

	DWORD		m_dwTime;
};

