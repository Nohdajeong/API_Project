#pragma once
#include "IScene.h"
#include "Define.h"
#include "Obj.h"

class CMonsterAttack : public IScene
{
public:
	CMonsterAttack();
	virtual ~CMonsterAttack();

public:
	// IScene을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	DWORD		m_dwTime = GetTickCount();
	TCHAR		szBuff[100] = L"";
	int			m_iLevel;
	int			m_iHp;
	int			m_iMaxHp;
};

