#pragma once
#include "Obj.h"
class CPlayerState : public CObj
{
public:
	CPlayerState();
	virtual ~CPlayerState();

public:

	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	TCHAR		szBuff[100] = L"";
	DWORD		m_dwTime;
	int			m_iCurHp;
};

